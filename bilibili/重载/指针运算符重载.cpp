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
    sp->showAge();
    (*sp).showAge();
}

int main()
{
    test01();
    
    return 0;
}