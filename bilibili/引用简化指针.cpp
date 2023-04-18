//利用引用可以简化指针
//可以直接用同级指针的引用给同级指针分配空间
#include<iostream>
using namespace std;

struct Person
{
    int age;
};

void allocateSpace(Person **p)
{
    *p=(Person *)malloc(sizeof(Person));
    (*p)->age=10;
}

void test01()
{
    Person *p=NULL;
    allocateSpace(&p);

    cout<<"p.age="<<p->age<<endl;
}

void allocateSpace2(Person *&pp)
{
    pp=(Person *)malloc(sizeof(Person));
    pp->age=20;
}

void test02()
{
    Person *p=NULL;
    allocateSpace2(p);
    cout<<"p.age"<<p->age<<endl;
}

int main()
{
    test01();
    test02();

}