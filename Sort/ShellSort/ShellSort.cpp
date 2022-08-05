# include <iostream>

using namespace std;


void ShellSort(int* plist, int length)
{
	for(int step=length/2; step>0; step=step/2)  //初始步长step为length/2 
    {
		for(int i=0; i<step; i++)  //遍历每一次分组后的第一个元素
        {	 
			for(int j=i+step; j<length; j+=step)  //遍历步长为step的所有元素 ，进行直接插入排序 
            {	
				int temp = plist[j];
				int m;
				for(m = j-step; m>=0 && plist[m]>temp; m-=step)  //plist[m]小于 temp 时循环结束，结束后应将 temp 赋值给plist[m+step]
                {
					plist[m+step] = plist[m];	//plist[m]比temp大，就将此数后移一位（此处是step位） 
				}
				plist[m+step] = temp;		//将 temp 赋值给plist[m+step]
			}
		}
	}
}


int main(){

    int length = 10;
    int plist[length] = {3, 4, 6, 1, 8, 7, 5, 2, 9, 0};
    // int plist[n] = {3, 1, 2, 5, 4};

    ShellSort(plist, length);

    for(int i=0; i<length; i++)
    {
        cout << plist[i] << " ";
    }

    return 0;
}
