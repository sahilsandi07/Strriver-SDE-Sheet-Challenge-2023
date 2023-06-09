#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head) {
    LinkedListNode<int>* prev = nullptr;
    LinkedListNode<int>* curr = head;
    
    while (curr != nullptr) {
        LinkedListNode<int>* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}
