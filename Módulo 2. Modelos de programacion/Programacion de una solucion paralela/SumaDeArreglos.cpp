// SumaDeArreglos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// Se incluye librería iostream para las entradas y salidas del programa 
#include <iostream>

// Se incluye librería omp para habilitar las funciones de procesamiento en paralelo
#include <omp.h>


//Número de elementos del arreglo

#define N 1000

//Número de elementos que se desplegaran en pantalla
int mostrar;

//Variable temporal
int n;

//Función que se encargará de imprimir los resultados por medio de un apuntador
void imprimeArreglo(float *d, int a);

//Programa principal
int main()
{
    //Se imprime el tamaño de los arreglos
    using namespace std;
    cout << "El numero de elementos de los arreglos es: " << N  << std::endl;

    //Número en el que se va a dividir el arreglo
    using namespace std;
    cout << "Ingresa el numero de hilos de proceso: ";
    cin >> n;

    int pedazos = n;

    std::cout << "Sumando los Arreglos en Paralelo\n";

    //Se definen los arreglos de tamaño N
    float a[N], b[N], c[N];

    //Se define el contador de ciclos
    int i;

    //Ciclo que asignará valores a los arreglos
    for (i = 0; i < N; i++)
    {
        a[i] = float(i) + 1;
        b[i] = float(i) / 2;
    }

    //Se llama un proceso for en paralelo con los parámetros antes definidos
    //Los arreglos son comunes entre los procesos, pero el contador es único

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos) //La planificación es estática para cada hilo

    //Se realiza la suma en paralelo de todos los elementos
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    //Número de elementos que se desplegaran en pantalla
    cout << "Ingresa el numero de elementos de los arreglos a mostrar: ";
    cin >> n;

    mostrar = n;

    //Se imprimen los resultados
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a, mostrar);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b, mostrar);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c, mostrar);
}

void imprimeArreglo(float* d, int a)
{
    for (int x = 0; x < a; x++)

        std::cout << d[x] << " - ";

    std::cout << std::endl;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
