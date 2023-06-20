// Code :

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> mp;

    // Create copies of nodes and store in hashmap
    LinkedListNode<int> *temp = head;
    while (temp)
    {
        mp[temp] = new LinkedListNode<int>(temp->data);
        temp = temp->next;
    }

    // Assign next and random pointers of copied nodes
    temp = head;
    while (temp)
    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}