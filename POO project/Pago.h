//Hecho por Monse Galván
#ifndef PAGO_H
#define PAGO_H
#include <iostream>
using namespace std;

//Clase para el manejo del pago
class Pago{
    public:
        //Métodos
        Pago();//Constructor por default
        Pago(string, float); //Constructor con parámetros
        //Getters
        string getTipoPago() const;
        float getTotal() const;
        //Setters
        void setTipoPago(string);
        void setTotal(float);
    private:
        //Atributos
        string tipoPago;
        float total;

};
//Constructor por default
Pago:: Pago(){
    tipoPago = "";
    total = 0;
}
//Constructor con parámetros
Pago::Pago(string _pago,float _total){
    tipoPago = _pago;
    total = _total;
}
//Getters
string Pago:: getTipoPago() const{
    return tipoPago;
}

float Pago:: getTotal() const{
    return total;
}

//Setters
void Pago:: setTipoPago(string _pago){
    //Asignación del tipo de pago
    if (_pago.compare("Tarjeta")){
        tipoPago = "Tarjeta";
    }
    else if (_pago.compare("Efectivo")){
        tipoPago = "Efectivo";
    }
    else{
        tipoPago = "No valido";
    }
}

//Asignación del total
void Pago:: setTotal(float  _total){
    total += _total;
}

#endif //PAGO_H