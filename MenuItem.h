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
    
    string name;
    string desc;
    double price;
    
public:
    MenuItem();
    MenuItem(string, string, double);
    void displayMenuItem(ostream& ) const;
    void readMenuItem(istream&);
    void setMenuItem(string, string, double);
    void setName(string);
    string getName() const;
    void setDescription(string);
    string getDescription() const;
    void setPrice(double);
    double getPrice() const;
};

ostream& operator<< (ostream&, const MenuItem&);
istream& operator>> (const istream&, MenuItem&);
#endif /* MENUITEM_H */
