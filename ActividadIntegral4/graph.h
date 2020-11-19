/*
 * Proyecto: Actividad Integral 4 .- Grafos (Evidencia Competencia)
 * Autor: Luis Ramirez
 * Fecha de creación: 18/11/2020
 * Archivo: graph.h
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
void print_vector(vector<T> vec);


template<class T>
class Graph {
	private:
	bool directed;
	vector<T> nodes_list;
	vector<vector<int>> adj_list;
	int nu_nodes = 0;
	int nu_edges = 0;

	public:
	Graph(){}
	Graph(bool d);
	void add_node(T val);
	void add_edge(T init_val, T target_val);
	T node_with_more_conections();
	vector<T> search(T p1, T p2);
	vector<T> BFS(int init_vertex, int target_vertex);
	string print_adj_list(bool indices);
	string print_nodes_list();
};




template<class T>
Graph<T>::Graph(bool d){
	directed = d;
}


template<class T>
void Graph<T>::add_node(T val){
	// Check if value already in nodes list
	for (int i=0; i<nodes_list.size(); i++){
		if (nodes_list[i] == val) return;
	}
	nodes_list.push_back(val);	
	// Expand the adjecency list
	vector<int> new_row;
	adj_list.push_back(new_row);
}


template<class T>
void Graph<T>::add_edge(T init_val, T target_val){
	int init_index = -1;
	int target_index = -1;

	for (int i=0; i<nodes_list.size(); i++){
		if (nodes_list[i] == init_val) init_index = i;
		if (nodes_list[i] == target_val) target_index = i;
	}
	if (init_index == -1 || target_index == -1){
		cout << "Node not found.\n";
		return;
	}
	adj_list[init_index].push_back(target_index);
	if (!directed)
		adj_list[target_index].push_back(init_index);
}


template<class T>
vector<T> Graph<T>::search(T p1, T p2){
	int i1;
	int i2;
	for (int i=0; i<nodes_list.size(); i++){
		if (nodes_list[i] == p1) i1 = i;
		if (nodes_list[i] == p2) i2 = i;
	}

	vector<T> results = BFS(i1, i2);
	return results;
}


template<class T>
T Graph<T>::node_with_more_conections(){
	int max=0;
	T node;
	for (int i=0; i<adj_list.size(); i++){
		if (adj_list[i].size() > max){
			max = adj_list[i].size();
			node = nodes_list[i];
		}
	}
	return node;
}


template<class T>
vector<T> Graph<T>::BFS(int init_vertex, int target_vertex){
	vector<int> queue;
	vector<bool> visited(nodes_list.size(), false);
	vector<T> path;
	int current;
	queue.push_back(init_vertex);
	do {
		// Dequeue
		current = queue[0];
		queue.erase(queue.begin());
		// Checar si ya esta visitado
		if (!visited[current]){
			// Marcar como visitado
			visited[current] = true;
			path.push_back(nodes_list[current]);
			// Agregar hijos
			for (int item : adj_list[current])
				queue.push_back(item);
		} 
	// Checar si es el valor
	} while (current != target_vertex);
	
	return path;
}


template<class T>
string Graph<T>::print_adj_list(bool indices){
	string result = "";
	// Indices
	if (indices){
		for(int i=0; i<20; i++){
			result += "vertex " + to_string(i) + " : ";
			for(int j=0; j<adj_list[i].size(); j++){
				result += to_string(adj_list[i][j]) + " ";
			}
			result += "\n";
		}
	} else {
	// Codes
		for(int i=0; i<20; i++){
			result += "vertex " + nodes_list[i] + " : ";
			for(int j=0; j<adj_list[i].size(); j++){
				result += nodes_list[adj_list[i][j]] + " ";
			}
			result += "\n";
		}
	}
	
	return result;
}


template<class T>
string Graph<T>::print_nodes_list(){
	string result = "";
	for (int i=0; i<nodes_list.size(); i++){
		result += to_string(i) + " " + nodes_list[i] + "\n";
	}
	return result;
}


template<class T>
void print_vector(vector<T> vec){
	for (T v : vec){
		cout << v << " ";
	}
	cout << endl;
}