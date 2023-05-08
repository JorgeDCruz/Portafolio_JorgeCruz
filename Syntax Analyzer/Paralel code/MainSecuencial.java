/*
Tutorial para la instalación de JFLEX (igonre las instrucciones para instalar CUP, no se la verdad que es eso):
https://www.youtube.com/watch?v=0lphu1CAsPw
https://www.skenz.it/compilers/install_windows

Ejecución:
El código funciona en una libreria llamada "JFLEX", la cual es similar a Flex pero para java.
Para que funcione el código hay 2 cosas que se pueden hacer:

1.- Instalar JFLEX con el tutorial que está arriba, solamente hay que ignorar lo que dice de CUP, correr en la terminal el comando "jflex"
va a resultar en un menú llamado "Jflex 1.8.2", en el cual debes de elegir el archivo .flex o .jflex que se quiere convertir, después hacer click en generar
Esto va a generar un archivo .java, de la misma manera que compilar flex haría un .C
También puedes ejecutar el comando "jflex archivo.flex" y llegas al mismo resultado

2.- Puedes añadir el archivo .Jar llamado JFLEX.jar que descargas de aqui:
https://mega.nz/file/kp5wmSTR#VRGITdbm5zuSWDMeZ8hVgVYWCNl-J0gMcAqQ2k8FBfM
Este lo añades a las librerias referenciadas en el apartado de JAVA PROJECTS -> Referenced Libraries -> Símbolo de "+" -> Elegir el .jar descargado
Esto permitirá que se genere el .java del .flex sin necesidad de instalar jflex 1.8.2

Yo recomiendo instalar jflex1.8.2, generar el archivo mediante el comando o ejecutable y luego correr el proyecto.

-->El archivo dará error si no encuentra el .java generado por jflex, este se quitara una vez que lo encuentre<---

El proyecto se encuentra enpaquetado, no logre que funcionara si no estaban los archivos principales dentro del paquete
El archivo de texto que va a leer debe de estar fuera del paquete

Está bien raro java, batalle un poco para poder empaquetar los archivos. Si no funcionan tal como están puede tratar de cambiar el paquete
o también visual estudio tiene un "Quick fix" que te crea un paquete, ya solo es mandar los otros archivos ahí.

Modifique como se hacía el resaltado desde como era antes en la act 3.4
La función que ejecuta el Lexer recibe 2 cosas:
1.- Nombre del archivo a leer 
2.- Nombre del archivo resultante
De esta manera es posible resaltar varios archivos.

No sabía si el resultado del resaltamiento de los archivos debía de estar en un solo archivo resultante, las instrucciones no lo especificaban, asi que para
ahorrarme problemas con el paralelismo decidí que cada archivo a resaltar genere un archivo individual.
*/ 
package Tarea5_3;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.io.FileWriter;
import java.io.File;


public class MainSecuencial {
    public static void main(String[] args) throws IOException {
        long startTime = System.currentTimeMillis();
        //Codigo de C
        String archivoLeer = "C:/Users/afron/OneDrive/Documentos/Programación/Tec/Metodos computacionales/tareaSecuencial/Act5_3/input.txt";
        String archivoEsc = "resultado.html";
        generarLexer(archivoLeer, archivoEsc);

        //Codigo de Matlab
        archivoLeer = "input2.txt";
        archivoEsc = "resultado2.html";
        generarLexer(archivoLeer, archivoEsc);

        //Codigo de python
        archivoLeer = "input3.txt";
        archivoEsc = "resultado3.html";
        generarLexer(archivoLeer, archivoEsc);

        long endTime = System.currentTimeMillis();
        long totalTime = (endTime - startTime);
        System.out.println("\nEl tiempo total de ejecucion fue " + totalTime + " ms");
        
    }

    //Función para la ejecución del Lexer creado con jflex
    public static void generarLexer(String nombArchRead, String nombArchWrite) throws IOException{
        //Creamos el archivo
        try {
            File myObj = new File(nombArchWrite);
            if (myObj.createNewFile()) {
                System.out.println("\nSe creo el archivo:  " + myObj.getName());
            } 
            else {
                System.out.println("\nNo se pudo crear el archivo: " + nombArchWrite);
            }
        }

        //La verdad no se cuando podria salir este error, pero VS code se enoja si no lo incluyo
        catch (IOException e) {
            System.out.println("Ocurrio un error inesperado");
            e.printStackTrace();
        }
        try {
            //Se escribiran los tokens en el archivo que haya especificado el programa
            FileWriter myWriter = new FileWriter(nombArchWrite);
            System.out.println("Se escribio en el archivo: " + nombArchWrite);

            //Se intentara escribir en el archivo, pero si por alguna razon no se puede regresara una excepcion y su mensaje de error
            try{
                //Segun los tutoriales que vi, esta es la mejor manera de que el Lexer lea el archivo que le pasas
                Reader lector = new BufferedReader(new FileReader(nombArchRead));
                Lexer lexer = new Lexer(lector);

                //Contenido inicial del archivo html
                myWriter.write("<!DOCTYPE HTML>");
                myWriter.write("\n<html>");
                myWriter.write("\n<head>");
                myWriter.write("\n\t<title>Resaltador de sintaxis secuencial</title>");
                myWriter.write("\n</head>");
                myWriter.write("\n\n<body>");
                myWriter.write("\n\n<h1>Resaltador de sintaxis del archivo: " + nombArchRead + "</h1>");
                myWriter.write("\n<p>Colores por familia:</p>");

                //Colores por familia
                //Para identificar el color en hexadecimal puede usar: https://htmlcolorcodes.com/es/
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

                //Se leeran e interpretaran los tokens del Lexer mientras no sean iguales a null
                while(true){
                    Tokens tokens = lexer.yylex();
                    if(tokens == null){
                        //Final del archivo
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
                        //Para que pueda identificar los parrafos y no salga todo pegado
                        case Parrafo:
                            myWriter.write("<p>\n</p>");
                            break;
                        //Intente que identificara los espacios pero no hace nada :(
                        case Espacio:
                            myWriter.write(" ");
                            break;
                        default:
                        //Si no se toma como ninguno de los tokens establecidos se resaltara como un ERROR
                            myWriter.write("\n<mark style=\"background: #EB2B25!important\">" + lexer.yytext() + "</mark>");
                            break;
                    }
                } 
            }
            //Añadi las exepciones en todos lados porque si no se enoja VS code
            catch(FileNotFoundException ex){
                System.out.println("No se encontro el archivo");
            }
        } 
        //Si explota el archivo no se va a escribir nada, ya que no se encontro 
        catch (IOException e) {
            System.out.println("Ocurrio un error inesperado");
            e.printStackTrace();
        }
    }
}
