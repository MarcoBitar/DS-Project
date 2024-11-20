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

MenuItem::MenuItem(int id, string name, string desc, double price){
    setMenuItem(id, name, desc, price);
}   
void MenuItem::setMenuItem(int id, string name, string desc, double price){
    setId(id);
    setName(name);
    setDescription(desc);
    setPrice(price);
}
void MenuItem::setId(int id){
    if(id > 0){
        this->id = id;
    } else {
        this->id = 0;
    }
}
int MenuItem::getId() const{
    return id;
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
    
    cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
}

ostream& operator<< (const ostream& out, const MenuItem& menuItem){
    
    menuItem.displayMenuItem(out);
    return out;
}