// This is a type agnostic Linked List class
// Author: Eric Wistrand
// Date  : 11/28/2018

#pragma once
#include <iostream>
#include <cstdlib>
#include "type_name.h"

using namespace std;

template<typename T> class CLinkedList
{
private:
    CLinkedList* next;
    CLinkedList* head;
    T value;
public:
    CLinkedList() {}
    ~CLinkedList() {}
    CLinkedList(const T &v, CLinkedList* n) : value(v), next(nullptr), head(n)
    {
        if (head == nullptr)
        {
            head = this;
        }
    }

    T getValue() { return value; }
    
    CLinkedList* AddNode(const T& value, CLinkedList* prev)
    {
        CLinkedList* node = new CLinkedList(value, head);
        if (head == nullptr) {
            head = node;
        }
        else
        {
            prev->next = node;
        }
        return node;
    }

    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        CLinkedList *current = head;
        CLinkedList *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    void print()
    {
        CLinkedList *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};