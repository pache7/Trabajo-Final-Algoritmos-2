#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estructuras.h"


void listadeturnos(TurnosNodo **, TurnosNodo **);
void listareserva(NodoReserva**,NodoReserva**);

//void elejirturno ();


//int main (){
void reserva (int sede,int tipo,int turno){
    int dni,num,reser;
    FILE *archres, *turarch;
    Rerserva res;
    NodoReserva *a = NULL, *s = NULL, *nv2 = NULL, *d = NULL;
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

                                        listadeturnos(&nv,&p);
                                        printf ("   se cargo la lista de turnos     ");
                                     }
                                      fread(&tur,sizeof(tur),1,turarch);
                        }
                                      fclose(turarch);
        }else printf("no se pudo abrir el archivo.\n");

        system ("pause");

    r=p;

    printf ("   sede tipo turno\t%d\t%d\t%d\t", sede, tipo, turno);       
          
    while ( r!=NULL){
        if(sede == r->turno.sede && turno == r->turno.turno &&  r->turno.tipo == tipo){
            reser = r->turno.espera + 1;
        }
    }
                if((turarch=fopen("turnos.bin","r+b"))!=NULL){
                    fread(&tur,sizeof(tur),1,turarch);
                    while (!feof(turarch)){
                    if (turno==tur.turno && sede == tur.sede  && tur.tipo== tipo){
                     
                        r->turno.espera + 1;
                        r->turno.espera;
                         
                          
                    fseek(turarch,sizeof(tur)*(-1),SEEK_CUR);
                    
                    fwrite(&tur,sizeof(tur),1,turarch);
                    fseek(turarch,sizeof(tur),SEEK_END);
                    }
                    fread(&tur,sizeof(tur),1,turarch);
                    }
		            fclose(turarch);
                printf ("\n\n\n!!!!El cupo de la actividad se actualizo!!!! ");
                }

                if((turarch=fopen("turnos.bin","r+b"))!=NULL){
                    fread(&tur,sizeof(tur),1,turarch);
                    while (!feof(turarch)){
                     if (turno==tur.turno && sede == tur.sede  && tur.tipo== tipo){
                     
                         tur.cupo--;
                     }
                     
                    fseek(turarch,sizeof(tur)*(-1),SEEK_CUR);
                    fwrite(&tur,sizeof(tur),1,turarch);
                    fseek(turarch,sizeof(tur),SEEK_END);


                    fread(&tur,sizeof(tur),1,turarch);
                    }

		            fclose(turarch);
                }else printf("error al abrir el archivo.\n");
   
    nv2 =(NodoReserva*)malloc(sizeof(NodoReserva));
        if( nv2!=NULL){
        
            printf ("ingrese DNI\n\n");
            scanf ("%d",&dni);
            nv2->reser.dni = dni;
            nv2->reser.sede = sede;
            nv2->reser.turno = turno;
            nv2->reser.tipo = tipo;
            nv2->reser.reserva = reser;


            printf ("Ingrese un numero de contacto\n\n");
            scanf ("%d",&num);
            nv2->reser.ncel = num;
            nv2->siguiente = NULL;
            listareserva(&nv2,&a);
            printf ("   se cargo la lista de turnos     ");
        }

        if((archres=fopen("reserva.bin","a+b"))!=NULL){
            res.dni = nv2->reser.dni;
            res.dni = nv2->reser.sede;
            res.dni = nv2->reser.turno;
            res.dni = nv2->reser.tipo;
            res.dni = nv2->reser.reserva;
            res.dni = nv2->reser.ncel;

        
        fwrite(&res,sizeof(res),1,archres);
		fclose(archres);
        printf ("\n\n se cargo el archivo reserva ");
        }
        



}


void listadeturnos(TurnosNodo **nv, TurnosNodo **ini){
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

void listareserva(NodoReserva**nv,NodoReserva**ini){
NodoReserva *aux;

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