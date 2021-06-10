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
void EJERCICIO_2();
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
    int fila=5, tecla, i;
    char ejercicios[20][50]={
        "1. BINARIO A DECIMAL",
        "2. SUMA CONTINUA",
        "3. POTENCIA DE UN NUMERO",
        "4. AREA DE UN TRIANGULO",
        "5. MAYOR DE 3 NUMEROS",
        "6. SUMA LOS PRIMEROS 20 IMPARES",
        "7. AREA Y VOLUMEN DE UNA ESFERA",
        "8. DETERMINAR SI ES PRIMO O NO",
        "9. EL MAYOR DE 10 DIGITOS",
        "10. NUMEROS PARES ENTRE 2 Y 100",
        "11. FACTORIAL DE UN NUMERO",
        "12. POSITIVO ENTERO ES PRIMO",
        "13. VALOR MAXIMO DE UN VECTOR DE ENTEROS",
        "14. GANANCIAS DE LA SEMANA",
        "15. GANANCIAS DEL MES",
        "16. ORDENAR DE FORMA ASCENDENTE",
        "17. AGENDA PERSONAL",
        "18. AGENDA PERSONAL CON ARCHIVO .TXT",
        "19. VOCALES, CONSONANTES Y DIGITOS DE UNA CADENA",
        "20. ALMACENAR, MOSTRAR Y VACIAR PILA"};
    do
    {
        system("cls");
        printf("\n\tMENU DE EJERCICIOS\n\n");
        printf("\tSeleccione una opcion:\n\n");
        for(i=0;i<20;i++){
            printf("\t\t%s\n",ejercicios+i);
        };
        printf("\t\t%c REGRESAR\n",174);
        printf("\n\tUse %c o %c para desplazarse y Enter para seleccionar...\n",30,31);
        gotoxy(14,fila); // posicion inicial
        printf("%c",26); // dibuja la flecha
        gotoxy(0,0);
        tecla=ESPERAR_TECLA(); // Espera la tecla arriba, abajo o enter
        if(tecla!=ENTER){
            fila=RESPONDE_TECLA(tecla,fila,5,25);
        } else {
            fila-=5;
            system("cls");
            printf("\n\t%s\n\n",ejercicios+fila);
            switch (fila){
            case 0:
                EJERCICIO_1();
                break;
            case 1:
                EJERCICIO_2();
                break;
            case 20:
                repetir=false;
                break;
            default:
                break;
            }
            if(fila!=20){
            printf("\n\tPresione cualquier tecla para regresar...\n");
            getch();}
            fila=5; // retorna a la primer fila del menu
        }
    } while(repetir);
}

void EJERCICIO_1(){
    int num, num2, count, i, res, mult;
    printf("\t\tEscriba un numero binario: ");
    scanf("%d", &num);
    num2=num;
    count=0;

    while(num>0){
        num=num/10;
        count=count+1;
    }
    int bin[count];
    printf("\t\tEn binario es: ");
    for(i=0;i<count;i++){
        if(num2 % 10 >0){
            bin[i]=1;
        }
        else{
            bin[i]=0;
        }
        num2=num2/10;
        printf("%d",bin[i]);
    }
    printf("\n\t\tTiene %d digitos\n",count);
    mult=1;
    res=0;
    for(i=0;i<count;i++){
        if(bin[i]==1){
            res=res+mult;
        }
        mult=mult*2;
    }

    printf("\t\tEl numero en decimal es: %d\n",res);
}
void EJERCICIO_2(){
    int sum=0, x;
    do{
        printf("\n\t\tPresione 1 para continuar sumando o 0 para obtener el total: ");
        scanf("%d",&x);
        if(x==1){
            printf("\n\t\tIngrese un numero a la suma: ");
            scanf("%d",&x);
            sum+=x;
            x=1;
        }
    }while(x!=0);
    printf("\n\t\tEl total es: %d\n",sum);
}

void MENU_CONCEPTOS(){

}