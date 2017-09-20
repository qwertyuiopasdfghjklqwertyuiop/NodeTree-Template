#include <iostream>
#include <string>
#include <cmath>

#include "./Node.hpp"
#include "./Node_Template.hpp"
#include "./Node_Tree.hpp"

 int main(){
   srand(time(NULL)); // ooga booga

   NodeT<std::string> test("omar");
   std::cout << test << std::endl;

/*
   Node** nArray;
   const int arraySize = 100;

// Populate Array
   nArray = new Node*[arraySize];
   for(int k = 0; k < arraySize; k++)
      nArray[k] = new Node;

// Setup family relations
   nArray[0]->setChild(nArray[1]);

   for(int k = 1; k < arraySize; k++)
      (rand() % 2) ? nArray[k]->setChild(nArray[k + 1]) : nArray[k]->setSib(nArray[k + 1]);// 50% chance it will be sibling or child

// Perfect Deallocation
   nArray[0]->killFamily();
   delete[] nArray;
   
*/


   return 0;
}