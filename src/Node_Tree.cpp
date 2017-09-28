#include "./Node_Tree.hpp"

class Node;

Node_Tree::Node_Tree(Node* head)
{
   this->head = head;
   this->iter = head;
}

Node_Tree::~Node_Tree()
{
   this->head->killFamily();
}

bool Node_Tree::addSib(Node* sib)
{
   // Add sibling unless already exists or is head
   if(this->iter == this->head)
      return false;
   if(this->iter->sib)
      return false;

   this->iter->setSib(sib);
   return true;
}

bool Node_Tree::addChild(Node* child)
{
   //Add child unless exists;
   if(this->iter)
      return false;
   this->iter->Node::setChild(child);
   return true;
}



bool Node_Tree::nextGen()
{
   bool success = (this->iter->child != NULL);
   if (success) 
      this->iter = this->iter->child;
   return success;
}

bool Node_Tree::prevGen()
{
   bool success = false;
   // we don't alter the real iterator until we are sure we have parent
   Node* temp = this->iter;    

   while(temp->prev)
   {
      if(temp->isParent(temp->prev)) // if( son.isParent(parent) )
      {
         this->iter = temp->prev;
         success = true;
         break;
      }

      temp = temp->prev;
   }  // end while
   return success;
}

bool Node_Tree::sib()
{
   bool success;
   this->iter->sib ? success = true : success = false;
   if(success)
      this->iter = this->iter->sib;
   return success;
}

bool Node_Tree::child()
{
   bool success;
   this->iter->child ? success = true : success = false;
   if(success)
      this->iter = this->iter->child;
   return success;
}


bool Node_Tree::prev()
{
   bool success;
   this->iter->prev ? success = true : success = false;
   if(success)
      this->iter = this->iter->prev;
   return success;
}
