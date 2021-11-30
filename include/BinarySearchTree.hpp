//
// Created by jbekios on 11/29/21.
//

#ifndef UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREE_H
#define UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREE_H

#include "opencv2/core.hpp"

using namespace cv;

class BinarySearchTree {

private:
    const int DIFFERENT = 1700;
    const int SIMILAR = 1300;
    /**
     * Contador para asignar identificadores a las caras
     */
    int counter;
    struct BinarySearchTreeNode* root;
    BinarySearchTreeNode* insert(BinarySearchTreeNode* node, Mat);
    double euclideanDistance(Mat, Mat);

public:
    BinarySearchTree() {
        counter = 0;
        root = nullptr;
    }

    void insert(Mat);

    //TODO: Falta hacer el destructor para eliminar cualquier el arbol complementamente
};


#endif //UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREE_H
