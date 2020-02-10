#include "bintree.h"
#include <iostream>

using namespace std;


int valor(char caracter){
	int val = 0;
	if(caracter >= 'a' && caracter <= 'z')	       //Como el ejercicio no especifica nada sobre que valor devuelve cada letra
		val = caracter-('a'-1);			// devolveremos su valor a=1, b=2, c=3...
	else	
	if(caracter >= 'A' && caracter <= 'Z')	       
		val = caracter-('A'-1);	
	return val;
}

int operar(int uno,int dos, char operando){
	int resultado;
	switch(operando){
		case '+':resultado = uno+dos; break;
		case '-':resultado = uno-dos; break;
		case '*':resultado = uno*dos; break;
		case '/':resultado = uno/dos; break;
	}
	return resultado;
}

int evaluar_arbol(const bintree<char> & A, const typename bintree<char>::node &v)
{
	if(v.null())
		return 0;
	if (v.left().null() && v.right().null())
		return valor(*v);
 	else
 		return operar(evaluar_arbol(A,v.left()),evaluar_arbol(A,v.right()),*v);
}


int main(){

	// Creamos el árbol:
	//     *
	//   /  \
	//  +   -
	// / \ / \
	// 2 2 3  1

	bintree<char> Arb('*');
	Arb.insert_left(Arb.root(), '+');
	Arb.insert_right(Arb.root(), '-');
	Arb.insert_left(Arb.root().left(), 'b');
	Arb.insert_right(Arb.root().left(), 'b');
	Arb.insert_left(Arb.root().right(), 'c');
	Arb.insert_right(Arb.root().right(), 'a');

	cout << evaluar_arbol(Arb, Arb.root()) << endl;
}
