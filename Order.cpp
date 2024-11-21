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
}

Order::Order(int orderId, string custName, MenuItem* items, int orderSize){
    setOrder(orderId, custName, items, orderSize);
}

void Order::setOrder(int orderId, string custName, MenuItem* items, int orderSize){
    setOrderId(orderId);
    setCustName(custName);
    setOrderSize(orderSize);
    calculateTotalAmount(items, orderSize);
    myCapacity = 10;
    
    for(int i = 0; i < orderSize; i++){
        this->items[i] = items[i];
    }
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

MenuItem& Order::getOrderItem(int pos) const {
    return items[pos];
}

bool Order::addOrderItem(MenuItem& item) {
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
            "Items: " << endl;
    
    for(int i = 0; i < orderSize; i++){
        out << items[i] << endl;
    }
}

Order& Order::operator=(const Order& other){
    if(this != &other){
        delete[] items;
        
        myCapacity = other.myCapacity;
        orderId = other.orderId;
        custName = other.custName;
        orderSize = other.orderSize;
        totalAmount = other.totalAmount;
        
        items = new MenuItem[myCapacity];
        for (int i = 0; i < other.orderSize; ++i) {
            items[i] = other.items[i]; 
        }
    }
    
    return *this;
}

ostream& operator<< (ostream& out, const Order& order){
    order.displayOrder(out);
    return out;
}
