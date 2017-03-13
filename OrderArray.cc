#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "OrderArray.h"

OrderArray::OrderArray()
{
  size = 0;
}

OrderArray::~OrderArray()
{
  for (int i = 0; i < size; i++)
    delete elements[i];
}

int OrderArray::getSize() { return size; }

Order* OrderArray::get(int index)
{
  //index -= 5002;
  if (index < 0 || index >= size){
    std::cout << "INVALID INDEX" << std::endl;
    return NULL;
  }
  return elements[index];
}


Order* OrderArray::getByID(int id){
  for (int i = 0; i < size; i++){
    if (elements[i]->getId() == id)
      return elements[i];
  }
  return NULL;
}

int OrderArray::add(Order* order)
{
  if (size >= MAX_ARR)
    return C_NOK;

  elements[size++] = order;
  return C_OK;

}
