//	Syed Tihami
//  BinaryTree.h
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <iostream>

using namespace std;

//***************************************************************************
//***************************************************************************
//                    Definition of Binary Tree:
//***************************************************************************
//***************************************************************************
template <class D>
class BinaryTree {
private:

	struct btNode {
		D data;
		btNode *left;
		btNode *right;
		btNode() { left = right = nullptr; }
	};

	int count;
	btNode *root;

public:
	BinaryTree() : count(0), root(nullptr) {}
	~BinaryTree() { deleteSubTree(root); }
	BinaryTree(const BinaryTree &obj);
	const BinaryTree &operator=(const BinaryTree &obj);
	void deleteSubTree(btNode *);
	void copySubTree(btNode *, btNode *&);
	void resort();
	void reinsert(btNode *);

	void insert(D value) { insert(value, root); }
	template <class C>
	bool remove(C value) { return remove(value, root); }
	template <class C>
	btNode *search(C value) { return search(value, root); }
	void printIndented(ostream &out = cout) { printIndented(root, 0, out); }
	void printInorder(ostream &out = cout) { printInorder(root, out); }
	btNode *getRoot() { return root; }
	void insert(D, btNode*&);
	template <class C>
	bool remove(C, btNode*&);
	void deleteNode(btNode*&);
	template <class C>
	btNode *search(C, btNode*);
	void printIndented(btNode*, int, ostream &);
	void printInorder(btNode*, ostream &);
	operator LinkedList<D>();
	LinkedList<D> &convertToList(btNode *node, LinkedList<D> &list);
	LinkedList<D> &convertToList(LinkedList<D> &list) { return convertToList(root, list); }

	//Specialized Traversals:
	void printFilePreorder(ostream &out = cout) { printFilePreorder(root, out); }
	void printFilePreorder(btNode*, ostream &);
	void deAllocate() { deAllocate(root); }
	void deAllocate(btNode*);

};







//***************************************************************************
//***************************************************************************
//                   Implementation of Binary Tree:
//***************************************************************************
//***************************************************************************

//***************************************************************************
//Definition of BinaryTree Template Class copy constructor                  *
//***************************************************************************
template <class D>
BinaryTree<D>::BinaryTree(const BinaryTree &obj) {
	copySubTree(obj.root, root);
}

template <class D>
const BinaryTree<D> &BinaryTree<D>::operator=(const BinaryTree<D> &obj) {
	copySubTree(obj.root, root);
	return *this;
}

template <class D>
void BinaryTree<D>::deleteSubTree(btNode *node) {
	if (node) {
		if (node->left) deleteSubTree(node->left);
		if (node->right) deleteSubTree(node->right);
		delete node;
		node = nullptr;
		count--;
	}
}

template <class D>
void BinaryTree<D>::copySubTree(btNode *node, btNode *&newNode) {
	if (node) {
		newNode = new btNode;
		newNode->data = node->data;
		count++;
		if (node->left) {
			copySubTree(node->left, newNode->left);
		}
		if (node->right) {
			copySubTree(node->right, newNode->right);
		}
	}
}

template <class D>
void BinaryTree<D>::resort() {
	if (root) {
		BinaryTree<D> *newTree = new BinaryTree<D>;
		newTree->insert(root->data);
		newTree->reinsert(root->left);
		newTree->reinsert(root->right);
		deleteSubTree(root);
		root = newTree->root;
		newTree->root = nullptr;
	}
}

template <class D>
void BinaryTree<D>::reinsert(btNode *oldNode) {
	if (oldNode) {
		insert(oldNode->data);
		if (oldNode->left) reinsert(oldNode->left);
		if (oldNode->right) reinsert(oldNode->right);
	}
}

template <class D>
void BinaryTree<D>::insert(D value, btNode *&node) {
	if (node) {
		if (node->data >= value) {
			insert(value, node->left);
		}
		else if (node->data < value) {
			insert(value, node->right);
		}
	}
	else {
		node = new btNode;
		node->data = value;
		node->left = node->right = nullptr;
		//balance();
		count++;
	}
}

template <class D>
template <class C>
bool BinaryTree<D>::remove(C value, btNode *&node) {
	if (!node) return false;
	else if (node->data < value)
		return remove(value, node->right);
	else if (node->data > value)
		return remove(value, node->left);
	else if (node->data == value) {
		deleteNode(node);
		count--;
		return true;
	}
	return false;
}

template <class D>
void BinaryTree<D>::deleteNode(btNode *&node) {
	if (!node) throw "ERROR: Cannot delete empty node!";

	btNode *replacement = nullptr;
	if (!node->left) {
		replacement = node->right;
		delete node;
		node = replacement;
	}
	else if (!node->right) {
		replacement = node->left;
		delete node;
		node = replacement;
	}
	else  {
		btNode *tempNode = node->right;
		while (tempNode->left)
			tempNode = tempNode->left;
		btNode temp = *tempNode;
		remove(tempNode->data, node);
		node->data = temp.data;
	}
}

template <class D>
template <class C>
typename BinaryTree<D>::btNode *BinaryTree<D>::search(C value, btNode *node) {
	btNode *location = nullptr;
	if (node) {
		if (node->data == value) {
			location = node;
		}
		else if (node->data >= value) {
			location = search(value, node->left);
		}
		else if (node->data < value) {
			location = search(value, node->right);
		}
	}
	return location;
}

template <class D>
void BinaryTree<D>::printInorder(btNode *node, ostream &out) {
	if (node != nullptr) {
		if (node->left != nullptr) {
			printInorder(node->left, out);
		}
		out <<"\t" << node->data << endl;
		if (node->right != nullptr) {
			printInorder(node->right, out);
		}
	}
}

template <class D>
void BinaryTree<D>::printIndented(btNode *node, int level, ostream &out) {
	if (node) {
		if (node->right) printIndented(node->right, level + 1, out);
		for (int i = 0; i < (level * 3) + 7; i++) {
			if (level == 0) {
				if (i == 0)
					out << "Root-> ";
			}
			else out << ' ';
		}
		out << node->data << endl;
		if (node->left) printIndented(node->left, level + 1, out);
	}
}

template <class D>
void BinaryTree<D>::printFilePreorder(btNode *node, ostream &out) {
	if (node != nullptr) {
		static_cast<Professor*>(node->data)->printToFile(out);
		out << endl;
		if (node->left != nullptr) {
			printFilePreorder(node->left, out);
		}
		if (node->right != nullptr) {
			printFilePreorder(node->right, out);
		}
	}
}

template <class D>
void BinaryTree<D>::deAllocate(btNode* node) {
	if (node) {
		deAllocate(node->left);
		deAllocate(node->right);
		delete static_cast<Professor*>(node->data);
	}
}

template <class D>
LinkedList<D> &BinaryTree<D>::convertToList(btNode *node, LinkedList<D> &list) {
	if (node) {
		list.insertSorted(node->data);
		convertToList(node->left, list);
		convertToList(node->right, list);
	}
	return list;
}

#endif
