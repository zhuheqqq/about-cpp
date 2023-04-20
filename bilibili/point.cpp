//点与圆关系
#include<iostream>
using namespace std;

class Point{
    //点
private:
    int x;
    int y;

public:
    void setx(int x){
        this->x=x;
    }

    void sety(int y){
        this->y=y;
    }

    int getx(){
        return x;
    }

    int gety(){
        return y;
    }
};

class Circle{
private:
    int r;
    Point Center;//圆心

public:
    void setr(int r){
        this->r=r;
    }

    int getr()
    {
        return r;
    }
//设置圆心
    void setCenter(Point p){
        Center=p;
    }
//获取圆心
    Point getCenter()
    {
        return Center;
    }

};

//利用全局函数判断点与圆的关系
void isInCircle(Circle c,Point p){
    int distance=(c.getCenter().getx()-p.getx())*(c.getCenter().getx()-p.getx())+(c.getCenter().gety()-p.gety())*(c.getCenter().gety()-p.gety());
    int Rdistance=c.getr()*c.getr();

    if(distance==Rdistance){
        cout<<"点在圆上"<<endl;
    }else if(distance>=Rdistance){
        cout<<"点在圆外"<<endl;
    }else if(distance<=Rdistance){
        cout<<"点在圆内"<<endl;
    }

    // cout<<distance<<endl;
    // cout<<Rdistance<<endl;
}

void Judge()
{
    Point p;
    p.setx(10);
    p.sety(10);

    Circle c;
    Point pCenter;
    pCenter.setx(10);
    pCenter.sety(0);
    c.setCenter(pCenter);
    c.setr(10);

    isInCircle(c,p);
}

int main()
{
    Judge();

    system("pause");

    return 0;

}