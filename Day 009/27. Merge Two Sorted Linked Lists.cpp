// Code :

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == NULL && second == NULL)
    {
        return NULL;
    }

    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    Node<int> *FH = NULL;
    Node<int> *FT = NULL;

    if (first->data < second->data)
    {
        FH = first;
        FT = first;
        first = first->next;
    }
    else if(first->data >= second->data)
    {
        FH = second;
        FT = second;
        second = second->next;
    }

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            FT->next = first;
            FT = first;
            first = first->next;
        }
        else if(first->data >= second->data)
        {
            FT->next = second;
            FT = second;
            second = second->next;
        }
    }

    if (first == NULL)
    {
        FT->next = second;
    }

    if (second == NULL)
    {
        FT->next = first;
    }

    return FH;
}
