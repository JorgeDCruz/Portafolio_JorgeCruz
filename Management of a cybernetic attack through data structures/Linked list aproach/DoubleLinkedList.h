//Hecho por: Jorge Daniel Cruz Case - A01634536
//15/10/2021
//Clase para el manejo de las listas doblemente ligadas

//Comandos para ejecucion

// g++ -std=c++17 -o main -g *.cpp
//valgrind --leak-check=full ./main
//g++ -std=c++17 *.cpp -Wall
//g++ -std=c++17 -o main -O3 *.cpp


#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <climits>
#include "Node.h"
#include "Stack.h"
#include "dateTime.h"
#include <fstream>
#include <sstream>

template <class T>
class DoubleLinkedList {
  private:
    Node<T>* head;
    Node<T>* tail;
    int numElements;
  public:
    //Constructor & Destructor
    DoubleLinkedList();
    ~DoubleLinkedList();

    //Metodos
    void addFirst(T value);
    void addLast(T value);
    void printList();
    T findData(int search);

    //Funciones de la act 2.3
    int binarySearch(time_t);

    //Manejo de archivos
    void escribirArchivo_busqueda(int,int);
    void escribirArchivo_ordenado();
    void cargaDatos(string);

    //Quicksort utilizando stacks
    void swap(T &, T &);
    Node<T>* partition(Node<T>*, Node<T>*);
    void quickSort();
    bool is_left(Node<T>*, Node<T>*);

    //Funciones de la act 2.2
    void clear();   
    void duplicate(); 
    void removeDuplicates();
    void getReversedSublist(int, int);

    //Getters
    Node<T>* getHead();
    Node<T>* getTail();
    int getNumElements();
};

//Constructor
template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
  std::cout << "--->Creando una lista vacia" << std::endl;
  head = NULL;
  tail = NULL;
  numElements = 0;
}

//Destructor
template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  std::cout << "\n--->Liberando memoria de la lista" << std::endl;
  Node<T> *p, *q;
  p = head;
  while (p != NULL) {
    q = p->next;
    delete p;
    p = q;
  }
  head = NULL;
  tail = NULL;
  numElements = 0;
}

//Funcion para limpiar la memoria de la lista, borrandola
//Recorre la lista creada y borra el valor de la memoria liberandola
//Complejidad de la funcion: O(n)
template<class T>
void DoubleLinkedList<T>::clear(){ //Complejidad total O(n)
  Node<T> *p, *q;
  p = head;
  while (p != NULL) { //Utilizamos el p!=Null como n, obtenemos: O(n)
    q = p->next;
    delete p;
    p = q;
  }
  head = NULL;
  tail = NULL;
  numElements = 0;
} 

//Metodo sacado de la actividad 1.3, solamente implementado en la clase
//Funcion para la lectura del archivo "bitacora.txt"
//La funcion mete el archivo a un vector, lo separa por atributos y lo añade a la lista ligada
//Complejidad total: O(n)
template<class T>
void DoubleLinkedList<T>::cargaDatos(string doc){
  ifstream archivo;
  archivo.open(doc);
  //Se logro abrir el archivo
  if (archivo.is_open()){//Complejidad total del if: O(n)
    string linea;
    while(getline(archivo,linea)){//Complejidad total del while: O(1)*O(1)*O(n) = O(n)
      stringstream sstr(linea); 
      string dato;
      vector<string> m;
      while (getline(sstr, dato,' ')){ //Complejidad del while: O(1)
        m.push_back(dato); 
      }
      
      string problema = m[4];
      int tamanio = m.size();
      for (int i = 5; i<tamanio; i++){ //Complejidad del ciclo: O(n)
        problema += (" " +m[5]);
        m[4] = problema;
        m.erase(m.begin()+5);
      }
      string horario = m[2];
      stringstream lineahora(horario);
      vector<string> h; 
      string hora = "";
      while (getline(lineahora, hora,':')){//Complejidad del while: O(1) 
        h.push_back(hora);
      }
      string horas = h[0];
      string minutos = h[1];
      string segundos = h[2];
      string dia = m[1];
      string mes = m[0];
      string ip = m[3];
      string error = m[4];
      dateTime tiempo(mes,dia,horas, minutos, segundos,ip,error);
      this->addLast(tiempo);
    }
    archivo.close(); 
  }
  else{
    //El archivo no se pudo abrir y da un error
    cout<< "Error de lectura de archivo"<<endl;
  }
}

//Metodo sacado de la actividad 1.3, solamente implementado en la clase y para escribir solo entre la busqueda
//Funcion para la escritura del archivo "resultado_busqueda" desde los indices de resultado de la busqueda binaria
//Complejidad aproximada de la funcion: O(n)
template<class T>
void DoubleLinkedList<T>::escribirArchivo_busqueda(int inf, int sup){
  ofstream file;
  string nombreArchivo;
  nombreArchivo = "resultado_busqueda.txt";
  file.open(nombreArchivo.c_str(), fstream::out);
  Node<dateTime> *p = head;
  //La lista leida esta vacia
  if(p == NULL){
    std::cout << "La lista esta vacia" << std::endl;
  }
  else{//Complejidad total del else: algo similar o equivalente a O(n)
    //La lista no esta vacia
    int i = 0;
    //Avanzamos la p hasta llegar al indice inferior
    while(i<=inf){
      p = p->next;
      i++;
    }
    //Llenamos el archivo con los resultados de la lista
    file << "----------------------Resultado de la busqueda----------------------" << endl;
    while(p!=NULL && inf<sup){ //Tomamos el "p!=NULL" y "inf<sup" como algo equivalente a O(n) 
      file << p->data.getMes() << " " << p->data.getDia() << " " << p->data.getHoras() << ":" << p->data.getMinutos() << ":" << p->data.getSegundos() << " " << p->data.getIP()  << " " << p->data.getError() << endl;
      p = p->next;
      inf++;
    }
  }
  std::cout << std::endl;
  file.close();
}

//Metodo sacado de la actividad 1.3, solamente implementado en la clase
//Funcion para la escritura del archivo "bitacora_ordenada"
//Complejidad aproximada de la funcion: O(n)
template<class T>
void DoubleLinkedList<T>::escribirArchivo_ordenado(){
  ofstream file;
  string nombreArchivo;
  //Indices de impresion, 0 al ultimo indice de la lista
  nombreArchivo = "bitacora_ordenada.txt";
  //Se crea el archivo
  file.open(nombreArchivo.c_str(), fstream::out);
  Node<dateTime> *p = head;
  if(p == NULL){//Complejidad total del if/else: O(n)
    std::cout << "La lista esta vacia" << std::endl;
  }
  else{
    while(p!=NULL){//Tomamos el "p!=NULL" como n, la complejidad es O(n) 
      file << p->data.getMes() << " " << p->data.getDia() << " " << p->data.getHoras() << ":" << p->data.getMinutos() << ":" << p->data.getSegundos() << " " << p->data.getIP()  << " " << p->data.getError() << endl;
      p = p->next;
    }
  }
  std::cout << std::endl;
  file.close();
}

//-->Quick sort iterativo inicio

//Funcion para realizar el intecambio entre 2 variables|
//Complejidad de la funcion: O(1)
template<class T>
void DoubleLinkedList<T>::swap(T &a, T &b ){ 
  T t = a; 
  a = b; 
  b = t; 
}

//Funcion para obtener el pivote necesario para el quicksort
//Complejidad de la funcion
template<class T>
Node<T>* DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h){
  if(h != NULL && l != h && l != h->next){
    T x = h->data;
    Node<T> *i = l->prev;
    Node<T> *j = l;
    while(j!=h){
      if(j->data <= x){
        i = (i == NULL)? l : i->next;
        swap(i->data, j->data);
      }
      j = j->next;
    }
    i = (i == NULL)? l : i->next;
    swap(i->data, h->data);
    return i;
  }
  else{
    return NULL;
  }
}

//Funcion para comprobar la posicion del pivote con respecto a los limites
//Complejidad de la funcion: O(n)
template<class T>
bool DoubleLinkedList<T>::is_left(Node<T>* inicio, Node<T>* fin){
  Node<T>* p;
  p = inicio;
  //Los indices ingresados son validos
  if(inicio!=NULL && fin!=NULL){
    int i = 1;
    while(p!=NULL){//Si tomamos "p!=NULL" como n, la complejidad es O(n)
      if(p == fin){//Ambos indices son iguales
        break;
      }
      p = p->next;
      i++;
    }
    if(i>1){ //El pivote esta en al menos 2 nodos de distancia
      return true;
    }
    else{
      return false;
    }
  }
  else{//Los indices ingresados son invalidos
    return false;
  }
}

//Funcion para el ordenamiento de la lista mediante un quicksort iterativo utilizando stacks
//Complejidad de la funcion: O(log n)
template<class T>
void DoubleLinkedList<T>::quickSort(){
  Node<T> *l, *h;
  Stack<Node<T>*> stack;
  l = head;
  h = tail;
  //Entran ambos al stack
  stack.push(l);
  stack.push(h);
  while(!stack.isEmpty()){//Mientras haya algo dentro del stack
    //Se sacan los datos del stack y se le asignan a h & l
    h = stack.pop();
    l = stack.pop();
    //Se calcula el pivote
    Node<T>* x = partition(l, h);
    //El pivote es valido
    if(x != NULL){
      //Se checa que el pivote este a la derecha de l
      if(is_left(l, x->prev)){
        //Se meten los datos al stack
        stack.push(l);
        stack.push(x->prev);
      }
      //Se checa que el pivote este a la izquierda de h
      if(is_left(x->next, h)){
        stack.push(x->next);
        stack.push(h);
      }
    }
  }
}

//-->Quick sort iterativo final


//Funcion para la busqueda de un dato en la lista
//Complejidad total de la funcion O(log n)
//Puede haber similitudes con el de Monserrat, esto ya que le ayude a implementarlo
template<class T>
int DoubleLinkedList<T>::binarySearch(time_t k){
  Node<dateTime> *p;
  p = head;
  int n = numElements;
  int inf = 0;
  int sup = n-1;
  int i = 0;
  while(inf<=sup){
    int m = (inf + (sup - inf) / 2);
    int fecha;
    while(i<m){
      p = p->next;
      fecha = p->data.getDate();
      i++;
    }
    i = 0;
    if (k == fecha) {
      return m;
    }
    else if (k < fecha) {
      sup = m - 1;
    }
    else {
      inf = m + 1;
    }
    p = head;
    fecha = p->data.getDate();
  }
  return -1;
}


//Funcion para duplicar cada elemento de la lista
//Complejidad de la funcion: O(n)
template<class T>
void DoubleLinkedList<T>::duplicate(){
  Node<T> *p;
  p = head;

  int value, valor;
  //Numero de elementos -1 para evitar errores debido al NULL
  int n = numElements-1;

  for(int i = 0; i<n; i++){//Complejidad del ciclo: O(n)

    value = p->data; // Valor a duplicar
    valor = p->next->data; //Valor next para no perderlo

    Node<T> *newNode = new Node<T>(value);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    p = p->next;

    numElements++;
    //If para asegurar que el ultimo dato se duplique
    if(p->next == NULL){
      addFirst(p->data);
    }
  }  
}

//Funcion para remover los elementos duplicados en una lista
//Complejidad de la funcion: O(n)
template<class T>
void DoubleLinkedList<T>::removeDuplicates(){//Complejidad O(n)
  Node<T>* p = head;
  Node<T>* q;
  if (p == NULL){
    std::cout << "La lista esta vacia" << std::endl;
    return;
  }
  while (p->next != NULL){//O(n)
    if (p->data == p->next->data){
      q = p->next->next;
      delete p->next;
      p->next = q;
    }
    else{
      p = p->next;
    }
  }
}

//Funcion para invertir una sublista entre los limites 
//Complejidad de la funcion: O(n)
template<class T>
void DoubleLinkedList<T>::getReversedSublist(int x, int y){
  Node<T> *p;
  Stack<int> myStack;
  p = head;
  int i = 0;
  int value;
  if(x>y){
    std::cout << "\nLimites invalidos, el inferior es mayor al superior!" << std::endl;
  }
  else if(y>numElements){
    std::cout << "\nLimites invalidos, el superior es demadiado grande" << std::endl;
  }
  else{//Sumamos las complejidades y obtenemos algo similar a O(n)
    std::cout << "\nLista original: ";
    printList();
    std::cout << "\nLos parametros: " << x << " y " << y << " son validos" <<std::endl;
    while(i<x){//O(n/x) equivalente a O()
      p = p->next;
      i++;
    }
    while(i<=y){//O(n/y) equivalente a O(n)
      myStack.push(p->data);
      i++;
      p = p->next;
    }
    i = x;
    p = head;
    for(int j = 0; j<x; j++){//O(n/x) equivalente a O(n)
      p = p->next;
    }
    while(i<=y){//O(n/y) equivalente a O(n)
      value = myStack.pop();
      p->data = value;
      p = p->next;
      i++;
    }
  }
}


//-->Funciones implementadas en clase

//Funcion para la impresion de la lista
//Complejidad total de la funcion: O(n)
template<class T>
void DoubleLinkedList<T>::printList(){
    Node<dateTime> *p;
    p = head;
    if(p == NULL){
        std::cout << "La lista esta vacia" << std::endl;
    }
    else{
        while(p!=NULL){//Si tomamos "p!=NULL" como n, la complejidad es O(n)
            p->data.imprime();
            p = p->next;
        }
    }
    std::cout << std::endl;
}

//Funcion para añadir algo al inicio de la lista
template<class T>
void DoubleLinkedList<T>::addFirst(T value) {
  Node<T> *newNode = new Node<T>(value);
  //La lista esta vacia
  if(head == NULL){
    head = newNode;
    tail = newNode;
  }
  else{
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  numElements++;
}

//Funcion para añadir algo al final de la lista
template<class T>
void DoubleLinkedList<T>::addLast(T value) {
  //La lista esta vacia
  if (head == NULL) {
    addFirst(value);
  }
  else {
    Node<T> *newNode = new Node<T>(value);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    numElements++;
  }    
}

//Funcion findData, busca un elemento en a lista
//Si el elemento existe regresa su posicion, si no regresa -1, si el arreglo esta vacio regresa -2
template<class T>
T DoubleLinkedList<T>::findData(int search) {//Complejidad O(n)
  Node<T> *p = head;
  int index = 0;
  //El arreglo esta vacio
  if(p == NULL){
    return -2;
  }
  //El arreglo no esta vacio
  else{
    while (p != NULL) {
      if (p->data == search){
        return index;
      }
      index++;
      p = p->next;
    }
    return -1;
  }
}



//Getters clasicos
template<class T>
Node<T>* DoubleLinkedList<T>::getHead(){
  return head;
}

template<class T>
Node<T>* DoubleLinkedList<T>::getTail(){
  return tail;
}

template<class T>
int DoubleLinkedList<T>::getNumElements() {
  return numElements;
}

#endif 