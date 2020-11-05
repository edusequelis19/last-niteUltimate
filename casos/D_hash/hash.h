/*
 * hash.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class Key, class Value>
class HashTable {
private:
	//apuntador a una funcion
	unsigned int (*func) (const Key);
	//Tamaño de tabla
	unsigned int size;
	//Vector de valores de la tabla de hash
	unsigned int count;
	
	Key *keys;
	Key initialValue;
	Value *values;
	
	long indexOf(const Key) const;
	
public:
	HashTable(unsigned int, Key, unsigned int (*f) (const Key)) throw (OutOfMemory);
	~HashTable();
	bool full() const;
	bool put(Key, Value) throw (Overflow);
	bool contains(const Key) const;
	Value get(const Key) throw (NoSuchElement);
	void clear();
	std::string toString() const;
};

template <class Key, class Value>
HashTable<Key, Value>::HashTable(unsigned int sze, Key init, unsigned int (*f) (const Key)) throw (OutOfMemory) {
	size = sze;
	keys = new Key[size];
	if (keys == 0) {
		throw OutOfMemory();
	}
	initialValue = init;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = init;
	}
	values = new Value[size];
	if (values == 0) {
		throw OutOfMemory();
	}
	for (int i = 0; i  < sze; i++){
        values[i] = 0;
    }

	func = f;
	count = 0;
	/*
	size = sze;
	//asignar funcion de hash al apuntador func
	func = f;
	//asegurarse que hay memoria disponible, de lo contario
	//mandar excepcion de memoria
	values = new Value[size];
	if(values == NULL ){
		throw OutOfMemory();
	}
	keys = new Key[size];
	if(keys == NULL ){
		throw OutOfMemory();
	}

	for(int i = 0; i<size; i++){
		keys[i] = init;
	}
	count = 0;
	*/
}

template <class Key, class Value>
HashTable<Key, Value>::~HashTable() {
	delete[] keys;
	keys = 0;
	delete[] values;
	values = 0;
	size = 0;
	func = 0;
	count = 0;
}


template <class Key, class Value>
bool HashTable<Key, Value>::full() const {
	if (count > size){
		return true;
	}
	return false;

}

template <class Key, class Value>
long HashTable<Key, Value>::indexOf(const Key k) const {
	/*
	aplica la funcion de hash y verifica que la llave sea igual 
	a la llave que se esta buscando, si es asi, devuelve el indice
	*/
	int inicio_busqueda = func(k) % size;
	int i = inicio_busqueda;


	//De lo contrario, aplica sondeo linear, si encuentra el valor devuelve el indice
	do{
		if(keys[i]==k){
			return i;
		}
		i = (i +1)%size;

	}while(i != inicio_busqueda);
	//Si no encuentra el valor despues de recorrer toda la tabla,
	//devuelve -1 para indicar que no se encontro
	return -1;
}

template <class Key, class Value>
bool HashTable<Key, Value>::put(Key k, Value v) throw (Overflow) {
	int posicion_tabla = indexOf(k);

	if(posicion_tabla!=-1){
		values[posicion_tabla] =v;
		return true;
	}
	// si la tabla esta llena, lanzar la excepcion
	if(full()){
		throw Overflow();
	}
	//si la llave ya tiene un indice, actuaizar su valor y devolver verdadero
	/*int posicion_tabla = indexOf(k);

	if(posicion_tabla!=-1){
		values[posicion_tabla] =v;
		return true;
	}
	*/

	//si la llave no tiene un indice, calcular su inidice con la funcion de hash
	//si esta disponible insertar la llave y el valor, aumantar el contador y devolver verdadero
	//Si no esta dispnible buscar un lugar disponible con sondeo de hash
	int valor_hash = func(k) % size;
	int i = valor_hash;
	//inserta la llave y el valor en la posicion de la tabla del valor d ehash
	//pero si esta ocupado, busca un lugar por sondeo lineal
	do{
		if(keys[i]== initialValue){
			keys[i] = k;
			values[i] = v;
			count++;
			return true;
		}
		i = (i + 1) % size;

	}while(i != valor_hash);
	return false;
}

template <class Key, class Value>
bool HashTable<Key, Value>::contains(const Key k) const {
	long pos;

	pos = indexOf(k);
	return (pos != -1);
}

template <class Key, class Value>
Value HashTable<Key, Value>::get(const Key k) throw (NoSuchElement) {
	Value v;
	unsigned int i, start;
	long pos;

	pos = indexOf(k);
	if (pos != -1) {
		return values[pos];
	}
	throw NoSuchElement();
}

template <class Key, class Value>
void HashTable<Key, Value>::clear() {
		count = 0;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = initialValue;
	}
}

template <class Key, class Value>
std::string HashTable<Key, Value>::toString() const {
	std::stringstream aux;
	
	for (unsigned int i = 0; i < size; i++) {
		aux << "[ " << i << ", " << keys[i] << ", " << values[i] << "]\n";
	}
	return aux.str();
}
#endif /* HASH_H_ */
	
