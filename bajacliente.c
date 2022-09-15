#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include"estructuras.h"
#include"sumarcupoturno.c"
void sumarcupoturno (int sede,int  tipo,int turno);

void insertarbaja(DatosNodo **nv, DatosNodo **ini);
PagosNodo* borrarnodoR (PagosNodo *,int);
void verpagos(PagosNodo**,PagosNodo**);

void bajacliente(){
//int main () {
    Datos dat;
    Pagos pago;
    DatosNodo *l = NULL, *p = NULL,*r = NULL;
    PagosNodo *nv=NULL,*np=NULL,*lp=NULL;
    FILE *datarch,*pgo;
    int dni,op,turno,sede,dia,mes,anio,tipo;
    long int baja;
    time_t ahora;
    struct tm *hora;
    time(&ahora);
    hora = localtime(&ahora);
    dia = hora->tm_mday; mes= hora->tm_mon+1; anio = hora->tm_year+1900;

                                   printf("-BAJA DE TURNO CLIENTE-\n");
                                   printf("Si desea desistir de algun turno pulse 1, 0 para finalizar \n");
                                         scanf("%d",&op);
                                  
                                   while (op != 0)
                                   {    
                                         printf("-Actividades a la que esta inscripto: \n");
                                          printf("ingrese su dni para ver: \n");
                                                 scanf("%d",&dni);
                                           if ((datarch=fopen("datos.bin","rb"))!= NULL){
                                               fread(&dat,sizeof(dat),1,datarch);
                                               while (!feof(datarch))
                                               {
                                                 if (dni == dat.dni)
                                                 {
                                                   p=(DatosNodo*)malloc(sizeof(DatosNodo));
                                                  if (p != NULL){
                                                     p->datos.sede = dat.sede;
                                                     p->datos.tipo = dat.tipo;
                                                     p->datos.turno = dat.turno;
                                                     p->siguiente = NULL;
                                                     insertarbaja(&p,&l);
                                                  }
                                                 }
                                                 
                                                 fread(&dat,sizeof(dat),1,datarch);
                                               } 
                                               fclose(datarch);
                                           }else printf("error al abrir el archivo.\n");

                                           r = l;
                                                while (r != NULL)
                                                {
                                                  printf("sede:%d\tID de actividad:%d\tturno:%d\n",r->datos.sede,r->datos.tipo,r->datos.turno);
                                                  
                                                  r = r->siguiente;
                                                }
                                                
                                                printf("ingrese sede de la que quiere darse la baja :\n");
                                                      scanf("%d",&sede);

                                                printf("ingrese Id Actividad de la que quiere darse la baja :\n");
                                                      scanf("%d",&tipo);
                                                printf("ingrese Turno de la que quiere darse la baja :\n");
                                                      scanf("%d",&turno);
                                                     
                                                     sumarcupoturno(sede,tipo,turno);
                                                    baja = (anio*10000) + (mes*100) + dia;

                                                if ((datarch=fopen("datos.bin","r+b"))!=NULL)
                                                {
                                                  fread(&dat,sizeof(dat),1,datarch);
                                                    while (!feof(datarch))
                                                    {
                                                      if (dni == dat.dni)
                                                      {
                                                        dat.sede = -1;
                                                        dat.tipo = -1;
                                                        dat.turno = -1;
                                                        dat.f_baja = baja;
                                                      }
                                                       
                                                       fseek(datarch,sizeof(dat)*(-1),SEEK_CUR);
                                                       fwrite(&dat,sizeof(dat),1,datarch);
                                                       fseek(datarch,sizeof(dat),SEEK_END);
                                                       
                                                       fread(&dat,sizeof(dat),1,datarch);
                                                    }
                                                    
                                                  fclose(datarch);
                                                }else printf("error al abrir el archivo.\n");
                                                
                                                if ((pgo=fopen("pagos.bin","rb"))!=NULL){
                                                   fread(&pago,sizeof(pago),1,pgo);
                                                   while (!feof(pgo))
                                                   {
                                                     if (dni==pago.dni) {
                                                        nv =(PagosNodo*)malloc(sizeof(PagosNodo));
                                                        nv->pago.dni = pago.dni;
                                                        nv->pago.cuotaxm = pago.cuotaxm;
                                                        
                                                        nv->pago.fecha_pago = pago.fecha_pago;
                                                        nv->pago.fecha_vencimiento = pago.fecha_vencimiento;
                                                        nv->pago.deuda = pago.deuda;
                                                        nv->pago.intereses = pago.intereses;
                                                        
                                                        nv->pago.estado = pago.estado;
                                                        verpagos(&nv,&np);
                                                     }

                                                     fread(&pago,sizeof(pago),1,pgo);
                                                   }
                                                  fclose(pgo);
                                                }else printf("error al abrir abrir archivo.\n");
                                                
                                                lp = np;
                                                lp = borrarnodoR(lp,dni);
                                                if ((pgo=fopen("pagos.bin","r+b"))!=NULL) { 
                                                  fread(&pago,sizeof(pago),1,pgo);
                                                   while (!feof(pgo))
                                                   {
                                                     if (dni==pago.dni) {
                                                       pago.estado = 0;
                                                       pago.deuda = 0;
                                                       pago.dni = -1;
                                                     }
                                                     fseek(pgo,sizeof(pago)*(-1),SEEK_CUR);
                                                     fwrite(&pago,sizeof(pago),1,pgo);
                                                     fseek(pgo,sizeof(pago),SEEK_END);

                                                     fread(&pago,sizeof(pago),1,pgo);
                                                   }
                                                  
                                                   fclose(pgo);
                                                }else printf("error la abrir el archivo.\n");
                                                
                                         fflush(stdin);
                                         printf("Si desea desistir otro turno pulse 1, 0 para finalizar \n");
                                         scanf("%d",&op);
                                   }
                                   

}



void verpagos(PagosNodo**nv,PagosNodo**ini){
   PagosNodo *aux;
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


void insertarbaja(DatosNodo **nv, DatosNodo **ini){
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


PagosNodo* borrarnodoR(PagosNodo*rc,int dni){
   
   PagosNodo *Borrarp = NULL;
      
      if (rc != NULL)
      {
          if (rc->pago.dni == dni)
          {
            Borrarp = rc;
            rc = rc->siguiente;
            free(Borrarp);

          }else{
                rc->siguiente = borrarnodoR(rc->siguiente,dni);
          }
      }
      
    return rc;
}
