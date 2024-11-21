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
#include "CustomOrder.h"
#include "CompletedOrder.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int choice;
    Menu* menu = new Menu(10);
    CustomOrder aOrder;
    CompletedOrder cOrder;
    cOrder.loadFromFile("C:\\Users\\Marco\\Downloads\\trial\\completed_orders.txt");
    (*menu).loadFromFile("C:\\Users\\Marco\\Downloads\\trial\\menu.txt");
    
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
                << "11. Exit" << "\n\n"
                << "Enter your choice: ";
        cin >> choice;
        
        cout << endl;
        
        switch (choice) {
            case 1: {
                cout << menu;
                break;
            }
            
            case 2: {
                MenuItem newItem;
                newItem.readMenuItem(cin);
                (*menu).addItem(newItem);
                cout << "Menu Item added successfully!" << endl;
                break;
            }
            
            case 3: {
                int id;
                cout << "Enter Id of Item (must be greater than 0): ";
                cin >> id;
                
                while(id <= 0  || id > (*menu).size()){
                    cout << "Id not valid" << endl;
                    cin >> id;      
                }
                
                (*menu).removeItem(id);
                cout << "Menu Item removed successfully!" << endl;
                break;
            }
            
            case 4: {
                (*menu).clear();
                cout << "Menu reset successful!" << endl;
                break;
            }
            
            case 5: {
                static int orderId = 0;
                int orderSize = 0, itemID, capacity = 10;
                string custName;
                int* itemsIdOrdered = new int[capacity];
                MenuItem* itemsOrdered;
                
                cout << "Enter Customer Name: ";
                cin >> custName;
                cout << "Enter items ID you want to purchase (0 to finish): ";
                cin >> itemID;
                
                int i = 0;
                
                while (itemID != 0) {
                    if (itemID > 0 && itemID <= (*menu).size()) {
                        
                        if (orderSize == capacity) {
                            capacity *= 2;
                            int* temp = new int [capacity];

                            for (int j = 0; j < orderSize; j++) {
                                temp [j] = itemsIdOrdered[j];
                            }

                            itemsIdOrdered = temp;
                            delete [] temp;
                            itemsIdOrdered[i] = itemID;
                            orderSize++;
                            i++;

                            cin >>itemID;
                        }

                        itemsOrdered = new MenuItem[orderSize];
                        
                        for (int i = 0; i < orderSize; i++) {
                            itemsOrdered[i] = (*menu).getMenuItem(itemsIdOrdered[i]);
                        }
                    } else {
                        cout << "Invalid Item ID. Try again: ";
                        cin >> itemID;
                    }
                }
                
                Order order(orderId++, custName, itemsOrdered, orderSize);
                aOrder.enqueue(order);
                cout << "Order added successfully!" << endl;
                break;
            }
            
            case 6: {
                Order copy = aOrder.dequeue();
                cout << "Processing order for " << copy.getCustName() << "..."
                        << endl;
                cOrder.addCompletedOrder(copy);
                cout << "Order processed successfully!" << endl;
                
                break;
            }
            
            case 7: {
                aOrder.displayCustomOrder(cout);
                cOrder.displayCompletedOrders(cout);
                break;
            }
            
            case 8: {
                int dId;
                cout << "Enter Id of Item (must be greater than 0): ";
                cin >> dId;
                
                while(dId <= 0  || aOrder.search(dId) == NULL){
                    cout << "Id not valid" << endl;
                    cin >> dId;      
                }
                
                aOrder.deleteOrder(dId);
                cout << "Order deleted successfully" << endl;
                break;
            }
            
            case 9: {
                cOrder.displayRevenue();
                break;
            }
            
            case 10: {
                cout << "Saving completed orders to file..." << endl;
                cOrder.saveToFile("C:\\Users\\Marco\\Downloads\\trial\\completed_orders.txt");
                break;
            }
            
            case 11: {
                cout << "Saving menu to file..." << endl;
                (*menu).saveToFile("C:\\Users\\Marco\\Downloads\\trial\\menu.txt");
                cout << "Saving completed orders to file..." << endl;
                cOrder.saveToFile("C:\\Users\\Marco\\Downloads\\trial\\completed_orders.txt");
                cout << "Exiting the program... GoodBye!" << endl;
                exit(1);
                
                break;
            }
            
            default: {
                cout << "Invalid choice" << endl;
                break;
            }    
        }
    } while (choice != 11);
    return 0;
}
