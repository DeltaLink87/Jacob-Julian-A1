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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "Product.h"
#include "PurchaseArray.h"

class Customer
{
  public:
    Customer(string="Unknown");
    int    getId();
    string getName();
    int    getPoints();
    PurchaseArray& getPurchases();
    void   addPoints(int);
  protected:
    PurchaseArray purchases;
    static int nextCustId;
    int        id;
    string     name;
    int        points;
};

#endif
