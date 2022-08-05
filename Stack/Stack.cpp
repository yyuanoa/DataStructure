
// #define _CRTDBG_MAP_ALLOC
// #include <stdlib.h>
// #include <crtdbg.h>
// #define NEW_WITH_MEMORY_LEAK_CHECKING new(_NORMAL_BLOCK, __FILE__, __LINE__)
// #define new NEW_WITH_MEMORY_LEAK_CHECKING

#include <iostream>

using namespace std;


class Node
{
private:
    int value;
    Node* next = nullptr;

public:
    Node(int mval)
    {
        value = mval;
    }

    void setNextNode(Node* node)
    {
        next = node;
    }

    int getValue()
    {
        return value;
    }

    Node* getNextNode()
    {
        return next;
    }
};

class Stack
{
private:
    Node* head = nullptr;
    int length = 0;

public:
    int pull()  // 弹出栈中元素
    {
        if(head == nullptr)
        {
            cout << "push from empty stack." << "\n";
            return -1;
        }
        Node* temp = head;
        while(temp->getNextNode()->getNextNode() != nullptr)
        {
            temp = temp->getNextNode();
        }
        int res = temp->getNextNode()->getValue();
        length -= 1;
        temp->setNextNode(nullptr);
        return res;
    }

    void push(int val)  // 压入栈中
    {
        Node* node = new Node(val);
        if(head == nullptr)
        {
            head = node;
        }
        else
        {
            Node* temp = head;
            while(temp->getNextNode() != nullptr)
            {
                temp = temp->getNextNode();
            }
            temp->setNextNode(node);
        }
        length += 1;
        // delete(node);
    }

    void print()
    {
        Node* temp = head;
        while(temp->getNextNode() != nullptr)
        {
            cout << temp->getValue() << " -> ";
            temp = temp->getNextNode();
        }
        cout << temp->getValue() << "\n";
    }

    int getLength()
    {
        return length;
    }
};

int main()
{
    Stack *stack = new Stack;

    stack->push(5);
    stack->push(8);
    stack->push(3);
    stack->push(7);

    stack->print();

    cout << stack->pull() << "\n";

    stack->print();
    delete(stack);

    // _CrtDumpMemoryLeaks();
    return 0;
}