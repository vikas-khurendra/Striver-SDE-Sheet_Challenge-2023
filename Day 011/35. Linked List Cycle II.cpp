// Code :

Node *firstNode(Node *head)
{
    unordered_set<Node *> st;
    Node *temp = head;
    while (temp != NULL)
    {
        if (st.find(temp) != st.end())
        {
            return temp;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return NULL;
}