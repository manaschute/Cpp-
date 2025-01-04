#include <iostream>
#include<thread>
#include<mutex>
std :: mutex m;
using namespace std;
int global = 0;


void print()
{

  for(int i =0;i<100000;++i)
  {
      if(m.try_lock()){

      ++global;
      m.unlock();
      }
  }


}

int main()
{

    std::thread t1(print);
    std:: thread t2(print);

    t1.join();

    t2.join();

    cout<<"threads are completed"<<"global = "<<global<<endl;
    return 0;
}
