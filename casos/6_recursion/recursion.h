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

long gcd_seq(long a, long b) {
	return 0;
}

long gcd_rec(long a, long b) {
	return 0;
}

bool find_seq(int arr[], int size, int val) {
	return false;
}

bool find_rec(int arr[], int low, int high, int val) {
	return false;
}

int max_seq(int arr[], int size) {
	return 0;
}

int max_rec(int arr[], int low, int high) {
	return 0;
}

int unimodal_seq(int arr[], int size) {
	return 0;
}

int unimodal_rec(int arr[], int low, int high) {
	return 0;
}

int unimodal_rec(int arr[], int size) {
	return 0;
}

int bs_seq(int arr[], int size, int val) {
	return 0;
}

int bs_aux(int arr[], int low, int high, int val) {
	return 0;
}

int bs_rec(int arr[], int size, int val) {
	return 0;
}
#endif /* RECURSION_H_ */
