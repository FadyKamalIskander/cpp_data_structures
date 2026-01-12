#include <iostream>

class Node
{
public:
    int val;
    Node *next;
    Node (int value)
    {
        this->val = value;
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
    ~LinkedList()
    {
        Node* temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    void append(int value)
    {
        if (length == 0)
        {
            head = new Node(value);
            tail = head;
        }
        else
        {
            const auto temp = new Node(value);
            tail->next = temp;
            tail = temp;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0) return;
        else if (length == 1)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
            length--;
        }
        else
        {
            int i = length;
            Node* tempNode = head;
            while (i > 2)
            {
                tempNode = tempNode->next;
                i--;
            }
            tail = tempNode;
            tail->next = nullptr;
            length--;
            delete tail->next;
            tempNode = nullptr;
        }
    }
    void prepend(int value)
    {
        if (length == 0)
        {
            head = new Node(value);
            tail = head;
            length++;
        }
        else
        {
            auto tempNode = new Node(value);
            tempNode->next = head;
            head = tempNode;
            length++;
        }
    }

    void deleteFirst()
    {
        if (length == 0) return;
        else if (length == 1)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
            length--;
        }
        else
        {
            auto temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }
    //bool insert(int index, int value){}
    void printList() const
    {
        const Node* temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->val << std::endl;
            temp = temp->next;
        }
    }
    void getHead() const
    {
        if (head != nullptr)
        {
            std::cout << "Head: " << head->val << std::endl;
        }
        else
        {
            std::cout << "Head is empty" << std::endl;
        }
    }
    void getTail() const
    {
        if (tail != nullptr)
        {
            std::cout << "Tail: " << tail->val << std::endl;
        }
        else
        {
            std::cout << "Tail is empty" << std::endl;
        }
    }
    void getLength() const
    {
        std::cout << "Length: " << length << std::endl;
    }
};

int main()
{
    auto *myLinkedList = new LinkedList(1);
    myLinkedList->deleteLast();
    myLinkedList->append(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();
    myLinkedList->deleteLast();
    myLinkedList->printList();
    delete myLinkedList;
    return 0;
}
