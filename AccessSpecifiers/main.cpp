#include <iostream>

using namespace std;



class base
{

private:
    int a;

protected:
    int b;

public:
    void values(int x, int y)
    {
        a=x;
        b=y;

        cout<<a<<" "<<b<<endl;
    }

};



int main()
{
  base b1;

  b1.values(10,20);
    return 0;
}
