#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"estructuras.h"



int main (){

    FILE *datarch;
    int dni,op;
    Datos dat;
    DatosNodo *p = NULL, *q = NULL, *nv = NULL;


printf("ingrese op \n\n");
    scanf ("%d",&op);

while (op == 1 ){


    if((datarch=fopen("datos","a+b"))!=NULL){
        printf("ingrese asis\n\n");
        scanf ("%d",&dat.asistencia);

        fwrite(&dat,sizeof(dat),1,datarch);
	    fclose(datarch);

        printf ("\t\t se guardo en el archivo ");
        system("pause");
    }
    fflush(stdin);
    printf("ingrese 0  para dejar de cargar \n\n");
    scanf ("%d",&op);

}






    if((datarch=fopen("datos","rb"))!=NULL){
                fread(&dat,sizeof(dat),1,datarch);
                while(!feof(datarch)){
                    printf ("asitencia es es %d ", dat.asistencia);
                    system("pause");
                    fread(&dat,sizeof(dat),1,datarch);




                }
    }else printf("no se pudo abrir");
}
