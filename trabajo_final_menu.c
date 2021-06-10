/*
PROGRAMACIÓN I
Trabajo Final
Integrantes: Karmen María Chalita Velázquez, José Eduardo García Ramirez, Nemesis J. Sierra Aranda 
Profesor: Hugo Adrián Delgado Rodriguez
Carrera: Ingeniería en Computación, 1er Semestre
*/
#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include <windows.h>
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

void gotoxy(int x,int y);
int MENU();
void MENU_EJERCICIOS();
void MENU_CONCEPTOS();
//funcion principal
void main(void)
{
    int opcion;
    opcion=MENU(); //entra al bucle de seleccion, retorna la opcion seleccionada
    switch (opcion)
        {
        case 5:
            MENU_CONCEPTOS();
            break;

        case 6:
            MENU_EJERCICIOS();
            break;

        default:
            break;
        }

    system("cls");
}
//menu principal
int MENU(){
    bool repetir=true;
    int opcion=5;
    int tecla;
    do
    {
        system("cls");
        printf("\n\tMENU DE CONCEPTOS Y EJERCICIOS\n\n");
        printf("\tSeleccione una opcion:\n\n");
        printf("\t\tCONCEPTOS\n");
        printf("\t\tEJERCICIOS\n");
        printf("\t\tSALIR\n");
        printf("\n\tUse %c o %c para desplazarse y Enter para seleccionar...\n",30,31);
        gotoxy(14,opcion); //posiciona el puntero en la posicion inicial
        printf("%c",26); // dibuja la flecha
        gotoxy(0,0);
        //espera una tecla a ser pulsada
        do
        {
            tecla=getch();
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER); //sale del bucle al presionar una de estas teclas
        switch (tecla)
        {
        case ARRIBA:
                opcion--; //regresa el puntero una fila arriba
                if (opcion==4)
                {
                    opcion=7;
                }
                
            break;
        case ABAJO:
                opcion++; //baja el puntero
                if (opcion==8)
                {
                    opcion=5;
                }
                
            break;
        case ENTER:
                repetir=false; // rompe el bucle
            break;
        default:
            break;
        }
        
    } while(repetir);
    return opcion; // retorna la opcion
}
//simula la funcion gotoxy que no funciona en la version 5.11 de DEVC++
void gotoxy(int x,int y){
    HANDLE hcon;
    hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon,dwPos);
}
//menu de ejercicios
void MENU_EJERCICIOS(){
    bool repetir=true;
    int tecla;
    int opcion2=5;
    do
    {
        system("cls");
        printf("\n\tMENU DE EJERCICIOS\n\n");
        printf("\tSeleccione una opcion:\n\n");
        printf("\t\t1. BINARIO A DECIMAL\n");
        printf("\t\t2. SUMA CONTINUA\n");
        printf("\t\t3. POTENCIA DE UN NUMERO\n");
        printf("\t\t4. AREA DE UN TRIANGULO\n");
        printf("\t\t5. MAYOR DE 3 NUMEROS\n");
        printf("\t\t6. SUMA LOS PRIMEROS 20 IMPARES\n");
        printf("\t\t7. AREA Y VOLUMEN DE UNA ESFERA\n");
        printf("\t\t8. DETERMINAR SI ES PRIMO O NO\n");
        printf("\t\t9. EL MAYOR DE 10 DIGITOS\n");
        printf("\t\t10. NUMEROS PARES ENTRE 2 Y 100\n");
        printf("\t\t11. FACTORIAL DE UN NUMERO\n");
        printf("\t\t12. POSITIVO ENTERO ES PRIMO\n");
        printf("\t\t13. VALOR MAXIMO DE UN VECTOR DE ENTEROS\n");
        printf("\t\t14. GANANCIAS DE LA SEMANA\n");
        printf("\t\t15. GANANCIAS DEL MES\n");
        printf("\t\t16. ORDENAR DE FORMA ASCENDENTE\n");
        printf("\t\t17. AGENDA PERSONAL\n");
        printf("\t\t18. AGENDA PERSONAL CON ARCHIVO .TXT\n");
        printf("\t\t19. VOCALES, CONSONANTES Y DIGITOS DE UNA CADENA\n");
        printf("\t\t20. ALMACENAR, MOSTRAR Y VACIAR PILA\n");
        printf("\n\tUse %c o %c para desplazarse y Enter para seleccionar...\n",30,31);
        gotoxy(14,opcion2);
        printf("%c",26);
        gotoxy(0,0);
        //Entra en bucle esperando pulsar una tecla
        do
        {
            tecla=getch();
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
        switch (tecla)
        {
        case ARRIBA:
                opcion2--;
                if (opcion2==4)
                {
                    opcion2=24;
                }
                
            break;
        case ABAJO:
                opcion2++;
                if (opcion2==25)
                {
                    opcion2=5;
                }
                
            break;
        case ENTER:
                repetir=false;
            break;
        default:
            break;
        }
        
    } while(repetir);
}

void MENU_CONCEPTOS(){

}