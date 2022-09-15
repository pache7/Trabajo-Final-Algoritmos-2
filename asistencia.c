#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"estructuras.h"

void insertarasis(DatosNodo **, DatosNodo **);

void asistencia (){
//int main (){
    FILE *datarch;
    int dni,opcion,aux;
    Datos dat;
    DatosNodo *p = NULL, *q = NULL, *nv = NULL;


    if((datarch=fopen("datos.bin","rb"))!=NULL){
            fread(&dat,sizeof(dat),1,datarch);
                while(!feof(datarch)){
                    nv = ( DatosNodo *) malloc(sizeof( DatosNodo));
                        if(nv!=NULL){
                            nv->datos.dni = dat.dni;
                            nv->datos.sede = dat.sede;
                            nv->datos.tipo = dat.tipo;
                            nv->datos.turno = dat.turno;
                            nv->datos.montoxm = dat.montoxm;
                            nv->datos.f_pago = dat.f_pago;
                            nv->datos.asistencia = dat.asistencia;
                            nv->datos.f_baja = dat.f_baja;
                            nv->datos.reserva = dat.reserva;
                            nv->siguiente = NULL;

                            nv->siguiente = NULL;

                            insertarasis(&nv,&p);
                            // p puntero final lista

                            printf("se cargo la lista de datos\n");


                        }else{
                            printf("ERROR DE ASIGNACION DE MEMORIA DATOS");
                        }
                    fread(&dat,sizeof(dat),1,datarch);
                }
            fclose(datarch);
    }




    q=p;
    //system ("cls");
    printf ("\n\t ingrese su DNI: \n\n");

    scanf ("%d", &dni);

    printf ("\n\n Sus actividades son\n\n");

        while (p != NULL ){
            if(p->datos.dni == dni){

            
                printf ("Sede N - %d ,la actividad N - %d , turno N - %d\n\n",p->datos.sede, p->datos.tipo, p->datos.turno);
                printf ("\n\n");
                printf (" marcar asistencia en este turno? Si [1], No [0]\n\n");
                scanf ("%d", &opcion);
                if (opcion == 1){
                    aux = p->datos.asistencia -1 ;
                    printf (" ya se a marcado su asistencia\n\n");
                    printf (" asistencias restantes  %d", aux);

                

                    if((datarch=fopen("datos.bin","r+b"))!=NULL){
                        fread(&dat,sizeof(dat),1,datarch);
                        while (!feof(datarch)){
                            if(p->datos.dni == dni){

                                dat.asistencia = aux;
                            }
                            
                            fseek(datarch,sizeof(dat)*(-1),SEEK_CUR);
                    
                            fwrite(&dat,sizeof(dat),1,datarch);
                            fseek(datarch,sizeof(dat),SEEK_END);
                            fread(&dat,sizeof(dat),1,datarch);

                        }
                            printf (" asistencias restantes final  %d", aux);
		            fclose(datarch);
                    printf ("\n\n\n!!La asistencia se marco con exito! ");
                    }
                }



            printf ("\t\t Listo \n\n");
            }

        p = p->siguiente;

        }


}


void insertarasis(DatosNodo **nv, DatosNodo **ini){
    DatosNodo *aux;

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

