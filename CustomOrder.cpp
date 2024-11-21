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
        return;
    }
    
    myBack->setNext(customOrder);
    myBack = customOrder;
}

Order CustomOrder::dequeue() {
    if(!isEmpty()) {
	Node* temp = myFront;
	myFront = myFront->getNext();
        
	if ( myFront  == NULL ) {
            myBack = NULL;
	}
	temp->setNext(NULL); 
        return temp->getData();
    }
    Order garbage;
    return garbage;
}

bool CustomOrder::isEmpty() const {
	if (myFront == NULL) {
            return true;
	}
	return false;
}

Order CustomOrder::search(int orderId) {
    Node* temp = myFront;
    while(temp != NULL) {
        if (temp->getData().getOrderId() == orderId) {
            return temp->getData();
	}
        
        temp->setNext(temp -> getNext());
    }
    Order garbage;
    return garbage;
}


void CustomOrder::displayCustomOrder(ostream& out) const {
    out << " - - - Active Orders - - - " << endl;
    Node* temp = myFront;
    while(temp != myBack){
        temp->getData().displayOrder(out);
        out << "Status: Pending" << endl;
        out << endl;
    }
}

ostream& operator<< (ostream& out, const CustomOrder& custOrder) {
    custOrder.displayCustomOrder(out);
    return out;
}
