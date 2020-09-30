/*
 * sorts.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef SORTS_H_
#define SORTS_H_

#include "exception.h"
#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
	std::vector<T> bubbleSort(const std::vector<T>&);
	std::vector<T> selectionSort(const std::vector<T>&);
	std::vector<T> insertionSort(const std::vector<T>&);
	std::vector<T> shellSort(const std::vector<T>&);
	std::vector<T> mergeSort(const std::vector<T>&);

	std::vector<T> bucketSort(const std::vector<T>&);
	std::list<T>   mergeList(const std::list<T>&, const std::list<T>&);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::bubbleSort(const std::vector<T> &source) {
	std::vector<T> vector(source);
	T auxiliar = vector[0];
	for(int j=0; j<vector.size(); j++){
		for(int i=1; i<vector.size(); i++){
			if(vector[i-1]>vector[i]){
				auxiliar = vector[i-1];
				vector[i-1] = vector[i];
				vector[i] = auxiliar;
			}else{
				auxiliar = vector[i];
			}
		}	
	}
	return vector;
}

template <class T>
std::vector<T> Sorts<T>::selectionSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	T auxiliar = v[0];
	T pos = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		auxiliar = v[i];
		pos = v[i];
		for (int j = 0; j < v.size(); j++)
		{
			if(v[j]>v[i]){
				auxiliar = v[i];
				v[i]=v[j];
				v[j]=auxiliar; 
			}
		}
	}
	return v;
}

template <class T>
std::vector<T> Sorts<T>::insertionSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	T auxiliar = v[0];
	T current = v[0];
	for(int i = 0; i<v.size();i++){
		for(int j=0; j<v.size();j++){
			current = v[j];
			for(int k = j; k>0; k--){
				if(v[k]<v[k-1]){
					auxiliar = v[k];
					v[k]=v[k-1];
					v[k-1]=auxiliar;
				}else{
					k = 0;
				}
			}
		}
	}
	
	return v;
}

template <class T>
std::vector<T> Sorts<T>::shellSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	T auxiliar = v[0];
	int h = 1;
	for (int i = 2; (v.size())/i>=1; i++){
		h = (v.size())/i;
		for(int j = 0; j<v.size(); j++){
			if(j+h <= v.size()){
				if(v[j]>v[j+h]){
					auxiliar = v[j];
					v[j] = v[j+h];
					v[j+h] = auxiliar;
				}
			}
		}
	}

	return v;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	//std::vector<T> B(A);
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;
	if((high -low)<1){
		return;
	}
	mid = (high + low)/2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

template <class T>
std::vector<T> Sorts<T>::mergeSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());
	//copyArray(v, tmp, 0, v.size()-1);
	mergeSplit(v, tmp, 0, v.size()-1);
	return v;
}

template <class T>
std::vector<T> Sorts<T>::bucketSort(const std::vector<T> &source) {
	typename  std::list<T>::iterator itr;
	std::vector<T> v;

	return v;
}

template <class T>
std::list<T> Sorts<T>::mergeList(const std::list<T> &lst1, const std::list<T> &lst2) {
	typename std::list<T>::const_iterator itr1, itr2;
	std::list<T> result;

	return result;
}

#endif /* SORTS_H_ */
