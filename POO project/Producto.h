//Clase hecha por Jorge Daniel Cruz Case
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
using namespace std;

//Clase para el manejo de los productos
class Producto{
    public:
        //Métodos
        Producto(); //Constructor por default
        Producto(int, string, int); //Constructor con parámetros
        //Setters
        void setID(int);
        void setNomSus(string);
        void setPrecio(int);
        //Getters
        int getID() const;
        string getNomSus() const;
        int getPrecio() const;
        //Imprime 
        void imprimeCatalogo();
    private:
        //Atribtuos
        int idComida;
        int precio;
        string nombreSus;
};

//Constructor por default
Producto::Producto(){
    idComida = 0;
    precio = 0;
    nombreSus="-";
}

//Constructor con parámetros
Producto::Producto(int _idCom, string _nombreSus, int _precio){
    idComida=_idCom;
    nombreSus=_nombreSus;
    precio = _precio;
}
//Setters
void Producto::setID(int _idCom){
    idComida=_idCom;
}

void Producto::setPrecio(int _precio){
    precio=_precio;
}

void Producto::setNomSus(string _nombreSus){
    nombreSus = _nombreSus;
}

//Getters
int Producto::getID() const{
    return idComida;
}

string Producto::getNomSus() const{
    return nombreSus;
}

int Producto::getPrecio() const{
    return precio;
}

//Método imprime
void Producto::imprimeCatalogo(){
    
    cout << idComida << "--" << nombreSus << "--" << "$" <<precio << endl;
}
#endif //PRODUCTO_H