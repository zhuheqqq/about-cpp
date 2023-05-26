#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

void MyPrint(int val,int start)
{
    cout<<val+start<<endl;
}
//函数适配器
void test01()
{
    
    vector<int> v;
    
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    // cout<<"请输入起始值:"<<endl;
    // int num;
    // cin>>num;
    //将函数指针适配成函数对象ptr_fun
    for_each(v.begin(),v.end(),bind2nd(ptr_fun(MyPrint),1000));
}



int main()
{
    test01();
    return 0;
}