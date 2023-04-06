#include<iostream>
#include<string>

using namespace std;
using std::string;

int main()
{
    string s;
    //punct_cnt类型和s.size()类型一样
    decltype(s.size()) punct_cnt=0;

    getline(cin,s);
    
    for(auto c:s){//对于s中每个字符
        if(ispunct(c)){//如果为标点符号
            ++punct_cnt;//将标点符号的计数值加1
        }
    }
    
    cout<<punct_cnt<<" punctuation characters in "<<s<<endl;

    return 0;
}