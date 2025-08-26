SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = create_singly_linked_list_node(data);
    if (position == 0) {
        newNode->next = llist;
        return newNode;
    }
    SinglyLinkedListNode* current = llist;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return llist; 
}