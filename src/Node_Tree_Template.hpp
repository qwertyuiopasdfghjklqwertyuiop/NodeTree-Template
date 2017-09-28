#ifndef _NODE_TREE_TEMPLATE_HPP
#define _NODE_TREE_TEMPLATE_HPP

template<typename T>
class TreeT : protected Node_Tree{

   // Constructor
public:
   TreeT(NodeT<T> tNode) : Node_Tree(tNode) { };

};

#endif
