#include <iostream>

using namespace std;

class rectangle
{
private:
    int length;
    int breadth;

public:
    int getlength() {return length;}
    int getbreadth() {return breadth;}
    void setlength(int l)  {length = l;}
    void setbreadth(int b) {breadth=b;}
    int area() {return (length*breadth);}

    rectangle()
    {
        int l=1;
        int b =1;

        length = 1;
        breadth = 1;
    }

};



class cuboid : public  rectangle
{
private:
    int heigth;

public:
        int setheigth(int h)  {heigth = h;}
    int volume()
    {
        cout<< getlength()*getbreadth()*heigth<<endl;
    }


};

int main()
{

    rectangle r1;
    cuboid c1,c2;

    r1.setlength(10);
    r1.setbreadth(20);

    c1.setheigth(10);
    cout<<r1 .area()<<endl;
    c2.setlength(2);
    c2.setbreadth(2);
    c2.setheigth(9);

    c1.volume();
    c2.volume();
    return 0;
}
