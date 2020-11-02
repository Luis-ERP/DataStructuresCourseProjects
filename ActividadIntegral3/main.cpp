#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "algorithms.h"
#include "dlist.h"
#include "bst.h"
using namespace std;

// Functions declaration
DList<DList<string>> readData(DList<BST<string, DList<string>>> &bst_list);
void writeData(DList<DList<string>> data, string fileName);
template<class T>
void outputData(DList<DList<T>> data, int start, int end);
template<class T>
DList<DList<T>> sortData(DList<DList<T>>& data, int start, int end, int varIndex);
void casosPrueba();
void search(string value, int varName, DList<BST<string, DList<string>>>& bstList);


// Main
int main() {
	int answer;

	// Define the list of BST's
	DList<BST<string, DList<string>>> data_bst;
	BST<string, DList<string>> entity;
	BST<string, DList<string>> code;
	BST<string, DList<string>> year;
	BST<string, DList<string>> co2;
	data_bst.push_back(entity);
	data_bst.push_back(code);
	data_bst.push_back(year);
	data_bst.push_back(co2);

	// Define the table of data and read the document
	DList<DList<string>> data = readData(data_bst);

	do {
		cout << "\nWelcome to the the CO2 emissions Worldwide database, please select an option\n";
		cout << "0. Exit\n";
		cout << "1. Output dataset\n";
		cout << "2. Ordenar por variable (versión lenta)\n";
		cout << "3. Buscar valor\n";
		cout << "4. Casos de prueba\n";
		cout << "-> ";
		cin >> answer;
		cout << endl;

		switch(answer){
			case 1: {
				int start;
				int end;
				cout << "Start row (min. 0) -> ";
				cin >> start;
				cout << "End row (max. 20853) -> ";
				cin >> end;
				outputData(data, start, end);
				break;
			}
			case 2: {
				string variableName;
				int index;
				cout << "Enter variable name\n";
				cout << "0. Entity\n";
				cout << "1. Code\n";
				cout << "2. Year\n";
				cout << "3. CO2 emissions\n-> ";
				cin >> index;
				int start;
				int end;
				cout << "Start row (min. 0) -> ";
				cin >> start;
				cout << "End row (max. 20853) -> ";
				cin >> end;
				DList<DList<string>> sortedData = sortData(data, start, end, index);
				writeData(sortedData, "co2_emission_sorted.csv");
				outputData(sortedData, start, end);
				break;
			}
			case 3: {
				int variableName;
				string valueToSearch;
				int start;
				int end;
				cout << "Enter the column where to search\n";
				cout << "0. Entity\n";
				cout << "1. Code\n";
				cout << "2. Year\n";
				cout << "3. CO2 emissions\n-> ";
				cin >> variableName;
				// cout << "Start row (min. 0) -> ";
				// cin >> start;
				// cout << "End row (max. 20853) -> ";
				// cin >> end;
				cout << "Enter the value to search\n-> ";
				cin >> valueToSearch;
				search(valueToSearch, variableName, data_bst);
				break;
			}	
			case 4: {
				cout << "## ORDENAR ##\n";
				cout << "Caso1.  [IN]: 3 0 10\n";
				DList<DList<string>> sortedData1 = sortData(data, 0, 10, 3);
				writeData(sortedData1, "co2_emission_sorted_PRUEBA1.csv");
				outputData(sortedData1, 0, 10);
				cout << "Caso2.  [IN]: 2 150 165\n";
				DList<DList<string>> sortedData2 = sortData(data, 150, 165, 2);
				writeData(sortedData2, "co2_emission_sorted_PRUEBA2.csv");
				outputData(sortedData2, 0, 10);
				cout << "## BUSCAR ##\n";
				cout << "Caso1. [IN]: 4 1 COL";
				search("COL", 1, data_bst);
				cout << "Caso2. [IN]: 4 2 1944";
				search("1994", 2, data_bst);
				break;
			}
		}
	} while (answer != 0);
}


// Read data
DList<DList<string>> readData(DList<BST<string, DList<string>>> &bst_list){
	DList<DList<string>> data;
	// Read file
	ifstream file;
	file.open("co2_emission_shuffled.csv");

	int counter = 0;
	while(file.good()){
		counter++;
		string str_entity;
		string str_code;
		string str_year;
		string str_co2;
		// Read line
		getline(file, str_entity, ',');
		getline(file, str_code, ',');
		getline(file, str_year, ',');
		getline(file, str_co2, '\n');
		// Append to the vector
		DList<string> row;
		row.push_back(str_entity);
		row.push_back(str_code);
		row.push_back(str_year);
		row.push_back(str_co2);
		DList<string>* row_ptr = data.push_back(row);
		//Append to the BST's
		bst_list[0].add(str_entity, row_ptr); // Entity
		bst_list[1].add(str_code, row_ptr); // Entity Code
		bst_list[2].add(str_year, row_ptr); // Year
		bst_list[3].add(str_co2, row_ptr); // CO2 Emissions

		// Como estoy en Repl.it, no tengo mucha memoria disponible, por 
		// lo que si dejo que inserte todas las filas, me va a dar un segfault
		if (counter > 15000) break;
	}
	file.close();
	return data;
}


// Print vector
template<class T>
void outputData(DList<DList<T>> data, int start, int end){
	cout << "\nENTITY     CODE     YEAR     CO2-EMISSIONS\n";
	for(int i=start; i<end; i++){
		cout << data[i][0] << "    ";
		cout << data[i][1] << "    ";
		cout << data[i][2] << "    ";
		cout << data [i][3] << endl;
	}
	cout << "\n\n";
}


// Write data
void writeData(DList<DList<string>> data, string fileName){
	ofstream file;
	file.open(fileName);
	for (int i=0; i<data.size(); i++){
		file << data[i][0] << "," 
			<< data[i][1] << "," 
			<< data[i][2] << ","
			<< data[i][3] << endl;
	}
	file.close();
}


// Sort
template<class T>
DList<DList<T>> sortData(DList<DList<T>>& data, int start, int end, int varIndex){
	DList<DList<T>> rangedVector;
	for (int i=start; i<end; i++){
		rangedVector.push_back(data[i]);
	}
	sort(rangedVector, varIndex);
	return rangedVector;
}


// Serarch
void search(string value, int varName, DList<BST<string, DList<string>>>& bstList){
	DList<string>* ptr = bstList[varName].search(value);
	DList<string> foundValue = *ptr;

	if (foundValue.size() == 0){
		cout << "\nValue not found." << endl;
	}
	else {
		DList<DList<string>> data;
		data.push_back(foundValue);
		outputData(data, 0, data.size());
	}
}