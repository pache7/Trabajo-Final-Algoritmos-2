#ifndef crearcliente_c
#define crearcliente_c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"estructuras.h"

void insertarCli(Nodo**,Nodo**);
void eliminarNodo(Nodo*);
Nodo* borrarlista(Nodo *ini);
int main();

//void InsertarCli()
void crearcliente(){
 FILE *cli;
 Cliente clientes;
 Nodo *tope = NULL,*nuevo=NULL,*n=NULL;
                          fflush(stdin);
                          printf("ingrese el nombre del cliente: \n");
                                gets(clientes.nomApe);
                         fflush(stdin);
                          printf("ingrese el dni del cliente: \n");
                               scanf("%ld",&clientes.dni);
                          printf("ingrese el celular del cliente: \n");
                               scanf("%ld",&clientes.cel);
                         
                          printf("ingrese el fecha de nacimiento: \n");
                               scanf("%ld",&clientes.fecha_nac);
                               //cargo la lista
                               nuevo =(Nodo*)malloc(sizeof(Nodo));
                               if (nuevo != NULL) {
							      strcpy(nuevo->cliente.nomApe,clientes.nomApe);
							      nuevo->cliente.dni = clientes.dni;
							      nuevo->cliente.cel = clientes.cel;
							      nuevo->cliente.fecha_nac = clientes.fecha_nac;
							      nuevo->siguiente = NULL;
							      insertarCli(&nuevo,&tope);
							   }else{
								    printf("error de asignacion de memoria.\n");
							        }
										 //cargo desde la lista al archivo.
                                         for (n = tope ; n != NULL; n = n->siguiente) {
                                              if ((cli=fopen("Clientes.bin","a+b"))!=NULL){
                                                    strcpy(clientes.nomApe,n->cliente.nomApe);
                                                      clientes.dni = n->cliente.dni;
                                                      clientes.cel = n->cliente.cel;
                                                      clientes.fecha_nac = n->cliente.fecha_nac;
                                                      fwrite(&clientes,sizeof(clientes),1,cli);
                                                      fclose(cli);
                                                 }else printf("error al abrir el archivo.\n");
                                              }
											
                                                 //muetra lo que se copio desde la lista al archivo.
                                              /*   if ((cli=fopen("Clientes.bin","rb"))!=NULL) {
                                                          fread(&clientes,sizeof(clientes),1,cli);
                                                                while (!feof(cli)){
                                                                   printf("nombre:%s\tdni:%ld \n",clientes.nomApe,clientes.dni);

                                                                   fread(&clientes,sizeof(clientes),1,cli);
                                                                 }
                                                    fclose(cli);
                                                  }else printf("error al abrir el archivo.\n");*/
                                                     //carga desde el archivo a la lista.
                                                     
    // tope = borrarlista(tope);				   
	system("pause.\n");
     main();
}

void insertarCli(Nodo**nv,Nodo**ini){
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

Nodo* borrarlista(Nodo *ini){
Nodo *naux;
             if(ini != NULL){
                naux = ini;
                ini->siguiente = borrarlista(ini->siguiente);
                naux->siguiente = NULL;
                free(naux);
             }
            return(ini);
}

#endif


