#include "OrderServer.h"

OrderServer::OrderServer() { 

}

void OrderServer::update(Order* newOrder){
  arr.add(newOrder);
}

void OrderServer::retrieve(OrderArray& array){
  array = arr;
}
