// Code :

int length(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node *removeKthNode(Node *head, int K)
{
    if(head == NULL)
    {
        return NULL;
    }

    int pos = length(head) - K;

    if(pos == 0)    // When 0th position is to be deleted add this condition
    {
        Node *temp = head;
        head = temp -> next;
        delete temp;
        return head;
    }

    Node *temp = head;
    int count = 1;
    while (count < pos)
    {
        temp = temp->next;
        count++;
    }

    Node *a = temp->next;
    temp->next = temp->next->next;
    delete a;

    return head;
}
