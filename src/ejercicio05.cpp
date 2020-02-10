#include "bintree.h"
#include <iostream>

using namespace std;

template <typename T>
int densidad(const bintree<T> & A, const typename bintree<T>::node &v)
{
	if (v.left().null() && v.right().null())
		return 1;
 	else {
 		int alt = 0;
		
		if(!v.left().null())
			alt = densidad(A,v.left());
		if(!v.right().null())
 			alt = alt + densidad(A,v.right());
		
 		return alt+1; 
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

	cout << densidad<int>(Arb, Arb.root()) << endl;
}
