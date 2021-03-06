// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "linkedList.h"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#ifdef _DEBUG
#define DEBUG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

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
    int index = 18;
    cout << "Print value at index: " << index << "\n";
    CLinkedList<int>* l = myList.GetNodeAtIndex(head, index);
    if (l) {
        cout << "Value is: " << l->value << "\n";
    }
    else
    {
        cout << "Index is out of range\n";
    }
    cout << "Printing the list in order\nBefore MoveFrontToBack()\n";
    myList.Print(head);
    cout << "MoveFrontToBack()\n";
    myList.MoveFrontToBack(&head);
    myList.Print(head);
    cout << "MoveBackToFront()\n";
    myList.MoveBackToFront(&head);
    myList.Print(head);
    cout << "Printing the list in order\nBefore reversal\n";
    myList.Print(head);
    myList.Reverse(&head);
    cout << "Printing the list in order\nAfter reversal\n";
    myList.Print(head);

    cout << "List length is " << myList.GetListLength(head) << "\n";
    myList.Clear(&head);

    //load at front of list
    head = new CLinkedList<int>(NodeValues[0]);

    //add some nodes
    cout << "Push to front of list\n";
    for (int i = 1; i < 16; ++i) {
        myList.PushNode(&head, NodeValues[i]);
    }
    cout << "Printing the list in order\n";
    myList.Print(head);
    //get previous node
    int val = 52;
    // if 52 return value should be 15 according to values above;
    cout << "Printing value of node before "<< val <<" \n";
    int prev_val = myList.GetPrevNodeValue(head, val);
    cout << "Previos node value is " << prev_val << " \n";
    cout << "Printing the list in order\nBefore reversal\n";
    myList.Print(head);
    myList.Reverse(&head);
    cout << "Printing the list in order\nAfter reversal\n";
    myList.Print(head);    cout << "Remove node " << val << "\n";
    myList.RemoveNode(&head, val);
    cout << "Printing the list in order\nAfter reversal\n";
    myList.Print(head);
    myList.Clear(&head);
#if _DEBUG
    _CrtDumpMemoryLeaks();
#endif

}

