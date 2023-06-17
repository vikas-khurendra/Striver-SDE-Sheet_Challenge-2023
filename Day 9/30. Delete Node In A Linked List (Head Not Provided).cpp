// Code :

void deleteNode(LinkedListNode<int> *node)
{
    node->data = node->next->data;
    node->next = node->next->next;

    // LinkedListNode<int> *tempNode = node->next;
    // node->data = tempNode->data;
    // node->next = tempNode->next;
    // tempNode->next = NULL;
    // delete tempNode;
}