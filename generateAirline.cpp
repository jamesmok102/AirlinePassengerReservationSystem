#include "generateAirline.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <assert.h>
#include <cstdlib>//乱数相关函数
#include <ctime>//时间相关函数
#include <direct.h>
#include <windows.h>
#include <io.h>
#include "airlineStruct.h"
using namespace std;

generateAirline::generateAirline() {
    /*Location.open("location.txt",ios::in);
    Airplane.open("airplane.txt",ios::in);
    Result.open("result.txt",ios::out|ios::trunc);
    while (getline(Location,line))//逐行读取
        vlocation.push_back(line);//把数据放进vector
    while (getline(Airplane,line))
        vairplane.push_back(line);*/
}

void generateAirline::addAnyWeek() {//一个星期只有七天，就直接push进去，无需用文件写入
    vweek.emplace_back("Mon");
    vweek.emplace_back("Tue");
    vweek.emplace_back("Wed");
    vweek.emplace_back("Thu");
    vweek.emplace_back("Fri");
    vweek.emplace_back("Sat");
    vweek.emplace_back("Sun");
}

void generateAirline::generateData() {
    srand(time(NULL));//随机数种子
    int locationSize = vlocation.size();//取得vector的size
    int airplaneSize = vairplane.size();

    for(int i=0; i<count; i++) {
        int locationX = rand() % (locationSize);//随机生成地点vector的下标
        int airlineX = rand() % (9999);//航班number从1-9999随机生成
        int airplaneX = rand() % (airplaneSize);
        int weekX = rand() % 7;
        int ticketX = randint(200+1);//随机生成票数1-200
        //把随机生成的各个航班属性写入航班表文件
        Result << airlineX << " ";
        Result << vairplane[airplaneX] << " ";
        Result << vlocation[locationX] << " ";
        Result << vweek[weekX] << " ";
        Result << ticketX << endl;
    }
}

int generateAirline::randint(int n) {//为了生成的随机数分布更均匀，重新写了一个生成随机数的算法
    if ((n - 1) == RAND_MAX) {
        return rand();
    } else {
        //計算可以被整除的長度
        long end = RAND_MAX / n;
        assert (end > 0L);
        end *= n;
        //將尾端會造成偏差的幾個亂數去除，若產生的亂數超過 limit，則將其捨去
        int r;
        while ((r = rand()) >= end);

        return r % n;
    }
}

void generateAirline::closeFile() {
    Location.close();
    Airplane.close();
    Result.close();//对文件进行写入后需关闭文件，再次打开时文件指头就会从文件最头的位置开始读入数据
}

void generateAirline::displayData() {//显示航班表
    Result.open("result.txt",ios::in);
    string airlineO, airplaneO, locationO, week0, ticket0;
    cout << setiosflags(ios::left) << setw(15) << "AIRLINE";
    cout << setiosflags(ios::left) << setw(15) << "FLIGHT";
    cout << setiosflags(ios::left) << setw(20) << "DESTINATION";
    cout << setiosflags(ios::left) << setw(15) << "DAY";
    cout << setiosflags(ios::left) << setw(15) << "TICKET_COUNT" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    while(getline(Result,line))
    {
        stringstream word(line);
        word >> airlineO;
        word >> airplaneO;
        word >> locationO;
        word >> week0;
        word >> ticket0;
        cout << setiosflags(ios::left) << setw(15) << airlineO;
        cout << setiosflags(ios::left) << setw(15) << airplaneO;
        cout << setiosflags(ios::left) << setw(20) << locationO;
        cout << setiosflags(ios::left) << setw(15) << week0;
        cout << setiosflags(ios::left) << setw(15) << ticket0 << endl;
    }
}

void generateAirline::DataInputIntoList(AirLineList &airlineList) {
    vairlineNum.clear();//清空上次随机生成的航班
    vticket.clear();//清空上次随机生成的每位乘客的票数
    Result.open("result.txt",ios::in);
    string airlineO, airplaneO, locationO, week0, ticket0;//临时保存某航班的各项属性
    int airlineInt, ticketInt;//从文件读取是string型，要转成int型
    while(getline(Result,line))
    {
        stringstream word(line);
        word >> airlineO;
        word >> airplaneO;
        word >> locationO;
        word >> week0;
        word >> ticket0;
        vairlineNum.push_back(airlineO);//若为本次生成就放在临时保存所有航班number的vector中
        airlineInt = stoi(airlineO);//转型
        ticketInt = stoi(ticket0);
        vticket.push_back(ticketInt);//若为本次生成就放在临时保存所有航班票数的vector中
        airlineList.push(airlineInt, airplaneO, locationO, week0, ticketInt);//从文件读取的航班表放在链表中
    }
    Result.close();
}

void generateAirline::inputCount() {
    int n;
    cout << "Random Count: ";//生成多少个航班
    cin >> n;
    count = n;
}

void generateAirline::getAnyData() {
    Location.open("location.txt",ios::in);//读取所有的地点
    Airplane.open("airplane.txt",ios::in);//读取所有的航班
    Result.open("result.txt",ios::out|ios::trunc);//读取航班表
    while (getline(Location,line))//逐行读取
        vlocation.push_back(line);//把地点数据放进vector
    while (getline(Airplane,line))
        vairplane.push_back(line);//把所有航班数据放进vector
}

void generateAirline::addName() {
    Name.open("name.txt",ios::in);//读取所有名字
    while (getline(Name,line))
        cname.push_back(line);//把所有名字放进vector
}

void generateAirline::creatCustomerFile() {
    for(int i=0; i<count; i++)
    {
        string path = "customer\\"+vairlineNum[i]+".txt";//为每个航班增加乘客表文件
        cout << path << " " << vticket[i] << endl;
        Customer.open(path,ios::out);//创建
        Customer.close();//关闭
    }
}

void generateAirline::generateCustomerData() {
    srand(time(NULL));//随机数种子
    int cnameSize = cname.size();//有多少乘客名字
    for(int i=0; i<count; i++) {
        int t = vticket[i];//这个航班己买多少票
        string path = "customer\\"+vairlineNum[i]+".txt";
        Customer.open(path,ios::out);//打开乘客表
        for(int j=0; j<200-t;)
        {
            int nameX = rand() % (cnameSize);//随机生成数字
            int ccountX;//随机生成票数
            if(j >= 200-t-5)//一个航班两百张票，如果航班只剩下小于等于五张，就把剩下的都给下一位乘客
            {
                ccountX = 200-t-j;
            }else
            {
                ccountX = 1+rand() % 5;//从1-5选一个数字作为一个乘客的票数
            }
            int levelX = 1+rand() % 3;//从1-3等级中选一个
            Customer << cname[nameX] << " ";//把刚才随机生成的数据放到某航班的乘客表中
            Customer << ccountX << " ";
            Customer << levelX << endl;
            j = j + ccountX;//j为己售票数，ccountx为随机生成票数，加在一起，直到j=200时退出循环
        }
        Customer.close();
    }
}

void generateAirline::CDataInputIntoList(AirLineList &airLineList) {
    AirlineStruct *cur = airLineList.getHead();//取得航班表的第一个node
    int i = 0;
    while (cur != NULL)//循环整个航班表
    {
        string name0,count0,level0;//临时保存乘客名字、票数和等级
        int countInt;//在文件读取时是string型，要转成int型
        string path = "customer\\"+vairlineNum[i]+".txt";//打开某航班表的文件
        Customer.open(path,ios::in);
        while(getline(Customer,line))
        {
            stringstream word(line);//string流，每隔一个空格为一变量
            word >> name0;
            word >> count0;
            word >> level0;
            countInt = stoi(count0);//string转int型
            cur->cl->push(name0,countInt,level0);//把数据放到某航空表的乘客表中
        }
        Customer.close();
        cur = cur->next;
        i++;
    }
}

void generateAirline::DeleteAllCFile() {
    for(int i = 0; i < vairlineNum.size(); i++)//逐文件删除
    {
        string path = "customer\\"+vairlineNum[i]+".txt";
        const char* p = path.data();//string转char*
        remove(p);//删除文件，只支持char*，要做类型转换
    }
}

void generateAirline::SaveData(AirLineList &airLineList) {//保存所有航班表和乘客表
    //写入所有航班表的数据
    Result.open("result.txt",ios::out|ios::trunc);
    AirlineStruct *cur = airLineList.getHead();
    while(cur != NULL)
    {
        Result << cur->airline << " ";
        Result << cur->flight << " ";
        Result << cur->destination << " ";
        Result << cur->day << " ";
        Result << cur->ticketCount << " ";
        Result << endl;
        cur = cur->next;
    }
    Result.close();
    //写入所有乘客表的数据
    cur = airLineList.getHead();
    while (cur != NULL)
    {
        string path = "customer\\"+to_string(cur->airline)+".txt";
        Customer.open(path,ios::out|ios::trunc);
        CustomStruct *curcl = cur->cl->getHead();//取得每个航班表中的首个乘客node
        while(curcl != NULL)
        {
            Customer << curcl->name << " ";
            Customer << curcl->count << " ";
            Customer << curcl->level << " ";
            Customer << endl;
            curcl = curcl->next;
        }
        Customer.close();
        cur = cur->next;//把一个航班表的所有乘客数据读取完后接到下一个航班
    }

}








