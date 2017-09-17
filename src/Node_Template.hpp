#ifndef _NODE_TEMPLATE_HPP
#define _NODE_TEMPLATE_HPP

//class Node;

template <typename T>
class NodeT : protected Node {
   //Members
private:
   T tVar;

   //Constructor
public:
   NodeT(T tVar) : Node::Node(){ this->tVar = tVar;}
   
   //Getters
public:
   T getVar() { return tVar; }

   //Mutators
public:
   void setVar(T tVar){ this->tVar = tVar; }


};

//operators
template<typename T>
std::ostream &operator<<(std::ostream &out, NodeT<T> nodeT)
{
   out << nodeT.getVar();
   return out;
}


#endif