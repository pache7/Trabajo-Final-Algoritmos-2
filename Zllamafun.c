#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "asistencia.c"
//#include "bajacliente.c"

#include "listaespera.c"

int main   (){
    int sede,tipo,turno;
//printf ("llamado");
//    asistencia ();

printf ("ingrese sede       tipo        turno \n");
scanf ("%d",&sede);
scanf ("%d",&tipo);
scanf ("%d",&turno);

    listaespera (sede,tipo,turno);

}