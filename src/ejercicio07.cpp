#include "bintree.h"
#include <iostream>

using namespace std;

template <typename T>
bool iguales( const typename bintree<T>::node &nA, const typename bintree<T>::node &nB)
{
	bool igual = false;
	if(nA.null() && nB.null())
		igual = true;
	else{
		if(nA.null())
			igual = false;
		else
		if(nB.null())
			igual = false;
		else
		if (iguales<T>(nA.left(),nB.left()) && iguales<T>(nA.right(),nB.right()))
			igual = true;	
	}
	
	return igual;
	
}

template <typename T>
bool ArbolesIguales(const bintree<T> & A, const bintree<T> & B)
{
	return iguales<T>(A.root(),B.root());
}


int main(){

	// Creamos el árbol:
	//     7
	//   /  \
	//  1   9
	// / \ /
	// 6 8 5
	// \
	// 4

	bintree<int> Arb1(7);
	Arb1.insert_left(Arb1.root(), 1);
	Arb1.insert_right(Arb1.root(), 9);
	Arb1.insert_left(Arb1.root().left(), 6);
	Arb1.insert_right(Arb1.root().left(), 8);
	Arb1.insert_right(Arb1.root().left().right(), 4);
	Arb1.insert_left(Arb1.root().right(), 5);

	// Creamos el árbol:
	//     1
	//   /  \
	//  1   8
	// / \ /
	// 6 8 5
	// \   \
	// 4    6

	bintree<int> Arb2(1);
	Arb2.insert_left(Arb2.root(), 1);
	Arb2.insert_right(Arb2.root(), 8);
	Arb2.insert_left(Arb2.root().left(), 6);
	Arb2.insert_right(Arb2.root().left(), 8);
	Arb2.insert_right(Arb2.root().left().right(), 4);
	Arb2.insert_left(Arb2.root().right(), 5);
	Arb2.insert_right(Arb2.root().right().left(),6); //Si comentamos esta linea son iguales.

	if(ArbolesIguales<int>(Arb1, Arb2))
		cout << "Son iguales" << endl;
	else
		cout << "Son distintos" << endl;

}
