#ifndef FuncionesArbol_h
#define FuncionesArbol_h

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include"estructuras.h"

NodoArbol *nuevoNodo(char cadena[maxima_longitud_cadena]);
void insertarArbol(NodoArbol *,char *);
void recorrerIRD (NodoArbol *);


NodoArbol *nuevoNodo(char cadena[maxima_longitud_cadena]){
     NodoArbol *nodo;
     nodo =(NodoArbol*)malloc(sizeof(NodoArbol));
     strcpy(nodo->cadena,cadena);
     nodo->izq = nodo->der = NULL;
     return nodo;
}



void insertarArbol(NodoArbol *r, char *cadena){

    if (strcmp(cadena,r->cadena)==0)
    {
      printf("La cadena ya se encuentra en el arbol.\n");
    }
    
    if (strcmp(cadena,r->cadena) > 0)
    {
       if (r->der == NULL)
       {
          r->der = nuevoNodo(cadena);
          
       }else {
            insertarArbol(r->der,cadena); 
       }
       
    }else {

          if (r->izq == NULL)
          {
             r->izq = nuevoNodo(cadena);
          }else {
               insertarArbol(r->izq,cadena);
          }

    }
    
}

void recorrerIRD (NodoArbol *raiz){
       if(raiz != NULL) {
             recorrerIRD(raiz->izq);
             printf("%s \n", raiz->cadena);
             recorrerIRD(raiz->der);
        }

}







#endif