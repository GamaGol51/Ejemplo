#include <iostream>
using namespace std;

class Nodo {
	private:
		int dato;
		Nodo *sig;
		friend class Lista;	
};

class Lista {
	private:
		Nodo *cab;
	public:
		Lista(){
			cab = NULL;
		}
		void mete(int x);		
		void mostrar();	
		bool pertenece(int x);
		void unir(Lista l1, Lista l2);
		void interseccion(Lista l1, Lista l2);					
};

void Lista::mete(int x){
	Nodo *p = cab;
	p = new Nodo();
	p -> dato = x;
	p -> sig = cab;
	cab = p;
}

void Lista::mostrar() {
	Nodo *p;
	p = cab;
	
	while (p != NULL){
		cout << p -> dato <<  " ";
		p = p -> sig;
	}
}



bool Lista::pertenece(int x){
	Nodo *p = cab;
	bool bandera = false;
	
	while (p != NULL){
		if( p -> dato == x){
			bandera = true;
			//cout << "VERDADERO!!";
		} 
		p = p -> sig;
	}
	return bandera;
}

//Copia los datos que no están repetidos
void Lista::unir(Lista l1, Lista l2) {
	Nodo *pl1 = l1.cab, *pl2 = l2.cab;
	
	if(pl1 == NULL || pl2 == NULL) {
		cout << endl << endl << "ERROR!! La lista se encuentra vacia" << endl << endl;
	} else {
		while (pl1 != NULL){
			mete(pl1 -> dato);
			pl1 = pl1 -> sig;
		}
		while (pl2 != NULL) {
			if(l1.pertenece(pl2 -> dato) == false){
				mete(pl2 -> dato);
			}
			pl2 = pl2 -> sig;
		}
	}
}

void Lista::interseccion(Lista l1, Lista l2) {
	Nodo *pl1 = l1.cab, *pl2 = l2.cab;
	
	while (pl2 != NULL) {
			if(l1.pertenece(pl2 -> dato) == true){
				mete(pl2 -> dato);
			}
			pl2 = pl2 -> sig;
		}
}


int main () {
	
	cout << "---------- Conjuntos ---------- " << endl << endl;
	
	Lista l1, l2, l3, l4;
	
	//Introduccion de datos
	l1.mete(4);
	l1.mete(3);
	l1.mete(2);
	l1.mete(1);
	cout << "Los datos en la lista A son: " << endl; //Pertenece, unión e intersección
	l1.mostrar();
	
	cout << endl << endl;
	
	//Introduccion de datos en la Lista B;
	l2.mete(1);
	l2.mete(3);
	l2.mete(7);
	l2.mete(6);
	cout << "Los datos en la Lista B son: " << endl;
	l2.mostrar();
	
	cout << endl << endl << "La union de la Lista A y la Lista B es: " << endl;
	
	l3.unir(l1, l2);
	l3.mostrar();
	
	cout << endl << endl;
	
	l4.interseccion(l1, l2);
	cout << "La Interseccion de la lista A y Lista B es: " << endl;
	l4.mostrar();

	return 0;
} 





#include <iostream>
using namespace std;

class Nodo {
	private:
		int dato;
		Nodo *sig;
		friend class Lista;	
};

class Lista {
	private:
		Nodo *cab;
	public:
		Lista(){
			cab = NULL;
		}
		void mete(int x);		
		void mostrar();	
		bool pertenece(int x);
		void unir(Lista l1, Lista l2);
		void interseccion(Lista l1, Lista l2);					
};

void Lista::mete(int x){
	Nodo *p = cab;
	p = new Nodo();
	p -> dato = x;
	p -> sig = cab;
	cab = p;
}

void Lista::mostrar() {
	Nodo *p;
	p = cab;
	
	while (p != NULL){
		cout << p -> dato <<  " ";
		p = p -> sig;
	}
}



bool Lista::pertenece(int x){
	Nodo *p = cab;
	bool bandera = false;
	
	while (p != NULL){
		if( p -> dato == x){
			bandera = true;
			//cout << "VERDADERO!!";
		} 
		p = p -> sig;
	}
	return bandera;
}

//Copia los datos que no están repetidos
void Lista::unir(Lista l1, Lista l2) {
	Nodo *pl1 = l1.cab, *pl2 = l2.cab;
	
	if(pl1 == NULL || pl2 == NULL) {
		cout << endl << endl << "ERROR!! La lista se encuentra vacia" << endl << endl;
	} else {
		while (pl1 != NULL){
			mete(pl1 -> dato);
			pl1 = pl1 -> sig;
		}
		while (pl2 != NULL) {
			if(l1.pertenece(pl2 -> dato) == false){
				mete(pl2 -> dato);
			}
			pl2 = pl2 -> sig;
		}
	}
}

void Lista::interseccion(Lista l1, Lista l2) {
	Nodo *pl1 = l1.cab, *pl2 = l2.cab;
	
	while (pl2 != NULL) {
			if(l1.pertenece(pl2 -> dato) == true){
				mete(pl2 -> dato);
			}
			pl2 = pl2 -> sig;
		}
}


int main () {
	
	cout << "---------- Conjuntos ---------- " << endl << endl;
	
	Lista l1, l2, l3, l4;
	
	//Introduccion de datos
	l1.mete(4);
	l1.mete(3);
	l1.mete(2);
	l1.mete(1);
	cout << "Los datos en la lista A son: " << endl; //Pertenece, unión e intersección
	l1.mostrar();
	
	cout << endl << endl;
	
	//Introduccion de datos en la Lista B;
	l2.mete(1);
	l2.mete(3);
	l2.mete(7);
	l2.mete(6);
	cout << "Los datos en la Lista B son: " << endl;
	l2.mostrar();
	
	cout << endl << endl << "La union de la Lista A y la Lista B es: " << endl;
	
	l3.unir(l1, l2);
	l3.mostrar();
	
	cout << endl << endl;
	
	l4.interseccion(l1, l2);
	cout << "La Interseccion de la lista A y Lista B es: " << endl;
	l4.mostrar();

	return 0;
} 
