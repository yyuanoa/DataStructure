# include<iostream>
# include<vector>
# include<queue>
# include<algorithm>

using namespace std;

class TreeNode
{
private:
    int weight;  // 权重
    TreeNode* leftChild = nullptr;
    TreeNode* rightChild = nullptr;

public:
    TreeNode(int val)
    {
        weight = val;
    }

    void setLeftChild(TreeNode* node)
    {
        leftChild = node;
    }

    void setRightChild(TreeNode* node)
    {
        rightChild = node;
    }

    int getWeight()
    {
        return weight;
    }

    TreeNode* getLeftChild()
    {
        return leftChild;
    }

    TreeNode* getRightChild()
    {
        return rightChild;
    }
};

class StackNode
{
private:
    TreeNode* value;
    StackNode* next = nullptr;
public:
    StackNode(TreeNode* val)
    {
        value = val;
    }
    TreeNode* getValue()
    {
        return value;
    }
    StackNode* getNextNode()
    {
        return next;
    }
    void setNextNode(StackNode* node)
    {
        next = node;
    }
};

class Stack
{
private:
    StackNode* head = nullptr;
    int length = 0;
public:
    void push(TreeNode* val)  // 将元素压入栈中
    {
        StackNode* node = new StackNode(val);
        if (head == nullptr)
        {
            head = node;
            length ++;
        }
        else
        {
            if(head->getValue()->getWeight() <= val->getWeight())  // 当头节点的值比插入值小时
            // 这里的符号要和下面的一起更改
            {
                node->setNextNode(head);
                head = node;
                length ++;
                return;
            }
            StackNode* cur = head;
            while(cur->getNextNode())
            {
                // cur中存储的是TreeNode类型元素，cur->getNextNode()->getValue()得到的是TreeNode，cur->getNextNode()->getValue()->getWeight()得到的才是int值
                if(cur->getNextNode() && cur->getNextNode()->getValue()->getWeight() <= val->getWeight())  // 将栈中数据从大到小排序
                /*
                两个条件的含义：
                1. 当前节点有下一节点；
                2. 当前节点下一节点的值比插入的值小，例如栈中元素为: 5->3->1, 插入4，cur指向5时，下一节点为3，比4小，则将4插入到3前面
                    对于相等的值，使用 < 号会使插入的值插入到后面，使用 <= 号会使其插入到前面，
                    例如：栈中元素为: 5->3->1, 插入元素为3，用(3)来表示
                    使用 < 号：5 -> 3 -> (3) -> 1
                    使用 <= 号：5 -> (3) -> 3 -> 1
                    注意：这里的符号要和上面的一起更改，否则逻辑会出现错误
                */
                {
                    node->setNextNode(cur->getNextNode());
                    cur->setNextNode(node);
                    length ++;
                    return;
                }
                cur = cur->getNextNode();
            }
            cur->setNextNode(node);
            length ++;
        }
    }

    TreeNode* pop()  // 将元素弹出栈中
    {
        if(!head->getNextNode())  // 若栈中只有一个元素
        {
            TreeNode* data = head->getValue();
            head = nullptr;
            length --;
            return data;
        }
        StackNode* cur = head;
        while(cur->getNextNode()->getNextNode())  // 该条件表示：当前节点cur不是栈顶节点
        {
            cur = cur->getNextNode();
        }
        TreeNode* data = cur->getNextNode()->getValue();
        cur->setNextNode(nullptr);
        length --;
        return data;
    }

    int getLength()
    {
        return length;
    }

    void print()
    {
        StackNode* cur = head;
        while(cur->getNextNode())
        {
            cout << cur->getValue()->getWeight() << "->";
            cur = cur->getNextNode();
        }
        cout << cur->getValue()->getWeight() << endl;
    }
};

class HuffmanTree
{
private:
    TreeNode* root = nullptr;
    Stack leafNode;
    int code[10];  // 10需要大于树的深度

    void _preorder(TreeNode* cur)
    {
        if(!cur)
        {
            return;
        }
        cout << cur->getWeight() << " ";
        _preorder(cur->getLeftChild());
        _preorder(cur->getRightChild());
    }

    void _getCode(TreeNode* cur, int length)  // length表示cur的深度
    {
        if (!cur->getLeftChild())  // 若cur的下一节点为空，即cur为叶子节点。由于每个节点都有左右节点，故只要一个没有就都没有
        {
            cout << cur->getWeight() << "的编号为: ";
            for(int i=0; i<length; i++)
            {
                cout << code[i] << " ";
            }
            cout << endl;
            return;
        }
        // 给左节点赋0
        code[length] = 0;
        _getCode(cur->getLeftChild(), length+1);
        // 给右节点赋1
        code[length] = 1;
        _getCode(cur->getRightChild(), length+1);

    }
public:
    HuffmanTree(vector<int> nums)  // 向leafNode中添加叶子节点
    {
        for(int i=0; i<nums.size(); i++)
        {
            TreeNode* temp = new TreeNode(nums[i]);
            leafNode.push(temp);
        }
        createTree();
    }

    void createTree()  // 将叶子节点组合为哈夫曼树
    {
        while(leafNode.getLength()>1)  // 当leafNode只剩一个节点时，这个节点就是根节点
        {
            TreeNode* left = leafNode.pop();  // 左子节点，值较小
            TreeNode* right = leafNode.pop();  // 右子节点，值较大
            TreeNode* parent = new TreeNode(left->getWeight()+right->getWeight());  // 双亲节点，其值为左右节点的值之和
            parent->setLeftChild(left);  // 指定双亲节点的左子节点
            parent->setRightChild(right);  // 指定双亲节点的右子节点
            leafNode.push(parent);
        }
        root = leafNode.pop();
    }

    void getCode()  // 哈夫曼编码
    {
        _getCode(root, 0);
    }

    void preorder()  // 前序遍历
    {
        _preorder(root);
        cout << endl;
    }
};

int main()
{
    vector<int> plist = {13, 8, 3, 9, 7, 8, 11, 1, 9, 6};
    // vector<int> plist = {1, 2, 3};
    HuffmanTree tree(plist);

    tree.preorder();
    tree.getCode();

    return 0;
}