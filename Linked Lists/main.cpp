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

    bool insert(Node* newNode, int index)
    {
        if (index < 0|| index > length)
        {
            return false;
        }
        if (length == 0)
        {
            head = newNode;
            length++;
            return true;
        }
        else
        {
            if (index == 0)
            {
                prepend(newNode->val);
                return true;
            }
            else if (index == length - 1)
            {
                append(newNode->val);
                return true;
            }
            else
            {
                Node* tempNode = get(index);
                auto temporar = tempNode->next;
                tempNode->next = newNode;
                newNode->next = temporar;
                length++;
                return true;
            }
        }
    }
    void printList() const
    {
        const Node* temp = head;
        std::cout << "Linked List:" << std::endl;
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
    Node* get(int index) const
    {
        if (index < 0|| index > length||length == 0)
        {
            return nullptr;
        }
        else if (length == 1)
        {
            return head;
        }
        else
        {
            Node* tempNode = head;
            int i = 0;
            while (i < index)
            {
                tempNode = tempNode->next;
                i++;
            }
            return tempNode;
        }
    }
    bool set(int index, int inputValue) const
    {
        if (index < 0|| index > length||length == 0)
        {
            return false;
        }
        else if (length == 1)
        {
            head->val = inputValue;
            return true;
        }
        else
        {
            Node* tempNode = head;
            int i = 0;
            while (i < index)
            {
                tempNode = tempNode->next;
                i++;
            }
            tempNode->val = inputValue;
            return true;
        }
    }

    bool deleteNode(int index)
    {
        if (index < 0 || index > length || length == 0)
        {
            return false;
        }
        else if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
            length--;
            return true;
        }
        else
        {
            Node *tempNode = head;
            Node* tempNode2 = head->next;
            if (index == 0)
            {
                head = tempNode2;
                delete tempNode;
                length--;
                return true;
            }
            else
            {
                for (int i = 0; i < index; i++)
                {
                    tempNode2 = tempNode;
                    tempNode = tempNode->next;
                }
                tempNode2->next = tempNode->next;
                delete tempNode;
                length--;
                return true;
            }
        }
    }

    void reverse()
    {
        auto tempo = tail;
        tail = head;
        Node* tempNode = head;
        Node* tempNode2 = head->next;
        Node* tempNode3 = new Node(0);
        tail->next = nullptr;

        for (int i = 0; i < length-1; i++)
        {
            tempNode3 = tempNode2->next;
            tempNode2->next = tempNode;
            tempNode = tempNode2;
            tempNode2 = tempNode3;
        }
        head = tempo;
        head->next = tempNode2;
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
    myLinkedList->printList();
    Node* newNode2 = new Node(669);
    myLinkedList->insert(newNode2, 0);
    myLinkedList->printList();
    Node* newNode3 = new Node(778);
    myLinkedList->insert(newNode3, 5);
    myLinkedList->printList();
    Node* newNode4 = new Node(567);
    myLinkedList->insert(newNode4, 2);
    myLinkedList->printList();
  //  myLinkedList->getHead();
  //  myLinkedList->getTail();
  //  myLinkedList->getLength();
  //  myLinkedList->printList();
  //  myLinkedList->deleteLast();
  //  myLinkedList->printList();
  //  myLinkedList->deleteNode(0);
  //  myLinkedList->printList();
  //  myLinkedList->deleteNode(6);
  //  myLinkedList->printList();
  //  myLinkedList->deleteNode(3);
  //  myLinkedList->printList();
    myLinkedList->reverse();
    myLinkedList->printList();
    delete myLinkedList;
    return 0;
}
