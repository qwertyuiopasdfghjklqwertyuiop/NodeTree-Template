#ifndef _NODE_TREE_HPP
#define _NODE_TREE_HPP

#include "./Node.hpp"

class Node_Tree{
   //Members
private:
   Node* head;
   Node* iter;

   //Constructor
protected:
   Node_Tree(Node* head);
   ~Node_Tree();


   //Tree Mutator - Modifies adds members to this->iter
private:
   bool addSib(Node* sib);
   bool addChild(Node* child);
public:
   bool createSib() { addSib( new Node() ); return true; }
   bool createChild() { addChild( new Node() ); return true; }

   //Iterator Mutator
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
