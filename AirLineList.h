#ifndef FINALPROGRAM2021_AIRLINELIST_H
#define FINALPROGRAM2021_AIRLINELIST_H

#include "airlineStruct.h"

class AirLineList {
public:
    AirLineList();
    void push(int airline0,string flight0,string destination0,string day0,int ticketCount0);//航班数据放在最后node中
    AirlineStruct *ASCgetPos(AirlineStruct *begin, AirlineStruct *end);//升序快排getPos
    void ASCQuickSort(AirlineStruct *begin, AirlineStruct *end);//升序快排
    AirlineStruct *DESCgetPos(AirlineStruct *begin, AirlineStruct *end);//降序快排getPos
    void DESCQuickSort(AirlineStruct *begin, AirlineStruct *end);//降序快排
    void Sort(string choose);
    void swap(AirlineStruct *a, AirlineStruct *b);//两个node间进行数据交换
    void insert(int pos);//插入航班
    void Delete(int air);//删除航班
    int getSize();//链表长度
    void Display();//显示航班表
    AirlineStruct *getHead();//取得第一毎Node
    void DeleteAll();//清空链表
    void checkDestination();//查询和目的地有关的航班
    void searchCustomerList();//查询某一航班的乘客表
    void BuyTicket();//以目的地为根据买票
    void BuyTicket2();//以航班号为根据买票
    void ReturnTicket();//退票
    void CustomerOwnTickets();
private:
    AirlineStruct *head, *tail;
};


#endif
