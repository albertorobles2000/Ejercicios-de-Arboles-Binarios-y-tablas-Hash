
#include "bintree.h"
#include <iostream>

using namespace std;

template <typename T>
void reflexion(bintree<T> & A, const typename bintree<T>::node &v)
{
	if(!v.left().null() && !v.right().null()){
		bintree<T> izq;
		A.prune_left(v,izq);
		bintree<T> drch;
		A.prune_right(v,drch);
		A.insert_right(v,izq);
		A.insert_left(v, drch);
		reflexion<T>(A,v.left());
		reflexion<T>(A,v.right());
	}
	else{
		if(!v.left().null()){
			bintree<T> izq;
			A.prune_left(v,izq);
			A.insert_right(v,izq);
			reflexion<T>(A,v.right());
		}
		else{
			if(!v.right().null()){
				bintree<T> drch;
				A.prune_right(v,drch);
				A.insert_left(v, drch);
				reflexion<T>(A,v.left());
			}	
		}
	}
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

	bintree<int> Arb(7);
	Arb.insert_left(Arb.root(), 1);
	Arb.insert_right(Arb.root(), 9);
	Arb.insert_left(Arb.root().left(), 6);
	Arb.insert_right(Arb.root().left(), 8);
	Arb.insert_right(Arb.root().left().right(), 4);
	Arb.insert_left(Arb.root().right(), 5);

	cout << "Recorrido por niveles: " << endl;
	for (bintree<int>::level_iterator it= Arb.begin_level(); it!=Arb.end_level(); ++it)
	  cout << *it << " ";
  	cout << endl;

	reflexion<int>(Arb,Arb.root());
	
	cout << "Recorrido por niveles: " << endl;
	for (bintree<int>::level_iterator it= Arb.begin_level(); it!=Arb.end_level(); ++it)
	  cout << *it << " ";
  	cout << endl;

}
