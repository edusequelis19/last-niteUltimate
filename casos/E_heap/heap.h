/*
 * heap.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	unsigned int size;
	unsigned int count;
	
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);
	
public:
	Heap(unsigned int) throw (OutOfMemory);
	~Heap();
	bool empty() const;
	bool full() const;
	void add(T) throw (Overflow);
	T remove() throw (NoSuchElement);
	void clear();
	std::string toString() const;
};

template <class T>
Heap<T>::Heap(unsigned int sze) throw (OutOfMemory) {
	size = sze;
	count = 0;
	data = new T[size];
	if(data == NULL){
		throw OutOfMemory();
	}
}

template <class T>
Heap<T>::~Heap() {
	delete [] data;
	data = NULL;
	count = 0;
	size = 0;
}

template <class T>
bool Heap<T>::empty() const {
	if(count == 0){
		return true;
	}
	return false;
}

template <class T>
bool Heap<T>::full() const {
	if(count == size){
		return true;
	}

	return false;
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos-1)/2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	
	return (2*pos) + 1;
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {


	return (2*pos) + 2;
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int posicion) {
		unsigned int posicion_min = posicion;
//Comparar el valor de la posicion es major con el valor de su hijo izquierdo
	if(data[posicion]>data[left(posicion)] && left(posicion) <= count){
	//La posicion mas pequenia seria la izquierda
		posicion_min = left(posicion);
	}
//Comprar el valor de la posicion con el valor de su hijo derecho
	if(data[posicion_min]>data[right(posicion)] && right(posicion) <= count){
	//La posicion mas pequenia seria la izquierda
		posicion_min = right(posicion);
	}
	//La posicion mas pequenia seria la derecha.

//Si la posicion mas pequenia es diferente de la posicion
	if(posicion_min != posicion){
	//Hacemos swap entre la posicion y la posicion mas pequenia.
	swap(posicion, posicion_min);
	//ReheapDown sobre la posicion mas pequenia heapify(posicion mas pequenia)
	heapify(posicion_min);
	}


}

template <class T>
void Heap<T>::add(T val) throw (Overflow) {
	//Verificar que no este lleno el heap
	if(full()){
		throw Overflow();
	}
	//Obtener la siguiente posicion disponible

	int posicion = count;

	//Agregar el nuevo valor a la posicion disponible

	data[posicion] = val;

	//aumentar el count

	count++;


	//reheap Up 
	//si el padre es mas grande, hacer swap
	if(posicion > 0 && data[parent(posicion)] > val){
		swap(posicion,parent(posicion));
		posicion = parent(posicion);
	}
}

template <class T>
T Heap<T>::remove() throw (NoSuchElement) {
	
	if(empty()){
		NoSuchElement();
	}

	T aux = data[0];
	count--;
	data[0] = data[count];
	//Hacer Reheap down
	heapify(0);
	return aux;
}

template <class T>
void Heap<T>::clear() {
	count = 0;
}
	

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	
	aux << "[";
	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
		aux << data[i];
	}
	aux << "]";
	return aux.str();
}
#endif /* HASH_H_ */
	
