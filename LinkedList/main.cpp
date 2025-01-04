#include <iostream>

using namespace std;


class node
{   public:
    int data;
    node *next;

};

void create(int A[],int size)
{
    node *first;

    first = new node;
    node *last;
    first->data = A[0];
    first->next = nullptr;
    last=first;
    node *temp;

    for (int i =1;i<size;++i)
    {
        temp= new node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = last->next;
    }
    node *p =first;
    while (p!=nullptr)
    {
        cout<<p->data<<endl;
        p=p->next;
    }


}


int main()
{
    int A[]={10,20,30,40,50};

    int size = (sizeof(A)/sizeof(A[0]));
    node *first;
    create(A,size);


    return 0;
}
