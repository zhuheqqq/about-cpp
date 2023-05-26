#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

class MyPrint:public binary_function<int,int,void>
{
public:
    void operator()(int val,int start)const
    {
        cout<<val+start<<endl;
    }
};

void test01()
{
    vector<int> v;
    
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    cout<<"请输入起始值:"<<endl;
    int num;
    cin>>num;
    
    for_each(v.begin(),v.end(),bind2nd(MyPrint(),num));
}

//1.利用bind2nd进行绑定
//2.继承public binary_function<参数1类型,参数2类型,返回值类型>
//3.加const

int main()
{
    test01();
    return 0;
}