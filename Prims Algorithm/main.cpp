#include <iostream>
#define I INT_MAX
#define V 8
using namespace std;
int cost [V][V] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
int near[V];
int MST[2][V-2]={0};



int main()
{
    int sum =0;
    int u,v;
    int min=I;
    //select first minimum cost edge of the graph i.e the edge which have very low weight in the entire graph

    for(int row=1;row<V;++row)
    {
        for(int column=row;column<V;++column)
        {
            if(cost[row][column]<min)
            {
                min = cost[row][column];
                u = row;
                v = column;
            }
        }
    }

    MST[0][0]=u;
    MST[1][0]=v;

    // here we have stored the verteces of the that edge which contain low weight of the graph
    near[u]=near[v]=0;

    for(int i=1;i<V;++i)
    {
        if(near[i]!=0)
        {
            if(cost[i][u]<cost[i][v])
            {
                near[i] = u;
            }
            else {
                near[i]=v;
            }
        }
    }

    for(int i =1;i<V-1;++i)
    {
        int k=0;
        int min = I;
        for(int j =0;j<V;++j)
        {
           if(near[j]!=0)
           {
               if(cost[j][near[j]] < min)
               {
                 min = cost[j][near[j]];
                 k = j;
               }

               MST[0][i] = k;
               MST[1][i] = near[k];
               near[k]=0;
           }

        }

        for(int i =1;i<V;++i)
        {
            if(near[i]!=0)
            {
                if(cost[i][near[i]] > cost[i][k])
                {
                    near[i] = k;
                }
            }
        }


    }


    for(int i =0; i<V-2;++i)
    {
        int s = cost[MST[0][i]][MST[1][i]]+sum;
        sum = s;

    }
    cout<<sum;

    return 0;
}
