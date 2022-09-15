#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"estructuras.h"
#include "mostraractividad.c"

void ListadeClientes(ListaClientes**,ListaClientes**);

void Listadeudores() {

//int main(){
    FILE  *datarch,*pgo;
    Pagos pago;
    Datos dat;
    ListaClientes  *l=NULL,*p=NULL,*r=NULL;

                                        if ((pgo=fopen("pagos.bin","rb"))!=NULL){
                                            if((datarch=fopen("datos.bin","rb"))!=NULL){
                                                fread(&pago,sizeof(pago),1,pgo);
                                                fread(&dat,sizeof(dat),1,datarch);
                                                     while (!feof(pgo)){
                                                        while (!feof(datarch)){
                                                            p =(ListaClientes*)malloc(sizeof(ListaClientes));
                                                             if (p != NULL)
                                                             {
                                                               p->datocli.sede = dat.sede;
                                                               p->datocli.tipo = dat.tipo;
                                                               p->datocli.turno = dat.turno;
                                                               p->deuda.estado = pago.estado;
                                                               p->deuda.deuda = pago.deuda;
                                                               p->siguiente = NULL;
                                                               
                                                               ListadeClientes(&p,&l);
                                                             }
                                                             
                                                          fread(&dat,sizeof(dat),1,datarch);
                                                        }
                                                      fread(&pago,sizeof(pago),1,pgo);
                                                     }
                                                     
                                                 fclose(datarch);
                                            }else printf("error al abrir el archivo.\n");
                                            fclose(pgo);
                                         }else printf("error al abrir el archivo.\n");
                            
                                               for (r = l; r != NULL; r = r->siguiente){
                                                     printf("sede: %d\n",r->datocli.sede);
                                                     printf("turno: %d \n",r->datocli.turno);
                                                     printf("actividad:%d\n",r->datocli.tipo);
                                                     printf("estado de deuda:%d\n",r->deuda.estado);
                                                     printf("total de deuda:%d\n",r->deuda.deuda);
                                                }
                                               printf("Descripcion de las actividades:\n");
                                               mostraractividad();

}


void ListadeClientes(ListaClientes**nv,ListaClientes**ini){

ListaClientes *aux;
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





