#ifndef _NODE_TREE_HPP
#define _NODE_TREE_HPP

#include "./Node.hpp"

class Node_Tree{
   //Members
private:
   Node* head;
   Node* iter;

   //Constructor
public:
   Node_Tree(Node* head);

   //Mutator
   bool nextGen();
   bool prevGen();
   bool sib();
   bool child();
   bool prev();

   //Accessors
protected:
   Node* getHead() { return this->head; }
   Node* getCurrent() { return this->iter; }
};

#endif