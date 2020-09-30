/*
 * recursion.h
 *
 *  Created on: 10/09/2015
 *      Author: pperezm
 */

#ifndef RECURSION_H_
#define RECURSION_H_

#include "exception.h"
#include <iostream>

long sum_seq(int n) {
	long acumulado = 0;
	
	for(int i = 0; i <= n; i++){
		acumulado = acumulado + i;
	}

	return acumulado;

}

long sum_rec(int n) {
	long acumulado;
	if (n == 0){
		return 0;
	}

	

	return n + sum_rec( n-1);
}

long fact_seq(int n) {
	long acumulado = 1;
	for (int i = 1; i <= n; i++){
		acumulado = acumulado*i;
	}


	return acumulado;
}

long fact_rec(int n) {
	

	if(n == 1){
		return 1;
	}
	return n*fact_rec(n-1);
}

long fib_seq(int n) {
	int anterior, actual, sig;

	anterior = 0;
	actual = 1; 

	for(int i = 1; i<n; i++){
		sig = anterior + actual;
		anterior = actual;
		actual = sig;
	}
	return sig;
}

long fib_rec(int n) {

	if((n==1)||(n==2)){
		return 1;
	}else{
	return (fib_rec(n-1) + fib_rec(n-2));
	}
}


// greatest common divisor
long gcd_seq(long a, long b) {
	long primer, segundo;
	long gcd = 1;
	bool newcode = false;
	if(newcode){
		if(primer > segundo){
			for(long i=1; i<=primer; i++){
				if((primer%i==0)&&(segundo%i==0)){
					gcd = i;
				}
			}	
		}else{
			for(long i=1; i<=segundo; i++){
				if((primer%i==0)&&(segundo%i==0)){
					gcd = i;
				}
			}
		}
	}else{
		long aux;
		while (b != 0) {
			aux = b;
			b = a % b;
			a = aux;
		}
	}
	return a;
}

// greatest common divisor
long gcd_rec(long a, long b) {
	if(a%b == 0){
		return b;
	}
			long aux;
			aux = b;
			b = a % b;
			a = aux;

	return gcd_rec(a-1, b-1);
}

bool find_seq(int arr[], int size, int val) {
	int value = val;
	
	for(int i = 0; i< size; i++){
		int val1 = arr[i];
		if(val1 == value){
			return true;
		}
	}
	
	return false;
}

bool find_rec(int arr[], int low, int high, int val) {
	bool newcode = true;
	if(newcode){
		if(arr[high] == val){
			return true;
		}
		if(high == low){
			return false;
		}
	}else{
		for(int i=low; low<high; i++){
			int valarr = arr[i];
			if(valarr == val){
				return true;
			}
		}
	}


	return find_rec(arr, low, high-1, val);
}

int max_seq(int arr[], int size) {
	int arrValue = 0;
	for(int i= 0; i<size-1; i++){
		
		if(arrValue <= arr[i]){
			arrValue = arr[i];
		} 

	}

	return arrValue;
}

int max_rec(int arr[], int low, int high) {
	if(high == low){
		return arr[low];
	}
	if (arr[low]<= arr[high]){
		arr[low] = arr[high];
	}

	return max_rec(arr, low, high-1);
}

int unimodal_seq(int arr[], int size) {
/*
SOLUCION DEL PROFE PARA RECURSIVA 
int unimodal_rec(int arr[], int low, int high) {
	if (low == high) {
        return low;
	}
	if(arr[low] > arr[high]) {
        return unimodal_rec(arr, low, high-1);
	}
    return unimodal_rec(arr, low+1, high);
}

int unimodal_rec(int arr[], int size) {
	return unimodal_rec(arr, 0, size-1);
}
*/
	int arrValue = 0;
	int j;
	for(int i= 0; i<size-1; i++){
		
		if(arrValue <= arr[i]){
			arrValue = arr[i];
			j = i;
		} 

	}
	return j;
}

int unimodal_rec(int arr[], int low, int high) {
	bool nuevocodigo = true;
	if(nuevocodigo){
		int arrValue = 0;
		int j;
		for(int i= 0; i<high; i++){
		
		if(arrValue <= arr[i]){
			arrValue = arr[i];
			j = i;
		} 

	}
	return j;
	}else{
		int size = high +1;

		if (size < 3) {
			return -1;
		}

		int mid;
		int lower = 0;
		int high1 = size - 1;
		while (lower < high1) {
			mid = (high1 + lower) / 2;
			if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
				return mid;
			} else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
				low = mid + 1;
			} else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
				high1 = mid - 1;
			}
		}
		return lower;
	}
	//return unimodal_rec(arr, low, high);
}

int unimodal_rec(int arr[], int size) {
	int arrValue = 0;
	int j;
	for(int i= 0; i<size-1; i++){
		
	if(arrValue <= arr[i]){
		arrValue = arr[i];
		j = i;
	} 

}
	return j;
}

int bs_seq(int arr[], int size, int val) {
	int low = 0;
	int high = size-1;
	int mid = (high + low)/2;

	while(low<high){
		mid = (high + low)/2;
		if(val == arr[mid]){
			return mid;
		}
		if(val < arr[mid]){
			high = mid-1;
		}else{
			low = mid +1;
		}
	}
	
	return low;

}

int bs_aux(int arr[], int low, int high, int val) {
	if(low > high){
		return low;
	}
	int mid =(high+low)/2;
	if(val==arr[mid]){
		return mid;
	}
	if(val < arr[mid]){
		return bs_aux(arr, low, mid-1, val);
	}else{
		return bs_aux(arr, mid+1, high, val);	
	}

	return 0;
}

int bs_rec(int arr[], int size, int val) {
	
	return bs_aux(arr, 0, size-1,val);
	
}
#endif /* RECURSION_H_ */
