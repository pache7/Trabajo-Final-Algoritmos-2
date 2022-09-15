#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estructuras.h"


void crearturno (){
//int main (){
    FILE *archtur;
    Turnos tur;
    TurnosNodo *p = NULL, *q = NULL, *nv = NULL, *r = NULL;
    

     nv = ( TurnosNodo *) malloc(sizeof(TurnosNodo));
        if(nv!=NULL){
            printf("\t\n\nIngrese la sede para la actividad.\n\n");
            scanf ("%d",&nv->turno.sede);
            printf("\t\n\nIngrese tipo de la actividad.\n\n");
            scanf ("%d",&nv->turno.tipo);
            printf("\t\n\nIngrese numero de turno.\n\n");
            scanf ("%d",&nv->turno.turno);
            printf("\t\nIngrese la cantidad de dias para el turno.\n\n");
            scanf ("%d",&nv->turno.dias);
            printf("\t\n\nIngrese los lugares para este turno.\n\n");
            scanf ("%d",&nv->turno.lugares);
            nv->turno.cupo = nv->turno.lugares;
            nv->turno.espera = 0;
            nv->turno.dni_prof = 0;
            printf("\t\n\nIngrese el monto por dia para el turno.\n\n");
            scanf ("%f",&nv->turno.montoxd);
           

            nv->turno.montoxm = nv->turno.dias * 4 * nv->turno.montoxd;
            printf("\tEl monto por mes sera %f\n\n",nv->turno.montoxm);
            printf("\t\n\nIngrese los horarios para el turno.\n\n");
            fflush(stdin);
            gets(nv->turno.descripcion);

            nv->siguiente = NULL;

            nv->siguiente = p;
            p = nv;
            nv = NULL;

            printf("se cargo lista con exito\n\n");




        } else { printf ("error");}

    if((archtur=fopen("turnos.bin","a+b"))!=NULL){
        tur.sede = p->turno.sede;
        tur.tipo = p->turno.tipo;
        tur.turno = p->turno.turno;
        tur.dias = p->turno.dias;
        tur.cupo = p->turno.cupo;
        tur.lugares = p->turno.lugares;
        tur.espera = p->turno.espera;
        tur.montoxd = p->turno.montoxd;
        tur.montoxm = p->turno.montoxm;
        tur.dni_prof = p->turno.dni_prof;
        strcpy(tur.descripcion,p->turno.descripcion);
        strcpy(tur.n_prof,p->turno.n_prof);

            fwrite(&tur,sizeof(tur),1,archtur);
	        fclose(archtur);

    printf ("\t\t se guardo en el archivo ");
    }



}


