//Hecho por Monse Galván
#ifndef UBICACION_H
#define UBICAION_H
#include <string>
#include <iostream>
using namespace std;

//Clase para el manejo de la ubicación
class Ubicacion{
    public:
        //Métodos
        Ubicacion (); //Constructor por default
        Ubicacion (string, string, string, int,int); //Constructor con parámetros
        //Getters
        string getEstado() const;
        string getCiudad() const;
        string getCalle() const;
        int getCP() const;
        int getNumero() const;
        //Setters
        void setEstado(string);
        void setCiudad(string);
        void setCalle(string);
        void setCP(int);
        void setNumero(int);
        void imprime();

    private:
        //Atributos
        string estado;
        string ciudad;
        string calle;
        int codigop;
        int numero;
};

//Constructor por default
Ubicacion::Ubicacion(){
    estado = "";
    ciudad = "";
    calle = "";
    codigop = 0;
    numero = 0;
}

//Constructor con parámetros
Ubicacion::Ubicacion(string _estado,string _ciudad,string _calle,int _CP, int _num){
    estado = _estado;
    ciudad = _ciudad;
    calle = _calle;
    codigop = _CP;
    numero = _num;
}

//Getters
string Ubicacion:: getEstado() const{
    return estado;
}

string Ubicacion:: getCiudad() const{
    return ciudad;
}

string Ubicacion:: getCalle() const{
    return calle;
}

int Ubicacion:: getCP() const{
    return codigop;
}

int Ubicacion:: getNumero() const{
    return numero;
}

//Setters
void Ubicacion:: setEstado(string _estado){
    estado = _estado;
}

void Ubicacion:: setCiudad(string _ciudad){
    ciudad = _ciudad;
}

void Ubicacion:: setCalle(string _calle){
    calle = _calle;
}

void Ubicacion:: setCP(int _CP){
    codigop = _CP;
}

void Ubicacion:: setNumero(int _num){
    numero = _num;
}

//Función imprime
void Ubicacion:: imprime(){
    cout<< "Estado: "<< estado << endl;
    cout<< "Ciudad: "<< ciudad << endl;
    cout<< "Calle: "<< calle << endl;
    cout<< "Codigo Postal: "<< codigop<< endl;
    cout<< "Numero: "<< numero << endl;

}
#endif //UBICACION_H