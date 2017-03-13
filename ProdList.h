/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PRODLIST_H
#define PRODLIST_H

#include "defs.h"
#include "Product.h"
#include <string>
#include <sstream>

class ProdList
{
  class ProdNode 
  {
    friend class ProdList;
    private:
      Product*     data;
      ProdNode*    next;
      ProdNode* prev;
  };
  
  public:
    ProdList();
    ~ProdList();
    void add(Product*);
    void remove(Product*);
    Product* find(int&);
    void reorg();
    void toString(string&);
    
    
  private:
    ProdNode* head;
    
    int size;
};

#endif

