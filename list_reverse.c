/*************************************************************************
	> File Name: main.c
	> Author: huihui 
	> Mail: xiaoyuering@163.com 
	> Created Time: Wed 14 Nov 2018 05:00:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>


#define max(a,b)  (((long)(a-b)) & 0x80000000)?b:a//判断a和b的大小
#define ISUNSIGNED(x) ((x)>=0&&~(x)>=0) //判断是否是有符号类型
#define LEN 5

typedef struct node{
    int data;
	struct node *next;
}Node;

Node *list_create(int len){
	int cnt = 0;
	Node *plist = malloc(sizeof(Node));

	plist->next = NULL;
    plist->data = cnt;

	for(cnt=1; cnt<len; cnt++)
	{
		Node *new = malloc(sizeof(Node));
		new->data = cnt; 
		new->next = plist;
		plist = new;
	}
	return plist;
}

Node *list_reverse(Node *phead){
	if(phead==NULL || phead->next==NULL){
		return NULL;	
	}
	Node *backup = phead;
	Node *p = phead->next;
	
	while(p->next!=NULL){
	    backup = p->next;	
		p->next = phead;

		phead = p;
		p = backup;	        
	}
	p->next = phead; //牢记善后处理。
	
	return p;
}

int main(int argc, char **argv)
{
	int cnt = 0;
	Node *pHeader = list_create(LEN);//pHeader is a head pointer to list.
	Node *ptmp = pHeader;
	for(cnt=0;cnt<LEN;cnt++){
	    printf("%3d", ptmp->data);
		ptmp = ptmp->next;
	}
    pHeader = list_reverse(pHeader);
	
	printf("\nresult:\n");
	for(cnt=0;cnt<LEN;cnt++){
	    printf("%3d", pHeader->data);
		pHeader = pHeader->next;
	}	
	printf("\ndone.\n");
	return 0;
}
