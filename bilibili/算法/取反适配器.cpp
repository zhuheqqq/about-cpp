#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

class GreaterThanFive:public unary_function<int,bool>//一元继承
{
public:
    bool operator()(int val)const
    {
        return val>5;
    }
};

void test02()
{
    //一元取反
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    cout<<"请输入起始值:"<<endl;
    int num;
    cin>>num;
   
    //vector<int>::iterator pos=find_if(v.begin(),v.end(),not1(GreaterThanFive());
    vector<int>::iterator pos=find_if(v.begin(),v.end(),not1(bind2nd(greater<int>(),num)));
    if(pos!=v.end())
    {
        cout<<"找到了小于"<<num<<"的值为:"<<*pos<<endl;
    }else{
        cout<<"未找到"<<endl;
    }                                  
}
                                      
//1.利用not1进行取反
//2.继承unary_function
//3.加const
                                      
int main()
{
    test02();
    return 0;
}