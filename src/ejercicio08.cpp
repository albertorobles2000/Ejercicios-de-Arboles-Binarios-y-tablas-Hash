#include "bintree.h"
#include <iostream>

using namespace std;

template <typename T>
int rango(const bintree<T> & A, const typename bintree<T>::node &v,T minimo, T maximo)
{
	int valor = 0;
	if(v.null()){
		return 0;
	}

	if (*v > minimo && *v < maximo)
		valor = rango(A,v.left(),minimo,maximo) + rango(A,v.right(),minimo,maximo) + 1;
 	else {
 		if(*v <= minimo){
			if(*v == minimo)
				valor = rango(A,v.right(),minimo,maximo) + 1;
			else
				valor = rango(A,v.right(),minimo,maximo);
		}
		else{
			if(*v >= maximo){
				if(*v == maximo)
					valor = rango(A,v.left(),minimo,maximo) + 1;
				else
					valor = rango(A,v.left(),minimo,maximo);
			}
		}
	}
	return valor;
}


int main(){

	// Creamos el árbol BST:
	//     7
	//   /  \
	//  3   10
	// / \ /
	// 1 6 9
	// \
	// 2

	bintree<int> Arb(7);
	Arb.insert_left(Arb.root(), 3);
	Arb.insert_right(Arb.root(), 10);
	Arb.insert_left(Arb.root().left(), 1);
	Arb.insert_right(Arb.root().left(), 6);
	Arb.insert_right(Arb.root().left().right(), 2);
	Arb.insert_left(Arb.root().right(), 9);

	cout << rango<int>(Arb, Arb.root(),5,10) << endl;
}

