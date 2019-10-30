#include "pch.h"
#include "BST.h"


struct BST::Node
{
	Key key;
	Item item;
	Node* leftChild;
	Node* rightChild;

	Node(Key k, Item i) :
		key(k),
		item(i),
		leftChild(nullptr),
		rightChild(nullptr)
	{
	}
};

BST::BST() :
	root(nullptr)
{
}

BST::~BST()
{
	if(!isLeaf(root))
		deepDelete(root);
}

BST::BST(const BST& original)
{
	this->root = deepCopy(original.root);
}


BST::Item* BST::lookup(Key k)
{
	/*Node* current = root;
	while (true)
	{
		if (current->key == k)
			return &current->item;
		else if (current->key > k)
			current = current->rightChild;
		else
			current = current->leftChild;
	}
	current = nullptr;
	return nullptr;*/

	return lookupRec(k, root);
}

BST::Item* BST::lookupRec(Key soughtKey, Node* currentNode)
{
	if (isLeaf(currentNode))
		return nullptr;
	if (currentNode->key == soughtKey)
		return &currentNode->item;
	else if (currentNode->key < soughtKey)
		return lookupRec(soughtKey, currentNode->rightChild);
	else
		return lookupRec(soughtKey, currentNode->leftChild);
}

void BST::insert(Key k, Item i)
{
	return insertRec(k, i, root);
}

void BST::insertRec(Key k, Item i, Node*& current)
{
	if (isLeaf(current))
	{
		Node* n = new Node(k, i);
		current = n;

		//n = nullptr; <-- dunno if i should ave this one or not
	}
	else if (current->key < k)
	{
		insertRec(k, i, current->rightChild);
	}
	else
	{
		insertRec(k, i, current->leftChild);
	}
}

bool BST::isLeaf(Node* n)
{
	return (n == nullptr);
}

void BST::displayEntries(std::ostream& os) const
{
	if (root != nullptr)
		displayEntryRec(os, root);
}

void BST::displayEntryRec(std::ostream& os, Node* n) const
{
	if (!isLeaf(n))
	{
		displayEntryRec(os, n->leftChild);
		os << n->item;
		displayEntryRec(os, n->rightChild);
	}
}

void BST::displayTree()
{
	displayTreeRec(root);
}

void BST::displayTreeRec(Node* n, std::string index)
{
	if (isLeaf(n))
		std::cout << index << "*" << std::endl;
	else
	{
		std::cout << index << n->item << " " << n->key << std::endl;
		displayTreeRec(n->leftChild, index + "    ");
		displayTreeRec(n->rightChild, index + "    ");
	}
}

std::ostream& operator<<(std::ostream& os, const BST& bst)
{
	bst.displayEntries(os);
	return os;
}

void BST::remove()
{
	if(!isLeaf(root))
		deepDelete(root);
}

void BST::deepDelete(Node*& n)
{
	if (!isLeaf(n->leftChild))
	{
		deepDelete(n->leftChild);
	}

	if (!isLeaf(n->rightChild))
	{
		deepDelete(n->rightChild);
	}

	delete n;
	n = nullptr;
}

BST::Node* BST::deepCopy(Node* original)
{
	Node* newNode = nullptr;
	if (!isLeaf(original))	{		newNode = new Node(original->key, original->item);		newNode->leftChild = deepCopy(original->leftChild);		newNode->rightChild = deepCopy(original->rightChild);	}	return newNode;
}