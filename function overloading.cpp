#include<iostream>
using namespace std;

class Circle
{
public:
    void Area(int r)
    {
        cout<<"Area of circle is: "<<3.14*r*r;
    }
};

class Rectangle: public Circle
{
public:
    void Area(int l,int b)
    {
        cout<<"Area of rectangle is:"<<l*b;
    }
};

int main()
{
    int l=10,b=10,r=10;
    Rectangle re;
    re.Area(l,b);

}