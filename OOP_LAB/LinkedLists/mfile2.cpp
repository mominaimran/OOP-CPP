// Creating a linked list in C++
#include<iostream>
using namespace std;

struct Node
{
    int Data;
    Node* Link;
};

void display(Node* current)
{
    while (current != nullptr)
    {
        cout << current->Data << endl;
        current = current->Link;
    }
}
void insertAtFront(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->Data = newData;

    newNode->Link = *head;  
    *head = newNode;          
}

int main()
{
    // declaration of the pointers for 3 nodes
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // first node
    head->Data = 32;
    head->Link = second;

    // second node
    second->Data = 46;
    second->Link = third;

    // third node
    third->Data = 6;
    third->Link = nullptr;

    display(head);
    insertAtFront(&head, 99); // inserts 99 at the front
    display(head);

    return 0;
}
