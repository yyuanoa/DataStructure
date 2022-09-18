# include<iostream>

using namespace std;

/// @brief 归并排序入口
/// @param arr 待排序数组
/// @param n 数组长度
void MergeSort(int arr[], int n);

/// @brief 归并排序
/// @param arr 待排序数组
/// @param tempArr 辅助数组
/// @param left 左指针
/// @param right 右指针
void msort(int arr[], int tempArr[], int left, int right);

/// @brief 合并
/// @param arr 待排序数组
/// @param tempArr 
/// @param left 
/// @param mid 
/// @param right 
void merge(int arr[], int tempArr[], int left, int mid, int right);

void print(int arr[], int n)
{
    for(int i=0; i < n-1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[n-1] << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    const int n = 10;
    int arr[n] = {3, 4, 6, 1, 8, 7, 5, 2, 9, 0};

    print(arr, n);

    MergeSort(arr, n);

    print(arr, n);

    return 0;
}

void MergeSort(int arr[], const int n)
{
    // 分配一个辅助数组
    int *tempArr = new int[n];
    if(tempArr)  // 辅助数组分配成功
    {
        msort(arr, tempArr, 0, n-1);
        delete[] tempArr;
    }
    else
    {
        printf("error");
    }
}

void msort(int arr[], int tempArr[], int left, int right)
{
    // 如果只有一个数组，那么就不需要继续划分，只需要被归并即可
    if(left < right)
    {
        int mid = (left + right) / 2;  // 找中间点
        msort(arr, tempArr, left, mid);  // 递归划分左半区域
        msort(arr, tempArr, mid+1, right);  // 递归划分右半区域
        merge(arr, tempArr, left, mid, right);  // 合并已经排序的部分
    }
}

void merge(int arr[], int tempArr[], int left, int mid, int right)
{
    // 标记左半区第一个未排序的元素
    int l_pos = left;
    // 标记右半区第一个未排序的元素
    int r_pos = mid + 1;
    // 临时数组元素的下标
    int pos = left;

    // 合并
    while(l_pos <= mid && r_pos <= right)
    {
        if(arr[l_pos] < arr[r_pos])  // 左半区第一个剩余元素更小
            tempArr[pos++] = arr[l_pos++];
        else  // 右半区第一个剩余元素更小
            tempArr[pos++] = arr[r_pos++];
    }

    // 合并左半区剩余的元素
    while(l_pos <= mid)
        tempArr[pos++] = arr[l_pos++];

    // 合并右半区剩余的元素
    while(r_pos <= right)
        tempArr[pos++] = arr[r_pos++];

    // 把临时数组中合并后的元素复制回原来的数组
    while(left <= right)
    {
        arr[left] = tempArr[left];
        left++;
    }
}
