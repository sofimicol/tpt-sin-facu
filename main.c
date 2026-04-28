#include "TAD_AST.h"

int main() {
	
	// Crear lista
	Tdata lista = create_list();
	
	// Crear strings
	Tdata s1 = create_str();
	s1->string = load2("hola");
	
	Tdata s2 = create_str();
	s2->string = load2("mundo");
	
	Tdata s3 = create_str();
	s3->string = load2("test");
	
	// Insertar en lista
	append(&lista, s1);
	append(&lista, s2);
	append(&lista, s3);
	
	// Mostrar resultado
	mostrarArbol(lista);
	
	printf("\n");
	
	return 0;
}
	
