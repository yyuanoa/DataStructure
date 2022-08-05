# include <iostream>

using namespace std;


void InsertSort(int* plist, int length)  // 直接插入排序
{
    for(int i=0; i<length-1; i++)
    {
        for(int j=i; j>=0; j--)
        {
            if (plist[j] > plist[j+1])
            {
                int temp = plist[j];
                plist[j] = plist[j+1];
                plist[j+1] = temp;
            }
        }
    }
}


int main()
{
    int length = 10;
    int plist[length] = {3, 4, 6, 1, 8, 7, 5, 2, 9, 0};
    // int plist[n] = {3, 1, 2, 5, 4};

    InsertSort(plist, length);

    for(int i=0; i<length; i++)
    {
        cout << plist[i] << " ";
    }

    return 0;
}