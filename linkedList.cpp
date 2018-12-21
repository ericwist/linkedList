// linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "linkedList.h"

int main()
{
    //Test loading and printing integers to binary tree
    int NodeValues[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };
    CLinkedList<int> myList;
    //Create first node in list
    CLinkedList<int>* node = myList.AddNode(NodeValues[0], nullptr);
    //Create rest and link to prev each time
    for (int i = 1; i < 16; ++i) {
        node = myList.AddNode(NodeValues[i], node);
    }
    cout << "Printing the list in order\nBefore reversal\n";
    myList.print();
    myList.reverse();
    cout << "Printing the list in order\nAfter reversal\n";
    myList.print();
    
}

