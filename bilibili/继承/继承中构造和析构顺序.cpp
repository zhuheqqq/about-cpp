#include<iostream>
using namespace std;

class Other
{
public:
    Other()
    {
        cout<<"Other的构造函数调用"<<endl;
    }

    ~Other()
    {
        cout<<"Other的析构函数调用"<<endl;
    }

};

class Base
{
public:
    int a;

    Base()
    {
        cout<<"Base的构造函数调用"<<endl;
    }

    ~Base()
    {
        cout<<"Base的析构函数调用"<<endl;
    }

   
};

class Son:public Base
{
public:
    Son()
    {
        cout<<"Son的构造函数调用"<<endl;
    }

    ~Son()
    {
        cout<<"Son的析构函数调用"<<endl;
    } 
    Other other;

};

void test01()
{
    Son s;//先调用父类构造,在调用其他成员构造,再调用自身构造,析构顺序与构造相反
}

int main()
{
    test01();

    return 0;
}