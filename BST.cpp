#include "BST.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	Node * BST::getRootNode() const {
		return root;
	}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::add(int data) {
		// cout << "add " << data <<endl;
	  //   Node *ptr = new Node(data);
	  //   ptr->left = NULL; // To test that the friend relationship works
	  //   NodeInterface *rval = ptr->getLeftChild();
	  //   long value = (long)rval;
	  //   cout << "Added "<<value<<endl;
	  //   root = ptr;
		addFunction(root, data);
	}

	bool BST::addFunction(Node*& temp, int data) {
		/* 
		The node *& is a reference to a pointer 
		(change the memory address pointed to by the pointer), 
		whereas node* is simply a pointer.  
		*/
		if(temp == NULL) {
			// cout << "add valuye" << endl;
			temp = new Node(data);
			numItem++;
			return true;
		}

			if (data < temp->data) {
				// cout << "left" << endl;
			return addFunction(temp->left, data);
		}
			else if (data > temp->data) {
				// cout << "right" << endl;
			return addFunction(temp->right, data);
		}
			else  {
				// cout << "wrong" << endl;
				return false;
			}
	
	}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::remove(int data) {
		return removeFunction(root ,data);
	}

	bool BST::removeFunction(Node*& tempRoot, int data) {
		if (tempRoot == NULL) {
			return false;
		}
		else {
			if (data < tempRoot->data) {
				return removeFunction(tempRoot->left, data);
		  }
			else if (data > tempRoot->data) {
				return removeFunction(tempRoot->right, data);
			}
			else { // item is the tempRoot
				Node* oldRoot = tempRoot;
				// if (tempRoot->left == NULL && tempRoot->left == NULL) { // no children
				// 	cout << "remove no children " << data << endl;
				// 	// delete tempRoot;
				// 	tempRoot = NULL;
				// 	numItem--;
				// 	// delete oldRoot;
				// 	// return true;
				// }
				// else 
				if (tempRoot->left == NULL) {
						cout << "remove one child " << data << endl;
						tempRoot = tempRoot->right;
						numItem--;
						// delete tempRoot->right;
						delete oldRoot;
						// return true;
				}
				else if (tempRoot->right == NULL) {
					cout << "remove one child" << data << endl;
					tempRoot = tempRoot->left;
					numItem--;
					// delete tempRoot->left;
					delete oldRoot;
					// return true;
			}
			else {
				cout << "remove 2 children " << data << endl;
				replace(oldRoot, tempRoot->left);
				// return true;
			}
			//delete oldRoot;
			return true;
	}
	}
	}

	void BST::replace(Node*& oldRoot, Node*& tempRoot) {
		if (tempRoot->right != NULL) {
			replace(oldRoot, tempRoot->right);
		}
		else {
			oldRoot->data = tempRoot->data;
			removeFunction(oldRoot->left, tempRoot->data);
		}
	}
	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear() {
		recursiveClear(root);
		root = NULL;
	}

	void BST::recursiveClear(Node*& tempRoot) {
		if (tempRoot != NULL) {
			recursiveClear(tempRoot->left);
			recursiveClear(tempRoot->right);
			delete tempRoot;
		}
	}