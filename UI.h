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

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

#include "ProdArray.h"
#include "CustArray.h"
#include "PurchaseArray.h"
#include "ProdList.h"

class UI
{
  public:
    void mainMenu(int&);
    void adminMenu(int&);
    void cashierMenu(int&);
    void productPurchase(float s, int t);
    void promptForInt(string, int&);
    void promptForStr(string, string&);
    void promptForFloat(string, float&);
    void printError(string);
    void printUsageError();
    void printStock(ProdArray*);
    void printStock(ProdList*);
    void printCustomers(CustArray*);
    void printPurchases(PurchaseArray*);
    void printOrders(OrderArray*);
    void pause();

  private:
    int    readInt();
};

#endif
