SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

if (!head1) return head2;
    if (!head2) return head1;

    SinglyLinkedListNode* mergedHead = NULL;
    SinglyLinkedListNode* mergedTail = NULL;

    // Initialize mergedHead and mergedTail
    if (head1->data <= head2->data) {
        mergedHead = mergedTail = head1;
        head1 = head1->next;
    } else {
        mergedHead = mergedTail = head2;
        head2 = head2->next;
    }
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            mergedTail->next = head1;
            mergedTail = head1;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            mergedTail = head2;
            head2 = head2->next;
        }
    }
    if (head1) {
        mergedTail->next = head1;
    } else {
        mergedTail->next = head2;
    }

    return mergedHead;
}
