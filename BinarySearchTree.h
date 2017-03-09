#ifnedef _BINARYSEARCHTREE_H_
#def _BINARYSEARCHTREE_H_

template <class T>
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
  void insert(T value, bstNode *root = head) {
    if (!data) {
      data = value;
      balance();
    }
    else if (value > data) {
      insert(value, left);
    }
    else if (value < data) {
      insert(value, right)
    }
  }
  void remove(T value);
  void balance();
  bstNode *search(T value);
  void printInOrder();
  void printPreOrder();
  void prePostOrder();
};

#endif
