#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estructuras.h"

void insertarprofe(ProfeNodo**,ProfeNodo**);
void insertarprofe2(ProfeNodo**,ProfeNodo**);

void profesor(){

//int main() {
 FILE *pr,*archtur;
 
ProfeNodo *p = NULL, *Tp = NULL, *l = NULL, *nv = NULL,*z=NULL,*nv2 = NULL;
Profesores profe;
Turnos tur;
TurnosNodo *a = NULL, *s = NULL, *nv3 = NULL, *d = NULL;

        if ((pr=fopen("profes.bin","rb"))!=NULL){

                    fread(&tur,sizeof(tur),1,pr);
                        while (!feof(pr)){

                                nv =(ProfeNodo*)malloc(sizeof(ProfeNodo));
                                    if (nv != NULL) {
                                        nv->profe.dni=profe.dni;
                                        nv->profe.ncel=profe.ncel;
                                        strcpy(nv->profe.profnom,profe.profnom);
                                        nv->siguiente = NULL;

                                        insertarprofe(&nv,&p);
                                        printf ("   se cargo la lista de turnos     ");
                                     }
                                      fread(&tur,sizeof(tur),1,pr);
                        }
                                      fclose(pr);
        }else printf("no se pudo abrir el archivo.\n");



  
  nv = (struct ProfeNodo *) malloc(sizeof(struct ProfeNodo));
    if(nv!=NULL){
      printf("ingrese el nombre del profesor:\n");
      gets(nv->profe.profnom);
      printf("ingrese el dni del profesor:\n");
      scanf("%d",&nv->profe.dni);
      printf("ingrese el celular del profesor:\n");
      scanf("%d",&nv->profe.ncel);

        nv2->siguiente = NULL;
        insertarprofe2(&nv2,&z);
                    //z tiene fin de lista turnos
        printf("se cargo lista profes con exito\n\n");

    }else{
      printf("ERROR DE ASIGNACION DE MEMORIA DATOS");
    }












                      

}


void insertarprofe(ProfeNodo**nv,ProfeNodo**ini){
    ProfeNodo *aux;
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
void insertarprofe2(ProfeNodo**nv,ProfeNodo**ini){
      ProfeNodo *aux;
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