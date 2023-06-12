/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    if (head == nullptr || k <= 0) {
        return head;
    }

    Node* fast = head;
    Node* slow = head;
    Node* prev = nullptr;

    // Move the fast pointer k nodes ahead
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            return head; // The list has fewer than k nodes
        }
        fast = fast->next;
    }

    // Move both pointers simultaneously until the fast pointer reaches the end
    while (fast != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the kth node
    if (prev == nullptr) {
        // If prev is still null, it means the head node is the kth node from the end
        head = head->next;
    } else {
        prev->next = slow->next;
    }

    // Delete the removed node
    delete slow;

    return head;
}

