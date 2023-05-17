# C++继承

## 继承基本语法

```c++
class 子类:继承方式(public/private/protect) 父类
   	子类又被称为派生类
    父类又被称为基类
```

## 继承优势

继承可以减少重复的代码,提高代码的复用性

## 继承方式

公共继承:

​				父类中的公共权限子类中仍为公共权限

​				父类中保护权限子类中仍为保护权限

​				父类中私有的部分子类中访问不到

保护继承:

​				父类中的公共权限子类中变为保护权限

​				父类中保护权限子类中仍为保护权限

​				父类中私有的部分子类中访问不到

私有继承:

​				父类中的公共权限子类中变为私有权限

​				父类中保护权限子类中仍为私有权限

​				父类中私有的部分子类中访问不到

## 继承注意事项

父类中私有属性子类中访问不到,由编译器隐藏了,但是子类会继承下去

## 继承中构造和析构顺序

> 先调用父类构造,在调用其他成员构造,再调用自身构造,析构顺序与构造相反

```c++
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
    Son s;
}

int main()
{
    test01();

    return 0;
}
```

## 无法继承

> 父类中构造函数,析构函数,拷贝构造函数以及operator=等子类无法继承-

## 解决菱形继承问题

在继承前面加上virtual关键字,发生虚继承后,类中会继承一个vbptr指针即虚基类指针,指向一个虚基类表vbtable,虚基类表中记录了偏移量,通过偏移量可以找到唯一一个成员变量