# DataStructure

## LinkedList

### 约瑟夫环

问题：N个人围成一圈，从第一个开始报数，第M个将被杀掉，最后剩下一个，其余人都将被杀掉。求剩下的这个人是谁。

分别利用线状链表（等同于数组）和环状链表实现约瑟夫环。

## Tree

### BinaryTree

实现二叉树的增、删、查、改功能，并利用递归实现前序、中序、后序遍历。

其中二叉树节点的删除操作需要额外注意：

首先，需要寻找删除节点是否存在，因此方法应该设置为bool类型，若存在则返回true，不存在则返回false；

然后，该节点的存在方式有三种，可分为两大类分别讨论：

1. 该节点的子节点 $\leqslant1$ ，例如：$15\rightarrow11\rightarrow13\rightarrow14$，删除11.

这种情况比较简单，用该节点的子节点替换该节点就行。此时该节点对应地址用不上，可以直接delete；

2. 该节点的子节点数 $=2$，例如：$15\rightarrow11\rightarrow10\rightarrow13\rightarrow12\rightarrow14$（前序遍历），删除11.

这种情况较为复杂，考虑到树单个节点的删除应该对树整体改动尽可能小，可以用该节点左子树的最大值（靠右下角的值），或右子树的最小值（靠左下角的值）代替该节点的值。在例中，右子树的最小值为12，故将11替换为12，并delete12，即可完成操作。

## Sort(例：3, 4, 6, 1, 8, 7, 5, 2, 9, 0)

### InsertSort(插入排序)

将第$i$个数插入到前$i-1$个数组成的有序数列中。

例中，将1插入到3,4,6中：比较1和6的大小，发现$1<6$，交换1和6的顺序；然后比较1和4的大小，发现$1<4$，交换1和4的位置；然后比较1和3的大小，发现$1<3$，交换1和3的位置，此时1，3，4，6组成的数列有序。

### ShellSort(希尔排序，缩小增量排序)

1. 设置初始步长step（一般设置为 length//2）；
2. 将数组中每隔step个数组成的数组归为一组，分别对其进行插入排序；
3. 将step=step//2，重复2，3操作直到step<1.

例中step=length//2=5，因此归类为{3, 7}, {4, 5}, {6, 2}, {1, 9}, {8, 0}，分别对其进行插入排序，整体数组变为:

{3, 4, 2, 1, 0, 7, 5, 6, 9, 8};

然后step=5//2=2，归类为{3, 2, 0, 5, 9}, {4, 1, 7, 6, 8}，分别进行插入排序，整体数组变为：

{0, 1, 2, 4, 3, 6, 5, 7, 9, 8};

然后step=2//2=1，进行插入排序，整体数组有序；

最后step=1//2=0，退出循环。

### QuickSort（快速排序）

1. 设置分界值（一般设置为第一个数），设置i，j下标，分别为数组最低位和最高位（以下分别用i，j代替i，j下标对应的值）；
2. j 从右向左寻找比i小的数，若找到，或 j 坐标 < i 坐标，则将 j 赋给 i ；
3. i 从左向右寻找比j大的数，若找到，或 i 坐标 > j 坐标，则将 i 赋给 j ；
4. 重复2，3操作，直到 i 坐标> j 坐标相遇，将分界值赋给i；
5. 递归操作分界值左边的数列和右边的数列，当数列长度为1时递归条件终止。

例中分界值为3，i对应3，j对应0，0<3，将 j 赋给 i ，i 为0；i向右寻找，找到 4>0，将 i 赋给 j ，j=4，此时数列为：

{0, 4, 6, 1, 8, 7, 5, 2, 9, 4}；

j向左寻找，找到 2<4, 将 j 赋给 i，i为2；i向右寻找，找到 6>2，将 i 赋给 j，j=6，此时数列为：

{0, 2, 6, 1, 8, 7, 5, 6, 9, 4}；

j向左寻找，找到 1<6, 将 j 赋给 i，i为1；i向右寻找，i>j，将 i 赋给 j，j=1，跳出循环，此时数列为：

{0, 2, 1, 1, 8, 7, 5, 6, 9, 4}；

i坐标>j坐标，跳出大循环，将分界值赋给 i ，i=3，此时数列为：

{0, 2, 1, 3, 8, 7, 5, 6, 9, 4}；

递归操作3左边的数列和3右边的数列。

### 时间复杂度的空间复杂度

| 排序方法     | 平均时间复杂度   | 空间复杂度 |
| ------------ | ---------------- | ---------- |
| 直接插入排序 | $O(n^2)$       | $O(1)$   |
| 希尔排序     | $O(n^{1.3})$   | $O(1)$   |
| 快速排序     | $O(nlog_{2}n)$ | $O(n^2)$ |
