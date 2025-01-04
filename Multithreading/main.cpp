#include <iostream>
#include <thread>
using namespace std;

void add(int a,int b)
{

    cout<<a+b<<endl;
}

int main()
{


//lambda function

auto f = [](int a,int b){cout<<a+b<<endl;};

//creating thread to execute this lambda function

std :: thread t1(f,10,20);

std :: thread t2(add,20,30);

//in this type i will insert lambda function inside thread only

std::thread t3( [](int a, int b){cout<<a+b<                                                                                                                                                                                                                                                                                                                                                                                                                                                              <endl;},40,50);
//please write this join otherwise if the thread is not complete its execution, still main function will get execute
//and we will not get the result of the thread
t1.join();
t2.join();
t3.join();




    return 0;
}
