/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuItem.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:31 pm
 */

#ifndef MENUITEM_H
#define MENUITEM_H

#include <cstring>
#include <iostream>
using namespace std;

class MenuItem {
private:
    int id;
    string name;
    string desc;
    double price;
    
public:
    MenuItem(int, string, string, double);
    void displayMenuItem(ostream& ) const;
    
    void setMenuItem(int, string, string, double);
    void setId(int);
    int getId() const;
    void setName(string);
    string getName() const;
    void setDescription(string);
    string getDescription() const;
    void setPrice(double);
    double getPrice() const;
};

ostream& operator<< (const ostream&, const MenuItem&);
#endif /* MENUITEM_H */