#include "TAD_ast.h"

Tdata copia_ast(Tdata elemento);
int esvacio(Tdata ast);
Tdata create_str(){ 
	Tdata str = malloc(sizeof(struct dataType));
	str->nodeType = 1;
	str->string = NULL;
	return str;
}

	Tdata create_set(){
		Tdata set =(Tdata)malloc(sizeof(TNodo));
		set->nodeType = 2;
		set->data = NULL;
		set->next = NULL;
		return set;
	}
		Tdata create_list(){
			Tdata list = (Tdata)malloc(sizeof(TNodo));
			list->nodeType = 3;
			list->data = NULL;
			list->next = NULL;
			return list;
		}
			
			Tdata create_gen(int tipo){ // Selector de tipos de datos
				Tdata gen;
				switch (tipo) {
				case 1:
					gen=create_str();
					break;
				case 2:
					gen=create_set();
					break;
				case 3:
					gen=create_list();
					break;
				}
				return gen;
			}
				int esvacio(Tdata ast){
					if (ast==NULL){
						return 1; //1 si es vacio
					}else{
						return 0;
					}
				}
			
					Tdata create_ast(){
						Tdata data;
						int tipo;
						do{ // verifica que se esten ingresando numeros dentro del rango solicitado entre 1 y 3
							printf("\nIngrese el tipo de dato que quiere ingresar: [1] str, [2] set y [3] list");
							scanf("%d",&tipo);
						} while(tipo < 1 || tipo > 3);
						
						data = create_gen(tipo); // Devuelve el dato correspondiente.
						
						switch(tipo) {
						case 1:
							data->string = load(); // solo strings
							break;
						/*case 2:
							data->data = cargar_conjunto(); // o lo que corresponda
							break;*/
						case 3:
							data->data = carga_lista();
							break;
						}
						data->next = NULL; 
						return data;
					}
						Tdata cargar_conjunto(){
							Tdata arbol;
							arbol=create_set();
							Tdata elem;
							int opcion;
							opcion=1;
							do{
								elem=create_ast();
								insert_set(&arbol,elem); //{1,{0,1},[1]}
								printf("\nIngrese el 0 para terminar");
								scanf("%d",&opcion);
							} while(opcion!=0);
							return arbol;
						}
							
							/*Tdata copia_ast(Tdata elemento){  //[1,{0,1},[1]]
							Tdata ast;
							if(!esvacio(elemento)){
							ast=(Tdata)malloc(sizeof(TNodo));
							ast->nodeType=elemento->nodeType;// numero que representa el tipo de dato a almacenar 
							switch(elemento->nodeType){
							case 1: ast->string=copy_str(elemento->string); break;
							case 2: ast->data=copy_ast(elemento>data); break;
							case 3: ast->data=copy_ast(elemento>data); break;
							}
							
							return ast;
							}
							else{
							return NULL;
							}
							}*/
							//posible ast
						int equals_node(Tdata n1, Tdata n2) { //retorna 1 si son iguales 
							if (n1 == NULL && n2 == NULL){ 
								return 1;
							}else {
								if(n1 == NULL || n2 == NULL){
									return 0;
								}else { 
									if (n1->nodeType != n2->nodeType){
										return 0;
									}else {
										if (n1->nodeType == 1) { 
											return compare_str(n1->string, n2->string); 
											
										} else { // Comparación estructural para Listas/Conjuntos
											if(equals_node(n1->data, n2->data) && equals_node(n1->next, n2->next)==1){
												return 1;
											}else{
												return 0;
											}
										}
									}
								}
							}
						}
							Tdata copy_ast(Tdata list) {//Copia una lista y la retorna  [1,{0,1},[1]]
								Tdata nuevo;
								if (list == NULL) { // Verifica que la lista no este vacia
									return NULL;
								}
								nuevo=NULL;
								if (list->nodeType == 1) {
									nuevo=create_str();
									nuevo->string = copy_str(list->string);  
							
								} else { //Si el elemento es una lista o conjunto entonces tiene mas elementos por lo que llamo a la misma funcion con el sig elem anidado
									if(list->nodeType == 2){
										nuevo=create_set();
										nuevo->data = copy_ast(list->data); 
										nuevo->next = copy_ast(list->next);
									}
									else{
										nuevo=create_list();
										nuevo->data = copy_ast(list->data); 
										nuevo->next = copy_ast(list->next);
									}
								}
								return nuevo; //Retorno el nuevo arbol 
							}	
							void eliminarprimero(Tdata* set){
								Tdata aux;
								if(*set!=NULL){
									aux=*set;
									(*set)=(*set)->next;
									free(aux);
								}
							}
								
								
								Tdata carga_lista(){
									Tdata arbol;
									arbol=create_list();
									Tdata elem;
									int opcion;
									opcion=1;
									do{
										elem=create_ast();
										append(&arbol,elem);
										printf("\nIngrese el 0 para terminar");
										scanf("%d",&opcion);
									} while(opcion!=0);
									return arbol;
								}
									void mostrarArbol(Tdata arbol) {
									if(arbol!=NULL){
										switch (arbol->nodeType) {
										case 1:
											print(arbol->string);
											break;
											
										case 2:
											printf("{");
											while (arbol != NULL && arbol->nodeType == 2) {
												mostrarArbol(arbol->data);
												arbol = arbol->next;
												if (arbol != NULL)
													printf(",");
											}
											printf("}");
											break;
											
											case 3:
												printf("[");
												Tdata aux = arbol->data;   // ?? ESTO es la lista real
												
												while (aux != NULL) {
													mostrarArbol(aux->data);
													aux = aux->next;
													if (aux != NULL) printf(",");
												}
												
												printf("]");
												break;
										}
									}else{
										printf("\nVacio");
									} 
									}
									Tdata prod_cartesiano(Tdata a, Tdata b) {
										if (a == NULL || b == NULL || a->data == NULL || b->data == NULL) 
											return create_list();
										
										Tdata prod = create_list();
										Tdata auxa = a->data; // Recorremos los eslabones de la lista A
										
										while (auxa != NULL) {
											Tdata auxb = b->data; // Recorremos los eslabones de la lista B
											while (auxb != NULL) {
												// Creamos un nuevo "par": [elementoA, elementoB]
												Tdata par = create_list();
												append(&par, auxa->data); // Metemos el elemento de A
												append(&par, auxb->data); // Metemos el elemento de B
												
												// Añadimos ese par a la lista de resultados
												append(&prod, par);
												
												auxb = auxb->next;
											}
											auxa = auxa->next;
										}
										return prod;
									}
										void append(Tdata* list, Tdata elem) {
											
											if (elem != NULL){
												
												Tdata nuevo = create_list();          
												nuevo->data = copy_ast(elem);         
												nuevo->next = NULL;
												
												if ((*list)->data == NULL) {
													(*list)->data = nuevo;
												}
												else{
													Tdata aux = (*list)->data;
													while (aux->next != NULL) {
														aux = aux->next;
													}
													
													aux->next = nuevo;
												}
											}else{
												printf("\nLista vacia");
											}
										}
										void insert_set(Tdata* set, Tdata elem) {
											
											if (elem != NULL){
												Tdata nuevo = create_set();          
												nuevo->data = copy_ast(elem);         
												nuevo->next = NULL;
												
												if ((*set)->data == NULL) {
													(*set)->data = nuevo;
												}
												else{
													Tdata aux = (*set)->data;
													while (aux->next != NULL) {
														aux = aux->next;
													}
													
													aux->next = nuevo;
												}
											}else{
												printf("\nConjunto vacio");
											}
										}
