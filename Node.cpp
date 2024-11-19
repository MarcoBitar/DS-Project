/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:56 pm
 */

#include "Node.h"
using namespace std;

Node::Node(const ElementType& n){
    data = n;
    next = NULL;
}

void Node::setData(const ElementType& n){
    data = n;
}

ElementType& Node::getData(){
    return data;
}

void Node::setNext(Node* newNext){
    next = newNext;
}

Node* Node::getNext(){
    return next;
}