# 智能指针管理new出来的对象的释放操作

在c++中,我们可能会new出来非常多的对象,这些对象开辟在堆区需要手动用delete释放内存,就像下面这段代码

```c++
#include<iostream>
using namespace std;

class Person
{
public:
    int Age;
    Person(int age)//构造函数
    {
        cout<<"Person的有参函数调用"<<endl;
        this->Age=age;
    }
    void showAge()
    {
        cout<<"年龄为:"<<this->Age<<endl;
    }
    ~Person()//析构函数
    {
        cout<<"Person的析构函数调用"<<endl;
    }
};

void test01()
{
    Person *p=new Person(18);
    p->showAge();
    (*p).showAge();
    delete p;//当在写很复杂很庞大的代码时,我们很容易忘记释放堆区开辟出来的内存,那我们可不可以使用一个函数或者是其他的方法去保证调用了new之后一定会调用delete(相当于将new和delete做一个捆绑)
}

int main()
{
    test01();
    
    return 0;
}
```

思路有了,解决方案是

> 保证调用了new之后一定会调用delete(相当于将new和delete做一个捆绑)

在c++中,程序员通常会利用一种"智能指针"或者叫指针运算符重载来托管new出来待释放的对象

```c++
#include<iostream>
using namespace std;

class Person
{
public:
    int Age;
    Person(int age)//构造函数
    {
        cout<<"Person的有参函数调用"<<endl;
        this->Age=age;
    }
    void showAge()
    {
        cout<<"年龄为:"<<this->Age<<endl;
    }
    ~Person()//析构函数
    {
        cout<<"Person的析构函数调用"<<endl;
    }
};

class SmartPoint
{
public:
    SmartPoint(Person *person)
    {
        this->person=person;
    }
    
    ~SmartPoint()
    {
        if(this->person)
        {
            delete this->person;
            this->person=NULL;
        }
    }
private:
    Person *person;
};

void test01()
{
   /* Person *p=new(person(18));
    p->showAge();
    (*p).showAge();
    delete p;*/
    
    //利用智能指针管理new出来的对象的释放操作
    SmartPoint sp(new Person(18));
}

int main()
{
    test01();
    
    return 0;
}
```

但是!这只体现出智能,并没有体现出智能指针,指针可以箭头可以解引用,这时候就需要对指针运算符进行重载!

```c++
//利用智能指针管理ne出来的对象的释放操作
#include<iostream>
using namespace std;

class Person
{
public:
    int Age;
    Person(int age)//构造函数
    {
        cout<<"Person的有参函数调用"<<endl;
        this->Age=age;
    }
    void showAge()
    {
        cout<<"年龄为:"<<this->Age<<endl;
    }
    ~Person()//析构函数
    {
        cout<<"Person的析构函数调用"<<endl;
    }
};

class SmartPoint
{
public:
    SmartPoint(Person *person)
    {
        this->person=person;
    }
    
    ~SmartPoint()//析构
    {
        if(this->person)
        {
            delete this->person;//这里会调用Person的析构函数
            this->person=NULL;
        }
    }

    //重载->
    Person * operator->()
    {
        return this->person;
    }

    //重载*解引用
    Person& operator*()//返回引用本身
    {
        return *person;
    }

private:
    Person *person;
};



void test01()
{
   /* Person *p=new(person(18));
    p->showAge();
    (*p).showAge();
    delete p;*/
    
    //利用智能指针管理new出来的对象的释放操作
    SmartPoint sp(new Person(18));
    sp->showAge();//本质为sp->->showAge(),编译器替我们简化为sp->showAge()
    (*sp).showAge();
}

int main()
{
    test01();
    
    return 0;
}
```

