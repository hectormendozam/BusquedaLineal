#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int countNumbersFromFile(char* filename) {
    ifstream fin;
    fin.open(filename);
    int dato, i = 0;

    do {
        fin >> dato;    /// Se saca dato del buffer (necesario para vaciar el buffer)
        i++;            /// Se contabiliza el dato obtenido
    } while (!fin.eof()); /// Se verifica si es fin de archivo (end of file)

    fin.close();

    return i;
}
void numbersFromFile(int A[], int N, char* filename) {
    ifstream fin;
    fin.open(filename);
    for (int i = 0; i < N; i++) {
        fin >> A[i];
    }
    fin.close();
}

int busquedaLineal(const int arreglo[], int tamano, int dato)
{
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == dato) {
            return i;
        }
    }
    return -1;
}
void mostrarArreglo(const int arreglo[], int tamano)
{
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }
}
int main()
{
    /*const int tamano = 7;
    int arreglo[] = { 6, 9, 12, 67, 3, 0, 2 };
    int prueba = busquedaLineal(arreglo, 7, 67);
    cout << "Elementos del arreglo: " << endl;
    mostrarArreglo(arreglo, tamano);

    cout << " El numero buscado se encuentra en la posicion " << prueba << " del arreglo " << endl;*/

    unsigned t0, t1;
    t0 = clock();

    char archivo[] = "numerosC.txt";
    int  N = countNumbersFromFile(archivo);
    cout << "\Datos: " << N << "\n";
    int  Arr[50001];
    numbersFromFile(Arr, N, archivo);
    cout << "BusquedaLineal NumerosC: posicion del numero 7: " << busquedaLineal(Arr, N, 7) << endl;

    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "\nExecution Time: " << time << " (" << t1 << "-" << t0 << ")" << endl;

    return 0;
}
