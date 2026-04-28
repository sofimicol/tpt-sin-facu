#ifndef TAD_STR_H
#define TAD_STR_H
#include <stdio.h>
#include <stdlib.h>

//estructura de lista enlazada
typedef struct Nodo{
	char data;
	struct Nodo*next;
}Tnodo;
typedef Tnodo*str;
str create_str_ast(); //crea una estructura de tipo str
str load();//insertar una lista de caracteres por consola 
str load2(const char*);
void print (str);
str concat(str,str);
void free_str(str);
int compare_str(str cad1, str cad2);
str copy_str(str original);
void append_str(str*cabeza, str nuevo);
str create_nodo(char c);
#endif
