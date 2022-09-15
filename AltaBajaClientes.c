#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "crearcliente.c"


#include "elejirturno.c"
#include "estructuras.h"
#include "bajacliente.c"

void bajacliente();
void crearcliente();
void elejirturno();
int main();

void AltaBajaClientes(){
//int main(){
    int opcion;


system ("cls");
printf ("\t\t	Alta y baja de actividades\n\n");
printf ("\t\t[1] Si es la primera vez en el gym\n\n");
printf ("\t\t[2] Para pasar a eleccion de turno\n\n");
printf ("\t\t[3] Baja de cliente\n\n");
printf ("\t\t[4] Volver\n\n");
    scanf ("%d", &opcion);

    switch (opcion){
			case 1:
				printf ("-NUEVO CLIENTE-\n");
				crearcliente();
				AltaBajaClientes();
				break;

            case 2:
				printf ("-ELECCION DE TURNO-\n");
				elejirturno();
				AltaBajaClientes();
				break;

			case 3:
				printf ("-DAR DE BAJA TURNO-\n");
				bajacliente();
				AltaBajaClientes();
				break;

			case 4:
				printf ("entro 4 ta opcion\n");
				main();
				break;

    }
	system("pause");
}
