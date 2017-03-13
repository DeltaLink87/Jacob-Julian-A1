#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std;

#include "PurchaseArray.h"
#include "Purchase.h"
#include "Product.h"
#include "Customer.h"

class Order
{
  public:
    Order(Customer*);
    int    getId();
    void add(Product*, int);
    PurchaseArray* getPurchases();
    int getSize();
    float getTotal();
    Customer* getPurchaser();
    
  protected:
    static int nextOrderId;
    int id;
    PurchaseArray purchases;
    Customer* purchaser;
};

#endif
