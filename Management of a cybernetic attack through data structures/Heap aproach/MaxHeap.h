//Hecho por: Jorge Daniel Cruz Case A01634536
//Max Heap base de la actividad 3.2

#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include<vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>

#include "Ip.h"
using namespace std;

template<class T>
class MaxHeap{
    private:
        // contiene los elementos del heap
        std::vector<T> data;  
        // capacidad maxima del heap
        int maxSize;
        // tamaño actual del heap   
        int size;   
        int parent(int i);
        int left(int i);
        int right(int i);
        
    public:
        //Constructor
        MaxHeap(int capacity);
        //Dsetructor
        ~MaxHeap();
        //Metodos
        void push(T key);
        void pop();
        T top();
        bool isEmpty();
        int getSize();
        int getCapacity();
        void printMaxHeap();
        //Metodos de la actividad 3.4
        void cargaDatos(string);
        void escribirArchivo_ordenado();
        //Heap sort por IP
        void heapify_sort_ip(int, int);
        void heapSort_ip();
        //Repeticiones de cada IP
        void contar();
        void contar_5();
        //Heap sort por cantidad
        void heapify_sort_cant(int, int);
        void heapSort_cant();
};

//Constructor
template <class T> 
MaxHeap<T>::MaxHeap(int capacity) {
    std::cout << "--->Creando un MaxHeap: " <<  this << std::endl;
    size = 0;
    maxSize = capacity;
    data.resize(maxSize);
}

//Dsetructor
template <class T> 
MaxHeap<T>::~MaxHeap() {
    std::cout << "\n--->Liberando memoria del MaxHeap: " <<  this << std::endl;
    data.clear();
}


//Funcion utilizada en todas las actividades anteriores
//Funcion para la lectura del archivo "bitacora.txt"
//La funcion mete el archivo a un vector, lo separa por atributos y lo añade a la lista ligada
//Complejidad total: O(n)
template<class T>
void MaxHeap<T>::cargaDatos(string doc){
    std::cout << "\n--->Llenando el Heap!" << std::endl;
    ifstream archivo;
    archivo.open(doc);
    //Se logro abrir el archivo
    if (archivo.is_open()){//Complejidad total del if: O(n)
        string linea;
        while(getline(archivo,linea)){//Complejidad total del while: O(1)*O(1)*O(n) = O(n)
            stringstream sstr(linea); 
            string dato;
            vector<string> m; //Vector que contara con las partes separadas
            while (getline(sstr, dato,' ')){ //Complejidad del while: O(1)
                m.push_back(dato); 
            }
            //Causa del error
            string problema = m[4]; 
            int n = m.size();
            for (int i = 5; i<n; i++){ //Complejidad del ciclo: O(n)
                problema += (" " +m[5]);
                m[4] = problema;
                m.erase(m.begin()+5);
            }   
            //Separamos la ip "ej. 80.169.79.65:1150" en 4
            string ipes = m[3];
            stringstream lineaIpe(ipes);
            vector<string> ip;
            string ip_util = "";
            while (getline(lineaIpe, ip_util,'.')){//Complejidad del while: O(1) 
                ip.push_back(ip_util);
            }
            //Separamos los ultimos 2 datos "ej. 65:1150"
            string ultima_ip = ip[3];
            stringstream linea_ult_ip(ultima_ip);
            vector<string> ult_ip;
            string ulti_ip_util = "";

            while (getline(linea_ult_ip, ulti_ip_util,':')){//Complejidad del while: O(1) 
                ult_ip.push_back(ulti_ip_util);
            }
            //Atributos separados
            string horas = m[2];
            string dia = m[1];
            string mes = m[0];
            //Ip: 80.169.79.65:1150
            int ip1 = stoi(ip[0]); //Ej. 80
            int ip2 = stoi(ip[1]); //Ej. 169
            int ip3 = stoi(ip[2]); //Ej. 79
            int ip4 = stoi(ult_ip[0]); //Ej. 65
            string puerto = ult_ip[1]; //Ej. 1150
            string error = m[4];
            IP tiempo(mes, dia ,horas, ip1, ip2, ip3, ip4, puerto, error, "1");
            this->push(tiempo);
        }
        archivo.close(); 
        cout << "--->Success! " << endl;
    }
    else{
        cout<< "Error de lectura de archivo"<<endl;
    }
}

//Funcion utilizada en lac actividades anteriores
//Metodo sacado de la actividad 2.3, solamente implementado en la clase
//Funcion para la escritura del archivo "bitacora_ordenada"
//Complejidad aproximada de la funcion: O(n)
template<class T>
void MaxHeap<T>::escribirArchivo_ordenado(){
    std::cout << "\n--->Creando el archivo bitacora_Ordenada.txt" << std::endl;
    ofstream file;
    string nombreArchivo = "bitacora_Ordenada.txt";
    file.open(nombreArchivo.c_str(), fstream::out);
    int n = this->getSize();
    for (int i = 0;  i <n;  i++){//Complejidad: O(n)
        file << data[i].getMes() << " " << data[i].getDia() << " " << data[i].getHora() << " " << data[i].getIP1() << "." << data[i].getIP2() << "." << data[i].getIP3() << "." << data[i].getIP4() << "." << data[i].getPuerto() << " " << data[i].getError() << endl;

    }
    file.close();
    cout << "--->Success! " << endl;
}




//Funcion para comprobar si el heap esta vacio
//Complejidad de la funcion: O(1) 
template <class T> 
bool MaxHeap<T>::isEmpty() {
    return (size <= 0);
}

//-->Getters
template <class T> 
int MaxHeap<T>::getSize() {
    return size;
}

template <class T> 
int MaxHeap<T>::getCapacity() {
    return maxSize;
}

//Funcion para imprimir el heap completo de mayor a menor
//Complejidad de la funcion: O(n)
template <class T> 
void MaxHeap<T>::printMaxHeap() {
    for (int i=0; i < size; i++){//tomamos size como n, la complejidad es O(n)
        data[i].imprime();
    }
    std::cout << std::endl;
}

//Funcion para obtener el padre de una hoja
//Complejidad de la funcion: O(1)
template <class T> 
int MaxHeap<T>::parent(int i) {
    return (i-1)/2; 
}

//Funcion para obtener el hijo izquierdo de una hoja
//Complejidad de la funcion: O(1)
template <class T> 
int MaxHeap<T>::left(int i) {
    return (2*i + 1); 
}

//Funcion para obtener el hijo derecho de una hoja
//Complejidad de la funcion: O(1)
template <class T> 
int MaxHeap<T>::right(int i) {
    return (2*i + 2);
}

//Funcion para insertar una hoja en un heap
//Complejidad de la funcion: O(log n)
template <class T> 
void MaxHeap<T>::push(T key) {
    //El heap esta en su tamaño maximo
    if (size == maxSize) {
        //std::cout << "Overflow: no se puede insertar la llave: " << key.imprime() << std::endl;
        std::cout << "Overflow" << std::endl;
        return;
    }
    // Insertamos la nueva llave al final del vector
    int i = size;
    data[i] = key;
    size++;
    //Reacomodamos el orden de las hojas para mantener las propiedades de un Max Heap
    while (i != 0 && data[parent(i)] < data[i]) {
        std::swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

//Funcion para sacar el top del Heap
//Complejidad de la funcion: O(log n)
template <class T> 
void MaxHeap<T>::pop(){
    //El heap esta vacio
    if (isEmpty()) {
        std::cout << "El MaxHeap está vacio" << std::endl;
        return;
    }
    else{
        int i = 0;
        data[0].setMes("");
        data[0].setDia("");
        data[0].setIP1(0);
        data[0].setMes("");
        size--;
        std::swap(data[0], data[(size)]);
        while(data[right(i)].getDia() != "" && data[left(i)].getDia() != "" && i < size-1){
            if (data[right(i)] > data[left(i)]){
                std::swap(data[i], data[right(i)]);
                i = right(i);
            }
            else{
                std::swap(data[i], data[left(i)]);
                i = left(i);
            }
        }
    }
}


//Funcion para obtener el top o raiz de un Max Heap, en esta caso el valor mayor
//Complejidad de la funcion: O(1)
template <class T> 
T MaxHeap<T>::top(){
    /*
    T result("Jan", "1", "00:00:00", 127, 0, 0, 1, "100", "No hay un top :c", 1);
    //No hay Raiz
    if (isEmpty()) {
        std::cout << "El MaxHeap está vacio" << std::endl;
        return result;
    }
    */
    return data[0];
}

//-->Heap sort obtenido de la pagina: https://www.geeksforgeeks.org/heap-sort/
template <class T>
void MaxHeap<T>::heapify_sort_ip(int n, int i){
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
    if (l < n && data[l] > data[largest]){
        largest = l;
    }
    if (r < n && data[r] > data[largest]){
        largest = r;
    }
    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify_sort_ip(n, largest);
    }
}

//Funcion para ordenar el Heap mediante las IPs
template <class T>
void MaxHeap<T>::heapSort_ip(){
    int n = this->getSize();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_sort_ip(n, i);
 
    for (int i = n - 1; i > 0; i--) {
        std::swap(data[0], data[i]);
        heapify_sort_ip(i, 0);
    }
}


//Funcion para asignarle a cada IP la cantidad de veces que se repite
//Complejidad total de la funcion: O(n)
template <class T>
void MaxHeap<T>::contar(){
    int cantidad = 1;
    int cantidadTotal = 0;
    //Recorremos el arreglo
    for(int i = 0; i<size; i++){ //Complejidad del ciclo O(n)
        //Mientras las Ips sean iguales su cantidad aumentara
        if(data[i] == data[i+1]){
            data[i].setCantidad(cantidad);
            cantidad++;
        }
        else{
            //Cantidad Total
            data[i].setCantidad(cantidad);
            //Rescatamos la cantidad total
            cantidadTotal = data[i].getCantidad();

            //Asignamos la cantidad total a las ips correspondientes
            for(int k = i-(cantidadTotal-1); k<i; k++){ //Complejidad similar a O(n/i) o algo por el estilo
                data[k].setCantidad(cantidadTotal);
            }
            //reiniciamos la cantidad para el siguiente set de IPs
            cantidad = 1;
            
        }
    }
}


//--> Ordenamiento a base de la cantidad de veces que se repite una IP
template <class T>
void MaxHeap<T>::heapify_sort_cant(int n, int i){
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 

    if (l < n && data[l].getCantidad() < data[largest].getCantidad()){
        largest = l;
    }

    if (r < n && data[r].getCantidad() < data[largest].getCantidad()){
        largest = r;
    }

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify_sort_cant(n, largest);
    }
}


template <class T>
void MaxHeap<T>::heapSort_cant(){
    int n = this->getSize();
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify_sort_cant(n, i);
    }
    for (int i = n - 1; i > 0; i--){
        std::swap(data[0], data[i]);
        heapify_sort_cant(i, 0);
    }
}

//-->Fin del Heap sort

//Funcion para obtener las 5 IPs mas repetidas en la bitacora
//Fucione 2 funciones en una, la primera solamente te regresaba las primeras 5 IPs mas repetidas
//y la segunda para escribir el archivo, similar a escribe archivo ordenado
//Complejidad de la funcion: O(n) 
template <class T>
void MaxHeap<T>::contar_5(){
    std::cout << "\n--->Creando el archivo ips_con_mayor_acceso.txt" << std::endl;
    int num = 0;
    ofstream file;
    //Creamos un vector temporal
    std::vector <T> vector1;
    string nombreArchivo = "ips_con_mayor_acceso.txt";
    file.open(nombreArchivo.c_str(), fstream::out);
    //Insertamos el data al vector 
    for(int i = 0; i<size; i++){
        //Insertamos solamente los valores unicos al vector
        if(data[i]!=data[i+1]){
            vector1.push_back(data[i]);
        }
    }
    //Guardamos el tamaño original
    int n = size;
    //Vaciamos el heap
    for(int i = 0; i<n; i++){
        this->pop();
    }
    //Reinsertamos el vector al heap con solamente los datos unicos
    int m = vector1.size();
    for(int i = 0; i<m; i++){
        this->push(vector1[i]);
    }
    //Reordenamos el heap mediante la cantidad de repeticiones que tiene cada ip
    this->heapSort_cant();
    //Llenamos el archivo
    file << "---------- Ips con mayor acceso ---------------" << endl;
    for(int i = 0; i<size; i++){ //Complejidad: O(n)
        if(num<5){
            file << data[i].getIP1() << "." << data[i].getIP2() << "." << data[i].getIP3() << "." << data[i].getIP4() << "; Cantidad de repeticiones: " << data[i].getCantidad() << endl;
            num++;
        }
    }
    file.close();
    cout << "--->Success! " << endl;
}



#endif // __MAXHEAP_H_