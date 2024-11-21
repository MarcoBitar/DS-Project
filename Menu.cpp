/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: Marco
 * 
 * Created on 19 November 2024, 3:31 pm
 */

#include "Menu.h"

Menu::Menu(unsigned capacity) {
    mySize = 0;
    myCapacity = capacity;
    items = new MenuItem[myCapacity];
}

bool Menu::addItem(MenuItem item) {
    if (mySize == myCapacity) {
        MenuItem* temp = new MenuItem[myCapacity * 2];
        for (int i = 0; i < myCapacity; i++) {
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
        myCapacity *= 2;
    }
    items[mySize] = item;
    mySize++;
    return true;
}

bool Menu::removeItem(int id) {
    for (int i = id - 1 ; i < mySize - 1; i++) {
        items[i] = items[i + 1];
    }
    mySize--;
    return true;
}

void Menu::clear() {
    mySize = 0;
    myCapacity = 0;
    delete[] items;
}

MenuItem& Menu::getMenuItem(int id) const {
    int i = 0;
    while (i < mySize) {
        if (i == id -1)
            return items[i];
        i++;
    }
    MenuItem garbage;
    return garbage;
}

int Menu::size() {
    return mySize;
}

void Menu::saveToFile(const char* fileName) {
    ofstream outputFile;
    
    outputFile.open(fileName);
    if (!outputFile.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return;
    }
    
    for (int i = 0; i < mySize; i++) {
        outputFile << i + 1 << "," << items[i].getName() 
                << "," << items[i].getDescription() << "," 
                << items[i].getPrice() << endl;
    }
    
    outputFile.close();
}

void Menu::loadFromFile(const char* fileName) {
    ifstream inputFile;
    
    inputFile.open(fileName);
    if (!inputFile.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        exit(1);
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

void Menu::displayMenu(ostream& out) const {
    out << "--- Menu Items ---" << endl;
    for (int i = 0; i < mySize; i++) {
        out << "ID: " << i + 1 << items[i];
    }
}

ostream& operator<< (ostream& out, const Menu& m) {
    m.displayMenu(out);
    return out;
}
