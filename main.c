#include "TAD_AST.h"
int main(){
	
	Tdata lista = create_list();
	
	Tdata s1 = create_str();
	s1->string = load2("hola");
	
	Tdata s2 = create_str();
	s2->string = load2("mundo");
	
	Tdata s3 = create_str();
	s3->string = load2("test");
	
	append(&lista, s1);
	append(&lista, s2);
	append(&lista, s3);
	Tdata lista2= create_list();
	Tdata s6 = create_str();
	s6->string = load2("hola");
	
	Tdata s4 = create_str();
	s4->string = load2("mundo");
	
	Tdata s5 = create_str();
	s5->string = load2("test");
	append(&lista2, s4);
	append(&lista2, s5);
	append(&lista2, s6);
	append(&lista,lista2);
	mostrarArbol(lista);
	printf("\n");
	
	return 0;
}
	
