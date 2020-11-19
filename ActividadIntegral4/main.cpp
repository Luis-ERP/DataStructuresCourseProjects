/*
 * Proyecto: Actividad Integral 4 .- Grafos (Evidencia Competencia)
 * Autor: Luis Ramirez
 * Fecha de creación: 18/11/2020
 * Archivo: main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "graph.h"
using namespace std;

// Declaration of functions
void read_airport_conections(Graph<string> &graph);
void read_airports(Graph<string> &graph);
void print_vector(vector<string> vec);


int main() {
	int answer;
	Graph<string> graph(true);
	read_airports(graph);
	read_airport_conections(graph);

	do {
		cout << "\nWelcome to the the flights-airports conection system\n";
		cout << "0. Exit\n";
		cout << "1. Aeropuerto con  más conecciones\n";
		cout << "2. Buscar código de aeropuerto\n";
		cout << "3. Casos de prueba\n";
		cout << "-> ";
		cin >> answer;
		cout << endl;

		switch(answer){
			case 1: {
				cout << graph.node_with_more_conections() << endl;
				break;
			}

			case 2 : {
				string p1;
				string p2;
				cout << "Código del aeropuerto de entrada -> ";
				cin >> p1;
				cout << "Código del aeropuerto de salida -> ";
				cin >> p2;
				vector<string> result = graph.search(p1, p2);
				print_vector(result);
				break;
			}

			case 3 : {
				cout << "[IN]: 1\n";
				cout << "[OUT]:" << graph.node_with_more_conections()<<endl<<endl;
				cout << "[IN]: 2 ABE DTW\n";
				vector<string> result = graph.search("ABE", "DTW");
				cout << "[OUT]:";
				print_vector(result);
				cout << endl;
				cout << "[IN]: 2 ABQ SLC\n";
				result = graph.search("ABQ", "SLC");
				cout << "[OUT]:";
				print_vector(result);
				cout << endl;
			}
		}
	} while (answer != 0);
	
}


// Read data
void read_airports(Graph<string> &graph){
	// Read file
	ifstream file;
	file.open("aeropuertos.csv");

	while(file.good()){
		string name;
		string code;
		string trash;
		// Read line
		getline(file, name, ',');
		getline(file, code, ',');
		getline(file, trash, '\n');
		// Add node
		graph.add_node(code);
	}
	file.close();
}


void read_airport_conections(Graph<string> &graph){
	// Read file
	ifstream file;
	file.open("vuelos.csv");

	while(file.good()){
		string aeropuerto_i;
		string aeropuerto_j;
		string trash;
		// Read line
		getline(file, aeropuerto_i, ',');
		getline(file, aeropuerto_j, ',');
		getline(file, trash, '\n');
		// Add edge
		graph.add_edge(aeropuerto_i, aeropuerto_j);
	}
	file.close();
}


void print_vector(vector<string> vec){
	for (string v : vec){
		cout << v << " ";
	}
	cout << endl;
}