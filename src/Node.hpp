#ifndef _NODE_HPP
#define _NODE_HPP

#include <iostream>

class NodeTree;

class Node{
   //Members
private:
   Node *prev;
   Node *sib;
   Node *child;

   //Contructor
public:
   Node(Node* sib = NULL, Node* child = NULL, Node* prev = NULL);
   ~Node();

   //Setters
protected:
   void setSib(Node* sib);
   void setChild(Node* child);

   //Getters
protected:
   Node* getPrev() { return this->prev; }
   Node* getSib() { return this->sib; }
   Node* getChild() { return this->child; }

   //Helpers
protected:
   bool isParent(Node* check);
   void killFamily(); // Recursively kills children and then ends himself
private:
   void killFamily(int level);  //dont let main alter level
   void removeNodeFromTree();    //dissappear from siblings + parents (isolation)

   //Friends
   friend class NodeTree;
};



#endif