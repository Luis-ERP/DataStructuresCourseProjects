#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "algorithms.h"
#include "dlist.h"
using namespace std;

// Functions declaration
DList<DList<string>> readData();
void writeData(DList<DList<string>> data, string fileName);
template<class T>
void outputData(DList<DList<T>> data, int start, int end);
template<class T>
DList<DList<T>> sortData(DList<DList<T>>& data, int start, int end, int varIndex);
void casosPrueba();


// Main
int main() {
	int answer;
	DList<DList<string>> data = readData();
	do {
		cout << "\nWelcome to the the CO2 emissions Worldwide database, please select an option\n";
		cout << "0. Exit\n";
		cout << "1. Output dataset\n";
		cout << "2. Sort by variable (ascending)\n";
		cout << "3. Search value\n";
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
				cout << "Start row (min. 0) -> ";
				cin >> start;
				cout << "End row (max. 20853) -> ";
				cin >> end;
				cout << "Enter the value to search\n-> ";
				cin >> valueToSearch;
				DList<DList<string>> foundValues = search(data, valueToSearch, variableName, start, end);
				if (foundValues.size() == 0){
					cout << "\nValue not found." << endl;
				}
				else {
					outputData(foundValues, 0, foundValues.size());
				}
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
				cout << "Caso1. [IN]: 1 1800 1820 COL"; // [OUT]: Colombia,COL,1924,197856
				DList<DList<string>> foundValues1 = search(data, "COL", 1, 1800, 1820);
				if (foundValues1.size() == 0){
					cout << "\nValue not found." << endl;
				}
				else {
					outputData(foundValues1, 0, foundValues1.size());
				}
				cout << "Caso2. [IN]: 0 1800 1820 Terabitia"; // [OUT]: Value not found.
				DList<DList<string>> foundValues2 = search(data, "Terabitia", 0, 1800, 1820);
				if (foundValues2.size() == 0){
					cout << "\nValue not found." << endl;
				}
				else {
					outputData(foundValues2, 0, foundValues2.size());
				}
				break;
			}
		}
	} while (answer != 0);
}


// Read data
DList<DList<string>> readData() {
	DList<DList<string>> data;
	// Read file
	ifstream file;
	file.open("co2_emission_shuffled.csv");
	while(file.good()){
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
		data.push_back(row);
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


void casosPrueba(){

}