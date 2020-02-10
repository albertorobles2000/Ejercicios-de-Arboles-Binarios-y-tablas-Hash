
#include "bintree.h"
#include <iostream>

using namespace std;

template <typename T>
int nivel_de_nodo_buscar(const bintree<T> & A, const typename bintree<T>::node &v, const typename bintree<T>::node & a_buscar)
{
	int nivel;
	if(v.null())
		nivel = -1;
	else{

		if (*a_buscar == *v){			
			nivel = 0;
		}
		else{
				int izq = nivel_de_nodo_buscar<T>(A,v.left(),a_buscar);
				int drch = nivel_de_nodo_buscar<T>(A,v.right(),a_buscar);

			if(izq > -1 ||drch > -1){
				if(izq > -1)
					nivel = izq +1;
							
				if(drch > -1)
					nivel = drch +1;
									
			}
			else //No esta dicho nodo en el arbol
				nivel = -1;
			
		}
	}
	return nivel;
	
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

	int n = 4;
	typename bintree<int>::node nodo(n);

	cout << "Nivel del nodo " << n << ": " << nivel_de_nodo_buscar<int>(Arb,Arb.root(),nodo) << endl;
}
