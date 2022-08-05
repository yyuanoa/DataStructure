# include <iostream>

using namespace std;


void QuickSort(int* plist, int low, int high)
{
    if(low >= high){
        return;
    }
    int i=low, j=high;
    int key = plist[low];
    while(i<j)
    {
        while(plist[j]>=key && i<j)
        {
            j --;
        }
        plist[i] = plist[j];
        while(plist[i]<=key && i<j)
        {
            i++;
        }
        plist[j] = plist[i];
    }
    plist[i] = key;
    QuickSort(plist, low, i-1);
    QuickSort(plist, i+1, high);
}


int main(){

    int length = 10;
    int plist[length] = {3, 4, 6, 1, 8, 7, 5, 2, 9, 0};
    // int plist[n] = {3, 1, 2, 5, 4};

    QuickSort(plist, 0, length-1);

    for(int i=0; i<length; i++)
    {
        cout << plist[i] << " ";
    }

    return 0;
}