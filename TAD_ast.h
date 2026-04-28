#ifndef TAD_AST_H
#define TAD_AST_H
#include <stdio.h>
#include <stdlib.h>
#include "TAD_STR.h"
#define STR 1
#define SET 2
#define LIST 3

typedef struct dataType{
	int nodeType;   /* 1 STR, 2 SET, 3 LIST */
	union{
		str string; 
		struct{
			struct dataType* data; // puntero a una estructura que contiene un dato
			struct dataType* next; // puntero a siguiente
		};
	};
}TNodo;
typedef TNodo*Tdata; // Tdata es un Puntero a un arbol
Tdata create_str();
Tdata create_set();
Tdata prod_cartesiano(Tdata, Tdata);
Tdata cargar_conjunto();
Tdata carga_lista();
Tdata create_list();
void mostrarArbol(Tdata);
Tdata copy_ast(Tdata);
Tdata create_gen(int);
int esvacio(Tdata);
Tdata create_ast();
int equals_node(Tdata, Tdata);
Tdata copy_ast(Tdata list);
void eliminarprimero(Tdata* set);
#endif
