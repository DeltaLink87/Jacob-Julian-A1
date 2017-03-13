#ifndef ORDERARRAY_H
#define ORDERARRAY_H

#include "defs.h"
#include "Order.h"

class OrderArray
{
  public:
    OrderArray();
    ~OrderArray();
    int add(Order*);
    Order* get(int);
    Order* getByID(int);
    int getSize();
  private:
    Order* elements[MAX_ARR];
    int size;
};

#endif
