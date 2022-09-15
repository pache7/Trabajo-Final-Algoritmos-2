#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "crearactividad.c"
#include "crearturno.c"
#include "listaturnos.c"
#include"gentereserva.c"
#include"Listadeudores.c"
#include"crearArbol.c"

void gentereserva();
void listarturnos();
void crearturnos();
void crearactividad();
void Listadeudores();
int main();


//int main (){
void admin (){
    int opcion;
    system("cls");
	printf ("\t Apartado Administrador \n\n ");
    printf ("\t [1] Crear Actividad\n\n ");
    printf ("\t [2] Crear Turno\n\n ");
	printf ("\t [3] Lista de Turnos\n\n ");
	printf ("\t [4] Lista de Deudores\n\n ");
	printf ("\t [5] Lista espera\n\n ");
	printf ("\t [6] Arbol de Deudores \n\n ");
	printf ("\t [7] Volver al Menu\n\n ");


    printf ("\t INGRESE SU OPCION: \n\n ");
    scanf ("%d", &opcion);
	getchar();

    switch (opcion){
			case 1:
				printf ("\tentro 1ra opcion\n\n");
				crearactividad();
				break;
				
			case 2:
				printf ("entro 2da opcion\n\n");
                crearturno();
				break;

			case 3:
				printf ("entro 3ra opcion\n\n");
                listaturnos();
				break;

			case 4:
				printf ("entro 4ta opcion\n\n");
                Listadeudores();
				break;

			case 5:
				printf ("entro 5ta opcion \n");
				gentereserva();
				break;

			case 6:
				printf ("entro 6ta opcion \n");
				crearArbol();
				break;
    
			case 7:
				printf ("entro 7ma opcion \n");
				main ();
				break;
    }

}