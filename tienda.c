#include <stdio.h>
#include <stdlib.h>
void menu1();
void menu2();
void menu3();
void lista(int cantProductos);
void listaTamano(int cantProductos, char op);
int limitador(int limite);
int agregarProducto(int cantProductos);
struct registro{
    char nombre[5];
	int stock;
	int codigBarras;
    char tamano;
    }registro[99999];
int main(void){
    int opcion1=0,opcion2=0,opcion3=0;
    int cantProductos=0,limite=0;
    printf("la cantidad de productos maximos es: %i\n",limite);
    limite=limitador(limite);
    printf("la cantidad de productos maximos es: %i\n",limite);
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
                    system("cls");
                    printf("\nno es posible agregar mas productos.\n");
                }
                else{
                    agregarProducto(cantProductos);
                    cantProductos++;
                }    
                break;
            case 2:
                opcion2=0;
                system("cls");
                while (opcion2!=4){
                    
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
                        system("cls");
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
                                    op='s';
                                    listaTamano(cantProductos,op);
                                    break;
                                case 2:
                                    op='m';
                                    listaTamano(cantProductos,op);
                                    break;
                                case 3:
                                    op='l';
                                    listaTamano(cantProductos,op);
                                    break;
                                case 4:
                                    system("cls");
                                    break;
                                default:
                                    system("cls");
                                    break;
                            }
                        }
                        break;
                    case 4:
                        system("cls");
                        break;
                        default:
                        system("cls");
                        break;
                    }
                }
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
}
void menu2(){
    printf ("\nPor favor seleccione una opcion:"); 
    printf ("\n1. Cantidad total de productos ingresados."); 
    printf ("\n2. Cantidad numerica de productos.");
    printf ("\n3. Cantidad de productos de tamanio mediano.");
    printf ("\n4. volver al menu anterior.\n");
}
void menu3(){
    printf("\nPor favor, elija un tamanio: \n");
    printf("1. Pequenio.\n");
    printf("2. Mediano.\n");
    printf("3. Grande.\n");
    printf("4. volver al menu anterior.\n");
}
void lista(int cantProductos){
    system("cls");
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
        if (registro[a].tamano=='s'){
            printf("S");
        }
        if (registro[a].tamano=='m'){
            printf("M");
        }
        if (registro[a].tamano=='l'){
            printf("L");
        }
        printf("\n");
    }  
}
void listaTamano(int cantProductos, char op){
system("cls");
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
            if (registro[a].tamano=='s'){
                printf("S");
            }
            if (registro[a].tamano=='m'){
                printf("M");
            }
            if (registro[a].tamano=='l'){
                printf("L");  
            }
            printf("\n");
        }
    }
}
int limitador(int limite){
    int preselec=0;
    int limitador=0;
    printf("Bienvenido, desea agregar un limite?\n");
    printf("1. Si\t\t2. No\n");
    scanf("%i",&preselec);
    if (preselec==1){
        printf("ingrese la cantidad maxima para ingresar un producto: \n");
        scanf("%i",&limite);
        return limitador=limitador+limite;
    }
    if (preselec==2){
        return limitador=99999;
    }
}
int agregarProducto(int cantProductos){
    int opcion3=0,total;
    printf("\npor favor, ingrese el nombre del producto: ");
    scanf("%5s",&registro[cantProductos].nombre);   
    printf("por favor, ingrese la cantidad en stock: ");
    scanf("%i",&total);
    if (total==0||total>100){
        printf("exede cantidad de stock.");
        return 0;
    }
    printf("por favor, ingrese el codigo de barras(maximo 9 digitos): ");
    scanf("%i",&registro[cantProductos].codigBarras);
    registro[cantProductos].stock=total;
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
        case 1: registro[cantProductos].tamano='s';
        break;
        case 2: registro[cantProductos].tamano='m';
        break;
        case 3: registro[cantProductos].tamano='l';
        break;
        default:
        system("cls");
        printf("opcion no valida:\n");
        printf("por favor, elija el tamanio del producto:\n");
        printf("1. Pequenio\t2. Mediano\t3. Grande\n");
        }
    }
    system("cls");
    printf("producto agregado.\n");
    return 0;
}