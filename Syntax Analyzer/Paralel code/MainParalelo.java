/*
Los comentarios de como hice el programa se encuentran en el otro main "MainSecuencial"

Al tratar de hacer el paralelismo me di cuenta que iba a ser complicado que el resultado esté en un solo archivo resultante, esto debido a que cada hilo
trabaja a destiempo de los demas, así que la escritura al archivo iba a estar desordenada.
Para evitar problemas y aprovechando que las instrucciones no lo especificaba, decidí que cada instancia del resaltamiento de un archivo cree un resultado
individualmente.

*/ 
package Tarea5_3;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.io.FileWriter;
import java.io.File;

//Clase que ejecutara cada hilo
class ResaltadorParalelo implements Runnable{
    private String nombArchread;
    private String nombArchWrite;

    //Constructor con parametros
    public ResaltadorParalelo(String archRead, String archWrite){
        this.nombArchWrite = archWrite;
        this.nombArchread = archRead;
    }

    //Runnable
    public void run(){
        try {
            System.out.println("La Thread " + Thread.currentThread().getId() + " esta trabajando");
            generarLexer(nombArchread, nombArchWrite);
        } catch (IOException e){
            e.printStackTrace();
        }
    }

    //Generacion del lexer de la misma manera que en el archivo secuencial
    public static void generarLexer(String nombArchread, String nombArchWrite) throws IOException{
        //Creamos el archivo
        try {
            File myObj = new File(nombArchWrite);
            if (myObj.createNewFile()) {
                System.out.println("\nSe creo el archivo:  " + myObj.getName());
            } 
            else {
                System.out.println("\nNo se pudo crear el archivo: " + nombArchWrite + " porque ya existe");
            }
        }
        //Si explota sale esto
        catch (IOException e) {
            System.out.println("Ocurrio un error inesperado");
            e.printStackTrace();
        }
        try {
            FileWriter myWriter = new FileWriter(nombArchWrite);
            System.out.println("\nSe escribio en el archivo: " + nombArchWrite);
            try{
                Reader lector = new BufferedReader(new FileReader(nombArchread));
                Lexer lexer = new Lexer(lector);

                //Contenido inicial del archivo html
                myWriter.write("<!DOCTYPE HTML>");
                myWriter.write("\n<html>");
                myWriter.write("\n<head>");
                myWriter.write("\n\t<title>Resaltador de sintaxis secuencial</title>");
                myWriter.write("\n</head>");
                myWriter.write("\n\n<body>");
                myWriter.write("\n\n<h1>Resaltador de sintaxis del archivo: " + nombArchread + "</h1>");
                myWriter.write("\n<p>Colores por familia:</p>");

                //Colores por familia
                myWriter.write("\n<mark style=\"background: #DBDDF0!important\"> Delimitadores </mark>" );
                myWriter.write("\n<mark style=\"background: #86A2EA!important\"> Numeros enteros </mark>" );
                myWriter.write("\n<mark style=\"background: #C7FF33!important\"> Numeros flotantes </mark>" );
                myWriter.write("\n<mark style=\"background: #B8F398!important\"> Comentarios </mark>" );
                myWriter.write("\n<mark style=\"background: #83F31A!important\"> Strings </mark>" );
                myWriter.write("\n<mark style=\"background: #6EB4C8!important\"> Operadores aritmeticos </mark>" );
                myWriter.write("\n<mark style=\"background: #A377C8!important\"> Asignacion </mark>" );
                myWriter.write("\n<mark style=\"background: #ECBE83!important\"> Operador booleano </mark>" );
                myWriter.write("\n<mark style=\"background: #D595E1!important\"> Comparadores </mark>" );
                myWriter.write("\n<mark style=\"background: #E08E8E!important\"> Literales </mark>" );
                myWriter.write("\n<mark style=\"background: #EAF31A!important\"> Palabra reservada </mark>" );
                myWriter.write("\n<mark style=\"background: #1AF3E9!important\"> Variable o palabra </mark>" );
                myWriter.write("\n<mark style=\"background: #EB2B25!important\"> Error o caracter no reconocido </mark>" );
                myWriter.write("<p>\nTexto del archivo:</p>");
                while(true){
                    Tokens tokens = lexer.yylex();
                    if(tokens == null){
                        //Cuando el token sea nulo no se va a interpretar
                        //va a imprimir los atributos finales del html, cerrar el archivo y salirse del while
                        myWriter.write("\n\n<address>29 de mayo del 2022<br> \nPor: Jorge Daniel Cruz - A01634536</address>");
                        myWriter.write("\n</html>");
                        myWriter.close();
                        return;
                    }
                    switch(tokens){
                        case ERROR:
                            myWriter.write("\n<mark style=\"background: #EB2B25!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case Delimitador:
                            myWriter.write("\n<mark style=\"background: #DBDDF0!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case NumeroEntero:
                            myWriter.write("\n<mark style=\"background: #86A2EA!important\">" + lexer.yytext() + "</mark>" );
                            break;
                        case Numerodecimal:
                            myWriter.write("\n<mark style=\"background: #C7FF33!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case Comentario:
                            myWriter.write("\n<mark style=\"background: #B8F398!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case Palabras:
                            myWriter.write("\n<mark style=\"background: #83F31A!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case OperadorAritmetico:
                            myWriter.write("\n<mark style=\"background: #6EB4C8!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case Asignacion:
                            myWriter.write("\n<mark style=\"background: #A377C8!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case OperadorBooleano:
                            myWriter.write("\n<mark style=\"background: #ECBE83!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case Comparador:
                            myWriter.write("\n<mark style=\"background: #D595E1!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case Literal:
                            myWriter.write("\n<mark style=\"background: #E08E8E!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case Reservadas:
                            myWriter.write("\n<mark style=\"background: #EAF31A!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case Variable:
                            myWriter.write("\n<mark style=\"background: #1AF3E9!important\">" + lexer.yytext() + "</mark>");
                            break;
                        case Parrafo:
                            myWriter.write("<p>\n</p>");
                            break;
                        case Espacio:
                            myWriter.write(" ");
                            break;
                        default:
                            myWriter.write("\n<mark style=\"background: #EB2B25!important\">" + lexer.yytext() + "</mark>");
                            break;
                    }
                } 
            }
            catch(FileNotFoundException ex){
                System.out.println("No se encontro el archivo, tal vez te equivocaste de path o de nombre");
            }
        } 
        catch (IOException e) {
            System.out.println("Ocurrio un error inesperado");
            e.printStackTrace();
        }
    }
}

public class MainParalelo {
    public static void main(String[] args) throws IOException {
        long startTime = System.currentTimeMillis();

        //El numero de archivos en este caso es de 3
        int numArchivos = 3;
        //Debido a que cada hilo se encargara de 1 archivo, la cantidad de hilos es igual a la de los archivos
        int num_threads = numArchivos;

        System.out.println("\nSe iniciaron " + num_threads + " threads\n");

        Thread[] myThreads = new Thread[num_threads];
        ResaltadorParalelo[] misArchivos = new ResaltadorParalelo[num_threads];

        //El programa permite que le pongas el nombre del archivo a leer o la dirección del mismo
        //Ej: C:/Users/afron/OneDrive/Documentos/Programación/Tec/Metodos computacionales/tareaSecuencial/Act5_3/input.txt
        String[] misArchivosLeer = {"input.txt", "input2.txt", "input3.txt"}; 

        String archivoescribir = "resultadoParalelo";

        for(int i = 0; i<num_threads; i++){
            archivoescribir+= i+1 + ".html";
            misArchivos[i] = new ResaltadorParalelo(misArchivosLeer[i], archivoescribir);
            myThreads[i] = new Thread(misArchivos[i]);
            myThreads[i].start();
            archivoescribir = "resultadoParalelo";
        }
        for (int i = 0; i < num_threads; i++) {
            try{
                myThreads[i].join();
            }
            catch(InterruptedException a ){
                System.out.println("Got interrupted");
            }
            
        }
        long endTime = System.currentTimeMillis();
        long totalTime = (endTime - startTime);
        System.out.println("\nEl tiempo total de ejecucion fue " + totalTime + " ms");
    }
}
