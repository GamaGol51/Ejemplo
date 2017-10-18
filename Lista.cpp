#include <iostream>
using namespace std;

class Nodo{
    private:
        int dato;
	public:
        Nodo *sig;
	friend class Lista;
};

class Lista{
private:
	Nodo *cab;
    public:
        Lista(){
             cab = NULL;
        }
        //~ Lista();
	void mete(int x);
	void saca();
	void mostrar();
	int mayor();
	void eliminarx(int x);
	void eliminaUltimo();

};

void Lista::mete(int x){
	Nodo *p;
	p = new Nodo();
	p-> dato = x;
	p-> sig = cab;
	cab = p;
}

void Lista::saca(){
	Nodo *p= cab;
	if(p == NULL){
		cout << "Error, Lista vacia";
	} else {
		cab = cab-> sig;
		delete p;
	}
}

void Lista::mostrar(){
	Nodo *p = cab;
	while(p != NULL){
		cout << p-> dato << " ";
			p = p-> sig;
	}
}

void Lista::eliminarx(int x){
    Nodo *p, *pAnt;
    p = cab;
    pAnt = NULL;

    while(p != NULL){
            if(p->dato == x){ //ya encontre x
                    if(pAnt == NULL){       // se borra el primero
                        cab = p ->sig;          //actualizar cabeza
                        delete p;
                    }else{ //Lo encontre pero no es el primero
                        pAnt -> sig = p -> sig;
                        delete p;
                    }

                    return;

            }
            pAnt = p;
            p = p -> sig;
    }
}
int Lista::mayor(){
    int aux=0;
    Nodo *p = cab;
    while(p!=NULL){
        if(p->dato>aux){
            aux = p->dato;
        }
        p = p->sig;
    }
    return aux;
}

void Lista::eliminaUltimo(){
    Nodo *p, *pAnt;
    p= cab;
    pAnt= NULL;
    while(p != NULL){
        if(p -> sig == NULL){
            if(p == cab){
                cab = NULL;
                delete p;
            }else{
             pAnt -> sig = NULL;
             delete p;
            }
        }
         pAnt = p;
         p= p->sig;
    }
}


int main(int argc, char const *argv[]){
	Lista l1;
	l1.mete(5);
	l1.mete(10);
	l1.mete(15);
	l1.mete(20);
	l1.mete(25);
	l1.mete(30);
	l1.mete(35);

    cout << " -- Operacion Meter --" << endl;
    l1.mostrar();
	cout << endl;

	l1.saca();
	cout << endl;
	cout << " -- Operacion Saca --" << endl;
	l1.mostrar();
	cout << endl;

	l1.eliminarx(25);
	cout << endl;
	cout << " -- Operacion EliminarX (25)  --" << endl;
	l1.mostrar();
	cout << endl;

	l1.eliminaUltimo();
	cout << endl;
	cout << " -- Operacion EliminaUltimo --" << endl;
	l1.mostrar();
	cout << endl;

	cout << endl;
    cout << " -- Operacion Numero mayor --" << endl;
    int may = l1.mayor();
    cout << may ;

	return 0;
}
