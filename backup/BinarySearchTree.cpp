//
// Created by jbekios on 11/29/21.
//

#include "BinarySearchTree.hpp"
#include "BinarySearchTreeNode.hpp"

#include <iostream>
using namespace std;

void BinarySearchTree::insert(int n) {
    root = insert(root, n);
}

BinarySearchTreeNode* BinarySearchTree::insert(BinarySearchTreeNode* node, int n) {
    //Si el árbol no tiene hijos
    if (node == nullptr){
        node = new BinarySearchTreeNode();
        node->key = n;
        node->left = nullptr;
        node->right = nullptr;

        return node;
    } else if (n < node->key){
        node->left = insert(node->left, n);
    } else if (n > node->key){
        node->right = insert(node->right, n);
    }

    return node;

}

void BinarySearchTree::preOrder(void) { // Public
    preOrder(root);
}

void BinarySearchTree::preOrder(BinarySearchTreeNode* node) {
    if(node == nullptr) return;
    cout << node->key << "\t";
    preOrder(node->left);
    preOrder(node->right);
}

void BinarySearchTree::remove(int n) { // Public
    remove(root, n);
}

BinarySearchTreeNode *BinarySearchTree::remove(BinarySearchTreeNode* node, int n) {
    // El nodo no se encuentra en el árbol
    if (node == nullptr){
        return node;
    }else if (n < node->key){ // Busco la clave por la izquierda
        node->left = remove(node->left, n);
    }else if (n > node->key){ // Busco la clave por la derecha
        node->right = remove(node->right, n);
    }else{ //Encontré la clave y la borro
        //Si es nodo hoja
        if (node->left == nullptr && node->right == nullptr){
            delete node;
            node = nullptr;
        }else if (node->left == nullptr){ //El nodo a eliminar tiene solo un hijo derecho
            BinarySearchTreeNode* aux = node;
            node = node->right;
            delete aux;
        }else if (node->right == nullptr){ //El nodo a eliminar tiene solo un hijo izquierdo
            BinarySearchTreeNode* aux = node;
            node = node->left;
            delete aux;
        }else{
            BinarySearchTreeNode* aux = findMinimum(node->right);
            node->key = aux->key;
            node->right = remove(node->right, aux->key);
        }
    }
    return node;
}


BinarySearchTreeNode* BinarySearchTree::findMinimum(BinarySearchTreeNode* node) {
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}
