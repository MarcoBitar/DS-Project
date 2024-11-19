/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CustomOrder.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:26 pm
 */

#ifndef CUSTOMORDER_H
#define CUSTOMORDER_H

#include <cstring>
#include <iostream>
#include "Order.h"
#include "Node.h"
using namespace std;

class CustomOrder{
private:
    int mySize;
    Node* myFront;
    Node* myBack;
    
public:
    CustomOrder();
    ~CustomOrder();
    void enqueue(const Order&);
    Order dequeue();
    bool isEmpty()const;
    Order search(int);
    void displayCustomOrder(ostream&) const;
    
};

ostream& operator<< (const ostream&, const CustomOrder&);
#endif /* CUSTOMORDER_H */
