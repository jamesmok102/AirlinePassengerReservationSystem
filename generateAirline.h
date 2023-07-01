#ifndef GENERATEAIRLINE_H
#define GENERATEAIRLINE_H

#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "airlineStruct.h"
#include "AirLineList.h"
#include "customerList.h"
using namespace std;

class generateAirline{
public:
    generateAirline();
    void addAnyWeek();//读取星期1-7到vweek
    void generateData();//随机生成数据
    int randint(int n);//更加均匀生成整数下标
    void closeFile();//关闭所有文件
    void displayData();
    void DataInputIntoList(AirLineList &airlineList);//把文件读取的各个航班放到航班链表中
    void inputCount();//生成多少个航班
    void getAnyData();//读取随机生成航班表所需要的飞机号、目的地
    void addName();//读取随机生成乘客表所需要的乘客名
    void creatCustomerFile();//为每个航班生成乘客表
    void generateCustomerData();//在每个乘客表生成多位乘客的资料
    void CDataInputIntoList(AirLineList &airLineList);//把每个乘客表文件读取到乘客表链表中
    void DeleteAllCFile();//删除所有乘客表文件
    void SaveData(AirLineList &airLineList);//保存所有在链表中的变动
    ifstream Location;//地点
    ifstream Airplane;//飞机号
    ifstream Name;//customer姓名
    fstream Customer;//乘客表读取
    fstream Result;//输出文件
    vector<string> vlocation,vairplane,vweek,cname;//储存从文件读入的数据
    vector<string> vairlineNum;
    vector<int> vticket;
    string line;//读取行
    int count;//冇多少行数据
};


#endif //GENERATEAIRLINE_H
