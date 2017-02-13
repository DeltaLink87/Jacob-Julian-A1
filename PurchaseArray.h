#ifndef PURCHASEARRAY_H
#define PURCHASEARRAY_H

#include "Product.h"
#include "Purchase.h"
#include <string>
#include "defs.h"

class PurchaseArray{
  public:
    PurchaseArray();
    ~PurchaseArray();
    void addPurchase(Product*, int);
    Product* getPurchaseByName(string);
    Product* getPurchaseByID(int);
    void printArray();
    
  private:
    Purchase* purchases[MAX_ARR];
    int size;
};

#endif
