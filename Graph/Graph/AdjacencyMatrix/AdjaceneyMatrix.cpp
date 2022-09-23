#include<iostream>
#include<string>
using namespace std;

#define MaxNum 50

// 判断数据是否在数组内
template<class t>
bool isInArray(t array[MaxNum], t data, int n)
{
    for(int i=0; i<n; i++)
        if(array[i] == data)
            return true;
    return false;
}

// 返回数据在数组中的下标，不存在返回 -1
template<class t>
int locate(t array[MaxNum], t data, int n)
{
    int i;  // 下标
    for(i=0; i<n; i++)
        if(array[i] == data)
            return i;
    return -1;
}

// ------  邻接矩阵  --------
template<class t>
struct AdjacencyMatrix
{
    t vexs[MaxNum];  // 顶点表
    int arcs[MaxNum][MaxNum] = {0};  // 邻接矩阵
    int vexnum;  // 顶点数量
};

template<class t>
void inputDataIntoMatrix(AdjacencyMatrix<t> *matrix)
{
    int vexnum;
    cout << "请输入顶点数量：";
    cin >> vexnum;
    (*matrix).vexnum = vexnum;

    cout << "请输入顶点存储的值，用空格隔开：";
    int i=0;
    t vex;
    while(cin >> vex)
    {
        (*matrix).vexs[i] = vex;
        i++;
        if(cin.get() == '\n')  break;
    }

    while(i != vexnum)
    {
        // 若输入顶点数量过多，重新输入
        while(i > vexnum)
        {
            cout << "输入顶点过多，请重新输入：";
            i = 0;
            while(cin >> vex)
            {
                (*matrix).vexs[i] = vex;
                i ++;
                if(cin.get() == '\n') break;
            }
        }
        // 若输入顶点过少，补充输入
        if(i < vexnum)
        {
            cout << "输入顶点过少，请继续输入：";
            while(cin >> vex)
            {
                (*matrix).vexs[i] = vex;
                i ++;
                if(cin.get() == '\n')  break;
            }
        }
    }

    cout << endl;

    for(int i=0; i<vexnum; i++)
    {
        int j = 0;
        t arc;  // 存储相邻顶点的数据
        cout << "请输入与顶点 " << (*matrix).vexs[i] << " 相连的顶点，用空格隔开：";
        while(cin >> arc)
        {
            int index = locate((*matrix).vexs, arc, vexnum);
            if(index != -1)  // 若顶点存在
            {
                (*matrix).arcs[i][index] = 1;
                (*matrix).arcs[index][i] = 1;
            }
            if(cin.get() == '\n')  break;  // 输入回车跳出循环
            j ++;
        }
    }
    cout << endl;
}

// 打印邻接矩阵
template<class t>
void printAdjacencyMatrix(AdjacencyMatrix<t> matrix)
{
    cout << "\t";
    for(int i=0; i<matrix.vexnum; i++)
    {
        cout << matrix.vexs[i] << '\t';
    }
    cout << endl;

    for(int i=0; i<matrix.vexnum; i++)
    {
        cout << matrix.vexs[i] << '\t';
        for(int j=0; j<matrix.vexnum; j++)
        {
            cout << matrix.arcs[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}
// ------- end ---------

int main()
{
    AdjacencyMatrix<string> matrix;
    inputDataIntoMatrix<string>(&matrix);
    printAdjacencyMatrix(matrix);

    return 0;
}