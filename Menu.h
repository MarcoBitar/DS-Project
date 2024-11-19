/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: Marco
 *
 * Created on 19 November 2024, 3:31 pm
 */

#ifndef MENU_H
#define MENU_H

#include <cstring>
#include <iostream>
#include "MenuItem.h"
using namespace std;

class Menu{
private:
    int mySize;
    int myCapacity;
    MenuItem* items;
    
public:
    Menu();
    ~Menu();
    void addItem(MenuItem& );
    void removeItem(int);
    void clear();
    void saveToFile(const string);
    void loadFromFile(const string);
    void displayOrder(ostream& ) const;
};

ostream& operator<< (const ostream&, const Menu&);
#endif /* MENU_H */
