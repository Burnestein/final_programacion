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
#define ESC 27

void gotoxy(int x,int y);
void MENU_PRINCIPAL();
void MENU_EJERCICIOS();
void MENU_CONCEPTOS();
int ESPERAR_TECLA();
int RESPONDE_TECLA(int opcion,int fila, int filamin, int filamax);
int maximo(int numero1, int numero2);
float totalsemana(int numsem); //FUNCION DEL EJERCICIO 15
float semana[4][8]; // VARIABLE GLOBAL DEL EJERCICIO 15
void EJERCICIO_1();
void EJERCICIO_2();
void EJERCICIO_3();
void EJERCICIO_4();
void EJERCICIO_5();
void EJERCICIO_6();
void EJERCICIO_7();
void EJERCICIO_8();
void EJERCICIO_9();
void EJERCICIO_10();
void EJERCICIO_11();
void EJERCICIO_12();
void EJERCICIO_13();
void EJERCICIO_14();
void EJERCICIO_15();

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
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER && tecla != ESC); //sale del bucle al presionar una de estas teclas
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
        "10. SUMA DE PARES ENTRE 2 Y 100",
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
            case 2:
                EJERCICIO_3();
                break;
            case 3:
                EJERCICIO_4();
                break;
            case 4:
                EJERCICIO_5();
                break;
            case 5:
                EJERCICIO_6();
                break;
            case 6:
                EJERCICIO_7();
                break;
            case 7:
                EJERCICIO_8();
                break;
            case 8:
                EJERCICIO_9();
                break;
            case 9:
                EJERCICIO_10();
                break;
            case 10:
                EJERCICIO_11();
                break;
            case 11:
                EJERCICIO_12();
                break;
            case 12:
                EJERCICIO_13();
                break;
            case 13:
                EJERCICIO_14();
                break;
            case 14:
                EJERCICIO_15();
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
                repetir=false;
                break;
            default:
                break;
            }
            if(fila!=20){
            printf("\n\n\tPresione cualquier tecla para continuar...\n");
            getch();}
            fila=5; // retorna a la primer fila del menu
        }
    } while(repetir);
}
int maximo(int numero1, int numero2){
		if(numero1>=numero2){
			return numero1;
		}
		else{
			return numero2;
		}
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
        } else if(x!=0){printf("\n\t\tOPCION NO VALIDA\n");};
    }while(x!=0);
    printf("\n\t\tEl total es: %d\n",sum);
}
void EJERCICIO_3(){
    int num,pot, i;
    int res=1;
    printf("\t\tIngrese el numero a sacar potencia: ");
    scanf("%d",&num);
    printf("\n\n\t\tIngrese la potencia: ");
    scanf("%d",&pot);
    for(i=pot;i>=1;i--){
        res*=num;
    }
    printf("\n\n\t\tEl resultado es: %d",res);
}
void EJERCICIO_4(){
    float base,altura,res;
    printf("\t\tIngrese el valor de la base: ");
    scanf("%f",&base);
    printf("\n\t\tIngrese el valor de la altura: ");
    scanf("%f",&altura);
    res=(base*altura)/2;
    printf("\n\t\tEl area del triangulo es: %f",res);
}
void EJERCICIO_5(){
    int num1=0, num2=0, num3=0, mayor;
    printf("\t\tIngrese los tres numeros separados por una coma: ");
    scanf("%d,%d,%d",&num1,&num2,&num3);
    if(num1>=num2){
        mayor=num1;
    }
    else{
        mayor=num2;
    }
    if(num3>=mayor){
        mayor=num3;
    }
    printf("\n\t\tEl numero mayor es: %d",mayor);
}
void EJERCICIO_6(){
    int i,res=0,count=1;
    printf("\t\tNumeros impares: ");
	for(i=1;i<=20;i++){
        printf("%d, ",count);
		res+=count;
		count+=2;
	}
    printf("...");
	printf("\n\n\t\tLa suma de los 20 primeros numeros impares es: %d",res);
}
void EJERCICIO_7(){
    float rad, area, vol, pi=3.14159265359;
	printf("\t\tIngrese el valor del radio: ");
	scanf("%f",&rad);
	area=4*pi*rad*rad;
	vol=(area*rad)/3;
	printf("\n\t\tEl valor del area es: %f",area);
	printf("\n\t\tEl valor del volumen es: %f",vol);
}
void EJERCICIO_8(){
    int num, div=2, primo=1;
	printf("\t\tIngrese el numero: ");
	scanf("%d",&num);
	if(num>1){
		while(div<num){
			if(num%div==0) {
				printf("\n\t\tEl numero %d NO es primo",num);
				num=0;
				primo=0;
			}
			div++;
		}
		if(primo==1)printf("\n\t\tEl numero %d SI es primo",num);
	}
	else printf("\n\t\tEl numero %d NO es primo",num);
}
void EJERCICIO_9(){
    int num, num2, count, i, mayor=0, div=1;
    printf("\t\tIngrese un numero de maximo diez digitos: ");
    scanf("%d", &num);
    num2=num;
    count=0;

    while(num>0){
        num=num/10;
        count=count+1;
    }
    //printf("Tiene %d digitos\n",count);

    int resta[count];
    int digito[count];
    int unidad[count];
    int suma;
    for(i=0;i<count;i++)digito[i]=0;
    for(i=0;i<count;i++){
        div*=10;
    }
    //printf("el primer divisor es %d\n",div);
    resta[0]=0;
    digito[0]=0;
    unidad[0]=0;
    suma=0;
    int div2=div/10;

    for(i=0;i<count;i++){
        unidad[i+1]=(digito[i]*(div));
        suma+=unidad[i+1];
        resta[i+1]=num2-suma;
        digito[i+1]=resta[i+1]/(div2);
        div/=10;
        div2/=10;
        //printf("la suma es %d\n",suma);
        //printf("la resta es %d\n",resta[i+1]);
        //printf("los digitos son %d\n",digito[i+1]);		
    }

    for(i=0;i<count;i++){
        if(digito[i]>=digito[i+1]&&digito[i]>mayor){
            mayor=digito[i];
        }
        else if(digito[i+1]>mayor) {
            mayor=digito[i+1];
        }
    }
    printf("\n\t\tEl digito mayor es: %d",mayor);
}
void EJERCICIO_10(){
	int i,res=0;
	for(i=2;i<=100;i++){
		if(i%2==0){
			res+=i;
		}
	}
	printf("\t\tLa suma de los pares entre 2 y 100 es: %d",res);
}
void EJERCICIO_11(){
	int num=0, resultado=0, i=0;
	printf("\t\tIngrese un numero: ");
	scanf("%d",&num);
	resultado=num;
	for(i=num;i>=2;i--){
		resultado=resultado*(i-1);
	}
	printf("\n\t\tEl factorial es: %d",resultado);
}
void EJERCICIO_12(){
	int num, div=2, primo=1;
	printf("\t\tIngrese el numero: ");
	scanf("%d",&num);
	if(num>1){
		while(div<num){
			if(num%div==0) {
				printf("\n\t\tEl numero %d NO es primo",num);
				num=0;
				primo=0;
			}
			div++;
		}
		if(primo==1)printf("\n\t\tEl numero %d SI es primo",num);
	}
	else printf("\n\t\tEl numero %d NO es primo",num);
}
void EJERCICIO_13(){
	int resultado=0, vector[5], i; //declaramos variables
    for(i=0;i<5;i++){
        vector[i]=0;
	}
	printf("\t\tIngrese los 5 valores del arreglo separados por un espacio: ");
	for(i=0;i<5;i++){
        gotoxy(16+i,4);
		scanf("%d",&vector[i]);
	}
	for(i=0;i<5;i++){
		resultado=maximo(resultado,vector[i]);
	}
	printf("\n\t\tEl numero mayor es: %d",resultado);
}
void EJERCICIO_14(){
    float dia[7], total;
    int i=0, tecla=0, fila=4;
    bool x=true;
    for(i=0;i<7;i++){ //inicializa el arreglo en ceros
        dia[i]=0;
    }
    do{
        system("cls");
        total=0;
        for(i=0;i<7;i++){
            total+=dia[i];
        }
        printf("\n\t14. GANANCIAS DE LA SEMANA\n\n");
        printf("\t\tDia         Ganancias\n");
        printf("\t\tLunes:      %f\n",dia[0]);
        printf("\t\tMartes:     %f\n",dia[1]);
        printf("\t\tMiercoles:  %f\n",dia[2]);
        printf("\t\tJueves:     %f\n",dia[3]);
        printf("\t\tViernes:    %f\n",dia[4]);
        printf("\t\tSabado:     %f\n",dia[5]);
        printf("\t\tDomingo:    %f\n",dia[6]);
        printf("\n\t\tTOTAL:	%f\n",total);
        printf("\n\tUse %c o %c para desplazarse, Enter para seleccionar...\n",30,31);
        printf("\n\tSALIR pulse ESC");
        gotoxy(14,fila); // posicion inicial
        printf("%c",26); // dibuja la flecha
        gotoxy(0,0);
        tecla=ESPERAR_TECLA(); // Espera la tecla arriba, abajo o enter
        if(tecla==ARRIBA || tecla==ABAJO){
            fila=RESPONDE_TECLA(tecla,fila,4,10);
        } else {
        if(tecla==ESC){
            x=false;
            } else {
                switch (fila){
                    case 4:
                        gotoxy(28,fila);
                        printf("                    ");
                        gotoxy(28,fila);
                        scanf("%f",&dia[0]);
                    break;
                    case 5:
                        gotoxy(28,fila);
                        printf("                    ");
                        gotoxy(28,fila);
                        scanf("%f",&dia[1]);
                    break;
                    case 6:
                        gotoxy(28,fila);
                        printf("                    ");
                        gotoxy(28,fila);
                        scanf("%f",&dia[2]);
                    break;
                    case 7:
                        gotoxy(28,fila);
                        printf("                    ");
                        gotoxy(28,fila);
                        scanf("%f",&dia[3]);
                    break;
                    case 8:
                        gotoxy(28,fila);
                        printf("                    ");
                        gotoxy(28,fila);
                        scanf("%f",&dia[4]);
                    break;
                    case 9:
                        gotoxy(28,fila);
                        printf("                    ");
                        gotoxy(28,fila);
                        scanf("%f",&dia[5]);
                    break;
                    case 10:
                        gotoxy(28,fila);
                        printf("                    ");
                        gotoxy(28,fila);
                        scanf("%f",&dia[6]);
                    break;
                    default:
                    break;
                }
            }
        }
    } while (x==true);
    gotoxy(12,15);
}

void EJERCICIO_15(){
    float totalmes=0, totalsem[4];
    int i, j, fila=4, tecla;
    bool x=true;
    //inicializar array en cero
        for(i=0;i<4;i++){
            for(j=0;j<8;j++){
                semana[i][j]=0;
            }
        }
        for(i=0;i<4;i++){
            totalsem[i]=0;
        }
    do{
        system("cls");
        totalmes=0;
        for(i=0;i<4;i++){
            totalmes+=totalsem[i];
        }
        printf("\n\t15. GANANCIAS DEL MES\n\n");
        printf("\t\tSemana 		Ganancias\n");
        printf("\t\t1.Semana 1:	%f\n",totalsem[0]);
        printf("\t\t2.Semana 2:	%f\n",totalsem[1]);
        printf("\t\t3.Semana 3:	%f\n",totalsem[2]);
        printf("\t\t4.Semana 4:	%f\n",totalsem[3]);
        printf("\n\t\tTOTAL MES:	%f\n\n",totalmes);
        //printf("\tSeleccione la semana o presione 0 para salir...\n");
        //scanf("%d",&menu2);
        printf("\n\tUse %c o %c para desplazarse, Enter para seleccionar...\n",30,31);
        printf("\n\tSALIR pulse ESC");
        gotoxy(14,fila); // posicion inicial
        printf("%c",26); // dibuja la flecha
        gotoxy(0,0);
        tecla=ESPERAR_TECLA(); // Espera la tecla arriba, abajo o enter
        if(tecla==ARRIBA || tecla==ABAJO){
            fila=RESPONDE_TECLA(tecla,fila,4,7);
        } else {
            if(tecla==ESC){
            x=false;
            } else {
                switch (fila){
                case 4:
                    totalsem[0]=totalsemana(0);
                break;
                case 5:
                    totalsem[1]=totalsemana(1);
                break;
                case 6:
                    totalsem[2]=totalsemana(2);
                break;
                case 7:
                    totalsem[3]=totalsemana(3);
                break;
                default:
                break;
                }
            }
        }
    } while (x==true);
    system("cls");
}
float totalsemana(int numsem){

	int fila=5, i, j, tecla;
	bool x=true;
	
	do{
		system("cls");
		semana[numsem][7]=0;
		for(i=0;i<7;i++){
			semana[numsem][7]+=semana[numsem][i];
		}
        printf("\n\t15. GANANCIAS DEL MES\n\n");
		printf("\t\tGanancias de la Semana %d\n",numsem+1);
		printf("\t\tDia 		Ganancias\n");
		printf("\t\t1.Lunes:	%f\n",semana[numsem][0]);
		printf("\t\t2.Martes:	%f\n",semana[numsem][1]);
		printf("\t\t3.Miercoles:	%f\n",semana[numsem][2]);
		printf("\t\t4.Jueves:	%f\n",semana[numsem][3]);
		printf("\t\t5.Viernes:	%f\n",semana[numsem][4]);
		printf("\t\t6.Sabado:	%f\n",semana[numsem][5]);
		printf("\t\t7.Domingo:	%f\n",semana[numsem][6]);
		printf("\n\t\tTOTAL:	%f\n\n",semana[numsem][7]);
		//printf("\tSeleccione un dia o presione 0 para regresar al menu...\n");
		//scanf("%d",&menu);
        printf("\n\tUse %c o %c para desplazarse, Enter para seleccionar...\n",30,31);
        printf("\n\tREGRESAR pulse ESC");
        gotoxy(14,fila); // posicion inicial
        printf("%c",26); // dibuja la flecha
        gotoxy(0,0);
        tecla=ESPERAR_TECLA(); // Espera la tecla arriba, abajo o enter
        if(tecla==ARRIBA || tecla==ABAJO){
            fila=RESPONDE_TECLA(tecla,fila,5,11);
        } else {
            if(tecla==ESC){
            x=false;
            } else {
                switch (fila){
                    case 5:
                        gotoxy(32,fila);
                        printf("                    ");
                        gotoxy(32,fila);
                        scanf("%f",&semana[numsem][fila-5]);
                    break;
                    case 6:
                        gotoxy(32,fila);
                        printf("                    ");
                        gotoxy(32,fila);
                        scanf("%f",&semana[numsem][fila-5]);
                    break;
                    case 7:
                        gotoxy(32,fila);
                        printf("                    ");
                        gotoxy(32,fila);
                        scanf("%f",&semana[numsem][fila-5]);
                    break;
                    case 8:
                        gotoxy(32,fila);
                        printf("                    ");
                        gotoxy(32,fila);
                        scanf("%f",&semana[numsem][fila-5]);
                    break;
                    case 9:
                        gotoxy(32,fila);
                        printf("                    ");
                        gotoxy(32,fila);
                        scanf("%f",&semana[numsem][fila-5]);
                    break;
                    case 10:
                        gotoxy(32,fila);
                        printf("                    ");
                        gotoxy(32,fila);
                        scanf("%f",&semana[numsem][fila-5]);
                    break;
                    case 11:
                        gotoxy(32,fila);
                        printf("                    ");
                        gotoxy(32,fila);
                        scanf("%f",&semana[numsem][fila-5]);
                    break;
                    default:
                    break;
                }
            }
        }
	} while (x==true);
	return semana[numsem][7];
}

void MENU_CONCEPTOS(){

}
