#include <iostream>


struct Node {
    char data;
    Node *next;
};

Node* head = nullptr;

bool cycle(Node* head) {
    if (!head) {
        return false;
    }
    Node *slow = head;
    Node *fast = head;

    int step = 0;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        std::cout << step << " "<< "{slow: " << slow->data << ", fast: ";

        if (fast) {
            std::cout << fast->data;
        } else {
            std::cout << "nullptr";
        }

        std::cout << " '}" << std::endl;
        

        if (slow == fast) {
            std::cout << "Meet at " << slow->data << std::endl;
            return true;
        }
        step++;
    }
    return false;
}



int main() {
    Node* node1 = new Node{'A', nullptr};
    Node* node2 = new Node{'B', nullptr};
    Node* node3 = new Node{'C', nullptr};
    Node* node4 = new Node{'D', nullptr};

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates a cycle

    Node* head1 = node1;
     if (cycle(head1)) {
        std::cout << "Cycle detected!" << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    // Clean up memory (not reachable due to cycle, but included for completeness)
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    Node* nodeA = new Node{'E', nullptr};
    Node* nodeB = new Node{'F', nullptr};
    Node* nodeC = new Node{'G', nullptr};
    Node* nodeD = new Node{'H', nullptr};

    head = nodeA;
    nodeA->next = nodeB;
    nodeB->next = nodeC;
    nodeC->next = nodeD;
    nodeD->next = nullptr; // No cycle

    Node* head2 = nodeA;

    if (cycle(head2)) {
        std::cout << "Cycle detected!" << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    // Clean up memory (not reachable due to cycle, but included for completeness)
    delete nodeA;
    delete nodeB;
    delete nodeC;
    delete nodeD;

    return 0;
}