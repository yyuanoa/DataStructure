# include<iostream>
# include<vector>

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

class LinkedList
{
private:
    Node* head = nullptr;
    int length = 0;

public:

    void addNextNode(int val)  // 向后增加一个节点
    {
        Node* node = new Node(val);
        if (head == nullptr)
        {
            head = node;
        }
        else
        {
            Node* temp = head;
            while (!(temp->getNextNode() == nullptr))
            {
                temp = temp->getNextNode();
            }
            temp->setNextNode(node);
        }
        length += 1;
    }

    void addNextNodes(vector<int> vals)  // 向后增加多个节点
    {
        for(int i=0; i<vals.size(); i++)
        {
            this->addNextNode(vals[i]);
        }
    }

    void addBeforeNode(int val)  // 向前增加一个节点
    {
        Node* temp = new Node(val);
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
        Node* node = new Node(val);
        Node* temp = head;
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
        Node* temp = head;
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

    int findValue(int val)  // 查找节点，返回index，没有返回-1
    {
        int index;
        Node* temp = head;
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
        Node* temp = head;
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

    void circular()  // 将链表首尾连接
    {
        Node* temp = head;
        while(temp->getNextNode() != nullptr)
        {
            temp = temp->getNextNode();
        }
        temp->setNextNode(head);
    }

};

int main()
{
    LinkedList *JosephRing = new LinkedList;
    int num = 7;  // 有7人参与约瑟夫环
    int kill = 3;  // 报3的人出局
    vector<int> nums = {};
    for(int i=0; i<num; i++)
    {
        nums.push_back(i);
    }
    JosephRing->addNextNodes(nums);
    // plist->circular();

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


    // plist->print();

    return 0;
}