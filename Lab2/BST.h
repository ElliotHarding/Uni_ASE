#pragma once
#include <string>
#include <iostream>

class BST
{
public:
	using Key = int;
	using Item = std::string;

	BST();
	~BST();
	BST(const BST&);
	void insert(Key, Item);
	Item* lookup(Key);
	void displayTree();
	void remove();

private:
	struct Node;
	Node* root;

	static bool isLeaf(Node*);
	static Item* lookupRec(Key, Node*);
	static void insertRec(Key, Item, Node*&);
	void removeRec(Node*&);
	void displayEntryRec(std::ostream& os, Node* n) const;
	void displayTreeRec(Node* n, std::string index = "");
	void displayEntries(std::ostream& os) const;	

	friend std::ostream& operator<<(std::ostream&, const BST&);
};

std::ostream& operator<<(std::ostream&, const BST&);

