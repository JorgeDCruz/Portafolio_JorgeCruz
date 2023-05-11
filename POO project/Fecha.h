//Clase hecha por Jorge Daniel Cruz Case

#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;
//Clase para el manejo de las fechas
class Fecha{
    public:
        //Constructores
        Fecha(); //Default
        Fecha(int, int, int); //Con parámetros
        //Getters
        int getMes() const;
        int getDia() const;
        int getYear() const;
        //Setters
        void setMes(int);
        void setYear(int);
        void setDia(int);
        //Imprime
        void imprime();
    private:
        //Atributos
        int dia, mes, year;
};

//Constructores
Fecha::Fecha(){
    dia=1;
    mes=1;
    year=2020;
}

//Constructor con parámetros
Fecha::Fecha(int _dia, int _mes, int _year){
    dia = _dia;
    mes = _mes;
    year = _year;
}

//Setters implementados
void Fecha::setMes(int _mes){
    mes = _mes;
    if (mes>12){
        mes=1;
    }
}

void Fecha::setDia(int _dia){
    dia = _dia;
    if (dia>31){
        dia = 1;
    }
}

void Fecha::setYear(int _year){
    year=_year;
}
//Método imprime
void Fecha::imprime(){
    cout << dia << "/"<< mes << "/"<< year << endl;
}
//Getters implementados
int Fecha::getMes() const{
    return mes;
}

int Fecha::getDia() const{
    return dia;
}

int Fecha::getYear() const{
    return year;
}
#endif //FECHA_H