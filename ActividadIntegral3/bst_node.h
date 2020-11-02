/*
 * node.h
 *
 *  Created on: 14/10/2020
 *      Author: Luis Ramirez
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Para que funcione el friend BST tenemos que definir BST
template <class T, class S> class BST;



template<class T, class S>
class Node_bst{
	private:
	T val;
	S* ptr;
	int level;
	Node_bst<T, S>* left;
	Node_bst<T, S>* right;

	public:
	Node_bst(){}
	Node_bst(T _val, S* _ptr, int _level){
		val = _val; 
		ptr = _ptr;
		level = _level;
	}

	int level_at(T _val);
	void add(T _val, S* _ptr, int current_depth, int& max_depth);
	S* search(T _val);
	void visit(vector<int>& prints, vector<int>& depths, int check);
	void ancestors(T _val, vector<T>& ancestors_vec);

	friend class BST<T, S>;
};


// --------------------------------------------------------------------


template<class T, class S>
void Node_bst<T, S>::add(T _val, S* _ptr, int current_depth, int& max_depth){
	current_depth++;
	if (_val == val){
		return;
	}
	else if (_val < val){
		if (left != 0){
			left->add(_val, _ptr, current_depth, max_depth);
		}
		else{
			Node_bst<T, S>* new_node = new Node_bst<T, S>(_val, _ptr, current_depth+1);
			left = new_node;
			if (current_depth > max_depth){
				max_depth = current_depth;
			}
		}
	}
	
	else {
		if (right != 0){
			right->add(_val, _ptr, current_depth, max_depth);
		}
		else{
			Node_bst<T, S>* new_node = new Node_bst<T, S>(_val, _ptr, current_depth+1);
			right = new_node;
			if (current_depth > max_depth){
				max_depth = current_depth;
			}
		}
	}
	
}


template<class T, class S>
S* Node_bst<T, S>::search(T _val){
	if (_val == val) return ptr;
	else if (_val < val){
		if (left != 0) return left->search(_val);
	}
	else{
		if (right != 0) return right->search(_val);
	}
	return 0;
}


template<class T, class S>
void Node_bst<T, S>::visit(vector<int>& prints, vector<int>& depths, int check){
	// Add +1
	int counter = 1;
	if (counter == check)
		prints.push_back(val);
	// Visit left node
	if (left != 0){
		left->visit(prints, depths, check);
	}
	// Add +1
	counter++;
	if (counter == check)
		prints.push_back(val);
	// Visit right node
	if (right != 0){
		right->visit(prints, depths, check);
	}
	// Add +1
	counter++;
	if (counter == check)
		prints.push_back(val);
}


template<class T, class S>
int Node_bst<T, S>::level_at(T _val){
	if (_val == val){
		return level;
	}
	if (left != 0){
		if (_val < val) return left->level_at(_val);
	}
	if (right != 0){
		if (_val > val) return right->level_at(_val);
	}
	return -1;
}



template<class T, class S>
void Node_bst<T, S>::ancestors(T _val, vector<T>& ancestors_vec){
	if (_val == val) return;
	
	if ((_val > val) && (right != 0)){
		ancestors_vec.push_back(val);
		right->ancestors(_val, ancestors_vec);
	} else {
		ancestors_vec = {};
	}	
}