#include<stdio.h>
/*
异或，也称为半加操作（不带进位的加法，比如 0^0=0，1^0=1，0^1=1，1^1=0（同为0，异为1），这些法则与加法是相同的，只是不带进位）
	1.异或满足交换律。
    2.相同两个数异或为0。
    3.0异或一个数为那个数本身。
例子:1^2^9^2^1 = 1^1^2^2^9 = 9

半加操作还可以交换两个数的值：
	switch()
*/
void swp(int *a,int *b) {
	*a=*a^*b; 
	*b=*a^*b; 
	*a=*a^*b;
}

int singleNumber(int A[], int n) {
	int num = 0;
	int i=0;
	for(i=0;i<n;i++){
		num^=A[i];
		printf("num=[%d], A[%d]=[%d]\n",num,i,A[i]);
	}
	return num;
}

int main(){

	int A[]= {1,2,9,2,1};
	printf("allen num=[%d]\n",singleNumber(A,5));
	int a=1,b =3;
	swp(&a, &b);
	printf("a:[%d],b[%d]\n",a,b);
	return 0;
}