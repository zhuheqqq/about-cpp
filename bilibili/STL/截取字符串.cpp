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