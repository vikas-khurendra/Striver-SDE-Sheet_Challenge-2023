// Code :

Node *newNode(int data)
{
    Node *newNode = new Node(data);
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

Node *addTwoNumbers(Node *num1, Node *num2)
{
    if (num1 == NULL && num2 == NULL)
    {
        return NULL;
    }

    if (num1 == NULL)
    {
        return num2;
    }

    if (num2 == NULL)
    {
        return num1;
    }

    int sum = 0, carry = 0;
    Node *temp = NULL; 
    Node *prev = NULL;
    Node *newHead = NULL;
    while (num1 != NULL && num2 != NULL)
    {
        sum = (num1->data) + (num2->data) + carry;
        carry = sum / 10;
        sum = sum % 10;
        temp = newNode(sum);

        if(newHead == NULL)
        {
            newHead = temp;
            prev = temp;
        }
        else
        {
            prev -> next = temp;
            prev = temp;
        }

        num1 = num1->next;
        num2 = num2->next;
    }

    while (num1 != NULL)
    {
        sum = (num1->data) + carry;
        carry = sum / 10;
        sum = sum % 10;
        temp = newNode(sum);
        prev -> next = temp;
        prev = temp;
        num1 = num1->next;
    }

    while (num2 != NULL)
    {
        sum = (num2->data) + carry;
        carry = sum / 10;
        sum = sum % 10;
        temp = newNode(sum);
        prev -> next = temp;
        prev = temp;
        num2 = num2->next;
    }

    if (carry > 0)
        temp->next = newNode(carry);

    return newHead;
}
