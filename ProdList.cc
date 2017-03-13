
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Product.h"
#include "ProdList.h"

ProdList::ProdList() : head(0) { }

ProdList::~ProdList() 
{ 
  ProdNode* currNode = head;
  ProdNode* nextNode;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

void ProdList::add(Product* prod)
{
  ProdNode* newProdNode;
  ProdNode* currNode;
  ProdNode* prevNode;

  newProdNode = new ProdNode;
  newProdNode->data = prod;
  newProdNode->next = NULL;
  newProdNode->prev = NULL;

  currNode = head;
  prevNode = NULL;
  if (head == NULL){
    head = newProdNode;
    head->next = NULL;
  }
  else{
    while (currNode != NULL) {
      if (newProdNode->data->getUnits() < currNode->data->getUnits())
        break;
      prevNode = currNode;
      currNode = currNode->next;
    }

    if (prevNode == NULL) {	// add to beginning
      head = newProdNode;
    } 
    else {
      prevNode->next = newProdNode;
      newProdNode->prev = prevNode;
    }
    newProdNode->next = currNode;
    if(currNode != NULL)
      currNode->prev = newProdNode;
  }
}

void ProdList::reorg(){
	
  if (head == NULL)
  	return;
  else if (head->next == NULL)
  	return;
  
  ProdNode* currNode = head->next;
  ProdNode* prevNode = head;
  
  while (currNode != NULL) {
  	while(currNode->data->getUnits() < currNode->prev->data->getUnits()){  	
  	ProdNode* tempNode = currNode->next;
  	  if(currNode->prev->prev == NULL){
  	    if(currNode->next == NULL){
  	      currNode->next = currNode->prev;
  	      currNode->next->prev = currNode;
  	      currNode->prev = NULL;
  	    }
  	    else{
  	      currNode->prev->next = tempNode;
  	      tempNode->prev = currNode->prev;
  	      currNode->prev = NULL;
  	      tempNode->prev->prev = currNode;
  	      currNode->next = tempNode->prev;
  	    }
  	  }
  	  else{
  	    if(tempNode == NULL){
  	     tempNode = currNode->prev;
  	     currNode->prev = currNode->prev->prev;
  	     currNode->prev->next = currNode;
  	     currNode->next = tempNode;
  	     tempNode->prev = currNode;
  	     tempNode->next = NULL; 
  	      
  	    }
  	    else{
  	      currNode->prev->next = tempNode;
  	      tempNode->prev = currNode->prev;
  	      currNode->prev = currNode->prev->prev;
  	      currNode->prev->next = currNode;
  	      tempNode->prev->prev = currNode;
  	      currNode->next = tempNode->prev;
  	    }
  	  }
  	  currNode = currNode->prev;
  	  prevNode = currNode->prev;
  	}
  	    
  	
    prevNode = currNode;
    currNode = currNode->next;
  }
  
  cout << "reorg" << endl;
  
  /*for (ProdNode* currNode = head; currNode != NULL; currNode = currNode->next){
    for (ProdNode* nextNode = currNode->next; nextNode != NULL; nextNode = nextNode->next){
      if (currNode->data->getUnits() < nextNode->data->getUnits()){
        currNode->next = nextNode->next;
        nextNode->prev = currNode->prev;
        currNode->prev = nextNode;
        nextNode->next = currNode;
        
        ProdNode* tempNode = currNode;
        currNode = nextNode;
        nextNode = tempNode;
      }
    } 
  }*/
	
}

void ProdList::remove(Product* product)
{
  if (product == NULL)
    return;
  
  ProdNode* currNode = head;
  ProdNode* prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data == product) 
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {
    head = currNode->next;
    head->prev = NULL;
  }
  else {
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
  }

  delete currNode;
  
  reorg();
}

Product* ProdList::find(int& id){
  ProdNode* currNode = head;
  ProdNode* prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data->getId() == id) 
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }
  
  if(currNode != NULL){
    if(currNode->data->getId() == id)
      return currNode->data;
  }
  else
    return NULL;
  
      
/*
  if (prevNode == NULL) {
    head = currNode->next;
    head->prev = NULL;
  }
  else {
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
  }
*/
  
  
}







void ProdList::toString (string& outStr){
  stringstream ss;
  stringstream ss2;
  
  ProdNode* currNode = head;
  ProdNode* prevNode = NULL;
  
  //outStr += " ";
  
  outStr += " ID                                 Name             Size    Qty    Price";
  outStr += " --                                 ----             ----    ---    -----";
  
  //Front to Back
  while (currNode != NULL){
    Product* prod = currNode->data;
    ss << prod->getId()   << "  " << setw(40) << prod->getName() << "  "
         << setw(10) << prod->getSize() << "  " << setw(4)  << prod->getUnits() << "    ";
    ss2 << setw(6) << fixed << setprecision(2) << prod->getPrice();
    
    outStr += ss.str();
    outStr += "$";
    outStr += ss2.str();
    outStr += '\n';
    ss.str("");
    ss2.str("");
    
    prevNode = currNode;
    currNode = currNode->next;
    
  }
  
  //Back to Front
  while ( prevNode != NULL){  
    Product* prod = prevNode->data;
    
    ss << prod->getId()   << "  " << setw(40) << prod->getName() << "  "
         << setw(10) << prod->getSize() << "  " << setw(4)  << prod->getUnits() << "    ";
    ss2 << setw(6) << fixed << setprecision(2) << prod->getPrice();
    
    outStr += ss.str();
    outStr += "$";
    outStr += ss2.str();
    outStr += '\n';
    ss.str("");
    ss2.str("");
    
    currNode = prevNode;
    prevNode = currNode->prev;
    
  }
  
  
  /*
  ss << endl << "STOCK: " << endl << endl;
  ss << " ID                                 Name             Size    Qty    Price" << endl;
  ss << " --                                 ----             ----    ---    -----" << endl;

  while (int i=0; i<arr->getSize(); i++) {

    Product* prod = arr->get(i);

    cout << prod->getId()   << "  " << setw(40) << prod->getName() << "  "
         << setw(10) << prod->getSize() << "  " << setw(4)  << prod->getUnits() << "    ";

    ss << setw(6) << fixed << setprecision(2) << prod->getPrice();

    cout << "$" << ss.str() << endl;
    ss.str("");
    }
    */
}

/*
void ProdList::print()
{
  cout << "STUDENTS:" << endl;

  for ( Node* currNode = head;
        currNode != NULL; 
        currNode = currNode->next) {
    currNode->data->print();     
  }
}
*/
