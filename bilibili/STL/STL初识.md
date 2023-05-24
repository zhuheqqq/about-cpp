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

## 评委打分案例

```c++
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

//构建一个类,包含选手的姓名和分数
class Player
{
public:
    string name;
    int score;//平均分

    //构造函数
    Player(string name,int score)
    {
        this->name=name;
        this->score=score;
    }
    ~Player()
    {

    }
};

void Createplayer(vector<Player>&v)
{
    string nameseed="ABCDE";
    for(int i=0;i<5;i++)
    {
        string name="选手";
        name+=nameseed[i];

        int score=0;
        //创建对象
        Player player(name,score);
        //将创建的对象放到容器中
        v.push_back(player);
    }
    
}

void Showplayer(vector<Player> v)
{
    for(vector<Player>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"姓名:"<<(*it).name<<" 平均分:"<<it->score<<endl;
    }
}

//设置分数并返回平均分
void setScore(vector<Player>&v)
{
    for(vector<Player>::iterator it=v.begin();it!=v.end();it++)
    {
        deque<int>d;//存放评委打分的容器
        for(int i=0;i<10;i++)
        {
            int score=rand()%41+60;//分数区间在60~100
            d.push_back(score);
        }

        cout<<it->name<<"打分情况:"<<endl;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            cout<<*dit<<" ";
        }
        cout<<endl;

        //排序
        sort(d.begin(),d.end());

        //去除最高分和最低分
        d.pop_back();//去除最高分
        d.pop_front();//去除最低分


        cout<<"去掉最高分和最低分后:"<<endl;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            cout<<*dit<<" ";
        }
        cout<<endl;

        //总分
        int sum=0;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            sum+=*dit;
        }

        //平均分
        //cout<<it->name<<"平均分为:"<<sum/d.size()<<endl;
        int avg=sum/d.size();

        it->score=avg;
    }
}

void Showscore(vector<Player>&v)
{
    for(vector<Player>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<it->name<<"选手平均分为:"<<it->score<<endl;
    }
}


int main()
{
    //创建五名选手
    vector<Player>v;
    Createplayer(v);

    Showplayer(v);

    //评委打分,并去掉最高分和最低分
    setScore(v);

    Showscore(v);
}
```

## 栈(stack)容器

栈是一种先进后出的数据结构,只有一个出口.stack容器允许新增元素,移除元素,取得栈顶元素,但是除了最顶端的元素外,没有任何方法可以存取stack的其他元素.换言之,stack不允许有遍历行为

推入栈push,推出栈pop

stack没有迭代器

## 队列(queue)容器

Queue是一种先进先出的数据结构,它有两个出口,queue容器允许从一端新增元素,从另一端移除元素

Queue同样不提供迭代器

## set/multiset容器

### set基本概念

set容器的特性是,所有元素都会根据元素的键值自动被排序,set的元素不像map那样可以同时拥有实值和键值,set的元素既是键值又是实值,set不允许两个元素拥有相同的键值

我们不可以通过set的迭代器改变set元素的值,因为set元素的值就是其键值,关系到set元素的排序规则,如果任意改变set元素值,会严重破坏set组织,换句话说,set的iterator是一种const_iterator

### multiset基本概念

multiset特性及用法和set完全相同,唯一的差别在于它允许键值重复.set和multiset的底层实现是红黑树,为平衡二叉树的一种

### pair创建



```c++
void test01()
{
    //第一种方式
    pair<string,int>p("Tom",10);
    cout<<"姓名:"<<p.first<<"年龄:"<<p.second<<endl;
    
    //第二种方式
    pair<string,int>p2=make_pair("Jerry",18);
    cout<<"姓名:"<<p2.first<<"年龄:"<<p2.second<<endl;
}
```

### set自定义排序规则

```cpp
#include<iostream>
#include<set>
using namespace std;

void printSet(set<int>&s)
{
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
}

class myCompareInt
{
public:
    void operator()(int v1,int v2)
    {
        return v1>v2;
    }
};

void test01()
{
    //set容器插入之后就不能在修改,所以只能在插入之前指定规则
    set<int,myCompareInt>s;//仿函数,不能用回调函数,因为括号里需要一个类型
    
    s.insert(10);
    s.insert(50);
    s.insert(30);
    s.insert(20);
    s.insert(40);
    
    //printSet(s);
     for(set<int,myCompareInt>::iterator it=s.begin();it!=s.end();it++)
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

### 对于自定义数据类型的排序

```cpp
#include<iostream>
#include<set>
using namespace std;

class Person
{
public:
    string name;
    int age;
    
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
};

class myComparePerson
{
public:
    bool operator()(const Person&p1,const Person&p2)
    {
        return p1.age<p2.age;
    }
}

void test02()
{
    //利用仿函数指定排序规则
    set<Person,myComparePerson>s;
    
    Person p1("aaa",10);
    Person p1("bbb",40);
    Person p1("ccc",20);
    Person p1("ddd",30);
    Person p1("eee",50);
    
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);
    
    for(set<Person,myComparePerson>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<"姓名:"<<(*it).name<<"年龄:"<<it->age<<endl;
    }
    
}
```

## map/multimap容器

Map的特性是,所有元素都会根据元素的键值对自动排序.Map所有元素都是pair,同时拥有实值和键值,pair的第一元素被视为键值,第二元素被视为实值,map不允许两个元素有相同的键值

和set一样,我们也不可以通过map的迭代器来修改map的值,也同样以红黑树为底层实现机制

map和multimap操作类似,唯一的区别是multimap键值可以重复

```cpp
#include<iostream>
#include<map>
using namespace std;

void test01()
{
    map<int,int>m;
    
   //第一种插入方式
    m.insert(pair<int,int>(1,10));
    
    //第二种插入方式
    m.insert(make_pair(2,20));
    
    //第三种
    m.insert(map<int,int>::value_type(3,30));
    
    //第四种
    m[4]=40;//如果利用第四种使用未指定的key,生成一个key为指定的值,value为0的数据插入到容器中
    
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<"key="<<it->first<<"value="it->second<<endl;
    }
}
```

