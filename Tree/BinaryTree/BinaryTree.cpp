# include<iostream>
# include<vector>

using namespace std;

class Node
{
private:
    int value;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;

public:
    Node(int m_val)
    {
        value = m_val;
    }

    int getValue()
    {
        return value;
    }

    void setValue(int val)
    {
        value = val;
    }

    Node* getLeftChild()
    {
        return leftChild;
    }

    Node* getRightChild()
    {
        return rightChild;
    }

    void setLeftChild(Node* node)
    {
        leftChild = node;
    }

    void setRightChild(Node* node)
    {
        rightChild = node;
    }
};

class BinaryTree
{
private:
    Node* root = nullptr;

    void _push(int val, Node* current_node)
    {
        if(val < current_node->getValue())
        {
            if(current_node->getLeftChild() == nullptr)
            {
                Node* node = new Node(val);
                current_node->setLeftChild(node);
            }
            else
            {
                _push(val, current_node->getLeftChild());
            }
        }
        else if(val > current_node->getValue())
        {
            if(current_node->getRightChild() == nullptr)
            {
                Node* node = new Node(val);
                current_node->setRightChild(node);
            }
            else
            {
                _push(val, current_node->getRightChild());
            }
        }
    }

    void _preorder(Node* current_node)
    {
        if(!current_node)
        {
            return;
        }
        cout << current_node->getValue() << " ";
        _preorder(current_node->getLeftChild());
        _preorder(current_node->getRightChild());
    }

    void _inorder(Node* current_node)
    {
        if(!current_node)
        {
            return;
        }
        _inorder(current_node->getLeftChild());
        cout << current_node->getValue() << " ";
        _inorder(current_node->getRightChild());
    }

    void _postorder(Node* current_node)
    {
        if(!current_node)
        {
            return;
        }
        _postorder(current_node->getLeftChild());
        _postorder(current_node->getRightChild());
        cout << current_node->getValue() << " ";
    }

public:
    void push(int val)  // ???
    {
        if(root == nullptr)
        {
            Node* node = new Node(val);
            root = node;
        }
        else
        {
            _push(val, root);
        }
    }

    bool search(int val)  // ???
    {
        Node* current_node = root;
        while(current_node)
        {
            if(val < current_node->getValue())
            {
                current_node = current_node->getLeftChild();
            }
            else if(val > current_node->getValue())
            {
                current_node = current_node->getRightChild();
            }
            else
            {
                delete current_node;
                return true;
            }
        }
        delete current_node;
        return false;
    }

    bool erase(int val)  // ???
    {
        Node* cur = root;
        Node* parent = nullptr;
        while(cur)
        {
            if(val < cur->getValue())  // ?????????
            {
                parent = cur;
                cur = cur->getLeftChild();
            }
            else if(val > cur->getValue())  // ?????????
            {
                parent = cur;
                cur = cur->getRightChild();
            }
            else  // ????????????
            {
                if(!cur->getLeftChild())  // ???????????????????????????
                {
                    if (cur == root)  // ?????????????????????????????????????????????
                    {
                        root = cur->getRightChild();
                    }
                    else
                    {
                        if(parent->getLeftChild() == cur)
                        {
                            parent->setLeftChild(cur->getRightChild());
                        }
                        else
                        {
                            parent->setRightChild(cur->getRightChild());
                        }
                    }
                    delete cur;
                }

                else if(!cur->getLeftChild())  // ???????????????????????????
                {
                    if (cur == root)  // ?????????????????????????????????????????????
                    {
                        root = cur->getLeftChild();
                    }
                    else
                    {
                        if(parent->getLeftChild() == cur)
                        {
                            parent->setLeftChild(cur->getLeftChild());
                        }
                        else
                        {
                            parent->setRightChild(cur->getLeftChild());
                        }
                    }
                    delete cur;
                }
                else  // ??????????????????????????????????????????
                {
                    // 1.???????????????????????????????????????????????????????????????
                    // 2.?????????????????????????????????????????????????????????
                    // ??????????????????
                    Node* maxNode = cur->getLeftChild();
                    Node* maxParent = cur;
                    while(maxNode->getRightChild())
                    {
                        maxParent = maxNode;
                        maxNode = maxNode->getRightChild();
                    }
                    if(maxParent->getLeftChild() == maxNode)
                    {
                        maxParent->setLeftChild(maxNode->getRightChild());
                    }
                    else
                    {
                        maxParent->setRightChild(maxNode->getRightChild());
                    }
                    cur->setValue(maxNode->getValue());
                    delete maxNode;
                }
                return true;
            }
        }
        return false;  // ??????????????????
    }

    bool change(int target, int val)  // ???
    {
        bool exist = erase(target);
        if(exist)
        {
            push(val);
        }
        return exist;
    }

    void preorder()  // ????????????
    {
        _preorder(root);
        cout << "\n";
    }

    void inorder()  // ????????????
    {
        _inorder(root);
        cout << "\n";
    }

    void postorder()  // ????????????
    {
        _postorder(root);
        cout << "\n";
    }
};

int main()
{
    BinaryTree tree;
    vector<int> nlist = {10, 5, 7, 15, 13, 12, 14, 11, 17};

    for(int i=0; i<nlist.size(); i++)
    {
        tree.push(nlist[i]);
    }

    // tree.push(3);
    // tree.push(1);
    // tree.push(5);
    // tree.push(2);
    // tree.push(4);
    // tree.push(6);

    // cout << tree.search(1) << endl;
    // cout << tree.search(7) << endl;
    tree.preorder();
    // tree.inorder();
    // tree.postorder();
    // tree.erase(12);
    // tree.preorder();

    tree.change(19, 20);
    tree.preorder();

    return 0;
}