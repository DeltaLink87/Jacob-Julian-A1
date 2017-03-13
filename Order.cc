#include "Order.h"
#include <iostream>

int Order::nextOrderId = 5001;

Order::Order(Customer* newPurchaser)
{ 
  id    = nextOrderId++;
  purchaser = newPurchaser;
}

void Order::add(Product* prod, int quantity) { purchases.addPurchase(prod, quantity); }
PurchaseArray* Order::getPurchases() { return &purchases; }

float Order::getTotal(){
  float total = 0;
  for (int i = 0; i < purchases.getSize(); i++){
    total += purchases.get(i)->getProduct()->getPrice() * purchases.get(i)->getQuantity();
  }
  return total;
}

int    Order::getId()    { return id; }
int Order::getSize() { return purchases.getSize(); }
Customer* Order::getPurchaser() { return purchaser; }
