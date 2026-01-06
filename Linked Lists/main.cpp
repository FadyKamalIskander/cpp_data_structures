#include <iostream>

class Node
{
public:
    int value;
    Node *next;
    Node (int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList(int value)
    {
        head = new Node(value);
        tail = head;
        length = 1;
    }
    ~LinkedList() {}
    void append(int value) {}
    void prepend(int value) {}
    bool insert(int index, int value){}
    void printList()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }
    void getHead() const
    {
        std::cout << "Head: " << head->value << std::endl;
    }
    void getTail() const
    {
        std::cout << "Tail: " << tail->value << std::endl;
    }

    void getLength() const
    {
        std::cout << "Length: " << length << std::endl;
    }
};


int main()
{
    LinkedList *myLinkedList = new LinkedList(4);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();
    delete myLinkedList;
    return 0;
}
