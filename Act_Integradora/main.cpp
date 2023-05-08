/*

Actividad Integradora 2
TC2038 Grupo 603

Por:
Jorge Daniel Cruz Case - A01634536 & Alberto Estrada Guerrero - A01276671

Intrucciones:
Escribe en C++ un programa que ayude a una empresa que quiere incursionar en los servicios de Internet respondiendo a la situación problema 2.

1. (Kruskal's, Floyd-Warshall) Leer un archivo de entrada que contiene la información de un grafo representado en forma de una matriz de 
adyacencias con grafos ponderados.
El peso de cada arista es la distancia en kilómetros entre colonia y colonia, por donde es factible meter cableado.

El programa debe desplegar cuál es la forma óptima de cablear con fibra óptica conectando colonias de tal forma que se pueda compartir 
información entre cuales quiera dos colonias.

2. (Traveling salesman) Debido a que las ciudades apenas están entrando al mundo tecnológico, se requiere que alguien visite cada colonia 
para ir a dejar estados de cuenta físicos, publicidad, avisos y notificaciones impresos. por eso se quiere saber ¿cuál es la ruta más 
corta posible que visita cada colonia exactamente una vez y al finalizar regresa a la colonia origen?
El programa debe desplegar la ruta a considerar, tomando en cuenta que la primera ciudad se le llamará A, a la segunda B, y así sucesivamente

 

3. (Ford Fulkenson) El programa también debe leer otra matriz cuadrada de N x N datos que representen la capacidad máxima de transmisión de 
datos entre la colonia i y la colonia j. Como estamos trabajando con ciudades con una gran cantidad de campos electromagnéticos, que pueden 
generar interferencia, ya se hicieron estimaciones que están reflejadas en esta matriz.

La empresa quiere conocer el flujo máximo de información del nodo inicial al nodo final. Esto debe desplegarse también en la salida estándar.

Caso de prueba:

Entrada:

Input1.txt:
0 16 45 32
16 0 18 21
45 18 0 7
32 21 7 0

Input2.txt:
0 48 12 18
52 0 42 32
18 46 0 56
24 36 52 0

Salida:

<---- Punto no. 1 ---->

Cada valor representa la distancia optima para poder conectar la colonia x con la colonia y

   A  B  C  D
A  0 16 34 32
B  16 0 18 21
C  34 18 0 7
D  32 21 7 0

<---- Punto no. 2 ---->

La ruta mas optima para visitar cada colonia es:
A -> B -> C -> D -> A

Con un costo de: 73

<---- Punto no. 3 ---->

El flujo maximo de informacion a traves de las colonias A y D es: 78

Tiempo de ejecucion: 24 ms

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <chrono>
#include <queue>
using namespace std;

//Atributos para el traveling salesman problem
//Para evitar problemas con la recursividad, opte por declararlos aquí
vector<int> finalPath;
int finalSol = 0x3f3f3f3f;

//Funciones para la impresión de los componentes de la actividad:
template<typename T>
void printMatrix(vector<vector<T>> arr, int n){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void printVector(vector<T> arr, int n){
    for(int x = 0; x < n; x++){
        cout << arr[x] << "  ";
    }
    cout << endl;
}

void printGraph(vector<vector<int>> arr, int n){
    int v, w;

    for(int i = 0; i < n; i++){
        cout << "Nodo: " << i << "\n";
        for(int j = 0; j < (int)arr[i].size(); j++){
            if(arr[i][j] != 0){
                cout << "\tNodo: " << j << " peso: " << arr[i][j] << "\n";
            } 
        }
        cout << endl;
    }
}

void printColonies(vector<int> path, vector<char> alphabet){
    int n = path.size();
    cout << endl;
    for(int i = 0; i < n-1; i++){
        cout << alphabet[path[i]] << " -> ";
    }
    cout << alphabet[path[n-1]] << endl;
}

//Función para la lectura de un archivo y escritura de su contenido en una matriz resultante
void readFile(vector<vector<int>>& arr, string nameDoc){
    ifstream archivo;
    archivo.open(nameDoc);
    int n, numNodes;
    if(archivo.is_open()){
        int lineNum = 0;
        string line;
        while(getline(archivo, line)){//El ciclo se ejecuta en base a cuantas lineas hay dentro, por lo cual si
            stringstream sstr(line); //tomamos la cantidad de lineas como m, por lo cual la complejidad es O(m)
            string data;
            vector<int> aux;
            n = line.size();
            //Ingresa toda la linea a un vector auxiliar
            while(getline(sstr, data, ' ')){
                aux.push_back(stoi(data));
            }
            arr.push_back(aux);
            lineNum++;
        }
        archivo.close();
    }
}

//Algoritmo de Floyd - Warshall para encontrar la distancia más corta desde un nodo hacia otro
void floydWarshall(vector<vector<int>> arr_1, int n, vector<char> alphabet) {
    int dMasCorta[n][n];
    int temp = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dMasCorta[i][j] = arr_1[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp = dMasCorta[j][i] + dMasCorta[i][k];
                if (temp < dMasCorta[j][k]){
                    dMasCorta[j][k] = dMasCorta[j][i] + dMasCorta[i][k];
                }
            }
        }
    }

    //Imprimimos la matriz resultante de una manera más sencilla de entender
    cout << "\n   ";
    printVector(alphabet, n);
    for (int i = 0; i < n; i++) {
        cout << alphabet[i] << "  ";
        for (int j = 0; j < n; j++) {
            cout << dMasCorta[i][j] << " ";
        }
        cout << endl;
    }
}

//Funciones para la ejecución del Traveling Salesman a través de branch and bound

//Función para encontrar el valor más pequeño de una matriz
int getLowest(vector<vector<int>> arr, int lastVertex, int numNodes){
    int min = 0x3f3f3f3f;
    for(int i = 0; i < numNodes; i++){
        if(arr[lastVertex][i] < min && lastVertex != i){
            min = arr[lastVertex][i];
        }
    }
    return min;
}

//Función para encontrar el segundo menor valor de una matriz
int getSecondLowest(vector<vector<int>> arr, int lastVertex, int numNodes){
    int first = 0x3f3f3f3f;
    int second = 0x3f3f3f3f;

    for(int i = 0; i < numNodes; i++){
        //Evitamos aquel vertice especificado para no tomarlo en cuenta
        if(lastVertex == i){
            continue;
        }
        //Si se encuentra un numero menor 
        if(arr[lastVertex][i] <= first){
            //El segundo menor se vuelve el anterior menor
            second = first;
            //El primer menor se vuelve aquel encontrado
            first = arr[lastVertex][i];
        }
        //Si se encontro un menor al segundo y no es el primero
        else if(arr[lastVertex][i] <= second && arr[lastVertex][i] != first){
            second = arr[lastVertex][i];
        }
    }
    return second;
}

//Función para pasar el camino guardado a un vector nuevo que solamente contenga el camino final
void getPath(vector<int> currentPath, vector<int>& finalPath, int numNodes){
    for(int i = 0; i < numNodes; i++){
        finalPath[i] = currentPath[i];
    }
    finalPath[numNodes] = 0;
}

//Algoritmo recursivo para resolver el problema del traveling salesman a través del método de branch and bound
void travelingSalesman(vector<vector<int>> graph, vector<bool> visited, int bound, int weight, int level, vector<int> currentPath, int numNodes){
    //Llegamos al último nivel de nodos, por lo cual ya analizamos todos los nodos anteriores
    if(level == numNodes){
        //Checar si hay un vertice que nos lleve de regreso al nodo original
        if(graph[currentPath[level-1]][currentPath[0]] != 0){
            int currentSol = weight + graph[currentPath[level-1]][currentPath[0]];
            if(currentSol < finalSol){
                //Obtenemos el camino final
                getPath(currentPath, finalPath, numNodes);
                finalSol = currentSol;
            }
        }
        //Terminamos la recursividad
        return;
    }

    //Checamos todos los nodos que no han sido visitados
    for(int i = 0; i < numNodes; i++){
        //Checamos que estemos dentro de rango y que el nodo actual no haya sido visitado antes
        if(graph[currentPath[level-1]][i] != 0 && visited[i] == false){
            int temp = bound;
            weight += graph[currentPath[level-1]][i];
            if(level == 1){
                bound -= ((getLowest(graph, currentPath[level-1], numNodes) + getLowest(graph, i, numNodes))/2);
            }
            else{
                bound -= ((getSecondLowest(graph, currentPath[level-1], numNodes) + getLowest(graph, i, numNodes))/2);
            }

            if(bound + weight < finalSol){
                currentPath[level] = i;
                visited[i] = true;
                travelingSalesman(graph, visited, bound, weight, level+1, currentPath, numNodes);
            }

            weight -= graph[currentPath[level-1]][i];
            bound = temp;
            
            //Reiniciamos los nodos visitados
            for(int j = 0; j < visited.size(); j++){
                visited[j] = false;
            }

            //Marcamos aquellos ya incluidos como visitados 
            for(int k = 0; k <= level-1; k++){
                visited[currentPath[k]] = true;
            }
        }
    }
}   

//Función para la ejecución del algoritmo de traveling salesman
//Ya que el algoritmo de traveling salesman es recursivo, es mejor ejecutarlo a través de una función intermediaria
void executeTravelingSalesman(vector<vector<int>> graph, int numNodes){
    vector<int> currentPath(numNodes+1, -1);
    vector<bool> visited(numNodes+1, false);
    finalPath.resize(numNodes+1);
    int bound = 0;

    //Obtenemos la frontera inicial al obtener los 2 valores más pequeños
    for(int i = 0; i < numNodes; i++){
        bound += (getLowest(graph, i, numNodes) + getSecondLowest(graph, i, numNodes));
    }

    //Checamos si bound es par
    //Si es impar se divide entre 2 y se suma 1 para obtener el punto medio
    //Si es par de divide entre 2 para obtener el punto medio
    bound = (bound&1)? bound/2 + 1 : bound/2;

    //Marcamos el punto inicial 
    visited[0] = true;
    currentPath[0] = 0;

    travelingSalesman(graph, visited, bound, 0, 1, currentPath, numNodes);
}


//Funciones del algoritmo de Ford - Fulkerson

//Breath First Search utilizado para el algoritmo
bool BFS(vector<vector<int>> &m, int &raiz, int &finalDestino, vector<int> &padres) {
    int n = m.size();
    vector<bool> visitado(n, false);
    queue<int> cola;

    cola.push(raiz);
    visitado[raiz] = true;
    padres[raiz] = -1;

    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        for (int i = 0; i < n; i++) {
            int v = i;
            int capacidadM = m[u][v];
            if (!visitado[v] && capacidadM > 0) {
                cola.push(v);
                padres[v] = u;
                visitado[v] = true;
            }
        }
    }
    if (visitado[finalDestino]) {
        return true;
    }
    return false;
}

//Algoritmo de Ford - Fulkerson para el cálculo del flujo a través de un grafo
int fordFulkerson(vector<vector<int>> &m, int raiz, int finalDestino) {
    int flujoMaximo = 0;

    vector<vector<int>> resM;
    int n = m.size();

    for (int i = 0; i < n; i++) {
        vector<int> fila;
        resM.push_back(fila);
        for (int j = 0; j < m[i].size(); j++) {
            resM[i].push_back(m[i][j]);
        }
    }

    vector<int> padres(n, -1);

    while (BFS(resM, raiz, finalDestino, padres)) {
        int flujo = 10000007;
        int dest_t = finalDestino;
        while (dest_t != raiz) {
            int padres_t = padres[dest_t];
            int capacidad = resM[padres_t][dest_t];
            flujo = min(flujo, capacidad);
            dest_t = padres_t;
        }
        dest_t = finalDestino;
        while (dest_t != raiz) {
            int padres_t = padres[dest_t];
            resM[padres_t][dest_t] -= flujo;
            resM[dest_t][padres_t] += flujo;
            dest_t = padres_t;
        }
        flujoMaximo += flujo;
    }
    return flujoMaximo;
}


int main(){

    auto startTime = std::chrono::high_resolution_clock::now();

    //Matriz de adyacencia para el punto 1 y 2
    vector<vector<int>> graphWeight;

    //Matriz de adyacencia para el punto 3
    vector<vector<int>> graphFlow;

    //Para la correcta impresión de las colonias vamos a utilizar una letra del abacedario para representarla
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    //Archivos de entrada
    string fileName1 = "input1.txt";
    string fileName2 = "input2.txt";

    //Llenamos las matrices con el contenido de los archivos
    readFile(graphWeight, fileName1);
    readFile(graphFlow, fileName2);

    //Asumiremos que todas las matrices serán del mismo tamaño y de NxN
    int numNodes = graphWeight.size();

    //
    cout << "\n<---- Punto no. 1 ---->" << endl; 
    cout << "\nCada valor representa la distancia optima para poder conectar la colonia x con la colonia y" << endl;
    floydWarshall(graphWeight, numNodes, alphabet);

    //Ejecución del algoritmo de traveling salesman a través de branch and bound
    //Esto para encontrar la ruta más eficiente para pasar por cada nodo
    cout << "\n<---- Punto no. 2 ---->" << endl; 
    cout << "\nLa ruta mas optima para visitar cada colonia es: ";
    executeTravelingSalesman(graphWeight, graphWeight.size());
    printColonies(finalPath, alphabet);
    cout << "\nCon un costo de: " << finalSol << endl;


    //Ejecución del algoritmo de Ford Fulkerson para encontrar el flujo a través de un grafo:
    //Necesitamos saber el flujo de inicio a fin, por lo cual se utilizarán los nodos inicial y final
    //Primer nodo del grafo
    int initialNode = 0;

    //Último nodo del grafo
    int finalNode = numNodes-1;

    cout << "\n<---- Punto no. 3 ---->" << endl; 
    cout << "\nEl flujo maximo de informacion a traves de las colonias " << alphabet[initialNode] << " y " << alphabet[finalNode] << " es: ";
    cout << fordFulkerson(graphFlow, initialNode, finalNode) << endl;

    //Tiempo de ejecución
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;

    cout << "\nTiempo de ejecucion: " << totalTime/std::chrono::milliseconds(1) <<" ms"<<endl;

    return 0;
}
