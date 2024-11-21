/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Marco
 *
 * Created on 18 November 2024, 1:08 pm
 */

#include <cstdlib>
#include <iostream>

#include "Menu.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int choice;
    Menu menu;
    menu.loadFromFile("menu.txt");
    
    cout << "---Restaurant Order Management System---" << endl;
    
    do{
        cout << "1. Display Menu" << "\n"
                << "2. Add Menu Item" << "\n"
                << "3. Delete Menu Item" << "\n"
                << "4. Reset Menu" << "\n"
                << "5. Add New Order" << "\n"
                << "6. Process Next Order" << "\n"
                << "7. Display Orders" << "\n"
                << "8. Delete Order" << "\n"
                << "9. Calculate Total Amount of Sold Orders" << "\n"
                << "10. Save Completed Orders to File" << "\n"
                << "11. Exit" << "\n"
                << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << menu;
                break;
                
            case 2:
                MenuItem newItem;
                cin >> newItem;
                menu.addItem(newItem);
                break;
                
            case 3:
                int id;
                cout << "\nEnter Id of Item (must be a positive number): ";
                cin >> id;
                
                while(id < 0 || id > menu.);
                break;
                
        }
        
        
               
    } while (choice != 11);
    return 0;
}