# STL初识

[TOC]



## STL基本概念

STL广义上分为容器,(container)算法(algorithm),迭代器(iterator),容器和算法之间通过迭代器进行无缝衔接

## STL六大组件

STL提供了六大组件,分别是:

- 容器:各种数据结构,如vector,list,deque,set,map等,用来存放数据,从实现角度来看,STL容器就是一种class template(类模板)
- 算法:各种常用的算法,如sort,find,copy,for_each,从实现的角度来看,STL算法是一种function template
- 迭代器:扮演了容器与算法之间的胶合剂,共有五种类型,从实现角度来看,迭代器是一种将operator*,operator->,operator++,operator--等指针相关操作予以重载的class template.原生指针也是一种迭代器
- 仿函数(重载小括号):行为类似函数,可作为算法的某种策略.从实现角度来看,仿函数是一种重载了operator()的class或class template.
- 适配器(配接器)一种用来修饰容器或者仿函数或迭代器接口的东西
- 空间配置器:负责空间的配置与管理,配置器就是一个实现了动态空间配置,空间管理,空间释放的class tempalte

## vector容器

```c++
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
    test01();
    test02();
    test03();
    test04();
    return 0;
}
```

## string容器

定义在头文件<string>

string和c风格字符串对比:

- char*是一个指针,string是一个类,string封装了char*星,是一个char*型的容器
- string中封装了find查找,copy删除,delete删除,replace替换,insert插入
- string不用考虑内存释放和越界的问题

```cpp
#include<iostream>
#include<string>
using namespace std;

void test01()
{
    string str="hello world";
   // for(int i=0;i<str.size();i++)
    //{
        //cout<<str[i]<<endl;
        //or cout<<str.at(i)<<endl;
        //[]和at区别,[]访问越界直接挂掉,at访问越界,抛出out_of_range异常
    //}
    
    try
    {
        cout<<str.at(100)<<endl;
    }
    catch(out_of_range &e)
    {
        cout<<e.what()<<endl;
    }
}

int main()
{
    test01();
    return 0;
}
```

### 解析字符串

```c++
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void test01()
{
    string str="www.itcast.com.cn";
    vector<string> v;//将www itcast com cn截取到vector容器中
    int start=0;
    int pos=-1;
    while(1)
    {
        pos=str.find(".",start);
        
        if(pos==-1)
        {
            //将cn截取出来
            string temStr=str.substr(start,str.size()-start);
            v.push_back(temStr);
            break;
        }
        string temStr=str.substr(start,pos-start);
        v.push_back(temStr);
        start=pos+1;
    }
    
    for(vector<string>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
}

int main()
{
    test01();
    return 0;
}
```

## deque容器

vector容器是单向开口的连续内存空间,deque是一种双向开口的连续线性空间.所谓双向开口,意思是可以在头尾两端分别做元素的插入和删除操作,当然,vector容器也可以在头尾两端插入元素,但是在其头部操作效率奇差,无法被接受

deque容器和vector容器最大的差异,一在于deque允许使用常数项时间对头端进行元素的插入和删除操作.二在于deque没有容量的概念,因为它是动态的以分段连续空间,随时可以增加一段新的空间并连接起来