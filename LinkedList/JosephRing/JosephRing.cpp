// 利用环状链表实现约瑟夫环
# include<iostream>
# include<vector>

using namespace std;

template<class type>
class Node
{
private:
    type value;
    Node<type>* next = nullptr;
public:
    Node(type val)
    {
        value = val;
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
class JosephRing
{
private:
    Node<type>* head = nullptr;
    int kill;  // 每当数到kill就kill掉
    int length = 0;

public:
    JosephRing(vector<type> nums, int k)
    {
        kill = k;
        for(int i=0; i<nums.size(); i++)
        {
            addNextNode(nums[i], i==nums.size()-1);
        }

    }

    void addNextNode(type val, bool circle)
    {
        Node<type>* node = new Node<type>(val);
        if(head == nullptr)
        {
            head = node;
        }
        else
        {
            Node<type>* cur = head;
            while(cur->getNextNode())
            {
                cur = cur->getNextNode();
            }
            cur->setNextNode(node);
            if(circle)  // 若到末尾，则将首尾连成环
            {
                cur->getNextNode()->setNextNode(head);
            }
        }
        length ++;  // 每增加一个节点，长度加1
    }

    void start()
    {
        Node<type>* cur = head;
        Node<type>* parent = nullptr;
        int k=1;
        while(true)
        {
            if(k == kill)
            {
                parent->setNextNode(cur->getNextNode());
                cur = cur->getNextNode();
                length --;
                k = 1;
                if(length == 1)
                {
                    cout << parent->getValue() << endl;
                    break;
                }
                continue;
            }
            parent = cur;
            cur = cur->getNextNode();
            k ++;
        }
        delete cur;
    }
};

int main()
{
    int kill = 3;
    vector<char> nums = {'a', 'b', 'c', 'd', 'e'};

    JosephRing<char> ring(nums, kill);

    ring.start();

    return 0;
}