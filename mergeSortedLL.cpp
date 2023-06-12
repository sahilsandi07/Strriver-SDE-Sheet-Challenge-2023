#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* head1, Node<int>* head2)
{
    Node<int>* mergedHead = nullptr;  // Head of the merged linked list
    Node<int>* mergedTail = nullptr;  // Tail of the merged linked list

    // Check if either list is empty
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    // Determine the head of the merged list
    if (head1->data <= head2->data) {
        mergedHead = head1;
        mergedTail = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        mergedTail = head2;
        head2 = head2->next;
    }

    // Merge the remaining nodes
    while (head1 != nullptr && head2 != nullptr) {
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

    // Attach the remaining nodes, if any
    if (head1 != nullptr) {
        mergedTail->next = head1;
    }
    if (head2 != nullptr) {
        mergedTail->next = head2;
    }

    return mergedHead;
}
