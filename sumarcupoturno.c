#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estructuras.h"

#include "mostraractividad.c"

//#include "AltaBajaClientes.c"


void insertaragregarturno(TurnosNodo **, TurnosNodo **);



void sumarcupoturno (int sede, int tipo, int turno){
//int main(){
    FILE *turarch;
    int dias,opc,nuevocup;
    float monto;
    Turnos tur;
    TurnosNodo *p = NULL, *q = NULL, *nv = NULL, *r = NULL;


        if ((turarch=fopen("turnos.bin","rb"))!=NULL){

                    fread(&tur,sizeof(tur),1,turarch);
                        while (!feof(turarch)){

                                nv =(TurnosNodo*)malloc(sizeof(TurnosNodo));
                                    if (nv != NULL) {
                                        nv->turno.sede=tur.sede;
                                        nv->turno.tipo=tur.tipo;
                                        nv->turno.turno=tur.turno;
                                        nv->turno.dias=tur.dias;
                                        nv->turno.cupo=tur.cupo;
                                        nv->turno.lugares=tur.lugares;
                                        nv->turno.espera=tur.espera;
                                        nv->turno.montoxd=tur.montoxd;
                                        nv->turno.montoxm=tur.montoxm;
                                        nv->turno.dni_prof=tur.dni_prof;
                                        strcpy(nv->turno.n_prof,tur.n_prof);
                                        strcpy(nv->turno.descripcion,tur.descripcion);
                                        nv->siguiente = NULL;

                                        insertaragregarturno(&nv,&p);
                                        printf ("   se cargo la lista de turnos     ");
                                     }
                                      fread(&tur,sizeof(tur),1,turarch);
                        }
                                      fclose(turarch);
        }else printf("no se pudo abrir el archivo.\n");

      system ("cls");  
q=p;
  while (q != NULL) {
        if (q->turno.sede == sede && q->turno.tipo == tipo && q->turno.turno == turno){
            printf ("El cupo de la actividad es %d ", q->turno.cupo);
            printf("\n");
            printf ("El cupo de la actividad es %d ", q->turno.espera);

            if((turarch=fopen("turnos.bin","r+b"))!=NULL){
                fread(&tur,sizeof(tur),1,turarch);
                while (!feof(turarch)){
                    if (tur.sede == sede && tur.tipo == tipo && tur.turno == turno){
                    
                    tur.cupo++;
                    nuevocup = tur.cupo;
                    }
                fseek(turarch,sizeof(tur)*(-1),SEEK_CUR);
                    
                fwrite(&tur,sizeof(tur),1,turarch);
                fseek(turarch,sizeof(tur),SEEK_END);
                fread(&tur,sizeof(tur),1,turarch);

                }

		        fclose(turarch);
                printf ("\n\n\n!!!!El cupo de la actividad se actualizo!!!!\n");
                printf("Cupo Nuevo: %d \n",nuevocup);
            }
            
            printf ("\n\n");

        }
        q=q->siguiente;
    }
}



void insertaragregarturno(TurnosNodo **nv, TurnosNodo **ini){
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