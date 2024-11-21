/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CompletedOrder.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:32 pm
 */

#ifndef COMPLETEDORDER_H
#define COMPLETEDORDER_H

#include <iostream>
#include <fstream>
#include "Order.h"
#include "Node.h"
using namespace std;

class CompletedOrder{
private:
    Node* myTop;
    int mySize;
    
public:
    CompletedOrder();
    ~CompletedOrder();
    bool isEmpty() const;
    void addCompletedOrder(Order& );
    Order removeCompletedOrder();
    double totalAmountSold();
    void saveToFile(const char*);
    void loadFromFile(const char*);
    Order search(int) const;
    void displayCompletedOrders(ostream& ) const;
    void displayRevenue();
    
};

ostream& operator<< (const ostream&, const CompletedOrder&);
#endif /* COMPLETEDORDER_H */
