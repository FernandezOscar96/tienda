#include <stdio.h>
#include <stdlib.h>

void menu1();
void menu2();

struct registro{
    char nombre[12];
	int stock;
	float codig_barras;
}registro[3];

int main(){

    int opcion1=0,opcion2=0;
    int cantProductos=0;

    while(opcion1!=3){
        menu1();
        while(scanf("%i",&opcion1)==0){
            //al poner el scan dentro del while se evita que '0' sea una opcion
				while (getchar() != '\n' );
                //con este getchar se evita que se pueda agregar una palabra
				system("cls");
    			menu1();
    		};
        switch (opcion1)
        {
            case 1:
                printf("por favor, ingrese el nombre del producto: ");
                scanf("%s",&registro[cantProductos].nombre);
                printf("por favor, ingrese la cantidad en stock: ");
                scanf("%i",&registro[cantProductos].stock);
                printf("por favor, ingrese el codigo de barras: ");
                scanf("%f",&registro[cantProductos].codig_barras);
                printf("producto agregado.\n");
                cantProductos++;
                break;
            case 2:
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
                        for (int i = 0; i < cantProductos; i++)
                        {
                            printf("%i nombre del producto: %s\n",i+1,registro[i].nombre);
                            printf("  cantidad en stock del producto: %i\n",registro[i].stock);
                            printf("  nombre del producto: %.4f\n",registro[i].codig_barras);
                            printf("\n");
                        }
                                                
                        break;
                    case 2:
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

