# include<iostream>
# include<vector>


using namespace std;

template<class t>
struct Node  // 图的结点，用于存储数据
{
    t data;
};

template<class t>
struct Edge  // 图的边，用于存储结点间的关系
{
    Node<t>* start;
    Node<t>* end;
    Edge(Node<t>* s, Node<t>* e)
    {
        start = s;
        end = e;
    }
};

class Graph
{
private:


public:

};

int main()
{

    return 0;
}

