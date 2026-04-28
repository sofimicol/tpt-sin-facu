#include "TAD_AST.H"
#include "TAD_LIST.H"
#include "TAD_STR.H"

int length(Tdata list) { // Calcula el tamanio de lalista
	int c = 0; // Contador
	Tdata aux = list; // Auxiliar (opcional) para despalzarce
	
	while(aux != NULL) { // Desplazamiento
		c++;
		aux = aux->next;
	}
	
	return c; // Tamanio de la lista
}

Tdata concatena_list(Tdata L1, Tdata L2) { 
	Tdata resultado = create_list(); // Declaro set
	Tdata fin = resultado;
	Tdata nuevo;
	if(esvacio(L1) == 0 && esvacio(L2) == 0) {
		resultado = copy_ast(L1);
		
		while(fin->next != NULL) {
			fin = fin->next;
		}
		while(L2 != NULL) {
			nuevo = create_list();
			nuevo->data = copy_ast(L2); //{0,1}
			//append
			fin->next = nuevo;
			fin = nuevo;
			
			L2 = L2->next;
		}
	}else {
		if(esvacio(L1) == 1) {
			resultado = copy_ast(L1);
			
		}else {
			if(esvacio(L2) == 1){
				resultado = copy_ast(L2);
			}
			else{
				resultado=NULL;
			}
		}
	}
	return resultado;
}

int search(Tdata list, Tdata elem){
	Tdata aux = list;
	while (aux != NULL) {
		if (equals_node(aux->data, elem)==1) { //Comparo los nodos
			return 1; // El elemento se ecnontro en la lista
		}
		aux = aux->next; //Contuinua el ciclo hasta que se termine la lista
	}
	return 0; //El elemento no se encontro 
}

