//数组类的封装
#include "MyArray.hpp"

//默认构造函数
MyArray::MyArray()
{
    this->Capacity=100;
    this->Size=0;
    this->pAddress=new int[this->Capacity];
}

//有参构造函数
MyArray::MyArray(int capacity)
{
    this->Capacity=capacity;
    this->Size=0;
    this->pAddress=new int[this->Capacity];

}

//拷贝构造函数
MyArray::MyArray(const MyArray &arr)
{
    this->Capacity=arr.Capacity;
    this->Size=arr.Size;
   // this->pAddress=arr.pAddress;浅拷贝

    this->pAddress=new int[arr.Capacity];//深拷贝
    for(int i=0;i<Size;i++){
        this->pAddress[i]=arr.pAddress[i];
    }

}

//析构函数
MyArray::~MyArray()
{
    if(this->pAddress!=NULL)
    {
        delete [] this->pAddress;//数组
        this->pAddress=NULL;
    }

}

//根据位置获取数据
int MyArray::getData(int pos)
{
    return pAddress[pos];

}

//尾插法
void MyArray::pushBack(int val)
{
    this->pAddress[this->Size]=val;
    this->Size++;

}

//根据位置设置数据
void MyArray::setData(int pos,int val)
{
    this->pAddress[pos]=val;

}

//获取数组容量
int MyArray::getCapacity()
{
    return this->Capacity;

}

//获取数组大小
int MyArray::getSize()
{
    return this->Size;

}