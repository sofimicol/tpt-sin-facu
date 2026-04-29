#include "TAD_ast.h"
#include "TAD_LISTA.h"
#include "TAD_STR.h"

#include "TAD_ast.h"
#include "TAD_LISTA.h"
#include "TAD_STR.h"

int main() {
	
	// =========================
	// CASO 1: LISTA SIMPLE
	// =========================
	printf("===== CASO 1: LISTA SIMPLE =====\n");
	
	Tdata L1 = NULL;
	
	Tdata a = create_str();
	a->string = load2("hola");
	
	Tdata b = create_str();
	b->string = load2("mundo");
	
	Tdata c = create_str();
	c->string = load2("test");
	
	L1 = create_list();
	append(&L1, a);
	append(&L1, b);
	append(&L1, c);
	
	printf("L1 = ");
	mostrarArbol(L1);
	printf("\n\n");
	
	
	// =========================
	// CASO 2: LISTA DE LISTAS
	// =========================
	printf("===== CASO 2: LISTA DE LISTAS =====\n");
	
	Tdata sub1 = NULL;
	
	Tdata x = create_str();
	x->string = load2("A");
	
	Tdata y = create_str();
	y->string = load2("B");
	
	sub1 = create_list();
	append(&sub1, x);
	append(&sub1, y);
	
	Tdata sub2 = NULL;
	
	Tdata z = create_str();
	z->string = load2("C");
	
	sub2 = create_list();
	append(&sub2, z);
	
	Tdata L2 = NULL;
	L2 = create_list();
	append(&L2, sub1);
	append(&L2, sub2);
	
	printf("L2 = ");
	mostrarArbol(L2);
	printf("\n\n");
	
	
	// =========================
	// CASO 3: LISTA VACÍA
	// =========================
	printf("===== CASO 3: LISTA VACÍA =====\n");
	
	Tdata L3 = NULL;
	
	printf("L3 = ");
	mostrarArbol(L3);
	printf("\n\n");
	
	
	// =========================
	// CASO 4: LISTA ANIDADA PROFUNDA
	// =========================
	printf("===== CASO 4: LISTA ANIDADA =====\n");
	
	Tdata deep = create_str();
	deep->string = load2("nivel1");
	
	Tdata Ldeep = NULL;
	Ldeep = create_list();
	append(&Ldeep, deep);
	
	Tdata Ldeep2 = NULL;
	Ldeep2 = create_list();
	append(&Ldeep2, Ldeep);
	
	printf("Ldeep = ");
	mostrarArbol(Ldeep2);
	printf("\n\n");
	
	
	// =========================
	// CASO 5: CONCATENACIÓN
	// =========================
	printf("===== CASO 5: CONCATENACIÓN =====\n");
	
	Tdata L5 = concatena_list(L1, L2);
	
	printf("L1 + L2 = ");
	mostrarArbol(L5);
	printf("\n\n");
	
	
	// =========================
	// CASO 6: PRODUCTO CARTESIANO
	// =========================
	printf("===== CASO 6: PRODUCTO CARTESIANO =====\n");
	
	Tdata P = prod_cartesiano(L1, L1);
	
	printf("L1 x L1 = ");
	mostrarArbol(P);
	printf("\n\n");
	
	
	// =========================
	// CASO 7: SEARCH
	// =========================
	printf("===== CASO 7: SEARCH =====\n");
	
	Tdata buscado = create_str();
	buscado->string = load2("mundo");
	
	printf("Buscar 'mundo': %d\n", search(L1, buscado));
	
	Tdata no = create_str();
	no->string = load2("noexiste");
	
	printf("Buscar 'noexiste': %d\n", search(L1, no));
	// =========================
	// CASO 8: CONJUNTO ANIDADO
	// =========================
	printf("===== CASO 8: CONJUNTO ANIDADO =====\n");
	
	// Crear elementos simples
	Tdata s1 = create_str();
	s1->string = load2("uno");
	
	Tdata s2 = create_str();
	s2->string = load2("dos");
	
	Tdata s3 = create_str();
	s3->string = load2("tres");
	
	// Crear una lista interna [A,B]
	Tdata la = create_str();
	la->string = load2("A");
	
	Tdata lb = create_str();
	lb->string = load2("B");
	
	Tdata lista_interna = create_list();
	append(&lista_interna, la);
	append(&lista_interna, lb);
	
	// Crear un conjunto interno {uno,dos}
	Tdata set_interno = create_set();
	insert_set(&set_interno, s1);
	insert_set(&set_interno, s2);
	
	// Crear conjunto principal
	Tdata conjunto = create_set();
	
	// Insertar elementos simples
	insert_set(&conjunto, s3);
	
	// Insertar estructura anidada
	insert_set(&conjunto, set_interno);
	insert_set(&conjunto, lista_interna);
	
	printf("Conjunto anidado = ");
	mostrarArbol(conjunto);
	printf("\n\n");
	printf("\n===== FIN DE PRUEBAS =====\n");
	
	return 0;
}
