/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CompletedOrder.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:32 pm
 */

#include "CompletedOrder.h"

CompletedOrder::CompletedOrder(){
    myTop = NULL;
    mySize = 0;
}

CompletedOrder::~CompletedOrder(){
    if(!isEmpty()){
        mySize = 0;
        
        while(myTop != NULL){
            Node* temp = myTop;
            myTop = myTop->getNext();
            delete temp;
        }
    }
}

bool CompletedOrder::isEmpty() const{
    return mySize == 0;
}

void CompletedOrder::addCompletedOrder(Order& addOrder){
   NodePtr newNode = new Node(addOrder);
    
   newNode->setNext(myTop);
   myTop = newNode;
    
   mySize++;
}
Order CompletedOrder::removeCompletedOrder(){
    Order output = myTop->getData();
    
    myTop = myTop->getNext();
    
    return output;
}

double CompletedOrder::totalAmountSold(){
    if(isEmpty()){
        return 0;
    }
    double total = 0;
    
    NodePtr temp = myTop;
    while(temp != NULL){
        total += temp->getData().getTotalAmount();
        temp = temp->getNext();
    }
    
    return total;
}

void CompletedOrder::displayRevenue(){
    cout << "-- Total Revenue --" << endl;
    NodePtr temp = myTop;
    for(int i = 0; i < mySize; i++){
        cout << "Order " << temp->getData().getOrderId() << ": $" <<
                temp->getData().getTotalAmount() << endl;
        
        temp = temp->getNext();
    }
    cout << "Total Sold: $" << totalAmountSold() << endl;
}

void CompletedOrder::saveToFile(const char* fileName){
    ofstream outputFile;
    
    outputFile.open(fileName);
    
    NodePtr temp = myTop;
     
    while(temp != NULL){
        outputFile << temp->getData().getOrderId() << ","
                << temp->getData().getCustName() << ",";
        temp = temp->getNext();
    }
    
    outputFile.close();
    
}

void CompletedOrder::loadFromFile(const char* fileName){
    ifstream inputFile;
    
    inputFile.open(fileName);
    if (!inputFile.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return;
    }
    
    string line;
    while (getline(inputFile, line)) {
        int comma1 = line.find(',');
        int comma2 = line.find(',', comma1 + 1);
        int comma3 = line.find(',', comma2 + 1);

        if (comma1 == -1 || comma2 == -1 || comma3 == -1) {
            cerr << "Invalid line format: " << line << endl;
            continue;
        }

        string id = line.substr(0, comma1);                           
        string name = line.substr(comma1 + 1, comma2 - comma1 - 1);       
        string desc = line.substr(comma2 + 1, comma3 - comma2 - 1);
        string priceStr = line.substr(comma3 + 1);

        double price = atof(priceStr.c_str());

        addItem(MenuItem(name, desc, price));
    }
    
    inputFile.close();
}

Order CompletedOrder::search(int id) const{
    
    NodePtr temp = myTop;
    for(int i = 0; i < mySize; i++){
        if(temp->getData().getOrderId() == id){
            return temp->getData();
        }
    }
    Order garbage;
    return garbage;
}

void CompletedOrder::displayCompletedOrders(ostream& out) const{
    
    if(isEmpty()){
        cout << "No orders completed" << endl;
    } else {
        out <<"-- Completed Orders --" << endl;
        Node* temp = myTop;
        for(int i = 0; i < mySize; i++){
            out << temp->getData();
        }
    }
}
