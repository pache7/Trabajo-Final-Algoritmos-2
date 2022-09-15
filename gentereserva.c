#ifndef gentereserva_c
#define gentereserva_c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "estructuras.h"

void listadogenteespera(NodoReserva **, NodoReserva **);

void gentereserva(){
//int main () {
    
    int sede,tipo;
    FILE *archres;
    Rerserva res;
    NodoReserva  *nuevo = NULL, *raiz = NULL,*reco=NULL;
/*    
        if((archres=fopen("reserva.bin","a+b"))!=NULL){
            res.tipo=2;
            res.sede=1;
            res.turno =5;
            res.dni=7;
            res.ncel=8;
            res.reserva = 9;
            

            fwrite(&res,sizeof(res),1,archres);
		    fclose(archres);
        }
*/
        if ((archres=fopen("reserva.bin","rb"))!=NULL){

                    fread(&res,sizeof(res),1,archres);
                        while (!feof(archres)){

                        nuevo = malloc(sizeof(struct NodoReserva));
                            if (nuevo != NULL) {
                                nuevo->reser.tipo =res.tipo;
                                nuevo->reser.sede =res.sede;
                                nuevo->reser.turno =res.turno;
                                nuevo->reser.dni =res.dni;
                                nuevo->reser.ncel =res.ncel;
                                nuevo->reser.reserva =res.reserva;
                                nuevo->siguiente = NULL;
                            
                                if (raiz == NULL){
                            
                                raiz = nuevo;
                                nuevo->siguiente= NULL;
                                }
                                else
                                {
                                    nuevo->siguiente = raiz;
                                    raiz = nuevo;
                                }
                                printf ("se cargo la pila de reserva");
                                fread(&res,sizeof(res),1,archres);
                            }
                        }
                            fclose(archres);
            }

        printf ("\n\n");
        printf ("\tIngrese la sede para listar reserva ");
        printf ("\n\n");
        scanf("%d",&sede);
        printf ("\tIngrese tipo de actividad");
        printf ("\n\n");
        scanf("%d",&tipo);



        reco=raiz;

        while (reco!=NULL)
        {
        
            if(sede == reco->reser.sede && tipo == reco->reser.tipo){
                printf("Turno N - %d. Gente en espera: %d ", reco->reser.turno, reco->reser.reserva);
                printf("\n\n");
            }
        
        reco=reco->siguiente;
        }
        printf("\n");

}


#endif