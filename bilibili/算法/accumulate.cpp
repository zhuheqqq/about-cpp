#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>//accumulate所在头文件
using namespace std;

void test01()
{
    vector<int>v;
    for(int i=0;i<=100;i++)
    {
        v.push_back(i);
    }
    
    int num=accumulate(v.begin(),v.end(),0);
    
    cout<<"num="<<num<<endl;
}

int main()
{
    test01();
    return 0;
}