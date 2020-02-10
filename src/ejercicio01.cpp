
#include "bintree.h"
#include <iostream>

using namespace std;

template <typename T>
void busqueda_rec(const typename bintree<T>::node &v,typename bintree<T>::node & nodo_profundo,int nivel,int & maxima_profundidad)
{
	if(!v.null()){
		//cout << nivel << "||" << maxima_profundidad << "||" << *v << "||"  << endl; 
		busqueda_rec<T>(v.left(),nodo_profundo,nivel+1,maxima_profundidad); //Buscamos en el nodo izquierdo
		if(nivel > maxima_profundidad){
			maxima_profundidad = nivel;
			nodo_profundo = v;
		}
		busqueda_rec<T>(v.right(),nodo_profundo,nivel+1,maxima_profundidad); //Buscamos en el nodo derecho
	}
}


int main(){

	// Creamos el árbol:
	//     7
	//   /  \
	//  1   9
	// / \ /
	// 6 8 5
	//   \
	//   4 

	bintree<int> Arb(7);
	Arb.insert_left(Arb.root(), 1);
	Arb.insert_right(Arb.root(), 9);
	Arb.insert_left(Arb.root().left(), 6);
	Arb.insert_right(Arb.root().left(), 8);
	Arb.insert_right(Arb.root().left().right(), 4);
	Arb.insert_left(Arb.root().right(), 5);


	typename bintree<int>::node solucion;
	int profundidad = -1;
	busqueda_rec<int>(Arb.root(),solucion,0,profundidad);

	cout << "Hoja mas profunda: " << *(solucion) << endl;
	cout << "Su profundidad era de " << profundidad << endl;
}
