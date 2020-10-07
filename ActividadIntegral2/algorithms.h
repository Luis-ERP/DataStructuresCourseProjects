#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "dlist.h"
using namespace std;

template<class T>
void swap(DList<DList<T>>& arreglo, int index1, int index2){
	DList<T> temp = arreglo[index2];
	arreglo[index2] = arreglo[index1];
	arreglo[index1] = temp;
}

// Bubble sort
template<class T>
void sort(DList<DList<T>>& arreglo, int varIndex){
	cout << "hasta aqui todo bien\n"; 
	for (int i=1; i<arreglo.size()-1; i++){
		for (int j=0; j<arreglo.size()-i; j++){
			T val2 = arreglo[j+1][varIndex];
			T val1 = arreglo[j][varIndex];
			if (val2 < val1){
				swap(arreglo, j+1, j);
			}
		}
	}
}

// Sequential search
template<class T>
DList<DList<T>> search(DList<DList<T>>& data, string value, int col, int start, int end){
	DList<DList<string>> foundValues;
	for (int i=start; i<end; i++){
		if (data[i][col] == value){
			foundValues.push_back(data[i]);
		}
	}
	return foundValues;
}