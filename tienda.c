#include <stdio.h>
#include <stdlib.h>

void menu1();
void menu2();

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