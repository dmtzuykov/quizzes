// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;
struct Node
{
	int data;
	 Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = nullptr;
	}
};

 void printPostorder( Node* node)
{
	if (node == nullptr)
		return;

	// first recur on left subtree 
	printPostorder(node->left);

	// then recur on right subtree 
	printPostorder(node->right);

	// now deal with the node 
	cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder( Node* node)
{
	if (node == nullptr)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder( Node* node)
{
	if (node == nullptr)
		return;

	/* first print data of node */
	cout << node->data << " ";

	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

int main()
{
	 Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}