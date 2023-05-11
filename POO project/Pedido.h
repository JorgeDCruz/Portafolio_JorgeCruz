//Clase hecha por Jorge Daniel Cruz Case
#ifndef PEDIDO_H
#define PEDIDO_H
using namespace std;
#include "Producto.h"
#include "Fecha.h"
#include "Pago.h"

class Pedido{
    //Métodos
    public:
        Pedido(); //Constructor por default
        Pedido( Fecha, int, Pago, Comprador); //Constructor por parámetros
        //setters
        void setFechaEntrega(Fecha);
        void setCantidad(int);
        void setTotal(Pago);
        void setUsuario(Comprador);
        //Getters
        Fecha getFechaEntrega() const;
        int getCantidad() const;
        Pago getTotal() const;
        Comprador getUsuario() const;
        //Imprime
        void imprimeTicket();
        int hacerPedidos();
    private:
        //Atributos
        Fecha fechaEntrega;
        int cantidad;
        Pago total;
        Comprador usuario;
};
//Constructor por default
Pedido::Pedido(){
    cantidad=0;
}
//Constructor con parámetros
Pedido::Pedido( Fecha _fechaEntrega,  int _cant,  Pago _total, Comprador _usuario ){
    fechaEntrega = _fechaEntrega;
    cantidad = _cant;
    total = _total;
    usuario = _usuario;
}

//Setters
void Pedido::setFechaEntrega(Fecha _fechaEntrega){
    fechaEntrega = _fechaEntrega;
}

void Pedido::setCantidad(int _cant){
    cantidad = _cant;
}


void Pedido::setTotal(Pago _total){
    total = _total;
}

void Pedido::setUsuario(Comprador _usuario){
    usuario = _usuario;
}

//Getters
Fecha Pedido::getFechaEntrega() const{
    return fechaEntrega;
}

int Pedido::getCantidad() const{
    return cantidad;
}

Pago Pedido::getTotal() const{
    return total;
}

Comprador Pedido:: getUsuario() const{
    return usuario;
}

//Método imprime
void Pedido::imprimeTicket(){
    cout << "\n----------------------------------------" << endl;
    cout << "Total a productos de productos del carrito de " << usuario.getNombre() << ": "<< cantidad << endl;
    cout << "El precio total es: " << total.getTotal();
    cout << "" << endl;
    cout << "\n----------------------------------------" << endl;
    cout << "La fecha de envio es: ";
    fechaEntrega.imprime();
    cout << "----------------------------------------\n" << endl;
}

#endif //PEDIDO_H