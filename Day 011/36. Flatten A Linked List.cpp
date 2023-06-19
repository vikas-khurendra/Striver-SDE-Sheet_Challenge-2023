// Code :

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }

    if (right == NULL)
    {
        return left;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else
        {
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }

    if (left != NULL)
    {
        temp->child = left;
    }

    if (right != NULL)
    {
        temp->child = right;
    }

    ans = ans->child;
    return ans;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *currentHead = head;
    Node *right = head->next;
    currentHead->next = NULL;

    right = flattenLinkedList(right);

    Node *ans = merge(currentHead, right);
    // Here 'ans' will save the merge of currHead (i.e. 7, 6 and 1, 3, 5 = 1, 3, 5, 6, 7).
    
    return ans;
    // Here 'ans' will return merged list (i.e. 1, 3, 5, 6, 7) to previous 'right' recursive call
    // for merging currHead & right.
}
