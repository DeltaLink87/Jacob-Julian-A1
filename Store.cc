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


#include "Store.h"

Store::Store(){
  stock = new ProdList();
  customers = new CustArray();
  orderServer = new OrderServer();
}

Store::~Store(){
  delete stock;
  delete customers;
  delete orderServer;
}

ProdList* Store::getStock()          { return stock; }

CustArray* Store::getCustomers()     { return customers; }

OrderServer* Store::getOrderServer() { return orderServer; }

void Store::addProd(Product* prod)
{
  stock->add(prod);
}

void Store::addCust(Customer* cust)
{
  customers->add(cust);
}

