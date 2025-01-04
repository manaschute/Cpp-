#include <iostream>
#include <thread>

using namespace std;


void print(int count)
{

    while(--count >0)
    {
        cout<<"printing "<<count<<"th"<<" time"<<endl;
    }
     std::this_thread :: sleep_for(chrono :: seconds(5));
}


int main()
{
    cout<<"Main started"<<endl;

    std::thread t1(print,10);

    t1.detach();// once we have detach the thread main function will start executing further
//in join() main function has to wait for to complete the thread t1 to complete, after that only
//main function will go further, but in detach that thread is detached main function started its execution further
//parallely that t1 thread is executing. But as main function ended this thread t1 exection will be terminated.


if(t1.joinable()) // this condition check if this thread can be join or not
{
    t1.detach(); // or t1.join(); if we are using join
}
    cout<<"main function ended"<<endl;

    return 0;
}
