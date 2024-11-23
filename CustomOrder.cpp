/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CustomOrder.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:26 pm
 */

#include "CustomOrder.h"
#include "Node.h" 

CustomOrder::CustomOrder() {
    myFront = NULL;
    myBack = NULL;
    mySize = 0;
}

CustomOrder::~CustomOrder() {
    while (!isEmpty()) {
	dequeue();
    }
}

void CustomOrder::enqueue(const Order& order) {
    Node* customOrder = new Node(order);
    if (isEmpty()) {
        myFront = customOrder;
        myBack = customOrder; 
        mySize++;
        return;
    }
    
    myBack->setNext(customOrder);
    myBack = customOrder;
    mySize++;
}

Order CustomOrder::dequeue() {
    if(!isEmpty()) {
	Node* temp = myFront;
	myFront = myFront->getNext();
        
	if ( myFront  == NULL ) {
            myBack = NULL;
	}
	temp->setNext(NULL); 
        mySize--;
        return temp->getData();
    }
    
    Order garbage;
    return garbage;
}

bool CustomOrder::isEmpty() const {
	if (mySize == 0) {
            return true;
	}
	return false;
}

Node* CustomOrder::search(int orderId) {
    Node* temp = myFront;
    while(temp != NULL) {
        if (temp->getData().getOrderId() == orderId) {
            return temp;
	}
        
        temp->setNext(temp->getNext());
    }

    return temp;
}

bool CustomOrder::deleteOrder(int orderId){
    Node* temp = search(orderId);
    
    if(isEmpty() || temp == NULL){
        return false;
        
    } else if (temp == myFront) {
        myFront = myFront->getNext();
        if(myFront == NULL){
            myBack == NULL;
        }
        
    } else{
        Node* prev = myFront;
        
        while(prev->getNext() != temp){
            prev = prev->getNext();
        }
        
        prev->setNext(temp->getNext());
        
        if(temp == myBack){
            myBack = prev;
        }
    }
    
    delete temp;
    mySize--;
    return true;
}

int CustomOrder::size(){
    return mySize;
}


void CustomOrder::displayCustomOrder(ostream& out) const {
    if(isEmpty()){
        out << "No active orders" << endl;
    } else {
        out << "--- Active Orders ---" << endl;
        Node* temp = myFront;
        while (temp != NULL) {
            temp->getData().displayOrder(out);
            out << "Status: Pending" << endl;
            out << endl;
            temp = temp->getNext();
        }
    }
    
}

ostream& operator<< (ostream& out, const CustomOrder& custOrder) {
    custOrder.displayCustomOrder(out);
    return out;
}
