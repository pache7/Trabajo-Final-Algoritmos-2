#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estructuras.h"
#include "mostraractividad.c"

void insertarlistaturnos(TurnosNodo **nv, TurnosNodo **ini);

//int main (){
void listaturnos (){
    Turnos tur;
    TurnosNodo *q = NULL, *r = NULL, *nv = NULL, *e = NULL;
    FILE *turarch;
    int sede,acti,cont;

        if ((turarch=fopen("turnos.bin","rb"))!=NULL){
            fread(&tur,sizeof(tur),1,turarch);
                while (!feof(turarch)){
                    nv =(TurnosNodo*)malloc(sizeof(TurnosNodo));
                        if (nv != NULL) {

                            nv->turno.sede = tur.sede;
                            nv->turno.tipo = tur.tipo;
                            nv->turno.turno = tur.turno;
                            nv->turno.cupo=tur.cupo;
                            nv->turno.lugares=tur.lugares;

                            nv->siguiente = NULL;

                            insertarlistaturnos(&nv,&q);
                            printf ("\t\t se cargo la lista desde el archivo ");

                        }
                    fread(&tur,sizeof(tur),1,turarch);
                }
        fclose(turarch);
        }


    system ("cls");
    printf ("\n\n");
    printf ("\tLista de actividades");
    printf ("\n\n");
    mostraractividad();

    printf ("Ingrese la actividad que desea\n\n");
    scanf ("%d",&acti);
    
        if(acti != 1){
            printf ("\n\ningrese la sede que desea 1 o 2\n\n");
            scanf ("%d",&sede);
            
        }
        if(acti == 1){
            printf ("\t complemento en cualquier sede \n\n");
            sede = 0;

        }


r=q;
        while(r != NULL){
            if (r->turno.sede == sede && r->turno.tipo == acti){

                    printf ("para la sede y actividad seleccionada los turnos N - %d    ", r->turno.turno );
                    cont = r->turno.lugares - r->turno.cupo ;
                    printf ("   Personas Inscriptas %d", cont);
                    printf ("\n\n");  


            }

            r = r->siguiente;
        }

         
}
void insertarlistaturnos(TurnosNodo **nv, TurnosNodo **ini){
    TurnosNodo *aux;

    aux = (*ini);

    	if((*ini) == NULL){
    		(*ini) = (*nv);
		}
		else{

			while(aux->siguiente != NULL){
				aux = aux->siguiente;
			}
			aux->siguiente = (*nv);
		}
}