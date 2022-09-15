#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include"estructuras.h"
#include"FuncionesArbol.h"

void insertarP(PagosNodo **, PagosNodo **);
void insertarC(Nodo **, Nodo **);
void insertarArbol(NodoArbol *,char *);
void recorrerIRD (NodoArbol *);

void crearArbol(){


time_t ahora; struct tm *hora;
time(&ahora);
hora = localtime(&ahora);
int dia,mes,anio,dni;
long int hoy;
int band=0,cont=0;
NodoArbol *raiz=NULL,*nuevo = NULL;
FILE *cli,*pgo; Pagos pago; Cliente cliente;
PagosNodo *lp=NULL,*np=NULL,*tp=NULL;
Nodo *lc=NULL,*nc=NULL,*tc=NULL;
                                  
                                printf("Arbol de Deudores, Mes de Mayo \n");
                                dia = hora->tm_mday+1; mes = hora->tm_mon+1; anio = hora->tm_year+1900;
                                hoy =(anio*10000) + (mes*100) + dia;
                                system("pause");
                                system("cls");
                                printf("fecha de hoy :%d/%d/%d \n",dia-1,mes,anio);

                              
                                if ((pgo=fopen("pagos.bin","r+b"))!=NULL)
                                {
                                    fread(&pago,sizeof(pago),1,pgo);
                                    while (!feof(pgo))
                                    {
                                        if (pago.estado==1) {
                                           if (pago.fecha_vencimiento < hoy)
                                           {
                                             pago.estado = 0;
                                           }
                                             fseek(pgo,sizeof(pago)*(-1),SEEK_CUR);
                                            fwrite(&pago,sizeof(pago),1,pgo);
                                            fseek(pgo,sizeof(pago),SEEK_END);

                                        }
                                       
                                      fread(&pago,sizeof(pago),1,pgo);
                                    }
                                    
                                    fclose(pgo);
                                }else printf("error al abrir el archivo.\n");
                                
                               
                                if ((pgo=fopen("pagos.bin","rb"))!=NULL){
                                    fread(&pago,sizeof(pago),1,pgo);
                                    while (!feof(pgo)){
                                    
                                      np=(PagosNodo*)malloc(sizeof(PagosNodo));
                                      if (np != NULL) {
                                           np->pago.dni = pago.dni;
                                           np->pago.estado = pago.estado;
                                           np->pago.cuotaxm = pago.cuotaxm;
                                           np->pago.deuda = pago.deuda;
                                           np->pago.fecha_pago = pago.fecha_pago;
                                           np->pago.fecha_vencimiento = pago.fecha_vencimiento;
                                           np->pago.intereses = pago.intereses;
                                           np->siguiente = NULL;
                                           insertarP(&np,&lp);
                                      }
                                      
                                     fread(&pago,sizeof(pago),1,pgo);
                                    }
                                    fclose(pgo);
                                }else printf("error al abrir el archivo.\n");
                                
                                if ((cli=fopen("Clientes.bin","rb"))!=NULL){
                                    fread(&cliente,sizeof(cliente),1,cli);
                                    while (!feof(cli)){
                                      
                                        nc =(Nodo*)malloc(sizeof(Nodo));
                                        if (nc != NULL)
                                        {
                                          nc->cliente.dni = cliente.dni;
                                          strcpy(nc->cliente.nomApe,cliente.nomApe);
                                          nc->cliente.cel = cliente.cel;
                                          nc->cliente.fecha_nac = cliente.fecha_nac;
                                          nc->siguiente = NULL;
                                          insertarC(&nc,&lc);
                                        }
                                        
                                     fread(&cliente,sizeof(cliente),1,cli);
                                    }
                                
                                   fclose(cli);
                                }else printf("error al abrir el archivo.\n");
                               
                                
                                tp = lp;
                                while (tp != NULL) {
                                        
                                    if (tp->pago.estado == 0){
                                        
                                          for(tc = lc; tc != NULL;tc = tc->siguiente){
                                           
                                          if (tp->pago.dni == tc->cliente.dni){
                                             if (raiz == NULL){
                                                 raiz = nuevoNodo("mmmmm");
                                               }
                                                insertarArbol(raiz,tc->cliente.nomApe);
                                            
                                          }
                                        }
                                        
                                      }
                                    
                                       tp = tp->siguiente;
                                     }
                                     
                                printf("nombres de los clientes deudores de mayo: \n");
                                   recorrerIRD(raiz);                       
                                 
 }

void insertarP(PagosNodo **nv, PagosNodo **ini){
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


void insertarC(Nodo **nv, Nodo **ini){
    Nodo *aux;
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

