// 利用环状链表实现约瑟夫环
# include<iostream>
# include<vector>

using namespace std;


class Node
{
private:
    int value;
    Node* next = nullptr;
public:
    Node(int val)
    {
        value = val;
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

class JosephRing
{
private:
    Node* head = nullptr;
    int kill;  // 每当数到kill就kill掉
    int length = 0;

public:
    JosephRing(vector<int> nums, int k)
    {
        kill = k;
        for(int i=0; i<nums.size(); i++)
        {
            addNextNode(nums[i], i==nums.size()-1);
        }

    }

    void addNextNode(int val, bool circle)
    {
        Node* node = new Node(val);
        if(head == nullptr)
        {
            head = node;
        }
        else
        {
            Node* cur = head;
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
        Node* cur = head;
        Node* parent = nullptr;
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
    int kill = 7;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

    JosephRing ring(nums, kill);

    ring.start();

    return 0;
}