/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Order.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:27 pm
 */

#include "Order.h"
Order::Order(){
    setOrder(-1, "", NULL, 0);
    myCapacity = 20;
}

Order::Order(int orderId, string custName, MenuItem* items, int orderSize){
    setOrder(orderId, custName, items, orderSize);
    myCapacity = 20;
}

void Order::setOrder(int orderId, string custName, MenuItem* items, int orderSize){
    setOrderId(orderId);
    setCustName(custName);
    items = new MenuItem[myCapacity];
    setOrderSize(orderSize);
    calculateTotalAmount(items, orderSize);
}

void Order::setOrderId(int orderId){
    this->orderId = orderId;
}

int Order::getOrderId() const{
    return orderId;
}

void Order::setCustName(string custName){
    this->custName = custName;
}

string Order::getCustName() const{
    return custName;
}

void Order::setOrderSize(int orderSize){
    this->orderSize = orderSize;
}

int Order::getOrderSize() const{
    return orderSize;
}

void Order::calculateTotalAmount(MenuItem* items, int orderSize){
    for(int i = 0; i < orderSize; i++){
        totalAmount += items[i].getPrice();
    }
}

double Order::getTotalAmount() const{
    return totalAmount;
}

MenuItem* Order::getMenuItem(int id) const {
    for(int )
}

bool Order::addMenuItem(MenuItem& item) {
    if(orderSize == myCapacity){
        myCapacity *= 2;
        MenuItem* temp = new MenuItem [myCapacity];
        
        for(int i = 0; i < orderSize; i++){
            temp[i] = items[i];
        }
        
        delete[] items;
        items = temp;
    }
    
    items[orderSize] = item;
    orderSize++;
    return true;
}

void Order::displayOrder(ostream& out) const{
    out << "Order ID: " << orderId <<
            ", Customer: " << custName << endl <<
            "Items: ";
    
    for(int i = 0; i < orderSize; i++){
        out << items[i] << endl;
    }
}

Order& Order::operator=(const Order& other){
    if(this != &other){
        setOrder(other.orderId, other.custName, other.items, other.orderSize);
        calculateTotalAmount(other.items, other.orderSize);
    }
    
    return *this;
}

/*istream& operator>>(istream& in, Order& order) {
    int orderId, orderSize;
    string custName;
    
    cout << "Enter Order ID: ";
    in >> orderId;
    cout << "Enter Customer Name: ";
    in >> custName;
    cout << "Enter the number of items: ";
    in >> custName;
    return in;
}*/

ostream& operator<< (ostream& out, const Order& order){
    order.displayOrder(out);
    return out;
}

