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

    bool insert(int index, int value)
    {
        if (index < 0|| index >= length)
        {
            return false;
        }
        if (length == 0)
        {
            head = new Node(value);
            length++;
            return true;
        }
        else
        {
            if (index == 0)
            {
                prepend(value);
                return true;
            }
            else if (index == length - 1)
            {
                append(value);
                return true;
            }
            else
            {
                Node* tempNode = get(index);
                auto temporar = tempNode->next;
                auto newNode = new Node(value);
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
        if (index < 0|| index >= length||length == 0)
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
        if (index < 0|| index >= length||length == 0)
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
        if (index < 0 || index >= length || length == 0)
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
        if (length == 0 || length == 1) return;
        Node* tempNode = head;
        Node* tempNode2 = head->next;
        Node* tempNode3 = tempNode2->next;

        for (int i = 0; i < length-1; i++)
        {
            tempNode2->next = tempNode;
            tempNode = tempNode2;
            if (tempNode3 == nullptr) break;
            tempNode2 = tempNode3;
            tempNode3 = tempNode3->next;
        }
        auto tempo = tail;
        tail = head;
        head = tempo;
        tail->next = nullptr;
    }

    // following implementation assumes linked list has no length member
    Node* findMiddleNode()
    {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        bool isFound = false;
        auto tempNode = head;
        int intSlow = 0;
        int intFast = 1;
        while (!isFound)
        {
            for (int i = 0; i <= intFast; i++)
            {
                if ((tempNode->next == nullptr) || (tempNode == tail))
                {
                    if (intFast % 2 != 0) intSlow++;
                    isFound =  true;
                    break;
                }
                tempNode = tempNode->next;
            }
            if (isFound) break;
            intSlow++;
            intFast = intSlow * 2;
            tempNode = head;
        }
        tempNode = head;
        for (int i = 0; i < intSlow; i++)
        {
            tempNode = tempNode->next;
        }
        return tempNode;
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
    myLinkedList->append(6);
    myLinkedList->append(7);
    myLinkedList->printList();
    //  myLinkedList->insert(0, 669);
    //  myLinkedList->printList();
    //  myLinkedList->insert(5, 6);
    //  myLinkedList->printList();
    //  myLinkedList->insert(2, 567);
    //  myLinkedList->printList();
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
    //  myLinkedList->reverse();
    //  myLinkedList->printList();
    std::cout << "middle index is: " << myLinkedList->findMiddleNode() << std::endl;;
    delete myLinkedList;
    return 0;
}
