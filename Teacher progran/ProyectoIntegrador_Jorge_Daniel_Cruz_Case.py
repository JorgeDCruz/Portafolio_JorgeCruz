"""
Jorge Daniel Cruz Case - A01634536 
José Miguel Martín - A01639791 
Natalia García Pérez - A01632993
"""

"""
Sección de matemáticas
Autor: Jorge Daniel Cruz Case - A01634536
"""

"""
Porfavor asegurese de guardar el proyecto en una carpeta Thonny
El archivo .csv se generará automáticamente en su caréta Thonny y se llamará formulas
"""
from random import *
#Libreria random para la generación de los datos en los problemas
import math
#Libreria math para los problemas en el nivel matemático 2

#Función para las sumas
def suma():
    print("\nNivel 1")
    print("\nObten 5 preguntas bien y subirás al nivel 2")
    cont=0
    preguntas = 5
    #Primer nivel
    for i in range(5):
        a=randint(1, 9)
        b=randint(1, 9)
        respuesta=int(input(f"{a} + {b} = "))
        if respuesta== a+b:
            cont+=1
            print("\nCorrecto!!!")
            print(f"Preguntas correctas {cont}\n")
        else:
            print("\nRespuesta incorrecta :c, no te desanimes")
            print(f"\nLa respuesta correcta era {a+b}")
            print(f"\nPreguntas correctas {cont}\n")
        
        if cont==5:
            #Segundo nivel
            preguntas = 10
            print("\n¡Llegaste al nivel 2!")
            for i in range(5):
                a=randint(10, 99)
                b=randint(10, 99)
                respuesta=int(input(f"{a} + {b} = "))
                if respuesta == a+b:
                    print("Correcto!!!")
                    cont+=1
                else:
                    print("Respuesta incorrecta :c, no te desanimes")
                    print(f"\nLa respuesta correcta era {a+b}")

    print(f"\nObtuviste {cont} bien!\n")
    if cont<5:
        print("¡Animo no te desanimes!")
    elif cont<10:
        print("¡Ya casi estas del otro lado!")
    else:
        print("Eres un maestro de las matemáticas")
        
    return cont, preguntas

#Función para las restas
def resta():
    print("\nNivel 1")
    print("\nObten 5 preguntas bien y subirás al nivel 2")
    preguntas=0
    cont=0
    for i in range(5):
        #Primer nivel 
        a=randint(1, 9)
        b=randint(1, 9)
        preguntas=5
        respuesta=int(input(f"{a} - {b} = "))
        if respuesta== a-b:
            cont+=1
            print("Correcto!!!")
            print(f"Preguntas correctas {cont}\n")
        else:
            print("\nRespuesta incorrecta :c, no te desanimes")
            print(f"\nLa respuesta correcta era {a-b}")
            print(f"Preguntas correctas {cont}\n")
        if cont==5:
            #Segundo nivel
            preguntas=10
            print("\n¡Llegaste al nivel 2!")
            for i in range(5):
                a=randint(10, 99)
                b=randint(10, 99)
                respuesta=int(input(f"{a} - {b} = "))
                if respuesta == a-b:
                    print("Correcto!!!")
                    cont+=1
                else:
                    print("\nRespuesta incorrecta :c, no te desanimes")
                    print(f"\nLa respuesta correcta era {a-b}")
                    
    print(f"Obtuviste {cont} bien!")
    if cont<5:
        print("¡Animo no te desanimes!")
    elif cont<10:
        print("¡Ya casi estas del otro lado!")
    else:
        print("Eres un maestro de las matemáticas")
    return cont, preguntas

#Funcion para las multiplicaciones
def multiplicacion():
    print("\nNivel 1")
    print("Obten 5 preguntas bien y subirás al nivel 2")
    cont=0
    preguntas=0
    for i in range(5):
        #Nivel 1
        a=randint(1, 9)
        b=randint(1, 9)
        respuesta=int(input(f"{a} x {b} = "))
        preguntas=5
        if respuesta== a*b:
            cont+=1
            print("Correcto!!!")
            print(f"Preguntas correctas {cont}\n")
        else:
            print("Respuesta incorrecta :c, no te desanimes")
            print(f"\nLa respuesta correcta era {a*b}")
            print(f"Preguntas correctas {cont}\n")
        
        if cont==5:
            #Nivel 2
            print("\n¡Llegaste al nivel 2!")
            preguntas=10
            for i in range(5):
                a=randint(10, 99)
                b=randint(10, 99)
                respuesta=int(input(f"{a} x {b} = "))
                if respuesta == a*b:
                    print("Correcto!!!")
                    cont+=1
                else:
                    print("Respuesta incorrecta :c, no te desanimes")
                    print(f"\nLa respuesta correcta era {a*b}")
    print(f"Obtuviste {cont} bien!")
    if cont<5:
        print("¡Animo no te desanimes!")
    elif cont<10:
        print("¡Ya casi estas del otro lado!")
    else:
        print("Eres un maestro de las matemáticas")
    return cont, preguntas

#Función para las divisiones
#Juego puede llegar a ser un poco complicado para un niño promedio
def division():
    print("\nNivel 1")
    print("Obten 5 preguntas bien y subirás al nivel 2")
    print("\n Redondea tu respuesta a máximo 2 decimales")
    cont=0
    preguntas=0
    for i in range(5):
        #Nivel 1
        a=randint(1, 9)
        b=randint(1, 9)
        respuesta=float(input(f"{a} / {b} = "))
        llave=round(a/b, 2)
        preguntas=5
        if respuesta== llave:
            cont+=1
            print("Correcto!!!")
            print(f"Preguntas correctas {cont}\n")
        else:
            print("\nRespuesta incorrecta :c, no te desanimes")
            print(f"Preguntas correctas {cont}\n")
        if cont==5:
            #Nivel 2
            print("\n¡Llegaste al nivel 2!")
            preguntas=10
            for i in range(5):
                a=randint(10, 99)
                b=randint(10, 99)
                respuesta=float(input(f"{a} / {b} = "))
                llave=round(a/b, 2)
                if respuesta == llave:
                    print("Correcto!!!")
                    cont+=1
                else:
                    print("Respuesta incorrecta :c, no te desanimes")
    print(f"Obtuviste {cont} bien!")
    if cont<5:
        print("¡Animo no te desanimes!")
    elif cont<10:
        print("¡Ya casi estas del otro lado!")
    else:
        print("Eres un maestro de las matemáticas")
    return cont, preguntas

#Función de las áreas
#Esta función se despliega cuando se elige la opción 1 en el menu de nivel 2
#La función recopila todas las funciones de áreas
def areas():
    eleccion=0
    while eleccion!=8:
        print("\n1.- Círculo \n2.- Triángulo \n3.- Cuadrado \n4.-Rectángulo \n5.- Esfera \n6.- Cubo \n7.- Cono \n8.- Regresar")
        eleccion=int(input("\nIngrese la figura: "))
        if eleccion==1:
            #Se despliega el juego del área del círculo
            calificacion_area_c=area_circulo()
            print(f"\nSacaste {calificacion_area_c[0]} preguntas correctas de {calificacion_area_c[1]} en el juego del área del circulo!\n")
            
        elif eleccion==2:
            #Se despliega el juego del área de un triángulo
            calificacion_area_t=area_triangulo()
            print(f"\nSacaste {calificacion_area_t[0]} preguntas correctas de {calificacion_area_t[1]} en el juego del  área del triángulo!\n")
            
        elif eleccion==3:
            #Se despliega el juego del área de un cuadrado
            calificacion_area_cua=area_cuadrado()
            print(f"\nSacaste {calificacion_area_cua[0]} preguntas correctas de {calificacion_area_cua[1]} en el juego del  área del cuadrado!\n")
            
        elif eleccion==4:
            #Se despliega el juego del área de un rectángulo
            calificacion_area_r=area_rectangulo()
            print(f"\nSacaste {calificacion_area_r[0]} preguntas correctas de {calificacion_area_r[1]} en el juego del  área del rectángulo!\n")
        
        elif eleccion==5:
            #Se despliega el juego del área de una esfera
            calificacion_area_esfera=area_esfera()
            print(f"\nSacaste {calificacion_area_esfera[0]} preguntas correctas de {calificacion_area_esfera[1]} en el juego del  área de la esfera!\n")
        
        elif eleccion==6:
            #Se despliega el juego del área de una esfera
            calificacion_area_cubo=area_cubo()
            print(f"\nSacaste {calificacion_area_cubo[0]} preguntas correctas de {calificacion_area_cubo[1]} en el juego del  área de la esfera!\n")
        
        elif eleccion==7:
            #Se despliega el juego del área de un cono
            calificacion_area_cono=area_cono()
            print(f"Sacaste {calificacion_area_cono[0]} preguntas correctas de {calificacion_area_cono[1]} en el juego del área del cono")
    menu_nivel_2()
            
            
#Función del área de un círculo
def area_circulo():
    correctas=0
    preguntas=0
    pi = "{:.4f}".format(math.pi)
    pi2 = float(pi) #Formato de pi para que sea 3.1416
    for i in range(3):#Se desplegarán solamente 3 preguntas
        radio = randint(10, 80)
        key = pi2*(radio**2)
        key2 = "{:.2f}".format(key)
        key2=float(key2) #Respuesta del problema redondeada a 2 decimales
        print(f"\nConsidere π como {pi2}\n")
        print("Escriba la respuesta con 2 decimales, el último decimal redondeado hacia el entero más cercano")
        print("Ejemplo: 3.146 ---> 3.15, or 3.141 ---> 3.14\n")
        respuesta=float(input(f"Ingrese al área de un círculo con {radio} cm de radio: "))
        preguntas+=1
        if respuesta==key2:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key2}")
            
    return correctas, preguntas

#Función del área de un cuadrado
def area_cuadrado():
    correctas=0
    preguntas=0
    for i in range(3): #Se desplegarán solamente 3 preguntas
        lado = randint(10, 80)
        key = 4*lado
        respuesta=float(input(f"Ingrese al área de un cuadrado con {lado} cm por lado: "))
        preguntas+=1
        if respuesta==key:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key}")
            
    return correctas, preguntas

#Función del área del rectángulo
def area_rectangulo():
    correctas=0
    preguntas=0
    for i in range(3): #Se desplegarán solamente 3 preguntas
        base = randint(10, 80)
        altura = randint(10, 80)
        key = (base*altura)
        key=round(key, 2) #Respuesta del problema redondeada a 2 decimales
        print("\n---------De ser necesario ingrese su respuesta con máximo 2 decimales------------\n")
        respuesta=float(input(f"Ingrese al área de un rectángulo con {base} cm de base y {altura} cm de altura: "))
        preguntas+=1
        if respuesta==key:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key}")
    return correctas, preguntas

#Función del área del triángulo
def area_triangulo():
    correctas=0
    preguntas=0
    for i in range(3): #Se desplegarán solamente 3 preguntas
        base = randint(10, 80)
        altura = randint(10, 80)
        key = (base*altura)/2
        key=round(key, 2) #Respuesta del problema redondeada a 2 decimales
        print("\n---------De ser necesario ingrese su respuesta con máximo 2 decimales------------\n")
        respuesta=float(input(f"Ingrese al área de un triangulo con {base} cm de base y {altura} cm de altura: "))
        preguntas+=1
        if respuesta==key:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key}")
    return correctas, preguntas

#Función para el área de una esfera
def area_esfera():
    correctas=0
    preguntas=0
    pi = "{:.4f}".format(math.pi)
    pi2 = float(pi) #Formato de pi para que sea 3.1416
    for i in range(3): #Se desplegarán solamente 3 preguntas
        radio = randint(10, 80)
        key = (pi2*(radio**2)*4)
        key2 ="{:.2f}".format(key)
        key2=float(key2) #Respuesta del problema redondeada a 2 decimales
        print(f"\nConsidere π como {pi2}\n")
        print("Escriba la respuesta con 2 decimales, el último decimal redondeado hacia el entero más cercano")
        print("Ejemplo: 3.146 ---> 3.15, or 3.141 ---> 3.14\n")
        respuesta=float(input(f"Ingrese al área de una esfera con {radio} cm de radio: "))
        preguntas+=1
        if respuesta==key2:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
    return correctas, preguntas

#Función del área del cubo
def area_cubo():
    correctas=0
    preguntas=0
    for i in range(3): #Se desplegarán solamente 3 preguntas
        lado = randint(10, 80)
        key = (lado**2)*6
        respuesta=float(input(f"Ingrese al área de un cubo con {lado} cm por lado: "))
        preguntas+=1
        if respuesta==key:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
    return correctas, preguntas

#Función para el área de un cono
#Puede llegar a ser complicado para un niño de secundaria
def area_cono():
    correctas=0
    preguntas=0
    pi = "{:.4f}".format(math.pi)
    pi2 = float(pi) #Formato de pi para que sea 3.1416
    for i in range(3): #Se desplegarán solamente 3 preguntas
        radio = randint(10, 80)
        generatriz = randint(10, 80)
        key = (pi2*(radio**2))+(pi2*radio*generatriz)
        key2 ="{:.2f}".format(key)
        key2=float(key2) #Respuesta del problema redondeada a 2 decimales
        print(f"\nConsidere π como {pi2}\n")
        print("Escriba la respuesta con 2 decimales, el último decimal redondeado hacia el entero más cercano")
        print("Ejemplo: 3.146 ---> 3.15, or 3.141 ---> 3.14\n")
        respuesta=float(input(f"Ingrese al área de un cono con {radio} cm de radio y {generatriz} cm de generatriz: "))
        preguntas+=1
        if respuesta==key2:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
    return correctas, preguntas


#Función de los perímetros
#La función se despliega cuando se elije la opción 2 del menu 2
#La función recopila todas las funciones de perímetros
def perimetros():
    eleccion=0
    while eleccion!=5:
        print("\nFiguras disponibles: ")
        print("\n1.- Círculo \n2.- Triángulo \n3.- Cuadrado \n4.- Rectángulo \n5.- Regresar")
        eleccion=int(input("\nIngrese la figura: "))
        if eleccion==1:
            #Se despliega el juego del perímetro del círculo
            calificacion_peri_circ = perimetro_circulo()
            print(f"\nSacaste {calificacion_peri_circ[0]} preguntas bien de {calificacion_peri_circ[1]} en el juego del perímetro del círculo!")
            
        elif eleccion==2:
            #Se despliega el juego del perímetro de un triangulo
            calificacion_peri_tria=perimetro_triangulo()
            print(f"\nSacaste {calificacion_peri_tria[0]} preguntas bien de {calificacion_peri_tria[1]} en el juego del perímetro del triángulo")
        
        elif eleccion==3:
            #Se despliega el juego del perímetro de un cuadrado
            calificacion_peri_cuad=perimetro_cuadrado()
            print(f"\nSacaste {calificacion_peri_cuad[0]} preguntas bien de {calificacion_peri_cuad[1]} en el juego del perímetro del cuadrado")
            
        elif eleccion==4:
            #Se despliega el juego para el perímetro de un rectángulo
            calificacion_peri_rect=perimetro_rectangulo()
            print(f"\nSacaste {calificacion_peri_rect[0]} preguntas bien de {calificacion_peri_rect[1]} en el juego del perímetro del cuadrado")
            
        else:
            None
            
    menu_nivel_2()


#Función del perímetro de un círculo
def perimetro_circulo():
    correctas=0
    preguntas=0
    pi = "{:.4f}".format(math.pi)
    pi2 = float(pi) #Formato de pi para que sea 3.1416
    for i in range(3): #Se desplegarán solamente 3 preguntas
        radio = randint(10, 80)
        key = 2*pi2*radio
        key2 ="{:.2f}".format(key)
        key2=float(key2) #Respuesta del problema redondeada a 2 decimales
        print(f"\nConsidere π como {pi2}\n")
        print("Escriba la respuesta con 2 decimales, el último decimal redondeado hacia el entero más cercano")
        print("Ejemplo: 3.146 ---> 3.15, or 3.141 ---> 3.14\n")
        respuesta=float(input(f"Ingrese el perímetro de un círculo con {radio} cm de radio: "))
        preguntas+=1
        if respuesta==key2:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key2}")
    return correctas, preguntas
        

#Perímetro del triangulo
def perimetro_triangulo():
    correctas=0
    preguntas=0
    for i in range(3): #Se desplegarán solamente 3 preguntas
        a = randint(10, 80)
        b = randint(10, 80)
        c = randint(10, 80)
        key = a + b + c
        respuesta=int(input(f"\nIngrese el perímetro de un triángulo con {a} cm, {b} cm y {c} cm de lados: "))
        preguntas+=1
        if respuesta==key:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("\nPregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key}\n")
    return correctas, preguntas
            

#Función para el perímetro del cudrado
def perimetro_cuadrado():
    correctas=0
    preguntas=0
    for i in range(3): #Se desplegarán solamente 3 preguntas
        lado = randint(10, 80)
        key = 4*lado
        respuesta=int(input(f"\nIngrese el perímetro de un cuadrado con {lado} cm por lado: "))
        preguntas+=1
        if respuesta==key:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key}\n")
    return correctas, preguntas
            

#Función para el perímetro del rectángulo
def perimetro_rectangulo():
    correctas=0
    preguntas=0
    for i in range(3): #Se desplegarán solamente 3 preguntas
        largo = randint(10, 80)
        ancho = randint(10, 80)
        key = 2*largo + 2*ancho
        respuesta=int(input(f"\nIngrese el perímetro de un rectángulo con {ancho} cm de ancho y {largo} cm de largo: "))
        preguntas+=1
        if respuesta==key:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("Pregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key}\n")
    return correctas, preguntas

#Función de los volúmenes
#La funcion se despliega cuando se elije la opción 3 en el menú 2
#La función recopila las funciones de los volúmenes
def volumenes():
    eleccion=0
    while eleccion!=4:
        print("\nFiguras disponibles")
        print("\n1.- Esfera \n2.- Cono \n3.- Cubo \n4.- Salir")
        eleccion=int(input("\nIngrese la figura: "))
        if eleccion==1:
            #Despliega el juego del volúmen de una esfera
            calificacion_vol_es=volumen_esfera()
            print(f"Sacaste {calificacion_vol_es[0]} preguntas bien de {calificacion_vol_es[1]}!")
        elif eleccion==2:
            #Despliega el juego del volúmen de un cono
            calificacion_vol_cono=volumen_cono()
            print(f"Sacaste {calificacion_vol_cono[0]} preguntas bien de {calificacion_vol_cono[1]}!")
        
        elif eleccion==3:
            #Despliega el juego del volúmen de un cubo
            calificacion_vol_cubo=volumen_cubo()
            print(f"Sacaste {calificacion_vol_cubo[0]} preguntas bien de {calificacion_vol_cubo[1]}!")
            
        else:
            None
    menu_nivel_2()

#Función para el volúmen de una esfera
def volumen_esfera():
    correctas=0
    preguntas=0
    pi = "{:.4f}".format(math.pi)
    pi2 = float(pi) #Formato de pi para que sea 3.1416
    for i in range(3): #Se desplegarán solamente 3 preguntas
        radio = randint(10, 80)
        key = (4/3)*pi2*radio**3
        key2 ="{:.2f}".format(key)
        key2=float(key2) #Respuesta del problema redondeada a 2 decimales
        print(f"\nConsidere π como {pi2}\n")
        print("Escriba la respuesta con 2 decimales, el último decimal redondeado hacia el entero más cercano")
        print("Ejemplo: 3.146 ---> 3.15, or 3.141 ---> 3.14\n")
        respuesta=float(input(f"Ingrese al volúmen de una esfera con {radio} cm de radio: "))
        preguntas+=1
        if respuesta==key2:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("\nPregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key2}")
    return correctas, preguntas
    

#Función para el volúmen de un cono
def volumen_cono():
    correctas=0
    preguntas=0
    pi = "{:.4f}".format(math.pi)
    pi2 = float(pi) #Formato de pi para que sea 3.1416
    for i in range(3): #Se desplegarán solamente 3 preguntas
        radio = randint(10, 80)
        altura = randint(10, 80)
        key = (1/3)*pi2*altura*radio**2
        key2 ="{:.2f}".format(key)
        key2=float(key2) #Respuesta del problema redondeada a 2 decimales
        print(f"\nConsidere π como {pi2}\n")
        print("Escriba la respuesta con 2 decimales, el último decimal redondeado hacia el entero más cercano")
        print("Ejemplo: 3.146 ---> 3.15, or 3.141 ---> 3.14\n")
        respuesta=float(input(f"Ingrese al volúmen de un cono con {radio} cm de radio y {altura} cm de altura: "))
        preguntas+=1
        if respuesta==key2:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("\nPregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key2}")
    return correctas, preguntas


#Función para el volúmen de un cubo
def volumen_cubo():
    correctas=0
    preguntas=0
    for i in range(3):
        lado = randint(10, 80)
        key = lado**3
        respuesta=int(input(f"Ingrese el volúmen de un cubo con {lado} cm por lado: "))
        preguntas+=1
        if respuesta==key:
            correctas+=1
            print("\n¡Correcto!")
            print(f"Preguntas correctas: {correctas}\n")
        else:
            print("\nPregunta incorrecta, no te desanimes\n")
            print(f"La respuesta correcta era {key}")
    return correctas, preguntas


#Menu que se despliega cuando se elige el nivel matemático 1
def menu_nivel_1(n):
    seleccion=0
    while seleccion!=5:
        print("\n\tRecuerda la jerarquía de oprecaciones: ")
        print("\t\tMultiplicación, división, suma y resta\n")
        print("\n1.- Sumas\n")
        print("2.- Restas\n")
        print("3.- Multiplicaciones\n")
        print("4.- Divisiones\n")
        print("5.- Salir\n")
        seleccion=int(input("Ingrese el campo matemático: "))
        if seleccion==1:
            #Se despliega el minijuego se sumas
            calificacion_suma = suma()
            print(f"\n{n} sacaste {calificacion_suma[0]} preguntas correctas de {calificacion_suma[1]} en el juego de sumas!")
            
        elif seleccion==2:
            #Se despliega el minijuego de restas
            calificacion_resta=resta()
            print(f"\n{n} sacaste {calificacion_resta[0]} preguntas correctas de {calificacion_resta[1]} en el juego de restas!")
        
        elif seleccion==3:
            #Se despliega el minijuego de multiplicaciones
            calificacion_multi=multiplicacion()
            print(f"\n{n} sacaste {calificacion_multi[0]} preguntas correctas de {calificacion_multi[1]} en el juego de multiplicaciones!")
        
        elif seleccion==4:
            #Se despliega el minijuego de Divisiones
            calificacion_div=division()
            print(f"\n{n} sacaste {calificacion_div[0]} preguntas correctas de {calificacion_div[1]} en el juego de divisiones!")
    main_mate() #Cuando se elija la opción de salir se regresará a la pantalla de nivel matemático
    
#Menu que se despliega cuando se elige el nivel matemático 2
def menu_nivel_2():
    seleccion=0
    while seleccion!="5":
        print("\n1.- Áreas")
        print("2.- Volúmenes")
        print("3.- Perímetros")
        print("4.- Checar fórmulas, recomendado solo hacer esto una vez")
        print("5.- Elegir nivel matemático")
        seleccion=input("\nIngrese el campo matemático: ")
        if seleccion=="1":
            #Se despliega menu de áreas para que se escoja la figura deseada
            areas()
            
        elif seleccion=="2":
            #Se despliega el menu de los volúmenes para que escojan la figura deseada
            volumenes()
        
        
        elif seleccion=="3":
            #Se despliega el menu de los perímetros para que se escoja la figura deseada
            perimetros()
            
        elif seleccion=="4":
            print("\nSe ha creado un archivo con las fórmulas checa tu carpeta Thonny\n")
            #Se crea un archivo.csv llamado Formulas, en este están las formulas básicas para las figuras
            header= "Figura, Área, Volúmen, Perimetro\n"
            #No pude hacer que en el archivo la formula desplegara el símbolo de pi "π" ya que pyhton no lo reconoce
            with open("../Thonny/Formulas.csv", "w") as outputFile:
                outputFile.write(header)
                circulo_formula="Círculo, pi*radio^2, n.a, 4*pi*radio\n"
                cuadrado_formula="Cuadrado, Lado * Lado, n.a, 4*Lado\n"
                triangulo_formula="Triangulo, Base*altura / 2, n.a, suma de sus lados: a + b + c\n"
                rectangulo_formula="Rectangulo, Base * Altura, n.a, suma de sus lados: 2a + 2b\n"
                esfera_formula = "Esfera, 4*pi*radio^2, 4/3 * pi * radio^3, n.a\n"
                cubo_formula= "Cubo, 6* lado^2, lado^3, n.a\n"
                cono_formula= "Cono, pi*radio*directriz + pi * radio^2, 1/3 * pi * radio^2 * altura, n.a\n"
                outputFile.write(circulo_formula)
                outputFile.write(cuadrado_formula)
                outputFile.write(rectangulo_formula)
                outputFile.write(triangulo_formula)
                outputFile.write(esfera_formula)
                outputFile.write(cono_formula)
                outputFile.write(cubo_formula)
                
    main_mate()#Cuando se elija la opción de salir se regresará a la pantalla de nivel matemático
        

#Programa principal
def main_mate():
    
    print("\tNivel matemático 1, sumas, restas, multiplicaciones y divisiones\n")
    print("\tNivel matemático 2, áreas, volumenes y perímetros")
    menu=input("\nIngrese el nivel matemático: ")
    if menu=="1":
        nombre=input("Ingrese su nombre: ")
        print(f"\nHola {nombre} esperamos que estes teniendo un buen día!")
        menu_nivel_1(nombre)
        
    elif menu=="2":
        nombre=input("Ingrese su nombre: ")
        print(f"\nHola {nombre} esperamos que estes teniendo un buen día!\n")
        menu_nivel_2()
        
    else:
        print("\n------------Porfavor ingrese una opción válida--------------\n")
        main_mate()

print("-----------------------Porfavor asegurese de guardar el documento en una carpeta Thonny-----------------------\n")
main_mate()


