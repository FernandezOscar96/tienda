#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu1();
void menu2();
void menu3();
void lista(int cantProductos);
void listaTamano(int cantProductos, char*op);
void ordenarLista(int cantProductos);
void limpiar(int cantProductos);
int limitador(int limite);
int agregarProducto(int cantProductos);
int eliminarProducto(int cantProductos);

struct registro{
    char nombre[5];
	int stock;
	int codigBarras;
    char tamano[2];
    }registro[0];
int main(void){
    int opcion1=0,opcion2=0,opcion3=0;
    int cantProductos=0,limite=0;
    struct registro registro[limite];
    printf("la cantidad de productos maximos es: %i\n",limite);
    limite=limitador(limite);
    printf("la cantidad de productos maximos es: %i\n",limite);
    while(opcion1!=3){
        menu1();
        fflush(stdin);
        while(scanf("%i",&opcion1)==0){
				while (getchar() !='\n');
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
                while (opcion2!=6){
                    menu2();
                    fflush(stdin);
                    while( scanf("%i",&opcion2)==0){
                        while (getchar() != '\n');
                        system("cls");
                        menu2();
                    };
                    switch (opcion2){
                    case 1:
                        lista(cantProductos);              
                        break;
                    case 2:
                        ordenarLista(cantProductos);
                        break;
                    case 3:
                        system("cls");
                        printf("\nla cantidad de productos ingresados es de: %i\n", cantProductos);
                        if (cantProductos==limite){
                            printf("se alcanzo el limite de productos a ingresar.\n");
                        }
                        break;
                    case 4:
                    opcion3=0; 
                    system("cls");
                        while (opcion3!=4){
                            char op[2];
                            menu3();
                            fflush(stdin);
                            while( scanf("%i",&opcion3)==0){
                                while (getchar() != '\n');
                                system("cls");
                                menu3();
                            };
                            switch (opcion3){
                                case 1:
                                strcpy(op,"s");
                                listaTamano(cantProductos,op);
                                break;
                                case 2:
                                strcpy(op,"m");
                                listaTamano(cantProductos,op);
                                break;
                                case 3:
                                strcpy(op,"l");
                                listaTamano(cantProductos,op);
                                break;
                                case 5:
                                system("cls");
                                break;
                                default:
                                system("cls");
                                break;
                            }
                        }
                        break;
                    case 5:
                        system("cls");
                        cantProductos=eliminarProducto(cantProductos);
                        break;
                    case 6:
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
    printf ("\n2. Mostrar productos ordenados alfabeticamente."); 
    printf ("\n3. Cantidad numerica de productos.");
    printf ("\n4. Cantidad de productos de tamanio mediano.");
    printf ("\n5. eliminar un producto de la lista.");
    printf ("\n6. volver al menu anterior.\n");
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
        printf("\n%d.nombre del producto: %s\n",a+1,registro[a].nombre);
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
        if (strcmp(registro[a].tamano,"s") ==0){
            printf("(S)");
        }
        if (strcmp(registro[a].tamano,"m") ==0){
            printf("(M)");
        }
        if (strcmp(registro[a].tamano,"l") ==0){
            printf("(L)");
        }
        printf("\n");
    }  
}
void ordenarLista(int cantProductos){
    system("cls");
    for (int a=97,b=65;a<=122&&b<=90; a++,b++){
        int posicion=0;
        for (int i = 0; i < cantProductos; i++){
            fflush(stdin);
            if (((char)a)==(registro[i].nombre[posicion])||((char)b)==(registro[i].nombre[posicion])){
                int contador=0;  
                int div=registro[i].codigBarras;
                while (div != 0) {
                    contador++;
                    div /= 10;
                }
                printf("\n  nombre del producto: %s\n",registro[i].nombre);
                printf("  cantidad en stock del producto: %i\n",registro[i].stock);
                printf("  codigo de barras: ");
                for (int z = 9; z>=contador; z--){
                    if (z>contador){
                        printf("0");
                    }
                    if (z==contador){
                        printf("%d\n",registro[i].codigBarras);
                    }
                }
                printf("  tamanio del producto: ");
                if (strcmp(registro[i].tamano,"s")==0){
                    printf("(S)");
                }
                if (strcmp(registro[i].tamano,"m")==0){
                    printf("(M)");
                }
                if (strcmp(registro[i].tamano,"l")==0){
                    printf("(L)");
                }
                printf("\n");
            }
        }
    }
}
void listaTamano(int cantProductos, char*op){
system("cls");
    for (int a = 0; a < cantProductos; a++){
        if (strcmp(registro[a].tamano,op) ==0){
            int contador=0;  
            int div=registro[a].codigBarras;
            while (div != 0) {
                contador++;
                div /= 10;
            }
            printf("\n%d.nombre del producto: %s\n",a+1,registro[a].nombre);
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
            if (strcmp(registro[a].tamano,"s") ==0){
                printf("(S)");
            }
            if (strcmp(registro[a].tamano,"m") ==0){
                printf("(M)");
            }
            if (strcmp(registro[a].tamano,"l") ==0){
                printf("(L)");  
            }
            printf("\n");
        }
    }
}
//agregar la logica en la funcion limpiar
void limpiar(int cantProductos){

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
    char nombre[6];
    printf("\npor favor, ingrese el nombre del producto: ");
    scanf("%s",&nombre);
    if (strlen(nombre)>5){
        system("cls");
        printf("\nnombre no permitido.\n");
        return 0;
    }
    printf("por favor, ingrese la cantidad en stock: ");
    scanf("%i",&total);
    if (total==0||total>100){
        system("cls");
        printf("exede cantidad de stock.\n");
        return 0;
    }
    printf("por favor, ingrese el codigo de barras(maximo 9 digitos): ");
    scanf("%i",&registro[cantProductos].codigBarras);
    registro[cantProductos].stock=total;
    strcpy(registro[cantProductos].nombre,nombre);
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
        case 1: strcpy(registro[cantProductos].tamano,"s"); 
        break;
        case 2: strcpy(registro[cantProductos].tamano,"m"); 
        break;
        case 3: strcpy(registro[cantProductos].tamano,"l"); 
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
int eliminarProducto(int cantProductos){
    int indice_a_borrar=-1;
    char nombre[50];
    printf("\nPor favor, ingrese el nombre que desea borrar:\n");
    printf("preciona 0 para volver al menu anterior.\n");
    scanf("%s",nombre);
    int a=0;
    while (a<1){
        for (int i = 0; i < cantProductos; i++){
            if (strcmp(registro[i].nombre,nombre)==0){
                indice_a_borrar = i;
                break;
            }
            if (strcmp(nombre,"0")==0){
                system("cls");
                a++;
                return cantProductos;
                break;
            }
            
        }
        if(indice_a_borrar!=-1) {
            for (int i = indice_a_borrar; i < cantProductos; i++){
                strcpy(registro[i].nombre,registro[i+1].nombre);
                registro[i].stock=registro[i+1].stock;
                registro[i].codigBarras=registro[i+1].codigBarras;
                strcpy(registro[i].tamano,registro[i+1].tamano);
            }
            strcpy(registro[cantProductos].nombre,"");
            registro[cantProductos].stock=0;
            registro[cantProductos].codigBarras=0;
            strcpy(registro[cantProductos].tamano,"");
            cantProductos--;
            system("cls");
            printf("Producto eliminado de la lista\n");
            a++;
            return cantProductos;
        }
        else{
            system("cls");
            printf("nombre no encontrado.\n");
            printf("\nPor favor, ingrese el nombre que desea borrar:\n");
            printf("preciona 0 para volver al menu anterior.\n");
            scanf("%s",nombre);
        }
    }    
}
