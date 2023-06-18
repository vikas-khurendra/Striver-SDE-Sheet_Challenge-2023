// Code :

#include <bits/stdc++.h>

bool detectCycle(Node *head)
{
    Node *temp = head;
    unordered_set<Node *> st;

    while (temp)
    {
        if (st.find(temp) != st.end())
        {
            return true;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return false;
}