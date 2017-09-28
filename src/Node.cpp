#include "./Node.hpp"

Node::Node(Node* sib, Node* child, Node* prev)
{
   this->prev = prev;
   setSib(sib);
   setChild(child);
}

Node::~Node()
{
}

void Node::setSib(Node* sib)
{
   if(this == sib)   //you can't be your own sibling
      return;
   this->sib = sib;
   if(sib)  //if sib exists
   sib->prev = this;
}

void Node::setChild(Node* child)
{
   if(this == child)    //you can't be your own child
      return;
   this->child = child;
   if(child)   //if child exists
   child->prev = this;
}



bool Node::isParent(Node* potentialParent)
{
   return (potentialParent->child == this);
}

//Genocide ------------------------------------------------------------
void Node::killFamily()
{
   this->removeNodeFromTree();   //isolation from sibings + parents before genocide
   this->killFamily(0);
}

void Node::killFamily(int level)
{
   if(this->child)  //if child exists
      this->child->killFamily(level + 1);
   if(this->sib)
      this->sib->killFamily(level);

   delete this;   //reaches delete once all family to right and below are dead
}

void Node::removeNodeFromTree()
{
   if(this->sib)
      this->sib->prev = this->prev;

   if(this->prev)
   {
      if(this->isParent(this->prev))
         this->prev->child = this->sib;   //set parents first born to this->sib
      else
         this->prev->sib = this->sib;
   }

   this->prev = NULL;      //cut all ties
   this->sib = NULL;    //cut all ties
}
