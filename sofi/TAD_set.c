#include "TAD_AST.h"
#include "TAD_set.h"

	int belongs(Tdata set, Tdata elem){
		Tdata aux = set;
		while(aux != NULL){
			if(equals_node(aux->data, elem)){
				return 1;
			}
			aux = aux->next;
		}
		return 0;
	}
		void remove_set(Tdata* set, Tdata elem){ //elem es str o set-list
			Tdata actual;
			Tdata anterior=NULL;
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
				Tdata resultado = NULL;
				
				// copiar A completo
				Tdata aux = A;
				while (aux != NULL) {
					insert_set(&resultado, copy_ast(aux->data));
					aux = aux->next;
				}
				// agregar elementos de B que no estén en A {0,1} {0,1,3}
				aux = B;
				while (aux != NULL) {
					if (belongs(resultado, aux->data)==0) {
						insert_set(&resultado, copy_ast(aux->data));
					}
					aux = aux->next;
				}
				return resultado;
			}
			Tdata intersection_set(Tdata A, Tdata B) {
				Tdata resultado = create_set();
				Tdata aux1;
				Tdata aux2;
				Tdata nuevo=NULL;
				
				if (esvacio(A)==0) {
					resultado = copy_ast(A);
				}else {
					if(esvacio(B) == 0) {
						resultado = copy_ast(B);
					}else {
						resultado = copy_ast(A);
						aux1 = A;
						while(aux1 != NULL) {
							aux2 = B;
							while(aux2 != NULL && belongs(aux1->data, aux2->data) == 0) {
								aux2 = aux2->next;
							}
							nuevo = create_set();
							nuevo->data = copy_ast(aux2->data);
							append(&resultado, nuevo);
							aux1 = aux1->next;
						}
					}
				}
				return resultado;
			}
			Tdata difference_set(Tdata A, Tdata B) { // Tomando el encuenta orede de los parametros de tipo A - B
				Tdata resultado=create_set();
				Tdata aux1;
				Tdata aux2;
				Tdata nuevo=NULL;
				if(esvacio(A) == 0 || esvacio(B) == 0){
					resultado = copy_ast(A);
				}else {
					resultado = copy_ast(A);
					aux1 = A;
					while(aux1 != NULL) {
						aux2 = B;
						while(aux2 != NULL && belongs(aux1->data, aux2->data) == 1) {
							aux2 = aux2->next;
						}
						nuevo = create_set();
						nuevo->data = copy_ast(aux2->data);
						append(&resultado, nuevo);
						aux1 = aux1->next;
					}
				}
				return resultado;
			} // son los elementos que pertenecen al primer conjunto y no pertenecen al segundo conjunto // son los elementos que pertenecen al primer conjunto y no pertenecen al segundo conjunto
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
			
