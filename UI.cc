/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "UI.h"
using namespace std;


void UI::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add new product \n\n";
  cout<< "          2. Add more inventory \n\n";
  cout<< "          3. Remove inventory \n\n";
  cout<< "          4. Print inventory \n\n";
  cout<< "          5. Print customers \n\n";
  cout<< "          6. Print orders \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 4) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void UI::cashierMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM CASHIER MENU\n\n";
  cout<< "          1. Product purchases\n\n";
  cout<< "          2. Product returns\n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection:  ";
    choice = readInt();
    if (choice == MAGIC_NUM) return;
  }
}

void UI::printStock(ProdArray* arr)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  stringstream ss;

  cout << endl << "STOCK: " << endl << endl;
  cout << " ID                                 Name             Size    Qty    Price" << endl;
  cout << " --                                 ----             ----    ---    -----" << endl;

  for (int i=0; i<arr->getSize(); i++) {

    Product* prod = arr->get(i);

    cout << prod->getId()   << "  " << setw(40) << prod->getName() << "  "
         << setw(10) << prod->getSize() << "  " << setw(4)  << prod->getUnits() << "    ";

    ss << setw(6) << fixed << setprecision(2) << prod->getPrice();

    cout << "$" << ss.str() << endl;
    ss.str("");
  }
}

void UI::printStock(ProdList* list)
{
  string output = "";
  list->toString(output);
  cout << output << endl;
}

void UI::printCustomers(CustArray* arr)
{
  cout << endl << "CUSTOMERS: " << endl << endl;

  for (int i=0; i<arr->getSize(); i++) {
    Customer* cust = arr->get(i);
    cout << cust->getId() << "  " << setw(10) << cust->getName() 
         << "  " << setw(4) << cust->getPoints() << endl;
    printPurchases(cust->getPurchases());
  }
}

void UI::printOrders(OrderArray* arr){
  cout << endl << "Orders: " << endl << endl;
  
  for (int i=0; i<arr->getSize(); i++){
    Order* orr = arr->get(i);
    PurchaseArray* pArr = orr->getPurchaseArray();
    cout << "Order " << i+1 << ":" << endl;
    for(int j=0; j<pArr->getSize(); j++){
      Purchase* purch = pArr->get(j);
    cout << purch->getProduct()->getId() << "  " << setw(10) << purch->getProduct()->getName() << " "<< purch->getQuantity() << endl;
      
    }
    cout << "The total cost of this order is $" << orr->getTotal() << endl << endl;    
  }
  
}

void UI::printPurchases(PurchaseArray* arr)
{
  cout << "Purchases: " << endl;

  for (int i=0; i<arr->getSize(); i++) {
    Purchase* purch = arr->get(i);
    cout << purch->getProduct()->getId() << "  " << setw(10) << purch->getProduct()->getName() << " "<< purch->getQuantity() << endl;
  }
}

void UI::productPurchase(float s, int t){
  cout << "Your total so far is $" << s << ".\n";
  if ( t == 1 )
    cout << "Which earned you " << t << " loyalty point.\n";
  cout << "Which earns you " << t << " loyalty points.\n";
  
}




void UI::printError(string err)
{
  cout << endl << err << " -- press enter to continue...";
  cin.get();
}

void UI::printUsageError()
{
  cout << endl << "Usage:  cushop OPTION" << endl << endl;
  cout <<         "        where OPTION is either: " << endl;
  cout <<         "              -a  Admin menu"        << endl;
  cout <<         "              -c  Cashier menu"      << endl << endl;
}

void UI::promptForInt(string prompt, int& num)
{
  cout << prompt << ": ";
  num = readInt();
}

void UI::promptForStr(string prompt, string& str)
{
  cout << prompt << ": ";
  getline(cin, str);
}

void UI::promptForFloat(string prompt, float& num)
{
  string str;

  cout << prompt << ": ";
  getline(cin, str);

  stringstream ss(str);
  ss >> num;
}

int UI::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void UI::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

