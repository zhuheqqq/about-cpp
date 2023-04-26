#include<iostream>
using namespace std;

class MyArray
{

private:
    int Capacity;//数组容量
    int Size;//数组大小
    int *pAddress;//真是在堆区开辟数组的指针

public:
    MyArray();//默认构造函数

    MyArray(int Capacity);//有参构造函数

    MyArray(const MyArray &arr);//拷贝构造函数

    ~MyArray();//析构函数

    //根据位置获取数据
    int getData(int pos);

    //尾插法
    void pushBack(int val);

    //根据位置设置数据
    void setData(int pos,int val);

    int getCapacity();//获取数组容量

    int getSize();//获取数组大小


};