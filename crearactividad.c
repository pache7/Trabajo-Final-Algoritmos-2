#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estructuras.h"

//int main (){
void crearactividad(){
    FILE *archacti;
    Actividades acti;
    NodoActi *p = NULL, *q = NULL, *nv = NULL, *r = NULL;
    int opc;

        if((archacti=fopen("Actividades.bin","rb"))!=NULL){
                fread(&acti,sizeof(acti),1,archacti);
                while(!feof(archacti)){
                    nv = ( NodoActi *) malloc(sizeof(NodoActi));
                        if(nv!=NULL){
                            nv->acti.tipo = acti.tipo;
                            strcpy(nv->acti.descripcion,acti.descripcion);


                            nv->siguiente = NULL;

                            nv->siguiente = p;
                            p = nv;
                            nv = NULL;

                            //p tiene fin de lista acti
                            printf("se cargo lista actividad con exito\n\n");

                        }else{
                            printf("ERROR DE ASIGNACION DE MEMORIA ACTIVIDAD");
                        }
                    fread(&acti,sizeof(acti),1,archacti);
                    }
            fclose(archacti);
        }
    //p tiene fin

    q=p;

system ("cls");
     nv = ( NodoActi *) malloc(sizeof(NodoActi));
        if(nv!=NULL){
            printf("\t\n\ningrese el tipo de la actividad.\n\n");
            scanf ("%d",&nv->acti.tipo);
            printf("\tingrese nombre de la actividad.\n");
            fflush(stdin);
            gets(nv->acti.descripcion);

            nv->siguiente = NULL;

            nv->siguiente = p;
            p = nv;
            nv = NULL;

            printf("se cargo lista con exito\n\n");




        } else { printf ("error");}

    if((archacti=fopen("Actividades.bin","a+b"))!=NULL){
            acti.tipo = p->acti.tipo;
            strcpy(acti.descripcion,p->acti.descripcion);


            fwrite(&acti,sizeof(acti),1,archacti);
	        fclose(archacti);

            printf ("\t\t se guardo en el archivo ");
    }

     printf ("\t\t Se a creado la actividad con exito ");
    crearactividad();

}
