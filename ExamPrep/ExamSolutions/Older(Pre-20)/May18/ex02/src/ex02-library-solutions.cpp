#include "ex02-library.h"

#include <iostream>

//Do not modify
void printSet(set<string> s){
	if(s.size()==0){
		cout << " No nodes\n";
	}
	else{
		set<string>::iterator it;
		for (it=s.begin(); it!=s.end(); ++it){
			cout << ' ' << *it << "\n";
		}
	}
	cout << "\n";
}

//Exercise 2 (a) Check and correct if necessary
void computeLeaves(Node *n, set<string> & leaves){
	if(n->left == nullptr && n->right == nullptr){
		leaves.insert(n->name);
	}
	else{
		if(n->left != nullptr){
			computeLeaves(n->left,leaves);
		}
		if(n->right != nullptr){
			computeLeaves(n->right,leaves);
		}
	}
}

/*
void computeLeavesWRONG(Node *n, set<string> & leaves){
	if(n->left == nullptr && n->right == nullptr){
		leaves.insert(n->name);
	}
	else{
		computeLeaves(n->left,leaves);
		computeLeaves(n->right,leaves);
	}
}
*/

//Exercise 2 (b) Implement this function
int countDescendants(Node * n){
	int descendants=0;
	if(n->left != nullptr){
		descendants+=1;
		int leftDescendants=countDescendants(n->left);
		descendants+=leftDescendants;
	}
	if(n->right != nullptr){
		descendants+=1;
		int rightDescendants=countDescendants(n->right);
		descendants+=rightDescendants;
	}
	return descendants;
}
