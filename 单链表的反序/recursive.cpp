
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;

struct Node
{
    int vale;
    Node *next;
};

/*创建长度为n的一个随机整数链表*/
Node* creat_list(int n)
{
    Node *head = new Node;
    head->next = NULL;
    Node *pre = head;
    srand(0);

    for(int i = 0; i < n; i++)
    {
        Node *current = new Node;
        current->vale = rand();
        current->next = NULL;
        pre->next = current;
        pre = current;
    }

    return head;
}

/*链表的逆序*/
Node* reverse_list(Node *plist, Node *&head) //这个函数的返回值并不是最终链表逆序后的链表头，而是尾，
                                            //它的头保存在head指针里，所以head用的是指针引用.
{
    Node *pback = NULL;
    if(plist == NULL || plist->next == NULL)
    {
        head->next = plist;
        return plist;
    }
    else
    {
        pback = reverse_list(plist->next, head);
        pback->next = plist;
        return plist;
    }
}

/*从头节点依次显示链表里的元素，注意这里头节点里的元素没有被当做第一个元素*/
void show_list(Node *p)
{
    while(p->next != NULL)
    {
        cout<<p->next->vale<<"  ";
        p = p->next; //因为每个结构体的节点不是以数组的形式存在，所以其地址不是连续的，不能用p++
    }
    cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int n = 10;
    Node *my_list = creat_list(n);
    cout<<"My list is : "<<endl;
    show_list(my_list);

    Node *head = new Node;
    cout<<"My reverse_list is : "<<endl;
    reverse_list(my_list->next, head)->next = NULL;
    show_list(head);
    return 0;
}