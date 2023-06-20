// Code :

Node *rotate(Node *head, int k)
{
    if (head == NULL || k == 0)
    {
        return head;
    }

    int len = 1;
    Node *current = head;
    while (current->next != NULL)
    {
        len++;
        current = current->next;
    }

    int rotations = k % len;  // k % len is used to determine the effective number of rotations needed
    if (rotations == 0)
    {
        return head;
    }

    int distance = len - rotations; // distance find no. of step to reach next head;
    Node *temp = head;

    int count = 1; // Start from 1 to stop at the node before the new head
    while (count < distance)
    {
        temp = temp->next;
        count++;
    }

    Node *newHead = temp->next;
    temp->next = NULL;
    current->next = head;

    return newHead;
}
