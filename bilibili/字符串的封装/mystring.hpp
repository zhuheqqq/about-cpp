#pragma once//防止头文件重复包含
#include<iostream>
using namespace std;
#include<string.h>

class MyString
{
    //友元
    friend ostream& operator<<(ostream & cout,MyString & str);
    friend istream& operator>>(istream & cin,MyString & str);
public:
    //有参构造函数
    MyString(char *str);

    //拷贝构造
    MyString(const MyString & str);

    //析构
    ~MyString();

private:
    char * pstring;//维护在堆区开辟的字符数组

    int Size;//字符串长度
};