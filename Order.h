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
    int orderId, orderSize, myCapacity;
    string custName;
    MenuItem* items;
    double totalAmount;
    
public:
    Order();
    Order(int, string, MenuItem*, int);
    void setOrder(int, string, MenuItem*, int);
    void setOrderId(int);
    int getOrderId() const;
    void setCustName(string);
    string getCustName() const;
    void setOrderSize(int);
    int getOrderSize() const;
    void calculateTotalAmount(MenuItem* , int);
    double getTotalAmount() const;
    MenuItem& getOrderItem(int) const;
    bool addOrderItem(MenuItem&);
    void displayOrder(ostream& ) const;
    Order& operator=(const Order& );
};

ostream& operator<< (ostream&, const Order&);
#endif /* ORDER_H */
