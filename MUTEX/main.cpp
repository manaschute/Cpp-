#include <iostream>
#include <thread>
#include <mutex>


using namespace std;
std::mutex m;
int x = 0;



void incr()
{
    m.lock();
    ++x;
    m.unlock();
}

int main()
{
    std::thread t1(incr); /*let us assume this thread goes first to the function and oit locks the critical region, Until
    it unlocks no other thread will or likely to lock that mutex. that means that region will only used by
    those thread which will lock the mutex */
    std::thread t2(incr);// this thread will block until the thread t1 will unlock the mutex.

    t1.join(); //this two we know will  wait until both threads execute their work
    t2.join();
// after that main thread or function will go and execute further lines
    cout<<x;


    return 0;
}
