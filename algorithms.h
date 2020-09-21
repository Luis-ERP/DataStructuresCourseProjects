#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void swap(vector<vector<T>>& arreglo, int index1, int index2){
	vector<T> temp = arreglo[index2];
	arreglo[index2] = arreglo[index1];
	arreglo[index1] = temp;
}

// Bubble sort
template<typename T>
void sort(vector<vector<T>>& arreglo, int varIndex){
	for (int i=1; i<arreglo.size()-1; i++){
		for (int j=0; j<arreglo.size()-i; j++){
			int val2 = stof(arreglo[j+1][varIndex]);
			int val1 = stof(arreglo[j][varIndex]);
			
			if (val2 < val1){
				swap(arreglo, j+1, j);
			}
		}
	}
}

// Sequential search
template<typename T>
vector<vector<T>> search(vector<vector<T>>& data, string value, int col, int start, int end){
	vector<vector<T>> foundValues;
	for (int i=start; i<end; i++){
		if (data[i][col] == value){
			foundValues.push_back(data[i]);
		}
	}
	return foundValues;
}