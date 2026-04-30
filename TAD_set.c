#include "TAD_AST.h"
#include "TAD_set.h"
void insert_set(Tdata* set, Tdata elem){ //insertar un elemento en un conjunto sin duplicados
	Tdata aux;
	if(belongs(*set,elem)==0){
		if(esvacio(*set)==1){
		(*set)=copy_ast(elem);
		}
		else{
			aux=*set;
			while(aux->next!=NULL){
			aux=aux->next;
			}
			aux->next=copy_ast(elem);
		}
	}
}
int belongs(Tdata set, Tdata elem){ // devuelve 1 si cuando pertenece al conjunto
	Tdata aux = set;
	while(aux != NULL && equals_node(aux->data, elem) == 0){
		aux = aux->next;
	}
	if(aux == NULL) {
		return 0;
	}else {
		return 1;
	}
}
void remove_set(Tdata* set, Tdata elem){ //elem es str o set-list
	Tdata actual;
	Tdata anterior = NULL;
	if(esvacio(*set)==1){
		printf("\nEl conjunto es vacio, no se pudo eliminar elemento");
	}else{
		actual=*set;
		while(actual->next!=NULL && !equals_node(actual->data,elem)){ // funcion generica
			anterior=actual;
			actual=actual->next;
		}
		if(actual->data==elem->data){ //elemento a eliminar encontrado, se debe eliminar
			if(anterior==NULL){
				eliminarprimero(set);
			}
			else{
				anterior->next=actual->next;
				free(actual);
				actual=NULL;
			}
		}else{
			printf("\nElemento no encontrado");
		}
	}
}
Tdata unionset(Tdata A, Tdata B) { 
	Tdata resultado = create_set();
	Tdata aux;
	
	if(esvacio(A) == 1 && esvacio(B) == 1) {
		printf("\nConjuntos vacios ");
		return NULL;
	}
	
	if(esvacio(A) == 1 && esvacio(B) == 0) { // Si A es vacio y B no, devuelvo B
		aux = B;
		while(aux != NULL){
			insert_set(&resultado, copy_ast(aux->data));
			aux = aux->next;
		}
	}
	
	if(esvacio(B) == 1 && esvacio(A) == 0) { // Si B es vacio y A no, devuelvo A
		aux = A;
		while(aux != NULL){
			insert_set(&resultado, copy_ast(aux->data));
			aux = aux->next;
		}
	}
	
	aux = A;
	while(aux != NULL){
		insert_set(&resultado, copy_ast(aux->data));
		aux = aux->next;
	}
	
	// Agregar B sin duplicados
	aux = B;
	while(aux != NULL){
		if(belongs(resultado, aux->data) == 0){
			insert_set(&resultado, copy_ast(aux->data));
		}
		aux = aux->next;
	}
	
	return resultado;
}
Tdata intersection_set(Tdata A, Tdata B) {
	Tdata resultado = create_set();
	Tdata aux;
	
	if(esvacio(A) == 1 || esvacio(B) == 1) { // Si A o B no tienen elementos
		printf("\nInterseccion vacia, NO se puede reslizar la interseccion");
		return NULL;
	}
	// Si A y B tiene elementos aplico porp. de interseccion
	aux = A;
	while(aux != NULL) {
		if(belongs(B, aux->data) == 1) {
			insert_set(&resultado, copy_ast(aux->data));
		}
		aux = aux->next;
	}
	return resultado;
}
Tdata difference_set(Tdata A, Tdata B) { // Tomando el encuenta orede de los parametros de tipo A - B
	Tdata resultado = create_set();
	Tdata aux = A;
	
	if(esvacio(A) == 1) {
		printf("\nConjunto vacio, NO se puede reslizar la diferencia");
		return NULL;// Si A y B tiene elementos aplico porp. de diferencia
	}
	
	if(esvacio(B) == 1) {
		while(aux != NULL){
			insert_set(&resultado, copy_ast(aux->data));
			aux = aux->next;
		}
		//inserter_set(&resultado, copy_ast(A));
		return resultado;
	}
	
	while(aux != NULL) {
		if(belongs(B, aux->data) == 1) {
			insert_set(&resultado, copy_ast(aux->data));
		}
		aux = aux->next;
	}
	return resultado;
}
 // son los elementos que pertenecen al primer conjunto y no pertenecen al segundo conjunto // son los elementos que pertenecen al primer conjunto y no pertenecen al segundo conjunto
int equals_set(Tdata A, Tdata B) {
	int a_en_b = subset(A, B);
	int b_en_a = subset(B, A);
	if (a_en_b == 1 && b_en_a == 1) {//Si A esta contenida en B y B esta contenida en A, entonces son iguales
		return 1;
	} else {
		return 0;
	}
}
int subset(Tdata A, Tdata B) {
	Tdata auxA = A;
	while (auxA != NULL) {
		if (search(B, auxA->data) == 0) {//Busca el elemento en la lista 
			return 0;//El elemento no esta en el conjunto 
		}
		auxA = auxA->next;
	}
	return 1; //Todos los elementos de B estan en A
}
int subset(Tdata A, Tdata B) {
				if (A == NULL || A->data == NULL)
					return 1; // conjunto vacío cualquier conjunto
				if (B == NULL || B->data == NULL)
					return 0; // conjunto no vacío no puede estar en vacío
				Tdata auxA = A->data;
				int compara;
				while (auxA != NULL) {
					//printf("%d",belongs(B, auxA->data));
					while(aux != NULL && equals_node(B->data, auxA->data) == 0){
						aux = aux->next;
					}
					if (aux != NULL) {//Busca el elemento en la lista 
						printf("\n");
						return 0;//El elemento no esta en el conjunto 
					}
					auxA = auxA->next;
				}
				return 1; // Todos los elementos de A están en B
			}

