//Hecho por Monse Galván
#ifndef COMPRADOR_H
#define COMPRADOR_H
#include <string>
#include <iostream>
#include "Ubicacion.h"
#include "Pago.h"
using namespace std;

//Clase para guardar los datos del usuario
class Comprador{
    //Métodos
    public:
        Comprador();//Constructor pro default
        Comprador(string,string, Ubicacion, Pago); //Constructor con parámetros
        //Getters
        string getNombre() const;
        string getTelefono() const;
        Ubicacion getDomicilio() const;
        Pago getFormaPago() const;
        //Setters
        void setNombre(string);
        void setTelefono(string);
        void setDomicilio(Ubicacion);
        void setFormaPago(Pago);
        //Método imprime
        void imprimeUsuario();
    private:
        //Atributos
        string nombre;
        string telefono;
        Ubicacion domicilio;
        Pago formaPago;
};

//Constructor por default
Comprador::Comprador(){
    nombre = "";
    telefono = "";
}

//Constructor con parámetros
Comprador::Comprador(string _nombre,string _telefono,Ubicacion _domicilio,Pago _formaPago){
    nombre = _nombre;
    telefono = _telefono;
    domicilio = _domicilio;
    formaPago = _formaPago;
}

//Getters
string Comprador:: getNombre() const{
    return nombre;
}

string Comprador:: getTelefono() const{
    return telefono;
}

Ubicacion Comprador:: getDomicilio() const{
    return domicilio;
}

Pago Comprador:: getFormaPago() const{
    return formaPago;
}

//Setters
void Comprador:: setNombre( string _nombre){
    nombre = _nombre;
}

void Comprador:: setTelefono(string _telefono){
    telefono = _telefono;
}

void Comprador:: setDomicilio( Ubicacion _domicilio){
    domicilio = _domicilio;
}

void Comprador::setFormaPago( Pago _formaPago ){
    formaPago = _formaPago;
}

//Método imprime
void Comprador:: imprimeUsuario(){
    cout << "\n----------------------------------------" << endl;
    cout<< "Nombre: " << nombre<<endl;
    cout << "\n----------------------------------------" << endl;
    cout<< "Telefono: " << telefono<<endl;
    cout << "\n----------------------------------------" << endl;
    cout<< "Domicilio: "<<endl;
    cout << "\n----------------------------------------" << endl;
    domicilio.imprime();
    cout << "\n----------------------------------------" << endl;
    cout<< "Forma de Pago: " << formaPago.getTipoPago()<<endl;
    cout << "\n----------------------------------------" << endl;

}

#endif //COMPRADOR_H