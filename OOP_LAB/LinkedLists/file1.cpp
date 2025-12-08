#include <iostream>
#include <string>
using namespace std;

struct Node{
    string data;
    Node *next;
};

int main() {
    Node *head = nullptr;
    //create first node
    Node *first = new Node();
    first->data = "Momina";
    first->next = nullptr;
    //point head to first node
    head = first;
    //display 
    cout << first->data << endl;

    return 0;
}

//✔ Linked List = scattered memory + connected by pointers