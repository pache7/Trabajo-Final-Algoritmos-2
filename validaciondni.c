#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"estructuras.h"
#include "crearcliente.c"

void insertarvalidacion(Nodo**,Nodo**);


//int main (){
void validaciondni (){
 FILE *cli;
 Cliente cl;
 Nodo *p = NULL,*r=NULL,*nv=NULL;
 int dni,ban;


    if ((cli=fopen("Clientes.bin","rb"))!=NULL){

                    fread(&cl,sizeof(cl),1,cli);
                        while (!feof(cli)){

                                nv =(Nodo*)malloc(sizeof(Nodo));
                                    if (nv != NULL) {
                                        nv->cliente.dni=cl.dni;
                                        nv->cliente.cel=cl.cel;
                                        nv->cliente.fecha_nac=cl.fecha_nac;
                                        strcpy(nv->cliente.nomApe,cl.nomApe);

                                        nv->siguiente = NULL;

                                        insertarvalidacion(&nv,&p);
                                        printf ("   se cargo la lista de clientes     ");
                                     }
                                      fread(&cl,sizeof(cl),1,cli);
                        }
                                      fclose(cli);
        }else printf("no se pudo abrir el archivo.\n");

system("cls");

printf ("\t\n\n Ingrese su DNI\n\n");
scanf ("%d",&dni);
r=p;
ban = 0;

    while ( r !=NULL){
        if (dni == r->cliente.dni){
            
            printf ("\n\n");
            printf ("Posee Usuario, puede proseguir");
            printf ("\n\n");
            ban = 1;
            break;
        
        } 
        r=r->siguiente;
    }    

     r=p;

if (ban == 0){
            printf ("\n\n");
            printf ("No posee Usuario, debera crear uno ");
            printf ("\n\n");

            crearcliente();

    } 


}

void insertarvalidacion(Nodo**nv,Nodo**ini){
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
		printf("*inserto");
}
