//
// Created by jamesmok on 2021/4/4.
//

#include "customerList.h"
#include <string>
#include <iostream>
using namespace std;

customerList::customerList() {//init化乘客表
    head = new CustomStruct;//headNode
    head->name = "NULL";
    head->count = -1;
    head->level = "-1";
    head->next = NULL;
    head->pre = NULL;
}

void customerList::push(string name0,int count0,string level0) {//从最后放入Node
    CustomStruct *p = new CustomStruct;//增加Node
    p->name = name0;//输入乘客名
    p->count = count0;//输入购买票数
    p->level = level0;//输入坐位等级
    if(head->next == NULL)//如果只有headNode
    {
        head->next = p;
        p->pre = head;
        tail = p;
    }
    else//己经有若干个node
    {
        CustomStruct *cur = head->next;
        CustomStruct *q;
        while(cur != tail)
            cur = cur->next;
        cur->next = p;
        q = cur;
        cur = cur->next;
        cur->pre = q;
        tail = cur;
        tail->next = NULL;
    }
}

CustomStruct *customerList::getHead() {
    return head->next;//headnode的后一个Node才是第一个node
}

void customerList::Delete(string name0) {
    CustomStruct *cur = head->next;//第一个node
    while(cur!=NULL)//以乘客名进行search
    {
        if(head->next->name == name0)//要删除的数据在第一个Node
        {
            head->next->next->pre = head;
            head->next = head->next->next;
            break;
        }
        else if(tail->name == name0)//要删除的数据在最后一个Node
        {
            tail = tail->pre;
            tail->next = NULL;
            break;
        }
        else if(cur->name == name0)//要删除的数据在中间
        {
            cur->pre->next = cur->next;
            cur->pre = cur->pre->pre;
            break;
        }
        cur = cur->next;
    }
}

CustomStruct *customerList::getCur(string name0) {
    CustomStruct *cur = head->next;
    while(cur!=NULL)
    {
        if(cur->name == name0)
        {
            return cur;
        }
        cur = cur->next;
    }
}


