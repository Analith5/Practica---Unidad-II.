#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ROJO_N  "\033[1;31m"
#define VERDE_N "\033[1;32m"
#define RESET   "\033[0m"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {	

	int n, i, j, longitud =0;
	printf("Ingrese la Cantidad de Libros: ");
	scanf("%d", &n);
	
	
	char titulo[n][100], autor[n][100], genero[n][100], isbn [n][100];
	float precio[n];
	int stock[n];
	float ganancia[n];
	
	
	for(i=0; i<n; i++){
		printf("Ingrese el Titulo del Libro:\n", i + 1);
		scanf(" %[^\n]", &titulo[i]);
		for(j = 0; titulo[i][j]; j++){
			titulo[i][j] = toupper(titulo[i][j]);
		}

		printf("Ingrese el Autor del Libro:\n");
		scanf(" %[^\n]", &autor[i]);
			for(j = 0; autor[i][j]; j++){
			autor[i][j] = toupper(autor[i][j]);
		}

		printf("Ingrese el Genero del Libro:\n");
		scanf(" %[^\n]", &genero[i]);

		for(j = 0; genero[i][j]; j++){
			genero[i][j] = toupper(genero[i][j]);
		}
		
		do{
		printf("Ingrese el Codigo ISBN de 10 digitos:\n");
		scanf(" %[^\n]", &isbn[i]);
		longitud = strlen(isbn[i]);
		 if (longitud != 10) {
                printf("Error: El ISBN debe tener exactamente 10 digitos. Intente de nuevo.\n");
            } 
			} while (longitud != 10);
		

	do{
		printf("Ingrese el Precio del Libro:\n");
		scanf("%f", &precio[i]);
		  if(precio[i] < 0) {
                printf( " Error: El precio no puede ser negativo. Intente nuevamente.\n");
		}
	}while(precio[i]< 0);
	 	
		 printf("Ingrese la cantidad disponible en el inventario:\n");
		scanf("%d", &stock[i]);	
	
		ganancia[i] = precio[i] * stock[i];
	
}
 	
	system("cls");

  
   printf("\n--- INVENTARIO DE LIBROS ---\n\n");
    printf("| %-20s | %-20s | %-15s | %-12s | %-10s | %-10s | %-10s\n", "TITULO", "AUTOR", "GENERO", "ISBN", "PRECIO", "STOCK","GANANCIA");
	 

    	for(i = 0; i < n; i++) {
        printf("| %-20s | %-20s | %-15s | %-12s | %-10.2f | %-10d | ",
               titulo[i], autor[i], genero[i], isbn[i], precio[i], stock[i]);

	if(ganancia[i] <= 0) {
       printf(ROJO_N "%.2f" RESET, ganancia[i]);
    	}else {
        printf(VERDE_N "%.2f" RESET, ganancia[i]);
}
		printf("\n");
                
}	
	int opcion;
	char busqueda[100];
	
printf("\nFiltrar por: \n");
	printf("1. Titulo\n");
	printf("2. Autor\n");
	printf("3. Genero\n");
	printf("4. ISBN\n");
	printf("Seleccion una opcion: "); 
	scanf("%d", &opcion); 

    while (getchar() != '\n');

	printf("Ingrese el termino:\n");
	scanf(" %[^\n]", busqueda); 


	for(i = 0; busqueda[i] != '\0'; i++){ 
		busqueda[i] = toupper (busqueda[i]);
    } 

printf("\n------- RESULTADO DE BUSQUEDA -------\n\n");
    printf("| %-20s | %-20s | %-15s | %-12s | %-10s | %-10s | %-10s |\n", "TITULO", "AUTOR", "GENERO", "ISBN", "PRECIO", "STOCK", "GANANCIA");

    int se_encontraron_resultados = 0;

    for(i = 0; i < n; i++){ 
        int encontrado = 0;
        char temp[100];

        if(opcion == 1) {
            if(strcmp(busqueda, titulo[i]) == 0) {
                encontrado = 1;
            }
        }
        else if(opcion == 2) {
            if(strcmp(busqueda, autor[i]) == 0) {
                encontrado = 1;
            }
        }
        else if(opcion == 3) {
            if(strcmp(busqueda, genero[i]) == 0) {
                encontrado = 1;
            }
        }
        else if(opcion == 4) {
            strcpy(temp, isbn[i]);
            for(j = 0; temp[j]; j++) {
                temp[j] = toupper(temp[j]);
            }
            if(strcmp(busqueda, temp) == 0) {
                encontrado = 1;
            }
        }

        if(encontrado) {
            printf("| %-20s | %-20s | %-15s | %-12s | %-10.2f | %-10d | ",
                   titulo[i], autor[i], genero[i], isbn[i], precio[i], stock[i]);

            if(ganancia[i] < 0) {
                printf(ROJO_N "%.2f" RESET, ganancia[i]);
            }
            else {
                printf(VERDE_N "%.2f" RESET, ganancia[i]);
            }
            printf(" |\n");
            se_encontraron_resultados = 1;
        }
    

	    
	   
}
 
	return 0;
}		//hola profe, mucho texto:c
