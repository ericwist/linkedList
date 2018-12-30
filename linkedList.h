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
public:
    CLinkedList *next;
    T value;
    CLinkedList() {}
    ~CLinkedList() {}
    CLinkedList(const T &v) : value(v), next(nullptr){}

    int GetListLength(CLinkedList *head)
    {
        int count = 0;
        CLinkedList *temp = head;
        while (temp) {
            temp = temp->next;
            ++count;
        }
        return count;
    }

    void PushNode(CLinkedList **head, const T &value)
    {
        CLinkedList *new_node = new CLinkedList(value);
        new_node->next = *head;
        *head = new_node;
        return;
    }

    void PushBackNode(CLinkedList *head, const T &value)
    {
        CLinkedList *new_node = new CLinkedList(value);
        CLinkedList *temp = head;
        while (temp->next)
            temp = temp->next;
            
            temp->next = new_node;
        return; 
    }

    CLinkedList* GetNodeAtIndex(CLinkedList *head, int index)
    {
        CLinkedList *temp = head;
        int count = 0;
        if (GetListLength(head) <= index)
        {
            return nullptr;
        }
        while (temp->next && index != count++)
        {
            temp = temp->next;
        }
        return temp;
    }

    void RemoveNode(CLinkedList **head, const T &value) {
        CLinkedList *node = FindNode(*head, value);
        if (node == nullptr) { return; }
        // if node to be deleted is head 
        if (*head == node)
        {
            if ((*head)->next == nullptr)
            {
                cout << "There is only one node. Can't delete the list.\n";
                return;
            }

            // copy the value of next node to head
            (*head)->value = (*head)->next->value;

            // store address of next node 
            node = (*head)->next;

            // remove the link of next node 
            (*head)->next = (*head)->next->next;

            // free memory 
            delete node;
            node = nullptr;

            return;
        }
        // if not first node, follow the normal deletion process 
        // find the previous node 
        CLinkedList *prev = *head;
        while (prev->next && prev->next != node)
            prev = prev->next;

        // check if node really exists in list 
        if (prev->next == nullptr)
        {
            cout << "The node is not present in Linked List\n";
            return;
        }

        // remove node from list 
        prev->next = prev->next->next;

        // free memory 
        delete node;
        node = nullptr;
        return;
    }

    void Reverse(CLinkedList **head)
    {
        // Initialize current, previous and
        // next pointers
        CLinkedList *curr = *head;
        CLinkedList *prev = nullptr, *next = nullptr;

        while (curr != nullptr)
        {
            // Store next
            next = curr->next;

            // Reverse current node's pointer
            curr->next = prev;

            // Move pointers one position ahead.
            prev = curr;
            curr = next;
        }
        *head = prev;
    }
    
    void Print(CLinkedList *head)
    {
        CLinkedList *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Clear(CLinkedList **head)
    {
        CLinkedList *temp = *head;
        while (temp != nullptr)
        {
            CLinkedList *pe = temp;
            temp = temp->next;
            delete pe;
            pe = nullptr;
        }
        *head = nullptr;
    }

private:

    CLinkedList *FindNode(CLinkedList *head, const T &value)
    {
        CLinkedList *temp = head;
        while (temp != nullptr)
        {
            if (temp->value == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

};

