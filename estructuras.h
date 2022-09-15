#ifndef estructuras_h
#define estructuras_h

typedef struct clientes
{
  char nomApe[30];
   int dni;
   int cel;
  long int fecha_nac;
}Cliente;

typedef struct Nodo {
    Cliente cliente;
    int tam;
    struct Nodo* siguiente;
}Nodo;











typedef struct Datos
{
  int dni;
  int sede;
  int tipo;
  int turno;
  float montoxm;
  long int f_pago;
  int dias;
  int asistencia;
  long int f_baja;
  int reserva;
  
}Datos;

typedef struct DatosNodo
{
    Datos  datos;
    struct DatosNodo* siguiente;
}DatosNodo;











typedef struct Actividades
{
    int tipo;
    char descripcion[30];
}Actividades;

typedef struct NodoActi
{
    Actividades acti;
    struct NodoActi* siguiente;
}NodoActi;










typedef struct Pagos
{
    int dni;
    long int fecha_pago;
    long int fecha_vencimiento;
    float cuotaxm;
    float deuda;
    int estado;
    float intereses;
}Pagos;
typedef struct PagosNodo
{
    Pagos pago;
    struct PagosNodo* siguiente;
}PagosNodo;













typedef struct Profesores
{
    char profnom[30];
     int dni;
     int ncel;
}Profesores;

typedef struct ProfeNodo{
  Profesores profe;
  struct ProfeNodo* siguiente;
}ProfeNodo;











typedef struct Rerserva
{
 int tipo;
 int sede;
 int turno;
 int dni;
 int ncel;
 int reserva;
}Rerserva;


typedef struct NodoReserva{
    Rerserva reser;
    struct NodoReserva *siguiente;
}NodoReserva;














typedef struct Turnos
{
    int sede;
    int tipo;
    int turno;
    char descripcion[30];
    int dias;
    int cupo;
    int lugares;
    int espera;
    float montoxd;
    float montoxm;
    int dni_prof;
    char n_prof[30];
}Turnos;




typedef struct TurnosNodo{
     Turnos turno;
     struct TurnosNodo *siguiente;
}TurnosNodo;



typedef struct ListaClientes{
    Pagos deuda;
    Datos datocli;
    struct ListaClientes* siguiente;
}ListaClientes;


#define maxima_longitud_cadena 50

typedef struct NodoArbol{
    char cadena[maxima_longitud_cadena];
    struct NodoArbol *izq;
    struct NodoArbol *der;

}NodoArbol;

#endif












