#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;
//using std::to_string;
//using std::stoi;



struct node {
	int element;
	node *next;
};

node *new_node(int x) {
	node *temp = new node();
	temp ->next = NULL;
	temp ->element = x;
	return temp;
}

// add x in front of linked list.
void push(node **root, int x) {
	node *head_temp = new_node(x);
	head_temp -> next = (*root);
	(*root) = head_temp;
}

void pinrtLList(node *L1) {
	while(L1) {
		cout << L1->element << " -> ";
		L1 = L1 ->next;
	}
	cout << "\n";
	return;
}



long long multiplyTwoLists(node *L1, node *L2) {
	long long x1 = 0, x2 = 0;
	while (L1 || L2) {
		if (L1) {
			x1 = x1 * 10 + L1->element;
			L1 = L1 ->next;
		}
		
		if (L2) {
			x2 = x2 * 10 + L2->element;
			L2 = L2 ->next;
		}
		
	}
	
	return (x1*x2);
}

/*
 long long multiplyTwoLists_v2(node *L1, node *L2) {
 
 int len1 = 0, len2 = 0;
 string s1 = "", s2 = "";
 
 // calculate the len of L1
 while (L1 != NULL) {
 s1 += std::to_string(L1->element);
 len1 += 1;
 L1 = L1->next;
 }
 
 // calculate the len of L2
 while (L2 != NULL) {
 s2 += to_string(L2->element);
 len2 += 1;
 L2 = L2->next;
 }
 
 if (len1 = 0) return std::stoi(s2);
 if (len2 = 0) return std::stoi(s1);
 
 long long product_result;
 product_result = stoi(s1) * stoi(s2);
 return product_result;
 }
 */

int main() {
	node *L1 = NULL;
	node *L2 = NULL;
	push(&L1, 1);
	push(&L1, 2);
	push(&L1, 3);
	pinrtLList(L1);
	
	push(&L2, 5);
	push(&L2, 0);
	pinrtLList(L2);
	
	long long res;
	res = multiplyTwoLists(L1, L2);
	cout << "product: " << res << "\n";
	
	return 0;
}
