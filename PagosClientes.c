#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#include"estructuras.h"
#include"actualizardeudores.c"

void insertarpago(PagosNodo**,PagosNodo**);
float actualizardeudores();
int main();

PagosNodo* borrarLES(PagosNodo *ini);
//int main (){
void pagosclientes(){

FILE *pgo,*cli,*datarch,*t; Pagos pago; Datos dat;

PagosNodo *Tp = NULL,*p=NULL,*l=NULL, *nv = NULL; time_t ahora; struct tm *hora;

int c_dias,diav,dia,mesv,mes,anio,aniov,dni,datdni,band;

float montpagado,montxm,total=0;
time(&ahora);
hora = localtime(&ahora);
  
                                if ((pgo=fopen("pagos.bin","rb"))!=NULL){

                                     fread(&pago,sizeof(pago),1,pgo);
                                  while (!feof(pgo)){
                                      nv =(PagosNodo*)malloc(sizeof(PagosNodo));
                                  if (nv != NULL) {
                                        nv->pago.dni=pago.dni;
                                        nv->pago.cuotaxm=pago.cuotaxm;
                                        nv->pago.deuda=pago.deuda;
                                        nv->pago.estado=pago.estado;
                                        nv->pago.intereses=pago.intereses;
                                        nv->pago.fecha_pago=pago.fecha_pago;
                                        nv->pago.fecha_vencimiento=pago.fecha_vencimiento;
 
                                        nv->siguiente = NULL;

                                        insertarpago(&nv,&p);
                                        printf ("   se cargo la lista de pagos     ");
                                  }
                                      fread(&pago,sizeof(pago),1,pgo);
                                  }
                                      fclose(pgo);
                          }else printf("no se pudo abrir el archivo.\n");

    
printf("\n");

printf("ingrese el dni del cliente\n");
scanf("%d",&dni);
printf("\n");

        l=p;   
    /*    while (l != NULL) {
            printf("%d\t",l->pago.dni);

          l = l->siguiente;

        }
        */

        band = 0;
               while (l != NULL){
               
                 if (dni == l->pago.dni) {
                    total = actualizardeudores();
                    band = 1;
                    printf("usted debe abonar: %.2f,ingrese su pago: \n",total);
                    scanf("%f",&montpagado);
                    while (montpagado != total)
                    {
                       printf("monto incorrecto: \n");
                        scanf("%f",&montpagado);
                    }
                        getch();
                        system("cls");

                        printf("fecha de su pago: %d/%d/%d\n",hora->tm_mday,hora->tm_mon,hora->tm_year+1900);
                        printf("fecha del venpimiento del pago: %d/%d/%d\n",hora->tm_mday,hora->tm_mon+1,hora->tm_year+1900);
                                dia = hora->tm_mday; mes = hora->tm_mon; anio = hora->tm_year+1900;
                                pago.fecha_pago = (anio*10000)+(mes*100)+dia;
                                if(mes == 12){
                                   diav=dia; mesv = 1; aniov = anio+1;
                                   pago.fecha_vencimiento = (aniov*10000) + (mesv+100) + diav;
                                }else if (mes < 12) {
                                  diav = dia; mesv = mes+1; aniov = anio;
                                  pago.fecha_vencimiento = (aniov*10000) + (mesv+100) + diav;
                                }
                    l->pago.fecha_pago = pago.fecha_pago;
                    l->pago.fecha_vencimiento = pago.fecha_vencimiento;
                    l->pago.deuda = 0;
                    l->pago.estado = 1;
                    l->pago.intereses = 0;
                  }
                   l = l->siguiente;
                 }

      if (band == 0){
         printf("No se encuentra el dni.\n");
         getch();
         main();
      }

                    if ((pgo=fopen("pagos.bin","r+b"))!=NULL)
                    {
                      fread(&pago,sizeof(pago),1,pgo);
                      while (!feof(pgo))
                      {
                        if (dni==pago.dni) {
                           pago.cuotaxm = l->pago.cuotaxm;
                           pago.deuda = l->pago.deuda;
                           pago.estado = l->pago.estado;
                           pago.fecha_pago = l->pago.fecha_pago;
                           pago.fecha_vencimiento = l->pago.fecha_vencimiento;
                           pago.intereses = l->pago.intereses;
                        }
                        fseek(pgo,sizeof(pago)*(-1),SEEK_CUR);
                        fwrite(&pago,sizeof(pago),1,pgo);
                        fseek(pgo,sizeof(pago),SEEK_END);

                        fread(&pago,sizeof(pago),1,pgo);
                      }
                      
                       fclose(pgo);
                    }else printf("error al abrir el archivo.\n");
                    
                
                  Tp = borrarLES(Tp);

 }
                      

void insertarpago(PagosNodo**nv,PagosNodo**ini){
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

PagosNodo* borrarLES(PagosNodo *ini){
PagosNodo *naux;
             if(ini != NULL){
                naux = ini;
                ini->siguiente = borrarLES(ini->siguiente);
                naux->siguiente = NULL;
                free(naux);
             }
            return(ini);
}






