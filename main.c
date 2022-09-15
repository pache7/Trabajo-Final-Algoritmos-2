#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "estructuras.h"
#include "AltaBajaClientes.c"
#include "asistencia.c"
#include "admin.c"
#include "pagosclientes.c"
#include "profesor.c"
#include "inscribirprofe.c"


void AltaBajaClientes();
void asistencia();
void admin();
void profesor();
void pagosclientes();
void inscribirprofe();

int main (){
    int opcion;

					system("cls");
					printf("\tBIENBENIDO AL GYM\n\n");
					printf("Ingrese una opcion\n");
					printf("[1] Alta y Baja de Clientes\n");
					printf("[2] Inscribir profesores\n");
					printf("[3] Turnos profesores\n");
					printf("[4] Asistencia\n");
					printf("[5] Apartado Administrador\n");
					printf("[6] Pago de Cuotas\n");
					scanf ("%d", &opcion);
					getchar();
					printf("\n\n");

		switch (opcion){
			case 1:
				printf ("-ABM DE CLIENTES \n");
				AltaBajaClientes();
				break;
			case 2:
				printf ("-INSCRIBIR PROFESOR-\n");
                  profesor();
				  break;
            case 3:
			    printf("-TURNOS DE PROFESOR.\n");
				  inscribirprofe();
				 break;
			
			case 4:
				printf ("-ASISTENCIA-\n");
				asistencia();
				break;
				
			case 6:
				printf ("-PAGOS DE CUOTAS-\n");
				pagosclientes();
				break;
            case 5:
			    printf("-ADMINISTRADOR-\n");
                admin();  break;

		}
}


