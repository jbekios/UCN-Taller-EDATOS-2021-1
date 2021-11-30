//
// Created by jbekios on 11/29/21.
//

#ifndef UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREE_H
#define UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREE_H


class BinarySearchTree {

private:
    struct BinarySearchTreeNode* root;
    BinarySearchTreeNode* insert(BinarySearchTreeNode*, int);
    BinarySearchTreeNode* remove(BinarySearchTreeNode*, int n);
    void preOrder(BinarySearchTreeNode*);
    BinarySearchTreeNode* findMinimum(BinarySearchTreeNode*);

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int);
    void remove(int);
    void preOrder(void);

//    Node* delete(Node*, int);
//
//    void inOrder(Node*);
//    void preOrder(Node*);
//    void postOrder(Node*);
//    Node* findMinimum(Node*);

//    Node* getRoot() {
//        return root;
//    }
//
//    /* mutator method helps to update root ptr after insertion
//    root is not directly updatable in the main because its private data member */
//    void setRoot(Node* ptr) {
//        root = ptr;
//    }

};


#endif //UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREE_H
