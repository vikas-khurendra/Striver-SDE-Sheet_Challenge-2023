// Problem :

Given a singly linked list of 'N' nodes.The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node. 

// Input :
5
1 2 3 4 5

// Output :
3 4 5

// Code :

Node *findMiddle(Node *head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;  // always write len++ first, before updating temp otherwise there will be memory issue.
        temp = temp->next;
    }

    int mid = len / 2;
    int count = 0;
    while (count < mid)
    {
        head = head->next;
        count++;
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return head;
}

// Note : 
// Calculating the length of the linked list using a loop and then trying to find the middle node 
// based on the length. If the linked list is extremely large, it can result in excessive memory 
// allocation, leading to the memory shortage error.
