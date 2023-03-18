#include <stdio.h>
#include <stdlib.h>

void menu1();
void menu2();
int agregarProducto(int cantProductos);
void lista(int cantProductos);
struct registro{
    char nombre[12];
	int stock;
	int codigBarras;
}registro[1];
//para llevar cuenta de cuantos productos se pueden ingresar limite siempre debe llevar +1 por encima de registro[], ya que uno especifica la cantidad de productos(limite) y el otro la cantidad que puede ser registrada(registro[])
int main(){
    int opcion1=0,opcion2=0;
    int cantProductos=0,limite=2;
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
                system("cls");
                while (opcion2!=4){
                    menu2();
                    while( scanf("%i",&opcion2)==0){
                        system("cls");
                        while (getchar() != '\n');
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
int agregarProducto(int cantProductos){
    printf("\npor favor, ingrese el nombre del producto: ");
    scanf("%s",&registro[cantProductos].nombre);
    printf("por favor, ingrese la cantidad en stock: ");
    scanf("%i",&registro[cantProductos].stock);
    printf("por favor, ingrese el codigo de barras(maximo 9 digitos): ");
    scanf("%i",&registro[cantProductos].codigBarras);
    printf("producto agregado.\n");
}
void lista(int cantProductos){
    for (int a = 0; a < cantProductos; a++){
        int contador=0;  
        int div=registro[a].codigBarras;
        //con este while se sabe de cuantos digitos es el codigo de barras, lo que hace es dividir el codigo de barras copiado por 10 para ir sacando 1 digito en cada recorrido del while;
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
    }  
}