#include <iostream>

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

Node* flatten_dfs(Node* prev, Node* curr) {
    if (!curr)
        return prev;

    curr->prev = prev;
    prev->next = curr;

    Node* tempNext = curr->next;
    Node* tail = flatten_dfs(curr, curr->child);
    curr->child = nullptr;

    return flatten_dfs(tail, tempNext);
}

Node* flatten(Node* head) {
    if (!head)
        return head;

    Node* pseudoHead = new Node(0);
    flatten_dfs(pseudoHead, head);

    Node* realHead = pseudoHead->next;
    if (realHead) {
        realHead->prev = nullptr;
    }
    delete pseudoHead;
    return realHead;
}

void printList(Node* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->prev = head->next->next->child;
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->prev = head->next->next->child->next;
    head->next->next->child->next->next->next = new Node(10);
    head->next->next->child->next->next->next->prev = head->next->next->child->next->next;

    head->next->next->child->next->child = new Node(11);
    head->next->next->child->next->child->next = new Node(12);
    head->next->next->child->next->child->next->prev = head->next->next->child->next->child;

    head = flatten(head);
    printList(head);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
