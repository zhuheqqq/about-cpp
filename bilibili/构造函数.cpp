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
        this->age=0;
        cout<<"Person的默认构造函数调用,p1的年龄为"<<age<<endl;
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

    //析构函数
    ~Person()//释放开在堆区的变量
    {

    }



};

int main()
{
    Person p;//不要用括号法调用无参构造函数,会被编译器认为是函数的声明
    Person p1(18);
    Person p2(p);//拷贝构造
    Person p3=Person(10);//显示法
    Person(10);//匿名对象执行完立即释放

    //不要用拷贝构造函数初始化匿名对象

    cout<<"p2的年龄为"<<p2.getAge()<<endl;
    cout<<"p3的年龄为"<<p3.getAge()<<endl;

    // system("pause");

    return 0;
}