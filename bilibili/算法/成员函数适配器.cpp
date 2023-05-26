#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
using namespace std;

class Person 
{
public:
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    
    //法二
    void showPerson()
    {
         cout<<"姓名:"<<this->name<<"年龄:"<<this->age<<endl;
    }
    
    string name;
    int age;
};

//法一
/*void MyPrint(Person&p)
{
    cout<<"姓名:"<<p.name<<"年龄:"<<p.age<<endl;
}*/

void test01()
{
    vector<Person>v;
    
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    
    //for_each(v.begin(),v.end(),MyPrint);//回调函数只要把函数名放进去就可以
    for_each(v.begin(),v.end(),mem_fun_ref(&Person::showPerson));
}

int main()
{
    test01();
    return 0;
}