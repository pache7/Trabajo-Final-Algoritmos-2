#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"estructuras.h"

float actualizardeudores(){
time_t ahora; struct tm *hora;
time(&ahora);
hora = localtime(&ahora);
int dia,mes,anio,dni;
long int hoy;
FILE *pgo;
Pagos pago;
float debe = 0;

                 printf("ingrese la fecha de hoy: \n");
                 dia = hora->tm_mday+1; mes = hora->tm_mon+1; anio = hora->tm_year+1900;
                 getch();
                 system("cls");
                 printf("fecha de hoy : %d/%d/%d\n",hora->tm_mday+1,hora->tm_mon+1,hora->tm_year+1900);
                 hoy = (anio*10000) + (mes*100) + dia;
                 printf("ingrese dni :\n");
                 scanf("%d",&dni);

                if((pgo=fopen("pagos.bin","r+b"))!=NULL){
                     fread(&pago,sizeof(pago),1,pgo);
                     while (!feof(pgo)){
                       if (dni==pago.dni ){
                          if (pago.fecha_vencimiento < hoy)
                          {
                             pago.intereses = (pago.cuotaxm*0.1);
                             pago.deuda = pago.cuotaxm + pago.intereses;
                             debe = pago.deuda;
                             printf("cuota con interes :%.2f \n",pago.deuda);
                          }
                          if (hoy < pago.fecha_vencimiento)
                          {
                            debe = pago.cuotaxm;
                             printf("cuota sin interes :%.2f \n",debe);
                          }
                          
                       }
                       
                       fread(&pago,sizeof(pago),1,pgo);
                     }

                         fseek(pgo,sizeof(pago)*(-1),SEEK_CUR);
                         fwrite(&pago,sizeof(pago),1,pgo);
                         fseek(pgo,sizeof(pago),SEEK_END);
                       
                       fread(&pago,sizeof(pago),1,pgo);
                     
                     
                    fclose(pgo);
                }else printf("error al abrir el archivo.\n");
                  printf("debe :%.2f \n",debe);
        return debe;
}