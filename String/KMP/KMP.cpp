# include<iostream>
# include<string>

using namespace std;


/// @brief 获取next[x]，直接法
/// @param P 子串
/// @param x 获取next[x]
/// @return 
int getNext(string P, int x)
{
    int i, j;
    for(i=x; i>0; i--)
    {
        if(P[0] == P[i])
        {
            for(j=1; i+j <= x; j++)
                if(P[j] != P[i+j])
                    return 0;

            return j;
        }
    }
    return 0;
}


void buildNext(string P, int* next)
{
    int len = P.size();
    int x = 1;  // next[0]一定是0，因此从next[1]开始算
    int now = 0;

    while(x < len)
    {
        if(P[now] == P[x])  // 若P[now] == P[x]，则向后扩展
        {
            now ++;
            next[x] = now;
            x ++;
        }
        else if(now)  // 若不匹配，则根据next向前回溯
            now = next[now - 1];
        else
            x ++;
    }
}

/// @brief 根据 next 进行查找
/// @param S 主串
/// @param P 子串
/// @return 
int KMP(string S, string P)
{
    int i = 0;  // 主串坐标
    int j = 0;  // 子串坐标
    const int len = P.size();
    int next[len] = {0};

    buildNext(P, next);

    while(i < S.size())
    {
        if (S[i] == P[j])  // 若主串和子串相同，则继续向后匹配
        {
            i ++;
            j ++;
        }
        else if(j)  // 若匹配失败，且 j 不为 0 ，则根据 next 跳到后面
            j = next[j - 1];
        else  // 若匹配失败，且 j == 0，则直接向后查找
            i ++;

        if(j == len)  // 若 j 已经达到 P 串结尾，则匹配成功
        {
            return i - j;  // 返回起点
        }
    }
    return -1;  // 匹配失败，返回-1
}



int main()
{
    // string S = "mississippi";
    // string P = "issip";
    string S = "abcabbabcababcababcbabcabababcabcaba";
    string P = "abcababcbabcab";

    cout << KMP(S, P) << endl;

    return 0;
}
