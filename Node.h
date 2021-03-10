#include <iostream>
#include <sstream>
#include <string>
#include "NodeInterface.h"

class Node : public NodeInterface {

public:
	Node * left;
	Node * right;
	int data;

	Node(int value) {
		// intialize each node to have "value" and two "sub-nodes" (left, right)
		data = value;
		left = NULL;
		right = NULL;
	}
	~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData()  const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	Node * getLeftChild()  const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	Node * getRightChild()  const;

};