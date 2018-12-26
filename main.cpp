// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "linkedList.h"

// main func to test linkedlist
int main()
{
    int NodeValues[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80 };
 
    //load from back of list
    CLinkedList<int> myList;
    CLinkedList<int>* head = new CLinkedList<int>(NodeValues[0]);

    //add some nodes
    cout << "Push to back of list\n";
    for (int i = 1; i < 16; ++i) {
        myList.PushBackNode(head, NodeValues[i]);
    }
    cout << "Printing the list in order\nBefore reversal\n";
    myList.Print(head);
    myList.Reverse(&head);
    cout << "Printing the list in order\nAfter reversal\n";
    myList.Print(head);
    myList.Clear(&head);

    //load at front of list
    head = new CLinkedList<int>(NodeValues[0]);

    //add some nodes
    cout << "Push to front of list\n";
    for (int i = 1; i < 16; ++i) {
        myList.PushNode(&head, NodeValues[i]);
    }
    cout << "Printing the list in order\nBefore reversal\n";
    myList.Print(head);
    myList.Reverse(&head);
    cout << "Printing the list in order\nAfter reversal\n";
    myList.Print(head);
    int val = 52;
    cout << "Remove node " << val << "\n";
    myList.RemoveNode(&head, val);
    cout << "Printing the list in order\nAfter reversal\n";
    myList.Print(head);
    myList.Clear(&head);


}

