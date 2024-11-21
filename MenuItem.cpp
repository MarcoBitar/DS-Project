/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuItem.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:31 pm
 */

#include "MenuItem.h"

MenuItem::MenuItem(){
    setMenuItem("", "", 0.0);
}

MenuItem::MenuItem(string name, string desc, double price){
    setMenuItem(name, desc, price);
}   

void MenuItem::setMenuItem(string name, string desc, double price){
    
    setName(name);
    setDescription(desc);
    setPrice(price);
}

void MenuItem::setName(string name){
    this->name = name;
}
string MenuItem::getName() const{
    return name;
}
void MenuItem::setDescription(string desc){
    this->desc = desc;
}
string MenuItem::getDescription() const{
    return desc;
}
void MenuItem::setPrice(double price){
    if(price > 0){
        this->price = price;
    } else {
        price = 1;
    }
}
double MenuItem::getPrice() const{
    return price;
}

void MenuItem::displayMenuItem(ostream& out) const{
    
    cout << ", Name: " << name << ", Price: $" << price << endl;
}

void MenuItem::readMenuItem(){
    string inputName, inputDescription;
    double inputPrice;
    
    cout << "Enter Item name: ";
    cin.ignore();
    getline(cin, inputName);
    setName(inputName);
            
    cout << "\nEnter Item Description: ";
    getline(cin, inputDescription);
    setDescription(inputDescription);
    
    cout << "\nEnter Item Price: ";
    cin >> inputPrice;
    setPrice(inputPrice);
}

ostream& operator<< (ostream& out, const MenuItem& menuItem){
    menuItem.displayMenuItem(out);
    return out;
}

istream& operator>>(istream& in, MenuItem& menuItem){
    menuItem.readMenuItem();
    return in;
}
