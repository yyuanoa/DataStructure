#include<iostream>
#include<string>
using namespace std;

#define MaxNum 50

// 邻接表的结点
template<class t>
struct Node
{
    t data;
    Node<t> *next = nullptr;
};

// 邻接表
template<class t>
struct AdjacencyList
{
    Node<t> vexs[MaxNum];
    int vexnum;
};


template<class t>
void inputDataIntoList(AdjacencyList<t>* list)
{
    int vexnum;
    cout << "请输入节点数量：";
    cin >> vexnum;
    (*list).vexnum = vexnum;

    int i=0;
    t inputData;
    cout << "请输入节点存储的值，用空格隔开：";
    while(cin >> inputData)
    {
        Node<t> vertex;
        vertex.data = inputData;

        (*list).vexs[i] = vertex;

        i ++;
        if(cin.get() == '\n')  break;
    }

    t inputVex;
    i=0;
    Node<t> *temp = nullptr;
    for(i=0; i<vexnum; i++)
    {
        cout << "请输入节点 " << (*list).vexs[i].data << " 连接的节点，用空格隔开：";
        int j=0;
        temp = &(*list).vexs[i];
        while(cin >> inputVex)
        {
            Node<t> *vertex = new Node<t>;
            vertex->data = inputVex;
            temp->next = vertex;
            temp = temp->next;

            j ++;
            if(cin.get() == '\n')  break;
        }
    }
}

template<class t>
void printAdjacencyList(AdjacencyList<t> list)
{
    Node<t> *temp;
    for(int i=0; i<list.vexnum; i++)
    {
        temp = &list.vexs[i];
        while(temp->next)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}

int main()
{
    AdjacencyList<string> list;
    inputDataIntoList(&list);
    printAdjacencyList(list);

    return 0;
}