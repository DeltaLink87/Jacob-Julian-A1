#include "PurchaseArray.h"
#include "Product.h"
#include "Purchase.h"
#include <string>
#include "defs.h"

#include <iostream>
using namespace std;

PurchaseArray::PurchaseArray(){
  size = 0;
}

void PurchaseArray::addPurchase(Product& newPurchase, int quantity){
  for (int i = 0; i < size; i++){
    if (newPurchase.getId() == purchases[i].getProduct().getId()){
      purchases[i].setQuantity(purchases[i].getQuantity() + quantity);
      return;
    }
  }
  
  if (size < MAX_ARR)
    purchases[size++] = Purchase(newPurchase, quantity);
}

Product& PurchaseArray::getPurchaseByName(string name){
  for (int i = 0; i < size; i++){
    if (name.compare(purchases[i].getProduct().getName()) == 0){
      return purchases[i].getProduct();
    }
  }
}

Product& PurchaseArray::getPurchaseByID(int id){
  for (int i = 0; i < size; i++){
    if (id == purchases[i].getProduct().getId()){
      return purchases[i].getProduct();
    }
  }
}

void PurchaseArray::printArray(){
  for (int i = 0; i < size; i++){
    cout << "Name:" << purchases[i].getProduct().getName() << ", ID:" << purchases[i].getProduct().getId() << ", Quantity:" << purchases[i].getQuantity() << endl;
  }
}
