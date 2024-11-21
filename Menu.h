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

#include <string>
#include <iostream>
#include <fstream>
#include "MenuItem.h"
using namespace std;

class Menu{
private:
    int mySize;
    unsigned myCapacity;
    MenuItem* items;
    
public:
    Menu(unsigned );
    bool addItem(MenuItem );
    bool removeItem(int );
    void clear();
    MenuItem& getMenuItem(int ) const;
    int size();
    void saveToFile(const char*);
    void loadFromFile(const char*);
    void displayMenu(ostream& ) const;
};

ostream& operator<< (ostream&, const Menu&);
#endif /* MENU_H */
