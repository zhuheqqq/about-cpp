#include<iostream>
using namespace std;

//构造函数分类
//按参数分,无参构造函数(默认)和有参构造函数
//按类型分,普通构造函数和拷贝构造函数
class Person{
private:
    int age;


public:
    Person()
    {
        cout<<"Person的默认构造函数调用"<<endl;
    }

    Person(int a)
    {
        age=a;
        cout<<"Person的有参构造函数调用"<<endl;
    }

    //拷贝构造函数
    Person(const Person &p)
    {
        age=p.age;
    }

    int getAge()
    {
        return age;
    }



};

int main()
{
    Person p(18);
    Person p2(p);

    cout<<"p2的年龄为"<<p2.getAge()<<endl;

    // system("pause");

    return 0;
}