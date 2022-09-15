#ifndef mostraractividad_c
#define mostraractividad_c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//mostraractividad
#include"estructuras.h"

void insertarActi(NodoActi**nv,NodoActi**ini);
void eliminarNodoActi(NodoActi*);


//int main (){
void mostraractividad(){

   FILE *acti;
   Actividades actividades;
   NodoActi *a=NULL,*l=NULL,*la=NULL;

                if ((acti=fopen("Actividades.bin","rb"))!=NULL){
                    fread(&actividades,sizeof(actividades),1,acti);
                         while (!feof(acti)){
                                a =(NodoActi*)malloc(sizeof(NodoActi));
                                    if (a != NULL) {
                                        a->acti.tipo = actividades.tipo;
                                        strcpy(a->acti.descripcion,actividades.descripcion);
                                         a->siguiente = NULL;
                                         insertarActi(&a,&l);
                                        
                                     }
                                      fread(&actividades,sizeof(actividades),1,acti);
                                     }
                                      fclose(acti);
                    }else printf("no se pudo abrir el archivo.\n");
                     la = l;
                     while (la != NULL) {
                            printf("\tID actividad:\t%d",la->acti.tipo);

                            printf("\tNombre:\t%s",la->acti.descripcion);
                            printf("\n\n");
                            la = la->siguiente;
                     }
                                                          
   eliminarNodoActi(la);
   eliminarNodoActi(l);
   eliminarNodoActi(a);
   printf("\n\n");

}


void insertarActi(NodoActi**nv,NodoActi**ini){
    NodoActi *aux;
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

void eliminarNodoActi(NodoActi* na){
    free(na);
}

#endif