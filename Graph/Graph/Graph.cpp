#include<iostream>
#include<queue>
#include<vector>
using namespace std;


// template<class t>
// struct Vertex  // 顶点，用于存放数据
// {
//     t data;
//     Vertex(t d)
//     {
//         data = d;
//     }
// };

// template<class t>
// struct Edge  // 边，用于存放点与点之间的关系
// {
//     Vertex<t> start;
//     Vertex<t> end;
//     Edge(Vertex<t> s, Vertex<t> e)
//     {
//         start = s;
//         end = e;
//     }
// };

// template<class t>
// class AdjacentMatrix  // 邻接矩阵
// {
// private:
//     bool directed;
//     vector<t> Vertics;  // 存放顶点，数据类型按照输入类型决定
//     vector<vector<int>> Edges;  // 存放边，临接矩阵中数据为距离，0表示不连接
//     int VerNum;  // 顶点数量

// public:
//     AdjacentMatrix(bool isDirected)  directed = isDirected;  // 输入true是有向图，false是无向图
//     void Create()  // 输入数据
//     {
//         cout >> "请输入结点，使用空格隔开：" << endl;;  // 输入顶点
        
//         for(int i=0; i<VerNum; i++)  // 按顺序输入
//         {
//             // cin >> ;
            
//         }

//     }

// };

template<class t>
vector<t> InputData()
{
    t i;
    vector<t> outData;
    while(cin >> i)
    {
        outData.push_back(i);
        while(cin.peek() == ' ')
            cin.get();
        if(cin.peek() == '\n')
            break;
    }
    return outData;
}

 
int main()
{
    vector<int> out;
    out = InputData<int>();
    for(auto it=out.begin(); it!=out.end(); it++)
        cout << *it << endl;

    return 0;
}