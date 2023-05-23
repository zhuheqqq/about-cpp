#include<iostream>
#include<vector>
#include<algorithm>//for_each所在头文件
using namespace std;

void myPrint(int val)
{
    cout<<val<<endl;
}

void test01()
{
    vector<int>v;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    
    vector<int>::iterator itBegin=v.begin();
    vector<int>::iterator itEnd=v.end();
    
    //第一种遍历
    while(itBegin!=itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
    
    //第二种遍历
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
    
    //第三种遍历
    for_each(v.begin(),v.end(),myPrint);//myPrint是回调函数
}

//自定义数据类型
class Person
{
public:
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    string name;
    int age;
};

void test02()
{
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"姓名:"<<(*it).name<<"年龄:"<<(*it).age<<endl;
    }
}

//自定义数据类型指针
void test03()
{
    vector<Person*> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    
    for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
    {
        //*it---Person*
        cout<<"姓名:"<<(*it)->name<<"年龄:"<<(*it)->age<<endl;
    }
}

//容器嵌套容器
void test04()
{
    vector<vector<int>>v;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    
    for(int i=0;i<5;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+10);
        v3.push_back(i+100);
    }
    //将小容器放入大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    
    //遍历大容器
    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
    {
        //*it--vector<int>
        for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
        {
            cout<<*vit<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}