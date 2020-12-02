#include <iostream>
#include <vector>
#include <iterator>
#include <list>
//#define is_string_type (T) (is_same <std::string, V>::value )
/// <summary>
/// Create a hashTable using generic programming
/// </summary>
/// <returns></returns>
/// 
template <class T, class V>
struct Node {
	T key;
	V value;
	std::list < Node<T, V> > ll;
	
};
template <class T, class V>

class hashTable {
public:
	hashTable(){
		
	std::cout << "Table Created" < <std::endl;
	
	}
	inline T hashFunction(T index) {
	                //Check to see if the Key is a String
			if constexpr (std::is_same_v<std::string, V>) {

				return (index % 10);
			}
			else {//If string
				return (index);
			}
			
	}
	inline T getValue(T value) {
	T getvalue  =	hashFunction(value);

	return hash[getvalue];
	}
	//Insert a new node
	void inline insertDict(T _key, V _value) {
		Node <T, V> node;
		/// <global hash function
		T getHashCode = hashFunction(_key);
		if (ifSpotTaken(getHashCode) == false) {
			
			node.key = getHashCode;
			node.value = _value;
			hash.push_back(node);
		}
		else {
			
			for (auto it = hash.begin(); it != hash.end(); it++) {
				if ((*it).key == getHashCode) {
					Node <T, V> newnode;
					
					newnode.key = getHashCode;
					newnode.value = _value;
					(*it).ll.push_back(newnode);

				}
			}
		}
	}
	bool inline findValue (T findNum) {
		findNum = hashFunction(findNum);
		auto it = hash.begin();
		
			for (it = hash.begin(); it != hash.end(); it++) {
				std::cout << " i " << std::endl;
				if ((*it).key == findNum) {
					if (!(*it).ll.empty()) {
						for (const auto& listiterator : (*it).ll) {
							
							std::cout << listiterator.value << std::endl;
							
						}
						return true;
					}
					else {
						std::cout << "found " << (*it).key << " " << (*it).value << std::endl;
						return true;
					}
				}
			}
		
						
		
		return false;
	}
	//Check to see if hashfunction created similar result
	bool ifSpotTaken(T getIndex) {
		
		for (auto it = hash.begin(); it != hash.end(); it++) {
			if ((*it).key == getIndex) {
				//Linked List function
				return true;
			}
		}
		return false;
	}
	

private:
	
	std::vector<Node<T, V> > hash;
	const bool compare = std::is_same<std::string, V>::value;
	//Check if the value is a string
	typename const bool _ifString = std::is_same<std::string, V>::value;

};
int main() {
	hashTable <int, std::string> t;
    
	t.findValue(43);

	return 0;
}
