#include "Purchase.h"
#include "Product.h"

Purchase::Purchase(){
  product = Product();
  quantity = 0;
}

Purchase::Purchase(Product* newProduct, int newQuantity){
  product = newProduct;
  quantity = newQuantity;
}

int Purchase::getQuantity(){ return quantity; }
void Purchase::setQuantity(int newQuantity){ quantity = newQuantity; }
Product* Purchase::getProduct(){ return product; }
