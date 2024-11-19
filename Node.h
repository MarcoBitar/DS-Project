/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:56 pm
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

typedef Order ElementType;

class Node{
private:
    ElementType data;
    Node* next;
    
public:
    Node(const ElementType&);
    void setData(const ElementType&);
    ElementType& getData();
    void setNext(Node* );
    Node* getNext();
};
#endif /* NODE_H */
