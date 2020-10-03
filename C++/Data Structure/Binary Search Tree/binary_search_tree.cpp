#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* left;
	Node* right;
};

//function to generate a new node

Node* newnode(int data) {
	//address of new node which stores the data
	Node* new_node = new Node();
	new_node->info = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;

}

//insert node in bst and return root

Node* insert(Node* root, int data) {

	if (root == NULL) {//tree is empty
		root = newnode(data);
	}
	else if (root->info < data) {
		root->right = insert(root->right, data);
	}
	else if (root->info >= data) {
		root->left = insert(root->left, data);
	}

	return root;

}

//search data

bool search(Node* root, int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->info == data) {
		return true;
	}
	else if (root->info >= data) {

		return search(root->left, data);
	}
	else if (root->info < data) {
		return search(root->right, data);
	}
}

// inorder transversal

void inorder(Node* root) {
	if (root != NULL)
	{
		inorder(root->left);
		cout <<"element "<< root->info<<endl;
		inorder(root->right);
	}
}

//main func
void main() {
	//head pointing to the first node
	Node* head = new Node();
	head = NULL;
	//insertion in bst
	/*head = insert(head, 15);
	head = insert(head, 10);
	head = insert(head, 25);
	head = insert(head, 8);
	head = insert(head, 12);
	head = insert(head, 19);*/

	int k,l;
	cout << "enter number of nodes";
	cin >> k;
	for (int i = 0; i < k; i++) {
		cout << "enter element ";
		cin >> l;
		head = insert(head, l);
	}
	//searchin data in bst
	int n;
	cout << "elements are "<<endl;
    inorder(head);
	cout << "enter data to be found";
	cin >> n;
	if (search(head, n) == true) {
		cout << "Element found";
	}
	else {
		cout << "not found";
	}

}