#include <iostream>

using namespace std;

template <class type>
class Node
{
private:
    type value;
    Node<type>* next = nullptr;

public:
    Node(type mval)
    {
        value = mval;
    }

    void setNextNode(Node* node)
    {
        next = node;
    }

    type getValue()
    {
        return value;
    }

    Node* getNextNode()
    {
        return next;
    }
};

template <class type>
class Stack
{
private:
    Node<type>* head = nullptr;
    int length = 0;

public:
    type pull()  // 弹出栈顶元素
    {
        if(head == nullptr)
        {
            cout << "push from empty stack." << "\n";
            return -1;
        }
        int res = head->getValue();
        head = head->getNextNode();
        return res;
    }

    void push(int val)  // 压入栈顶
    {
        Node<type>* node = new Node<type>(val);
        if(head == nullptr)
        {
            head = node;
        }
        else
        {
            node->setNextNode(head);
            head = node;
        }
        length += 1;
    }

    void print()
    {
        Node<type>* temp = head;
        cout << "top: ";
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
    Stack<char> stack;

    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');

    stack.print();

    cout << stack.pull() << "\n";

    stack.print();

    return 0;
}