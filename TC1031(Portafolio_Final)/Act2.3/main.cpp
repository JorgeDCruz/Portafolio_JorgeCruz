//Hecho por: Jorge Daniel Cruz Case
//Actividad Actividad Integral estructura de datos lineales
//Codigo para el ordenamiento y lectura del archivo "Bitacora" mediante algoritmos vistos en clase mediante estructuras de datos
//15/10/2021

//-->Compilacion:

//g++ -std=c++17 -o main -g *.cpp "Debugeo"
//valgrind --leak-check=full ./main "Memory leak"
//g++ -std=c++17 *.cpp -Wall "Variables relleno"

//Recomendado correr con:
//g++ -std=c++17 -o main -O3 *.cpp
//./main

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

#include "dateTime.h"
#include "Stack.h"
#include "DoubleLinkedList.h"

using namespace std;

int main(){
    //Iniciamos el conteo de ejecucion
    auto startTime = std::chrono::high_resolution_clock::now();
    DoubleLinkedList <dateTime> lista;
    //Exepcion
    try{
        lista.cargaDatos("bitacora.txt");
    }
    catch(const char* msg){
        std::cerr << msg << std::endl;
    }
    lista.quickSort();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    std::cout << std::endl;
    //Termina el tiempo contado
    cout << "Tiempo de llenado y ordenamiento: " << totalTime/std::chrono::milliseconds(1) <<" ms"<<endl;
    
    //Creamos los datos a ingresar
    string mes_inf, mes_sup;
    string dia_inf, dia_sup, hora_inf, hora_sup, min_inf, min_sup, seg_inf, seg_sup;
    
    //Resultados de la busqueda
    int busqueda_binaria_inf;
    int busqueda_binaria_sup;

    std::cout << "\nIngrese la fecha inferior: " << std::endl;
    std::cout << "Mes: ";
    std::cin >>mes_inf;
    std::cout << "Dia: ";
    std::cin>>dia_inf;
    std::cout << "Hora: ";
    std::cin>>hora_inf;
    std::cout << "Minuto: ";
    std::cin>>min_inf;
    std::cout << "Segundo: ";
    std::cin>>seg_inf;
    dateTime fecha_inf(mes_inf, dia_inf, hora_inf, min_inf, seg_inf, "", "");

    busqueda_binaria_inf = lista.binarySearch(fecha_inf.getDate());

    if(busqueda_binaria_inf==-1){
        std::cout << "\nLa fecha ingresada no se encontro" << std::endl;
    }
    else{
       std::cout <<"Resultado de la busqueda inferior: "<< busqueda_binaria_inf << std::endl; 
    }
    

    std::cout << "\nIngrese la fecha superior: " << endl;
    std::cout << "Mes: ";
    std::cin >>mes_sup;
    std::cout << "Dia: ";
    std::cin>>dia_sup;
    std::cout << "Hora: ";
    std::cin>>hora_sup;
    std::cout << "Minuto: ";
    std::cin>>min_sup;
    std::cout << "Segundo: ";
    cin>>seg_sup;
    dateTime fecha_sup(mes_sup, dia_sup, hora_sup, min_sup, seg_sup, "", "");
    
    busqueda_binaria_sup = lista.binarySearch(fecha_sup.getDate());

    if(busqueda_binaria_sup ==-1){
        
        std::cout << "\nLa fecha ingresada no se encontro" << endl;
    }
    else{
        std::cout <<"Resultado de la busqueda superior: "<<busqueda_binaria_sup << endl;
    }
    //Escribimos los archivos
    std::cout << "\n--->Creando archivo con los resultados de busqueda" << std::endl;
    lista.escribirArchivo_busqueda(busqueda_binaria_inf, busqueda_binaria_sup);
    std::cout << "\n--->Creando archivo con la bitacora ordenada" << std::endl;
    lista.escribirArchivo_ordenado();
}