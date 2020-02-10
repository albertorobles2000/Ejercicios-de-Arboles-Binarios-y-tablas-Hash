#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
class hash_table{
	private:
		std::vector<std::list<T>> tabla;
		unsigned size;
		
		unsigned hash_function(T elemento){
			return elemento%size;	
		}
		
	public:
		hash_table(int n = 11)
			:size(n)
		{
			tabla = std::vector<std::list<T>> (n, std::list<int>());
		}
		
		void insert(const T elemento){
				unsigned indice = hash_function(elemento);
				tabla[indice].push_back(elemento);
		}
		
		void erase(T elemento){
			unsigned indice = hash_function(elemento);
			typename list<T>::iterator it = tabla[indice].begin();
			while(it!=tabla[indice].end() && *it != elemento){
				it++;
			}
			
			if(*it == elemento){
				tabla[indice].erase(it);	
			}
		}
		
		friend class iterator;
		class iterator{
            private:
               typename list<T>::iterator it;
               unsigned fila;
               hash_table * tab;
					 
            public:
            	iterator(){}
               iterator operator++(){
      				
      				++it;
      				
                	if(it == tab->tabla[fila].end() && *this!=tab->end())
                  {
                  	fila++;
                  	while(fila < tab->size && tab->tabla[fila].size() == 0)
                  		fila++;
                    	it = tab->tabla[fila].begin();
                  }
                    return *this;
               }
               
               iterator operator--(){
               	
               	if(it != tab->tabla[fila].begin())
							--it;
      				else{
      					if(*this!=tab->begin()){
      						fila--;
      						while(tab->tabla[fila].size() == 0){
      							fila--;	
      						}
      						it = tab->tabla[fila].end();
      						it--;
      					}
      				}
         
                    return *this;
               }
                
             	T & operator * (){
             		return *it;	
             	}
             	
             	bool operator!=(const iterator &otro) const{
                    return it != otro.it;
                }

                friend class hash_table;
      };
      
		iterator begin(){
            iterator i;
            unsigned j=0;
            while(j<size && tabla[j].size() == 0){
            	j++;	
            }
            i.it = tabla[j].begin();
            i.fila = j;
            i.tab = this;
            return i;
      }
      
      iterator end(){
            iterator i;
            int j=size-1;
            
            while(j>=0 && tabla[j].size() == 0){
            	j--;	
            }
            
            i.it = tabla[j].end();
            i.fila = j;
            i.tab = this;
            return i;
      }
};

int main(){
	hash_table<int> tabla(11);
	
	tabla.insert(1);
	tabla.insert(3);
	tabla.insert(49);
	tabla.insert(30);
	tabla.insert(0);
	tabla.insert(22);
	tabla.insert(33);
	tabla.insert(8);
	tabla.insert(19);
	tabla.insert(7);
	tabla.insert(21);
	tabla.insert(45);
	

	
	hash_table<int>::iterator it = tabla.end();
	--it;
	cout << "Iterando sobre tabla hash (--):" << endl;
	cout << *it << endl;
	while(it != tabla.begin()){
		--it;
		cout << *it << endl;
		
	}
	cout << endl;
	
	return 0;		
}
