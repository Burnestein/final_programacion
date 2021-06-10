/*
PROGRAMACIÓN I
Trabajo Final
Integrantes: Karmen María Chalita Velázquez, José Eduardo García Ramirez, Nemesis J. Sierra Aranda 
Profesor: Hugo Adrián Delgado Rodriguez
Carrera: Ingeniería en Computación, 1er Semestre
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

void gotoxy(int x,int y);
void MENU_PRINCIPAL();
void MENU_EJERCICIOS();
void MENU_CONCEPTOS();
int ESPERAR_TECLA();
int RESPONDE_TECLA(int opcion,int fila, int filamin, int filamax);
void EJERCICIO_1();
//funcion principal
void main(void)
{
        MENU_PRINCIPAL();
        system("cls");
}
//menu principal
void MENU_PRINCIPAL(){
    bool repetir=true;
    int fila=5, tecla;
    do
    {
        system("cls");
        printf("\n\tMENU DE CONCEPTOS Y EJERCICIOS\n\n");
        printf("\tSeleccione una opcion:\n\n");
        printf("\t\tCONCEPTOS\n");
        printf("\t\tEJERCICIOS\n");
        printf("\t\tSALIR\n");
        printf("\n\tUse %c o %c para desplazarse y Enter para seleccionar...\n",30,31);
        gotoxy(14,fila); // posicion inicial
        printf("%c",26); // dibuja la flecha
        gotoxy(0,0);
        tecla=ESPERAR_TECLA(); // Espera la tecla arriba, abajo o enter
        if(tecla!=ENTER){
            fila=RESPONDE_TECLA(tecla,fila,5,7); //mueve la posicion de la fila si no fue ENTER.
        } else {
            switch (fila){
            case 5:
                MENU_CONCEPTOS();
                break;
            case 6:
                MENU_EJERCICIOS();
                break;
            case 7:
                repetir=false;
                break;
            default:
                break;
            }
        }
    } while(repetir);
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
int ESPERAR_TECLA(){
    int tecla;
    do
        {
            tecla=getch();
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER); //sale del bucle al presionar una de estas teclas
    return tecla;
}
int RESPONDE_TECLA(int opcion,int fila, int filamin, int filamax){
    switch (opcion)
        {
        case ARRIBA:
                fila--; //regresa la posicion una fila arriba
                if (fila==filamin-1){
                    fila=filamax;
                }
            break;
        case ABAJO:
                fila++; //baja la posicion
                if (fila==filamax+1){
                    fila=filamin;
                }
            break;
        default:
            break;
        }
    return fila;
}
void MENU_EJERCICIOS(){
    bool repetir=true;
    int fila=5, tecla;
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
        printf("\t\t%c REGRESAR\n",174);
        printf("\n\tUse %c o %c para desplazarse y Enter para seleccionar...\n",30,31);
        gotoxy(14,fila); // posicion inicial
        printf("%c",26); // dibuja la flecha
        gotoxy(0,0);
        tecla=ESPERAR_TECLA(); // Espera la tecla arriba, abajo o enter
        if(tecla!=ENTER){
            fila=RESPONDE_TECLA(tecla,fila,5,25);
        } else {
            fila-=4;
            system("cls");
            switch (fila){
            case 1:
                EJERCICIO_1();
                break;
            case 2:
                
                break;
            case 21:
                repetir=false;
                break;
            default:
                break;
            }
        }
    } while(repetir);
}

void EJERCICIO_1(){
    int num, num2, count, i, res, mult;
    printf("Escriba Un numero binario\n");
    scanf("%d", &num);
    num2=num;
    count=0;

    while(num>0){
        num=num/10;
        count=count+1;
    }

    printf("Tiene %d digitos\n",count);

    int bin[count];

    for(i=0;i<count;i++){
        if(num2 % 10 >0){
            bin[i]=1;
        }
        else{
            bin[i]=0;
        }
        num2=num2/10;
        printf("en arreglo es %d\n",bin[i]);
    }

    mult=1;
    res=0;
    for(i=0;i<count;i++){
        if(bin[i]==1){
            res=res+mult;
        }
        mult=mult*2;
    }

    printf("El numero en decimal es: %d",res);
    getchar();
}

void MENU_CONCEPTOS(){

}