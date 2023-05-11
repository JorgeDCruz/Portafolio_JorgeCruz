//Proyecto hecho por:
//Fernanda Monserrat Galvan Romero -- A00344712
//Jorge Daniel Cruz Case -- A01634536

//Proyecto Integrador

//Librerias:
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Clases:
#include "Fecha.h"
#include "Producto.h"
#include "Comprador.h"
#include "Pedido.h"
//Creditos de las clases presentes en las mismas


//Funciones:


//Consulta Jorge
bool ReadInt(int &ola){ //Función para la comprobación que a las variables tipo int no se les ingrese una letra o palabra
    cin >> ola;
    bool ok=cin.good();
    if (!ok){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Utilizamos métodos que no sabemos realmente como funcionan ni se nos enseñaron en clase, pero cumplen su proposito
    }
    return ok;
}
//La función te marcará error cuando se ingrese algo que no es un int


//Consulta Jorge
string Validar(string &hola){ //Función para la comprobación que las variables tipo string no se les ingrese un número
    string ola;
    cin>>ola;
    char vl;
        for (int i=0; i<ola.length();i++){
        vl = ola[i];
        if (isalpha(vl)){ //Similar a la función ReadInt, aquí se utilizaron métodos que no sabemos como funcionan pero cumplen su propósito
        }
        else{
            cout << "Caracter invalido" << endl;
            cin>>ola;
        }
    }
    return ola;
}
//La función marcará error cuando se ingrese un número a la variable correspondiente


//Consulta Jorge
void llenarCatalogo(Producto arrCatalogo[], int &cantArt){ //La función llenará el array con los datos proporcionados por el acrhivo de texto incluido con el proyecto
    int IDtech;
    string nombreTech;
    int precioTech;
    cantArt = 0;
    ifstream archivo;
    archivo.open("listaProducto.txt");
    while (archivo >> IDtech >> nombreTech >> precioTech){
        arrCatalogo[cantArt].setID(IDtech);
        arrCatalogo[cantArt].setNomSus(nombreTech);
        arrCatalogo[cantArt].setPrecio(precioTech);
        cantArt++;
    }    
    archivo.close();
} //La función servirá cada vez que necesites ver el catálogo


//Consulta Monse
void muestraCatalogo(Producto listaArt[]) { //La función será la indicada para mostrar el catálogo guardado en la función anterior
    cout << "\n----------------------------------------" << endl;
    cout<< "ID" << "-" <<"Articulo"<< "---" <<"Precio"<<endl;
    cout<<" "<<endl;
    for (int i = 0; i<13; i++){ //Recibirá el objeto tipo Producto con el array establecido anteriormente
        listaArt[i].imprimeCatalogo();
    }
}

//Consulta Monse
void modificarDatos(Comprador &usuario){ //Función para el manejo de los datos proporcionados por el usuario
    string nombre;
    string telefono;
    Ubicacion domicilio1;
    string estado1;
    string ciudad1;
    string calle1;
    int codigo1;
    int num1;
    Pago forma1;
    string tarjeta;
    char opcion;
    do{
        cout<<"\ta- Cambiar nombre: "<<endl; //Opciones disponibles en el menú
        cout<<"\tb- Cambiar telefono: "<<endl;
        cout<<"\tc- Cambiar domicilio: "<<endl;
        cout<<"\td- Cambiar forma de pago: "<<endl;
        cout<<"\te- Salir: \n"<<endl;
        cout << "Ingrese su eleccion: ";
        cin>>opcion; //Está opción no tiene comprobación porque francamente no supimos como comprobar que sea compatible el c in
    switch (opcion)    {
        case 'a':
            cout << "\n----------------------------------------" << endl;
            cout << "Usted eligio cambiar nombre" << endl;
            cout<<"Ingrese nuevo nombre: ";
            nombre = Validar(nombre); //Implementación de la función validar para la comprobación de la variable
            usuario.setNombre(nombre);
            cout << "----------------------------------------" << endl;
            cout<<"Listo "<<nombre <<" los cambios se han guardado"<<endl;
            cout << "\n----------------------------------------\n" << endl;
            break;
        case 'b':
            cout << "\n----------------------------------------" << endl;
            cout << "Usted eligio cambiar no. de telefono" << endl;
            cout<<"Ingrese nuevo telefono: ";
            cin>>telefono;
            usuario.setTelefono(telefono); //Telefono se toma como string por si el usuario decide poner guiónes
            cout << "\n----------------------------------------" << endl;
            cout<<"Listo, tu telefono ahora es  "<<telefono <<", los cambios se han guardado"<<endl;
            cout << "\n----------------------------------------" << endl;
            break;
        case 'c':
            cout << "\n----------------------------------------" << endl;
            cout << "Usted eligio cambiar domicilio" << endl;
            cout<<"Ingrese nuevo domicilio: "<<endl;
            cout << "\n----------------------------------------" << endl;
            cout<<"Ingrese su estado: ";
            estado1 = Validar(estado1); //Implementación de la función validar para la comprobación de la variable
            cout << "\n----------------------------------------" << endl;
            cout<<"Ingrese su ciudad: ";
            ciudad1 = Validar(ciudad1); //Implementación de la función validar para la comprobación de la variable
            cout << "\n----------------------------------------" << endl;
            cout<<"Ingrese su calle: ";
            calle1 = Validar(calle1); //Implementación de la función validar para la comprobación de la variable
            cout << "\n----------------------------------------" << endl;
            cout<<"Ingrese el codigo postal: ";
            while(true){ //Continuación de la función ReadInt para la comprobación de la variable
                if (!ReadInt(codigo1)){ //Es necesario aplicar estos ciclos para comprobar la variable de la manera que la implementamos
                    cout<<"Error"<<endl;
                }
                else{
                    domicilio1.setCP(codigo1);
                    break;
                }}
            cout << "\n----------------------------------------" << endl;
            cout<<"Ingrese el numero de domicilio: ";
                while(true){ //Continuación de la función ReadInt para la comprobación de la variable
                if (!ReadInt(num1)){ //Es necesario aplicar estos ciclos para comprobar la variable de la manera que la implementamos
                    cout<<"Error"<<endl;
                }
                else{
                    domicilio1.setNumero(num1);
                    break;
                }
        }
            //Actualización de los datos con aquellos nuevos
            domicilio1.setEstado(estado1);
            domicilio1.setCiudad(ciudad1);
            domicilio1.setCalle(calle1);
        

            usuario.setDomicilio(domicilio1);
            cout << "\n----------------------------------------" << endl;
            cout << "Listo " << nombre << " los cambios se ha guardado." << endl;
            cout << "----------------------------------------\n" << endl;
            break;
        case 'd':
            cout << "\n----------------------------------------" << endl;
            cout << "Usted eligio cambiar el metodo de pago" << endl;
            cout<<"Ingrese metodo de pago: ";
            cin>>tarjeta;
            while (tarjeta != "Efectivo" && tarjeta != "efectivo" && tarjeta != "Debito" && tarjeta != "debito" && tarjeta != "Credito"&& tarjeta != "credito"){ //Comprobación que el método ingresado sea uno válido
                cout<<"Metodo no valido, ingreselo de nuevo: ";
                cin>>tarjeta;   
                }
            //Actualización de los datos con aquellos nuevos
            forma1.setTipoPago(tarjeta);
            cout << "\n----------------------------------------" << endl;
            cout<<"Listo, tu metodo de pago ahora es  "<<tarjeta <<", los cambios se han guardado"<<endl;
            cout << "----------------------------------------\n" << endl;
            break;
        case 'e':
            cout<<"Datos guaradados" << endl;
            cout << "----------------------------------------\n" << endl;
            break;
        default:
            cout<<"Opcion invalida";
    }
    }while(opcion != 'e');
}
//Consulta Monse
void comprarProductos(Producto arrCatalogo[],Producto listaCompra[], Comprador &usuario, Pago &pago1, Fecha &fecha1,Pedido &pedido1, int &art){ //Función para la compra de los productos
    muestraCatalogo(arrCatalogo); //Muestra el catálogo siempre al elegir esta función, vease las funciones muestra catalogo y llenar catalogo
    cout << "----------------------------------------" << endl;
    cout<<endl;
    cout<<"Cuantos articulos desea comprar: ";
    while(true){ //Continuación de la función ReadInt para la comprobación de la variable
        if (!ReadInt(art)){ 
            cout<<"Error"<<endl;
        }
        else{
            break;
        }}

        while (art <= 0 ){
            cout<< "Numero no valido"<<endl;
            cin>>art;
        }
    cout << "\n----------------------------------------" << endl;  
    cout<<"Seleccione la ID del articulo deseado: ";
    for (int i = 0; i<art;i++){ //Ciclo para la cantidad de artículos seleccionada
        int id;
        while(true){ //Continuación de la función ReadInt para la comprobación de la variable
            if (!ReadInt(id)){
                cout<<"Error"<<endl;
            }
            else{
                break;
            }}
        while (id < 0 || id >= 13){
            cout<< "ID no valida"<<endl;
            cin>>id;
        }
        
        for (int j = 0; j<=13;j++){ //Ciclo para añadir los artículos comprados a un array y que puedan ser utilizados posteriormente
            int idPorduto = arrCatalogo[j].getID();
            if( idPorduto == id){
                listaCompra[i].setPrecio(arrCatalogo[j].getPrecio());
                listaCompra[i].setNomSus(arrCatalogo[j].getNomSus());
                pago1.setTotal(listaCompra[i].getPrecio());
                              
        }        
     }}
     cout << "\n----------------------------------------" << endl;
     cout<<"Gracias por su compra" << endl;
     cout << "----------------------------------------\n" << endl;
     pedido1.setCantidad(art);
     pedido1.setFechaEntrega(fecha1);
     pedido1.setTotal(pago1);
     pedido1.setUsuario(usuario);
    
}
//Consulta Monse
void imprimirTicket(Producto listaCompra[],Pedido &pedido1, int articulos){
    string producto;
    cout << "----------------------------------------\n" << endl;
    cout<<"Usted compro los productos: "<<endl;
    for(int i = 0; i<articulos;i++){
       producto = listaCompra[i].getNomSus();
       cout<<producto<<endl;
    }
    cout<<"Estos han sido asignados a su carrito"<<endl;
    pedido1.imprimeTicket();
}
//Consulta Jorge
void confirmarEnvio(Comprador &_usuario, Fecha _date, Producto listaCompras[], int articulos, Pedido pedido){ //Función para acceder a la fecha estimada para la llegada de los productos
    string producto;
    int mes1 = _date.getMes();
    if(mes1==12){ //Asigna un mes más al mes indicado al principio
        _date.setMes(1);
        _date.setYear(_date.getYear() + 1);//Le suma uno al año si el mes es más de 12
    }
    else{
        _date.setMes(mes1+1); //Regresa la misma fecha proporcionada por el usuario
    }
    imprimirTicket(listaCompras, pedido, articulos);;
    cout<<"Llegaran el dia: "<<endl;
    _date.imprime();
    cout<< "Al domicilio: "<<endl;
    pedido.getUsuario().getDomicilio().imprime();
    cout<<"Gracias por confiar en nosotros "<<pedido.getUsuario().getNombre();

}


int main(){
    int articulostotal;
    Producto arrCatalogo[20], listaCompras[50];
    Pedido pedido;
    Pago Tarjeta;
    string nombre;
    string telefono;
    string estado1;
    string ciudad1;
    string calle1;
    int codigo1;
    int num1;
    string tarjeta;
    int dia;
    int mes;
    int year;
    int art;
    //Función para llenar el catálogo con las variables que serán utilizadas
    llenarCatalogo(arrCatalogo, articulostotal);
    cout << "-------------------------------------------------" << endl;
    cout<<"-----Bienvenido a la plaza de la tecnologia-----"<<endl;
    cout << "-------------------------------------------------" << endl;
    cout<<"Porfavor, ingrese su nombre: ";
    nombre = Validar(nombre); //Función para la validación del nombre, utilizando la función validar
    cout << "\n----------------------------------------" << endl;
    cout<<"Ingrese su no. de telefono: ";
    cin>>telefono;
    cout << "\n----------------------------------------" << endl;
    cout<<"Ingrese su estado: ";
    estado1 = Validar(estado1); //Función para la validación del nombre, utilizando la función validar
    cout << "\n----------------------------------------" << endl;
    cout<<"Ingrese el nombre de su ciudad: ";
    ciudad1 = Validar(ciudad1); //Función para la validación del nombre, utilizando la función validar
    cout << "\n----------------------------------------" << endl;
    cout<<"Ingrese el nombre de su calle: ";
    calle1 = Validar(calle1); //Función para la validación del nombre, utilizando la función validar
    cout << "\n----------------------------------------" << endl;
    //Implementación de la función ReadInt para la validación de la variable con la variable que será utilizada
    cout<<"Ingrese el codigo postal: "<<endl;
     while(true){
        if (!ReadInt(codigo1)){
            cout<<"Codigo postal invalido, ingreselo de nuevo: "<<endl;
        }
        else{
            break;
        }
    }
    while (codigo1 <= 0 ){
            cout<< "Codigo postal invalido, ingreselo de nuevo: ";
            cin>>codigo1;
        }
    //Implementación de la función ReadInt para la validación de la variable con la variable que será utilizada
    cout << "\n----------------------------------------" << endl;
    cout<<"Ingrese el numero de domicilio: "<<endl;
    while(true){
        if (!ReadInt(num1)){
            cout<<"Numero invalido, ingreselo de nuevo: ";
        }
        else{
            break;
        }
    }
    while (num1 <= 0 ){
            cout<< "Numero no valido "<<endl;
            cin>>num1;
        }
    
    Ubicacion ubi (estado1,ciudad1,calle1, codigo1,num1);
    cout << "\n----------------------------------------" << endl;
    cout << "Metodos de pago disponibles: \n\t1.- Efectivo \n\t2.- Debito \n\t3.- Credio" << endl;
    cout<<"Ingrese metodo de pago: ";
    cin>>tarjeta;

    while (tarjeta != "Efectivo" && tarjeta != "efectivo" && tarjeta != "Debito" && tarjeta != "debito" && tarjeta != "Credito"&& tarjeta != "credito"){
        cout<<"Metodo no valido"<<endl;
        cin>>tarjeta;
    }
    //Implementación de funciones
    Tarjeta.setTipoPago(tarjeta);
    cout << "\n----------------------------------------" << endl;
    cout<<"Ingrese la fecha de hoy: "<<endl;
    //Implementación de la función ReadInt para la validación de la variable con la variable que será utilizada
    //Esta se repetira con las 3 variables
    while(true){
        if (!ReadInt(dia)){
            cout<<"Dia invalido, ingreselo de nuevo: ";
        }
        else{
            break;
        }
    }
    while(true){
        if (!ReadInt(mes)){
            cout<<"Mes invalido, ingreselo de nuevo: "<<endl;
        }
        else{
            break;
        }
    }
    while(true){
        if (!ReadInt(year)){
            cout<<"Año invalido, ingreselo de nuevo: "<<endl;
        }
        else{
            break;
        }
    }
    while (dia>31 || mes>13 or (dia>29 && mes ==2) ||  ((mes%2 == 0 || mes == 6 ) && dia >30)){ //Validación para que el usuario no ingrese una fecha que no existe
        cout<<"FECHA INCORRECTA"<<endl;
        cin>>dia>>mes>>year;
    }
    Fecha Date(dia,mes,year);
    cout << "\n----------------------------------------" << endl;
    int opcion;
    Comprador Yo(nombre, telefono, ubi, Tarjeta); //Objeto que serivirá como usuario y tendrá todos los datos pertinentes
    //Implementación del menú principal
    do
    {   
        cout << "\n----------------------------------------" << endl;
        cout << "Hola " << nombre << endl;
        cout << "----------------------------------------" << endl;
        cout<<"Opciones disponibles:\n"<<endl;
        cout<<"\t1  Modificar datos del usuario: "<<endl;
        cout<<"\t2  Ver el catalogo: "<<endl;
        cout<<"\t3  Comprar productos: "<<endl;
        cout<<"\t4  Revisar los datos del usuario: "<<endl;
        cout<<"\t5  Imprimir ticket: "<<endl;
        cout<<"\t6  Revisar envio: "<<endl;
        cout<<"\t7  Salir: "<<endl;
        cout << "----------------------------------------" << endl;
        cout << "Ingrese una eleccion: ";
        while(true){ //Validación de la variable a través del método ReadInt
            if (!ReadInt(opcion)){
                cout<<"Caracter invalido, ingreselo de nuevo: ";
            }
            else{
                break;
            }
    }
    while (opcion <= 0 || opcion>8){ //Validación que el usuario no ingrese un número negativo o mayor a 7
            cout<< "Opcion invalida, ingresela de nuevo: ";
            cin>>opcion;
        }
        switch (opcion)
        {
        case 1:
            modificarDatos(Yo);//Función para modificar los datos
            break;
        case 2:
            cout << "Usted eligio mostrar el catalogo" << endl;
            cout << "\n----------------------------------------" << endl;
            cout << "Catalogo disponible:" << endl;
            muestraCatalogo(arrCatalogo); //Función para el acceso del catalogo de los productos
            break;
        case 3:
            comprarProductos(arrCatalogo,listaCompras, Yo, Tarjeta, Date, pedido, art); //Función para comprar con los objetos pertinentes
            break;
        case 4:
            cout << "Usted eligio revisar los datos del usuario " << endl;
            Yo.imprimeUsuario(); //Despliege de los datos actuales del usuario
            break;
        case 5:
            imprimirTicket(listaCompras, pedido,art); //Despliege de la información de la compra del usuario
            break;
        case 6:
            confirmarEnvio( Yo, Date,listaCompras, art, pedido); //Despliega los datos del envio de los productos
            break;
        case 7:
            cout<<"Gracias por visitar nuestra tienda";
            break;
        default:
            cout<<"Opcion no valida";
        }

    } while (opcion != 7);
return 0;
}
