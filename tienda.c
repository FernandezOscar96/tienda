#include <stdio.h>
#include <stdlib.h>
void menu1();
void menu2();
void menu3();
int agregarProducto(int cantProductos);
void lista(int cantProductos);
void listaTamano(int cantProductos, char op);
struct registro{
    char nombre[12];
	int stock;
	int codigBarras;
    char tamano;
    }registro[3];
//para llevar cuenta de cuantos productos se pueden ingresar limite siempre debe llevar +1 
//por encima de registro[], ya que uno especifica la cantidad de productos(limite) y 
//el otro la cantidad que puede ser registrada(registro[])
int main(){
    int opcion1=0,opcion2=0,opcion3=0;
    int cantProductos=0,limite=4;
    while(opcion1!=3){
        menu1();
        while(scanf("%i",&opcion1)==0){
            //al poner el scan dentro del while se evita que '0' sea una opcion
				while (getchar() !='\n');
                //con este getchar se evita que se pueda agregar una palabra
				system("cls");
    			menu1();
    		};
        switch (opcion1){
            case 1:
                if (cantProductos==limite){
                    printf("\nno es posible agregar mas productos.\n");
                }
                else{
                    agregarProducto(cantProductos);
                    cantProductos++;
                }    
                break;
            case 2:
                while (opcion2!=4){
                    system("cls");
                    menu2();
                    while( scanf("%i",&opcion2)==0){
                        while (getchar() != '\n');
                        system("cls");
                        menu2();
                    };
                    switch (opcion2)
                    {
                    case 1:
                        lista(cantProductos);              
                        break;
                    case 2:
                        printf("\nla cantidad de productos ingresados es de: %i\n", cantProductos);
                        if (cantProductos==limite){
                            printf("se alcanzo el limite de productos a ingresar.\n");
                        }
                        break;
                    case 3:
                    opcion3=0; 
                    system("cls");
                        while (opcion3!=4){
                            char op;
                            menu3();
                            while( scanf("%i",&opcion3)==0){
                                while (getchar() != '\n');
                                system("cls");
                                menu3();
                            };
                            switch (opcion3){

                                case 1:
                                op='p';
                                listaTamano(cantProductos,op);
                                break;
                                case 2:
                                op='m';
                                listaTamano(cantProductos,op);
                                break;
                                case 3:
                                op='g';
                                listaTamano(cantProductos,op);
                                break;
                                case 4:
                                break;
                                default:
                                system("cls");
                                break;
                            }
                        }
                        break;
                    case 4:
                        break;
                    default:
                        system("cls");
                        break;
                    }
                }
                opcion2=0;
                system("cls");
                break;
            case 3:
                break;
            default:
                system("cls");
                break;
        }
    }
    return 0;
}
void menu1(){
    printf("\nPor favor seleccione una opcion:");
    printf("\n1. Ingreso de un nuevo producto:");
    printf("\n2. Productos ingresados:");
    printf("\n3. salir");
    printf("\n");
    return;
}
void menu2(){
    printf ("\nPor favor seleccione una opcion:"); 
    printf ("\n1. Cantidad total de productos ingresados."); 
    printf ("\n2. Cantidad numerica de productos.");
    printf ("\n3. Cantidad de productos de tamanio mediano.");
    printf ("\n4. volver al menu anterior.\n");
    return;
}
void menu3(){
    printf("\nPor favor, elija un tamanio: \n");
    printf("1. Pequenio.\n");
    printf("2. Mediano.\n");
    printf("3. Grande.\n");
    printf("4. volver al menu anterior.\n");
    return;
}
int agregarProducto(int cantProductos){
    int opcion3=0;
    printf("\npor favor, ingrese el nombre del producto: ");
    scanf("%s",&registro[cantProductos].nombre);
    printf("por favor, ingrese la cantidad en stock: ");
    scanf("%i",&registro[cantProductos].stock);
    printf("por favor, ingrese el codigo de barras(maximo 9 digitos): ");
    scanf("%i",&registro[cantProductos].codigBarras);
    printf("por favor, elija el tamanio del producto:\n");
    while (opcion3<1||opcion3>3){
        printf("1. Pequenio\t2. Mediano\t3. Grande\n");
        while(scanf("%i",&opcion3)==0){
				while (getchar() !='\n');
				system("cls");
                printf("opcion no valida:\n");
                printf("por favor, elija el tamaño del producto:\n");
                printf("1. Pequeño\t2. Mediano\t3. Grande\n");
    		};
        switch (opcion3){
        case 1: registro[cantProductos].tamano='p';
        break;
        case 2: registro[cantProductos].tamano='m';
        break;
        case 3: registro[cantProductos].tamano='g';
        break;
        default:
        system("cls");
        printf("opcion no valida:\n");
        printf("por favor, elija el tamanio del producto:\n");
        printf("1. Pequenio\t2. Mediano\t3. Grande\n");
        }
    }
    printf("producto agregado.\n");
}
void lista(int cantProductos){
    for (int a = 0; a < cantProductos; a++){
        int contador=0;  
        int div=registro[a].codigBarras;
        //con este while se sabe de cuantos digitos es el codigo de barras, lo que hace es dividir 
        //el codigo de barras copiado por 10 para ir sacando 1 digito en cada recorrido del while;
        while (div != 0) {
            contador++;
            div /= 10;
        }
        printf("\n%i nombre del producto: %s\n",a+1,registro[a].nombre);
        printf("  cantidad en stock del producto: %i\n",registro[a].stock);
        printf("  codigo de barras: ");
        for (int i = 9; i>=contador; i--){
            //con este for se agregan 0 dependiendo de la longitud del codigo de barras;
            if (i>contador){
                printf("0");
            }
            if (i==contador){
                printf("%d\n",registro[a].codigBarras);
            }
        }
        printf("  tamanio del producto: ");
        if (registro[a].tamano=='p'){
            printf("pequenio\n");
        }
        if (registro[a].tamano=='m'){
            printf("mediano\n");
        }
        if (registro[a].tamano=='g'){
            printf("grande\n");
        }
    }  
}

void listaTamano(int cantProductos, char op){

for (int a = 0; a < cantProductos; a++){
    if (registro[a].tamano==op){
        int contador=0;  
        int div=registro[a].codigBarras;
        while (div != 0) {
            contador++;
            div /= 10;
        }
        printf("\n%i nombre del producto: %s\n",a+1,registro[a].nombre);
        printf("  cantidad en stock del producto: %i\n",registro[a].stock);
        printf("  codigo de barras: ");
        for (int i = 9; i>=contador; i--){
            if (i>contador){
                printf("0");
            }
            if (i==contador){
                printf("%d\n",registro[a].codigBarras);
            }
        }
        printf("  tamanio del producto: ");
        if (registro[a].tamano=='p'){
            printf("pequenio\n");
        }
        if (registro[a].tamano=='m'){
            printf("mediano\n");
        }
        if (registro[a].tamano=='g'){
            printf("grande\n");
        }
    }
}
return;
}