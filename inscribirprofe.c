#ifndef  inscribirprofe_c
#define  inscribirprofe_c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estructuras.h"

void insertaprofe(ProfeNodo**,ProfeNodo**);
void turnosprofe(TurnosNodo**,TurnosNodo**);

void inscribirprofe(){

//int main() {

FILE *pr,*archtur;
 
ProfeNodo *p = NULL, *Tp = NULL, *l = NULL, *nv = NULL,*z=NULL;
Profesores profe;

Turnos tur;
TurnosNodo *a = NULL, *s = NULL, *nv2 = NULL, *d = NULL;
int dni,sede,acti,turno;


if ((pr=fopen("profes.bin","rb"))!=NULL){

                    fread(&profe,sizeof(profe),1,pr);
                        while (!feof(pr)){

                                nv =(ProfeNodo*)malloc(sizeof(ProfeNodo));
                                    if (nv != NULL) {
                                        nv->profe.dni=profe.dni;
                                        nv->profe.ncel=profe.ncel;
                                        strcpy(nv->profe.profnom,profe.profnom);
                                        nv->siguiente = NULL;

                                        insertaprofe(&nv,&p);
                                        printf ("   se cargo la lista de turnos     ");
                                     }
                                      fread(&profe,sizeof(profe),1,pr);
                        }
                                      fclose(pr);
        }else printf("no se pudo abrir el archivo.\n");



        if ((archtur=fopen("turnos.bin","rb"))!=NULL){

                    fread(&tur,sizeof(tur),1,archtur);
                        while (!feof(archtur)){

                                nv2 =(TurnosNodo*)malloc(sizeof(TurnosNodo));
                                    if (nv2 != NULL) {
                                        nv2->turno.sede=tur.sede;
                                        nv2->turno.tipo=tur.tipo;
                                        nv2->turno.turno=tur.turno;
                                        nv2->turno.dias=tur.dias;
                                        nv2->turno.cupo=tur.cupo;
                                        nv2->turno.lugares=tur.lugares;
                                        nv2->turno.espera=tur.espera;
                                        nv2->turno.montoxd=tur.montoxd;
                                        nv2->turno.montoxm=tur.montoxm;
                                        nv2->turno.dni_prof=tur.dni_prof;
                                        strcpy(nv2->turno.n_prof,tur.n_prof);
                                        strcpy(nv2->turno.descripcion,tur.descripcion);
                                        nv2->siguiente = NULL;

                                        turnosprofe(&nv2,&a);
                                        printf ("   se cargo la lista de turnos     ");
                                     }
                                      fread(&tur,sizeof(tur),1,archtur);
                        }
                                      fclose(archtur);
            }else printf("no se pudo abrir el archivo.\n");




system ("cls");
printf("\n\n");
printf("\tIngrese DNI");
scanf ("%d",&dni);

s=a;
    while(s != NULL){
    printf("\n\n");
    printf("\tLos turnos sin profesores ");
    printf("\n\n");
        if (s->turno.dni_prof == 0){
                
                
                printf("\n Para la sede N. %d el tipo de actividad %d en el turno %d",s->turno.sede, s->turno.tipo, s->turno.turno);
                                
                }

            
        
        s = s->siguiente;     
    }

printf("\tIngrese sede, actividad y turno para inscribirse ");
scanf ("%d",&sede);
scanf ("%d",&acti);
scanf ("%d",&turno);


s=a;
    while(s != NULL){
    
                if((archtur=fopen("turnos.bin","r+b"))!=NULL){
                   fread(&tur,sizeof(tur),1,archtur);
                   while (!feof(archtur)){
                      if (s->turno.sede == sede && s->turno.tipo == acti && s->turno.turno == turno){ 
                             tur.dni_prof=dni;
                      }
                       fseek(archtur,sizeof(tur)*(-1),SEEK_CUR);
                       fwrite(&tur,sizeof(tur),1,archtur);
                       fseek(archtur,sizeof(tur),SEEK_END);

                      fread(&tur,sizeof(tur),1,archtur);
                   }

		            fclose(archtur);
                    printf("\n\n");
                    printf("\t Se incribio para dar clase en esa actividad con exito ");

                }else printf("error al abrir el archivo.\n");

                
            
       
        s = s->siguiente;     
    }








}

void insertaprofe(ProfeNodo**nv,ProfeNodo**ini){
    ProfeNodo *aux;
      aux = (*ini);
    	if((*ini) == NULL){
    		(*ini) = (*nv);
		}
		else{
			while(aux->siguiente!= NULL){
				aux = aux->siguiente;
			}
			aux->siguiente = (*nv);
		}
}

void turnosprofe(TurnosNodo**nv,TurnosNodo**lista){
  TurnosNodo *aux;
     aux = (*lista);
    	if((*lista) == NULL){
    		(*lista) = (*nv);
		}
		else{
			while(aux->siguiente != NULL){
				aux = aux->siguiente;
			}
			aux->siguiente = (*nv);
		}

}

#endif