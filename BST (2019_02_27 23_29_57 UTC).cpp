//
//  BST.cpp
//  TreeProject
//
//  Created by Toby Dragon on 11/13/14.
//  Copyright (c) 2014 Toby Dragon. All rights reserved.
//

#include <iostream>
#include "BST.h"

//O(1)
BST::BST(){
    root = nullptr;
}

//O(n)
void deleteSubTree(BTNode* current){
    if (current != nullptr) {
        deleteSubTree(current->getLeft());
        deleteSubTree(current->getRight());
        delete current;
    }
}

//O(n)
BTNode* copyTree(BTNode* treeToCopy){
    BTNode* newNode;
    if(treeToCopy != nullptr){
        newNode = new BTNode(treeToCopy->getItem());
        newNode->setLeft(copyTree(treeToCopy->getLeft()));
        newNode->setRight(copyTree(treeToCopy->getRight()));
    }else{
        return nullptr;
    }return newNode;
}

//O(n)
BST::BST(const BST& treeToCopy){
    ::copyTree(treeToCopy.root);
}

//O(n)
BST& BST::operator=(const BST& treeToCopy){
    if(this->root != treeToCopy.root){
        deleteSubTree(this->root);
        ::copyTree(treeToCopy.root);
        return *this;
    }else{
        return *this;
    }
}

//O(n)
BST::~BST(){
    deleteSubTree(root);
}

//O(h)
void add(BTNode* current,  int newValue){
    if (newValue == current->getItem()){
        throw DuplicateValueException();
    }
    else if (newValue < current->getItem()){
        BTNode* child = current->getLeft();
        if (child != nullptr){
            add(child, newValue);
        }
        else {
            current->setLeft(new BTNode(newValue));
        }
    }
    else { //newValue > current->getItem()
        BTNode* child = current->getRight();
        if (child != nullptr){
            add(child, newValue);
        }
        else {
            current->setRight(new BTNode(newValue));
        }
    }
}

//O(h)
void BST::add(int newValue){
    if (root == nullptr){
        root = new BTNode(newValue);
    }
    else {
        ::add(root, newValue);
    }
}

//O log(n)
bool find(BTNode *current, int itemToFind) {
    if (current == nullptr){
        return false;
    }
    else {
        if (current->getItem() == itemToFind) {
            return true;
        } else if (current->getItem() > itemToFind) {
            return find(current->getLeft(), itemToFind);
        } else {
            return find(current->getRight(), itemToFind);
        }
    }
}

//O log(n)
bool BST::find(int itemToFind) {
    return ::find(root, itemToFind);
}

//O(n)
void printInOrder(BTNode* current){
    if(current != nullptr){
        if(current->getLeft() != nullptr){
            printInOrder(current->getLeft());
        }
        std::cout<<current->getItem()<<", ";
        if(current->getRight() != nullptr){
            printInOrder(current->getRight());
        }

    }else{
        std::cout<<"Empty Tree"<<std::endl;
    }
}

//O(n)
void BST::printInOrder(){
    ::printInOrder(root);
}

//O(n)
int itemCount(BTNode* current, int count){
    if (current != nullptr) {
        return 1 + itemCount(current->getLeft(), count) + itemCount(current->getRight(), count);
    }else{
        return count;
    }
}

//O(n)
int BST::itemCount(){
    int count = 0;
    return ::itemCount(root, count);
}

//O(n)
int height(BTNode* current){
    if(current == nullptr){
        return -1;
    }else{
        int left = height(current->getLeft());
        int right = height(current->getRight());
        return 1 + std::max(left, right);
    }
}

//O(n)
int BST::height(){
    int count = 0;
    return ::height(root);
}

//O(n)
int max(BTNode* current){
    if(current == nullptr){
        throw std::out_of_range("Empty Tree");
    }if(current->getRight() == nullptr){
        return current->getItem();
    }return max(current->getRight());
}

//O(n)
int BST::max(){
    return ::max(root);
}







