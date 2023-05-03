//数组类的封装
#pragma once
#include "MyArray.cpp"

void test01()
{
    MyArray arr;
    for(int i=0;i<10;i++){
        arr.pushBack(i);
    }

    for(int i=0;i<arr.getSize();i++){
        cout<<arr.getData(i)<<endl;
    }
}

int main()
{
    test01();

    return 0;
}