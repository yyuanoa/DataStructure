# include<iostream>
# include<vector>

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

template<class type>
class LinkedList
{
private:
    Node<type>* head = nullptr;
    int length = 0;

public:

    void addNextNode(type val)  // 向后增加一个节点
    {
        Node<type>* node = new Node<type>(val);
        if (head == nullptr)
        {
            head = node;
        }
        else
        {
            Node<type>* temp = head;
            while (!(temp->getNextNode() == nullptr))
            {
                temp = temp->getNextNode();
            }
            temp->setNextNode(node);
        }
        length += 1;
    }

    void addBeforeNode(int val)  // 向前增加一个节点
    {
        Node<type>* temp = new Node<type>(val);
        temp->setNextNode(head);
        head = temp;
        length += 1;
    }

    void insertNode(int index, int val)  // 在index处插入节点
    {
        if(index >= length)
        {
            this->addNextNode(val);
            return;
        }
        Node<type>* node = new Node<type>(val);
        Node<type>* temp = head;
        for(int i=0; i<index-1; i++)
        {
            temp = temp->getNextNode();
        }
        node->setNextNode(temp->getNextNode());
        temp->setNextNode(node);
        length += 1;
    }

    void deleteNode(int index)  // 删除index处节点
    {
        if(index >= length)
        {
            cout << "delete index out of range." << "\n";
            return;
        }
        if(index == 0)
        {
            head = head->getNextNode();
            length -= 1;
            return;
        }
        Node<type>* temp = head;
        for(int i=0; i<index-1; i++){
            temp = temp->getNextNode();
        }
        if(temp->getNextNode() == nullptr)
        {
            temp->setNextNode(nullptr);
        }
        else
        {
            temp->setNextNode(temp->getNextNode()->getNextNode());
        }
        length -= 1;
    }

    type findValue(type val)  // 查找节点，返回index，没有返回-1
    {
        int index;
        Node<type>* temp = head;
        for(index=0; index<length; index++)
        {
            if(temp->getValue() == val)
            {
                return index;
            }
            temp = temp->getNextNode();
        }
        return -1;
    }

    void print()  // 打印链表
    {
        Node<type>* temp = head;
        while (!(temp->getNextNode() == nullptr))
        {
            cout << temp->getValue() << " -> ";
            temp = temp->getNextNode();
        }
        cout << temp->getValue() << "\n";
    }

    int getLength()  // 获取链表长度
    {
        return length;
    }

};

int main()
{
    LinkedList<int> *JosephRing = new LinkedList<int>;
    int num = 7;  // 有7人参与约瑟夫环
    int kill = 3;  // 报3的人出局
    vector<int> nums = {};
    for(int i=0; i<num; i++)
    {
        JosephRing->addNextNode(i);
    }

    JosephRing->print();
    int k = 1;  // 从1开始报数
    int index = 0;  // 第index个人，从0开始到num-1
    while (JosephRing->getLength() > 1)
    {
        if (index >= JosephRing->getLength())  // 若index比length大，则将index重置为0
        {
            index = 0;
        }
        if(k == kill)  // 若报kill，则将这个人移除，k重置为0.由于移除时index指向了下一个人，将index-1
        {
            JosephRing->deleteNode(index);
            k = 0;
            index -= 1;
            JosephRing->print();
        }  
        k += 1;
        index += 1;
    }

    delete JosephRing;

    return 0;
}