#ifnedef _BINARYSEARCHTREE_H_
#def _BINARYSEARCHTREE_H_

//template <class T>
//This will be used with a collection of pointers to LinkedList<Professor> Nodes
class BinarySearchTree {
private:
  bstNode *head;
  struct bstNode {
    bstNode *left;
    bstNode *right;
    T data;
  }
public:
  BinarySearchTree() {}
  ~BinarySearchTree() {}
  insert(T value);
  remove(T value);
  balance();
  search(T value);
  printInOrder();
  printPreOrder();
  prePostOrder();
};

#endif
