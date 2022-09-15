#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

#include "estructuras.h"

#include "mostraractividad.c"
#include "reserva.c"
#include "validaciondni.c"


void reserva(int,int,int);
void eliminarNodotur(TurnosNodo*);

void insertarturno1(TurnosNodo **, TurnosNodo **);
void insertarturno2(DatosNodo **, DatosNodo **);


void elejirturno (){
//int main(){
    int sede,tipo,turno,dias,opc,nuevocup;
    float monto;
    time_t ahora; struct tm *hora;
    int c_dias,diav=0,dia,mesv=0,mes,anio,aniov=0;
    time(&ahora);
    hora = localtime(&ahora);
    Turnos tur;
    TurnosNodo *p = NULL, *q = NULL, *nv = NULL, *r = NULL,*l=NULL;

    Datos dat;
    DatosNodo *z = NULL, *x = NULL, *nv2 = NULL, *c = NULL;

    Pagos pago;

    FILE *turarch, *datarch, *pg;

    // paso del archivo a la lista

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

                                        insertarturno1(&nv,&p);
                                        printf ("   se cargo la lista de turnos     ");
                                     }
                                      fread(&tur,sizeof(tur),1,turarch);
                        }
                                      fclose(turarch);
        }else printf("no se pudo abrir el archivo.\n");


    system ("cls");
    printf("\n\n");
    validaciondni ();
    printf("\n\n");
    
    mostraractividad();

    
    printf("\n\n");
    printf("\n\n\tElija el ID de actividad\n\n");
    scanf ("%d",&tipo);

        if(tipo == 1){
            printf ("\t complemento en cualquier sede \n\n");
            sede = 0;
        }else{
            printf ("\n\ningrese la sede que desea 1 o 2\n\n");
            scanf ("%d",&sede);
        }

        system("cls");

        r=p;    
        while(r != NULL){

                if (r->turno.sede == sede && r->turno.tipo == tipo){
                
                printf("\n La sede y Actividad seleccionadas con N[%d]\tlos dias:%s\t tiene un cupo de :%d\n",r->turno.turno,r->turno.descripcion,r->turno.cupo);
                }

            r = r->siguiente;
        }

        
        q=p;
        printf ("seleccione el numero de turno que desea:   ");
        scanf ("%d",&turno);

        while(q != NULL){
                if (q->turno.sede == sede && q->turno.tipo == tipo && q->turno.turno == turno){
                    if (q->turno.cupo == 0 ){
                        printf ("   No existe disponibilidad desea estar en lista de espera? [1] sino volvera a elegir turno");
                        scanf ("%d",&opc);
                            if (opc == 1){
                                printf ("LISTA DE ESPERA:   ");
                                reserva(sede,tipo,turno);
                            }else printf("\n\nllamar otra funcion");//AltaBajaClientes();

                    }

                    
                        
                }

            q = q->siguiente;
        }
        


        l=p;

        printf ("ustede slecciono el turno:     %d",turno);
         printf ("\n\n");
        system ("pause");

        while(l != NULL ){
            
            if( l->turno.turno == turno && l->turno.sede == sede && l->turno.tipo == tipo){
                printf ("monto por mes: %.2f",l->turno.montoxm);
                monto = l->turno.montoxm;
                printf ("\n\ndias:%d", l->turno.dias);
                dias = l->turno.dias;

                        // actualizar el cupo    
            
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

            }
            l = l->siguiente;
        }

        //cargar nuevos datos del usuario a la lista

        nv2 = (struct DatosNodo *) malloc(sizeof(struct DatosNodo));
            if(nv2!=NULL){
                printf ("\t\n\n Ingrese su DNI\n\n");
                    scanf ("%d",&nv2->datos.dni);
                    printf ("\t\n\n se ingreso el DNI:%d",nv2->datos.dni);
                    nv2->datos.sede = sede;
                    printf ("\t\n\n se ingreso sede %d",nv2->datos.sede);
                    nv2->datos.tipo = tipo;
                    printf ("\t\n\n se ingreso tipo %d",nv2->datos.tipo);
                    nv2->datos.turno = turno;
                    printf ("\t\n\n se ingreso turno %d",nv2->datos.turno);
                    nv2->datos.montoxm = monto;
                    printf ("\t\n\n se ingreso montoxm %f",nv2->datos.montoxm);
                    printf ("\t El importe a pagar es %.2f\n\n", monto);
                    nv2->datos.asistencia = 4 * dias;
                    printf ("\t\n\n posee un total de asistencias de:  %d \n\n",nv2->datos.asistencia);
                    nv2->siguiente = NULL;

                    insertarturno2(&nv2,&z);
                    //z tiene fin de lista turnos
                    printf("se cargo lista datos con exito\n\n");

            }else{
                printf("ERROR DE ASIGNACION DE MEMORIA DATOS");
            }
            system("cls");
        x=z;
        if((datarch=fopen("datos.bin","a+b"))!=NULL){
            dat.dni = x->datos.dni;
            dat.sede = x->datos.sede;
            dat.tipo = x->datos.tipo;
            dat.turno = x->datos.turno;
            
            dat.montoxm = x->datos.montoxm;
            dat.dias = x->datos.dias;
            dat.f_baja = x->datos.f_baja;
            dat.reserva = x->datos.reserva;
            dat.asistencia = x->datos.asistencia;
            

            fwrite(&dat,sizeof(dat),1,datarch);
		    fclose(datarch);

            printf ("\t\t se guardo en el archivo ");
        }
       
        // ACACACACACACACACA 
               dia = hora->tm_mday; mes = hora->tm_mon; anio = hora->tm_year+1900;
               diav = hora->tm_mday; mesv = hora->tm_mon+1; aniov = hora->tm_year+1900;

        if((pg=fopen("pagos.bin","a+b"))!=NULL){
            pago.dni=x->datos.dni;
            pago.cuotaxm =x->datos.montoxm;
            pago.deuda =0;
            pago.estado = 1;
            pago.intereses = 0;

            pago.fecha_pago = (anio*10000)+(mes*100)+dia;
            pago.fecha_vencimiento = (aniov*10000) + (mesv*100) + diav;

            fwrite(&pago,sizeof(pago),1,pg);
		    fclose(pg);
            printf("dia: %d mes: %d anio :%d \n",diav,mesv,aniov);
            system("pause");
            printf ("\t\t se guardo en el archivo ");
        }

    printf ("\t\t Su inscribcion se realizo con exito \n\n");

  eliminarNodotur(p);
  eliminarNodotur(q);
  eliminarNodotur(nv);
  eliminarNodotur(r);
  eliminarNodotur(l);
}

void insertarturno1(TurnosNodo **nv, TurnosNodo **ini){
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
void insertarturno2(DatosNodo **nv, DatosNodo **ini){
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

void eliminarNodotur(TurnosNodo *nt){
    free(nt);
}
