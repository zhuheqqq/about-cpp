#include<iostream>
using namespace std;
int main()
{
    string s("Hello World!!!");
    for(auto &c : s)
        c = toupper(c);
    cout << s << endl;
}

int main()
{
    string s("some string");
    if(s.begin()!=s.end()){
        auto it=s.begin();
        *it=toupper(*it);
    }
}