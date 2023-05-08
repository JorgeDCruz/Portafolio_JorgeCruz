//Hecho por: Jorge Daniel Cruz Case
//Actividad Actividad Integral estructura de datos lineales 3.4
//Codigo para el ordenamiento y lectura del archivo "Bitacora" mediante algoritmos vistos en clase mediante un Max Heap
//2/11/2021

//-->Compilacion:

//g++ -std=c++17 -o main -g *.cpp "Debugeo"
//valgrind --leak-check=full ./main "Memory leak"
//g++ -std=c++17 *.cpp -Wall "Variables relleno"

//Recomendado correr con:
//g++ -std=c++17 -o main -O3 *.cpp
//./main

#include "MaxHeap.h"
#include "Ip.h"
#include <iostream>
#include <chrono>

using namespace std;


int main(){
    //system("cls"); //Solo windows :p

    //Iniciamos el reloj
    auto startTime = std::chrono::high_resolution_clock::now();
    auto startTime_cant = std::chrono::high_resolution_clock::now();

    //Creamos el max Heap
    MaxHeap <IP> lista(100000);
    try{
        lista.cargaDatos("bitacoraHeap.txt");
    }
    catch(const char* msg){
        std::cerr << msg << std::endl;
    }
    
    //Ordenamos el heap mediante las IPs
    lista.heapSort_ip();

    //Hacemos el archivo "Bitacora_Ordenada"
    lista.escribirArchivo_ordenado();

    //Se termina el conteo
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    std::cout << std::endl;

    //Termina el tiempo contado
    cout << "Tiempo de llenado y ordenamiento mediante IP: " << totalTime/std::chrono::milliseconds(1) <<" ms"<<endl;

    //Se modifica el atributo "cantidad" de capa IP dependiendo de la cantidad de veces que se repitan
    lista.contar();
    
    //Termina el tiempo contado
    auto endTime_cant = std::chrono::high_resolution_clock::now();
    auto totalTime_cant = endTime_cant - startTime_cant;
    cout << "\nTiempo de llenado y ordenamiento mediante su cantidad: " << totalTime_cant/std::chrono::milliseconds(1) <<" ms"<<endl;
    
    //Contamos las 5 ips con mas repeticiones y las ponemos en el archivo "ips_con_mayor_acceso"
    lista.contar_5();

    return 0;
}