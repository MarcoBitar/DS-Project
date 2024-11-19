/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Order.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:27 pm
 */

#ifndef ORDER_H
#define ORDER_H

#include <cstring>
#include <iostream>
#include "MenuItem.h"
using namespace std;

class Order {
private:
    int orderId;
    string custName;
    MenuItem* items;
    double totalAmount;
    
public:
    Order(int, string, MenuItem*);
    void displayOrder(ostream& ) const;
    Order& operator=(Order&);
};

ostream& operator<< (const ostream&, const Order&);
#endif /* ORDER_H */
