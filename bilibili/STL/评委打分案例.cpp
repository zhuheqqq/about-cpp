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