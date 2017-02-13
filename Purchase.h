#ifndef PURCHASE_H
#define PURCHASE_H

#include "Product.h"

class Purchase{
  public:
    Purchase();
    Purchase(Product*, int);
    int getQuantity();
    void setQuantity(int);
    Product* getProduct();
    
  private:
    Product* product;
    int quantity;
};

#endif
