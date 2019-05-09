#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
快速排序（交换类）：主要分两个步骤，
1. 先来一次快排：将第一个元素作为枢轴，从右往左遍历，碰到比key小的，则换位置；换完后再从左往右遍历，碰到比key大的，则换位置。
  时间复杂度为n

2. 经过一次快排后，继续对小于key的和大于key的部分分别进行递归快排。

*/
int LEN;

/*打印指定整形数组*/
void print_arr(int *array, int L, int R){
    if(L<R){
        while(L <= R){
            printf("%-3d", array[L++]);
        }
    }
    printf("\n");
}

void quickSort(int *arr, int left,int right){
/*  printf("start->L=%d R=%d ",left, right);
    print_arr(arr, left, right);
*/
    if(left < right){  //从递归退出的条件
        int L = left;
        int R = right;
        int key = arr[L];

        while(L!=R){
            /*先从右往左遍历，直到遇到比key小的*/
            while(arr[R] >= key && L<R){
                R--;
            }
            if(R>L){
                arr[L] = arr[R];
                L++;
            }
            /*再从左往右遍历，直到遇到比key大的*/
            while(arr[L] < key && L<R){
                L++;
            }
            if(L<R){
                arr[R] = arr[L];                
                R++;
            }
        }
        arr[L]=key;//经过一次快排之后，原来的序列变成以key为中枢，划分为两部分（左边的都小于key，右边的大于key）
        
        quickSort(arr, left, L-1);// 继续对左边部分进行快排
        quickSort(arr, L+1, right);//对右边部分快排
    }
}

int main()
{
    int arr[]={49, 38, 65, 97, 76, 13, 27, 49};
    int length=sizeof(arr)/sizeof(int);
    LEN=length;

    quickSort(arr, 0, LEN-1);

    print_arr(arr, 0, LEN-1);
    exit(0);
}
