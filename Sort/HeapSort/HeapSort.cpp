/*
    下标为i的节点的父节点下标: (i - 1) // 2
    下标为i的节点的左孩子下标: i * 2 + 1
    下标为i的节点的右孩子下标: i * 2 + 2
*/

# include<iostream>

using namespace std;

int getParent(int index)
{
    return (index - 1) / 2;
}

int getLeftChild(int index)
{
    return index * 2 + 1;
}

int getRightChild(int index)
{
    return index * 2 + 2;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
        cout << arr[i] << ", ";
    cout << arr[n-1] << endl;
}

/**
 * @brief 维护堆的性质，交换节点与子节点顺序
 * 
 * @param arr 存储堆的数组
 * @param n 数组长度
 * @param i 待维护节点的下标
 */
void heapify(int arr[], int n, int i);

/**
 * @brief 堆排序入口
 * 
 * @param arr 待排序数组
 * @param n 数组长度
 */
void heapSort(int arr[], int n);

int main()
{
    const int n = 10;
    int arr[n] = {3, 4, 6, 1, 8, 7, 5, 2, 9, 0};
    
    heapSort(arr, n);

    // print(arr, n);

    return 0;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int lChild = getLeftChild(i);
    int rChild = getRightChild(i);

    if(lChild < n && arr[largest] < arr[lChild])  // 左节点比父节点大
        largest = lChild;
    if(rChild < n && arr[largest] < arr[rChild])  // 右节点比左节点大
        largest = rChild;
    if(largest != i)  // 最大的节点不是父节点
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // 建堆
    for(int i=getParent(n); i >= 0; i--)  // 从最后一个有子节点的节点开始维护
        heapify(arr, n, i);
    print(arr, n);

    // 排序
    // 建好堆后，根节点一定是最大的
    for(int i=n-1; i>1; i--)  // i表示未排序的数组的长度，当i=2时，只有头两个节点需要交换顺序，后面的节点已全部有序
    {
        swap(&arr[0], &arr[i]);  // 将根节点与最后一个节点交换，此时后面的节点已经有序
        heapify(arr, i, 0);  // 对根节点进行维护，长度需要排除后面的节点
        print(arr, n);
    }
    swap(&arr[0], &arr[1]);
    print(arr, n);
}