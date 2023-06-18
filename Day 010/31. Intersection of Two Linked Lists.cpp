// Code :

#include <bits/stdc++.h>

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    if (firstHead == NULL && secondHead == NULL)
    {
        return NULL;
    }

    Node *head1 = firstHead;
    Node *head2 = secondHead;
    unordered_set<Node*> st;

    while (head1)
    {
        st.insert(head1);
        head1 = head1->next;
    }

    while (head2)
    {
        if (st.find(head2) != st.end())
        {
            return head2;
        }
        head2 = head2->next;
    }

    return NULL;
}