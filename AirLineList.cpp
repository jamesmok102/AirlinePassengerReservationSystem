//
// Created by jamesmok on 2021/3/18.
//

#include "AirLineList.h"
#include "CustomStruct.h"
#include "customerList.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

AirLineList::AirLineList() {
    head = new AirlineStruct;
    head->airline = -1;
    head->flight = "NULL";
    head->destination = "NULL";
    head->day = "NULL";
    head->ticketCount = -1;
    head->next = NULL;
    head->pre = NULL;
    head->cl = NULL;
}

void AirLineList::push(int airline0,string flight0,string destination0,string day0,int ticketCount0) {
    AirlineStruct *p = new AirlineStruct;
    p->airline = airline0;
    p->flight = flight0;
    p->destination = destination0;
    p->day = day0;
    p->ticketCount = ticketCount0;
    p->cl = new customerList;
    if(head->next == NULL)
    {
        head->next = p;
        p->pre = head;
        tail = p;
    }
    else
    {
        AirlineStruct *cur = head->next;
        AirlineStruct *q;
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

void AirLineList::Display() {
    cout << setiosflags(ios::left) << setw(15) << "AIRLINE";
    cout << setiosflags(ios::left) << setw(15) << "FLIGHT";
    cout << setiosflags(ios::left) << setw(20) << "DESTINATION";
    cout << setiosflags(ios::left) << setw(15) << "DAY";
    cout << setiosflags(ios::left) << setw(15) << "TICKET_COUNT" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    AirlineStruct *cur = head->next;
    while(cur!=nullptr)
    {
        cout << setiosflags(ios::left) << setw(15) << cur->airline;
        cout << setiosflags(ios::left) << setw(15) << cur->flight;
        cout << setiosflags(ios::left) << setw(20) << cur->destination;
        cout << setiosflags(ios::left) << setw(15) << cur->day;
        cout << setiosflags(ios::left) << setw(15) << cur->ticketCount << endl;
        cur = cur->next;
    }
}

AirlineStruct* AirLineList::ASCgetPos(AirlineStruct *begin, AirlineStruct *end) {
    AirlineStruct *p = begin;
    AirlineStruct *q = begin->next;
    int x = begin->airline;
    while(q!=end)
    {
        if(q->airline < x)
        {
            p = p->next;
            swap(p,q);
        }
        q = q->next;

    }
    swap(begin,p);
    return p;
}

void AirLineList::ASCQuickSort(AirlineStruct *begin, AirlineStruct *end) {
    if(begin != end)
    {
        AirlineStruct *pos = ASCgetPos(begin,end);
        ASCQuickSort(begin,pos);
        ASCQuickSort(pos->next,end);
    }
}

void AirLineList::Sort(string choose) {
    if(choose == "ASC")
        ASCQuickSort(head->next,NULL);
    else if(choose == "DESC")
        DESCQuickSort(head->next,NULL);

}

void AirLineList::swap(AirlineStruct *a, AirlineStruct *b) {
    int Tairline, TticketCount;
    string Tflight, Tdestination, Tday;
    customerList *CLtemp;
    Tairline = a->airline;
    Tflight = a->flight;
    Tdestination = a->destination;
    Tday = a->day;
    TticketCount = a->ticketCount;
    CLtemp = a->cl;
    a->airline = b->airline;
    a->flight = b->flight;
    a->destination = b->destination;
    a->day = b->day;
    a->ticketCount = b->ticketCount;
    a->cl = b->cl;
    b->airline = Tairline;
    b->flight = Tflight;
    b->destination = Tdestination;
    b->day = Tday;
    b->ticketCount = TticketCount;
    b->cl = CLtemp;
}

AirlineStruct *AirLineList::DESCgetPos(AirlineStruct *begin, AirlineStruct *end) {
    AirlineStruct *p = begin;
    AirlineStruct *q = begin->next;
    int x = begin->airline;
    while(q!=end)
    {
        if(q->airline > x)
        {
            p = p->next;
            swap(p,q);
        }
        q = q->next;

    }
    swap(begin,p);
    return p;
}

void AirLineList::DESCQuickSort(AirlineStruct *begin, AirlineStruct *end) {
    if(begin != end)
    {
        AirlineStruct *pos = DESCgetPos(begin,end);
        DESCQuickSort(begin,pos);
        DESCQuickSort(pos->next,end);
    }
}

void AirLineList::insert(int pos) {
    AirlineStruct *data;
    int airline0,ticket0;
    string flight0,destination0,day0;
    cout << "Please enter your data of airline" << endl;
    cout << "Airline: "; cin >> airline0;
    cout << "Flight: "; cin >> flight0;
    cout << "Destination: "; cin >> destination0;
    cout << "Day: "; cin >> day0;
    cout << "TicketCount: "; cin >> ticket0;
    if(pos == 1)
    {
        data = new AirlineStruct;

        data->airline = airline0;
        data->flight = flight0;
        data->destination = destination0;
        data->day = day0;
        data->ticketCount = ticket0;
        data->cl = new customerList;

        data->next = head->next;
        head->next->pre = data;
        head->next = data;
        data->pre = head;
    }else if(pos == getSize())
        push(airline0,flight0,destination0,day0,ticket0);
    else if(pos >= 1 && pos <= getSize())
    {
        data = new AirlineStruct;

        data->airline = airline0;
        data->flight = flight0;
        data->destination = destination0;
        data->day = day0;
        data->ticketCount = ticket0;
        data->cl = new customerList;

        AirlineStruct *p = head->next;
        int count = 1;
        while(count != pos)
        {
            count++;
            p = p->next;
        }
        data->next = p;
        data->pre = p->pre;
        p->pre->next = data;
        data->pre = p;
    }else
    {
        cout << "Insert Error!!" << endl;
    }
    fstream Customer;
    string path = "customer\\"+to_string(airline0)+".txt";
    Customer.open(path,ios::out);
    Customer.close();
}

int AirLineList::getSize() {
    AirlineStruct *p = head->next;
    int size;
    while(p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}

void AirLineList::Delete(int air) {
    AirlineStruct *cur = head->next;
    int airline0;
    while(cur!=nullptr)
    {
        if(cur->airline == air)
        {
            airline0 = cur->airline;
            break;
        }
        cur = cur->next;
    }
    if(head->next->airline == air)
    {
        head->next->next->pre = head;
        head->next = head->next->next;
    }
    else if(tail->airline == air)
    {
        tail = tail->pre;
        tail->next = NULL;
    }
    else if(cur == NULL)
    {
        cout << "Delete Error!!" << endl;
    }
    else
    {
        AirlineStruct *p = head->next;
        while(p->airline != air)
            p = p->next;
        p->pre->next = p->next;
        p->pre = p->pre->pre;
    }
    string path = "customer\\"+to_string(airline0)+".txt";
    const char* p = path.data();
    remove(p);
}

AirlineStruct *AirLineList::getHead() {
    return head->next;
}

void AirLineList::DeleteAll() {
    head->next = NULL;
    tail = NULL;
}

void AirLineList::checkDestination() {
    string d;
    cout << "Destination: ";
    cin >> d;
    AirlineStruct *cur = head->next;
    cout << setiosflags(ios::left) << setw(15) << "AIRLINE";
    cout << setiosflags(ios::left) << setw(15) << "FLIGHT";
    cout << setiosflags(ios::left) << setw(20) << "DESTINATION";
    cout << setiosflags(ios::left) << setw(15) << "DAY";
    cout << setiosflags(ios::left) << setw(15) << "TICKET_COUNT" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    while(cur != NULL)
    {
        if(cur->destination == d)
        {
            cout << setiosflags(ios::left) << setw(15) << cur->airline;
            cout << setiosflags(ios::left) << setw(15) << cur->flight;
            cout << setiosflags(ios::left) << setw(20) << cur->destination;
            cout << setiosflags(ios::left) << setw(15) << cur->day;
            cout << setiosflags(ios::left) << setw(15) << cur->ticketCount << endl;
        }
        cur = cur->next;
    }
}

void AirLineList::searchCustomerList() {
    int num;
    cout << "Airline Number: ";
    cin >> num;
    AirlineStruct *cur = head->next;
    bool flag = false;
    while(cur!=NULL)
    {
        if(cur->airline == num)
        {
            flag = true;
            break;
        }
        cur = cur->next;
    }
    if(!flag)
    {
        cout << "NULL CUSTOMER LIST" << endl;
        return;
    }
    if(cur->cl->getHead() == NULL)
    {
        cout << "NULL Airline" << endl;
        return;
    }
    CustomStruct *Customcur = cur->cl->getHead();
    cout << setiosflags(ios::left) << setw(15) << "NAME";
    cout << setiosflags(ios::left) << setw(15) << "COUNT";
    cout << setiosflags(ios::left) << setw(15) << "LEVEL" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    while(Customcur!=nullptr)
    {
        cout << setiosflags(ios::left) << setw(15) << Customcur->name;
        cout << setiosflags(ios::left) << setw(15) << Customcur->count;
        cout << setiosflags(ios::left) << setw(15) << Customcur->level << endl;
        Customcur = Customcur->next;
    }
}

void AirLineList::BuyTicket() {
    string YourName,YourDestination,YourLevel;
    int YourCount;
    bool Bought = false;
    AirlineStruct *cur = head->next;
    cout << "Name: ";
    cin >> YourName;
    cout << "Count: ";
    cin >> YourCount;
    cout << "Destination: ";
    cin >> YourDestination;
    cout << "Level: ";
    cin >> YourLevel;
    while(cur!=NULL)
    {
        if(cur->destination == YourDestination)
        {
            if(cur->ticketCount >= YourCount)
            {
                cout << cur->airline << " ";
                cout << "success" << endl;
                cur->cl->push(YourName,YourCount,YourLevel);
                cur->ticketCount = cur->ticketCount - YourCount;
                Bought = true;
                break;
            }
            else
            {
                cur = cur->next;
                continue;
            }
        }
        cur = cur->next;
    }
    if(cur == NULL || !Bought) cout << "没冇空余的位置" << endl;
}

void AirLineList::ReturnTicket() {
    string YourName;
    int YourAirline;
    AirlineStruct *cur = head->next;
    cout << "Name: ";
    cin >> YourName;
    cout << "Airline: ";
    cin >> YourAirline;
    while(cur!=NULL)
    {
        if(cur->airline == YourAirline)
        {
            cur->ticketCount = cur->ticketCount + cur->cl->getCur(YourName)->count;
            cur->cl->Delete(YourName);
            cout << "return ticket success!" << endl;
            break;
        }
        cur = cur->next;
        if(cur==NULL)
        {
            cout << "姓名或航班不存在" << endl;
        }
    }
}

void AirLineList::BuyTicket2() {
    string YourName,YourLevel;
    int YourCount,YourAirline;
    bool Bought = false;
    AirlineStruct *cur = head->next;
    cout << "Name: ";
    cin >> YourName;
    cout << "Airline: ";
    cin >> YourAirline;
    cout << "Count: ";
    cin >> YourCount;
    cout << "Level: ";
    cin >> YourLevel;
    if(YourCount > 5)
    {
        cout << "一人最多只能买5张票" << endl;
        return;
    }
    while(cur!=NULL)
    {
        if(cur->airline == YourAirline)
        {
            if(cur->ticketCount >= YourCount && YourCount <= 5)
            {
                cout << cur->airline << " ";
                cout << "success" << endl;
                cur->cl->push(YourName,YourCount,YourLevel);
                cur->ticketCount = cur->ticketCount - YourCount;
                Bought = true;
                break;
            }
            else
            {
                cur = cur->next;
                continue;
            }
        }
        cur = cur->next;
    }
    if(cur == NULL || !Bought) cout << "没冇空余的位置" << endl;
}

void AirLineList::CustomerOwnTickets() {
    string YourName;
    AirlineStruct *cur = head->next;
    cout << "Name: ";
    cin >> YourName;
    cout << setiosflags(ios::left) << setw(15) << "AIRLINE";
    cout << setiosflags(ios::left) << setw(15) << "NAME";
    cout << setiosflags(ios::left) << setw(15) << "COUNT";
    cout << setiosflags(ios::left) << setw(15) << "LEVEL" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    while(cur!=NULL)
    {
        CustomStruct *curcl = cur->cl->getHead();
        while(curcl!=NULL)
        {
            if(curcl->name == YourName)
            {
                cout << setiosflags(ios::left) << setw(15) << cur->airline;
                cout << setiosflags(ios::left) << setw(15) << curcl->name;
                cout << setiosflags(ios::left) << setw(15) << curcl->count;
                cout << setiosflags(ios::left) << setw(15) << curcl->level << endl;
                break;
            }
            curcl = curcl->next;
        }
        cur = cur->next;
    }
}





