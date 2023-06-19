// Code :

int length(LinkedListNode<int> *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

LinkedListNode<int> *reverseLL(LinkedListNode<int> *head2)
{
    LinkedListNode<int> *cur = head2;
    LinkedListNode<int> *pre = NULL;
    LinkedListNode<int> *nex = NULL;
    while (cur != NULL)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    head2 = pre;
    return head2;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    if (head == NULL)
    {
        return true;
    }

    int len = length(head);
    int mid = len / 2;

    int count = 1;
    LinkedListNode<int> *temp = head;
    while (count < mid)
    {
        temp = temp->next;
        count++;
    }
    LinkedListNode<int> *head2 = temp->next;
    temp->next = NULL;

    head2 = reverseLL(head2);

    while (head != NULL && head2 != NULL)
    {
        if (head->data != head2->data)
        {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }

    return true;
}