#include <iostream>
#define I INT_MAX
#define V 8
using namespace std;

int weigth_of_edge [V][V] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
int n =7;
int near[V]={I};
int MST[2][6]={0};
int k;


int main()
{
    //from the upper triangular part of the matrix just select the very low weighted edge of the graph
    //we are going for upper triangular only because it is a non directed graph.

    int min = I;
    int u;
    int v;
    for(int i =1;i<V; ++i)
    {
        for(int j =i; j<V; ++j)
        {
          if(weigth_of_edge[i][j] < min )
          {
              min = weigth_of_edge[i][j];
              u = i;
              v = j;
          }

        }
    }


    MST[0][0] = u;
    MST[1][0]= v;
    cout<< MST[0][0]<<endl<<MST[1][0]<<endl;

    near[u]=near[v]=0;

    //after finding out the first two vertice's now we have to find, about all of the other vertices which are nearer to u and v

    for(int i =1;i<=n;++i)
    {


            if(near[i]!=0 && weigth_of_edge[i][u] < weigth_of_edge[i][v])
            {
                 near[i] = u;
            }else{

            near[i] = v;

            }

    }

    for(int i=1; i<n-1; ++i)
    {
         min = I;
       for(int j =1;j<=n;++j)
       {

          if(near[j]!=0)
          {
              if(weigth_of_edge[j][near[j]]<min)
              {

                 k = j;
                 min = weigth_of_edge[j][near[j]];
              }
          }

       }
        MST[0][i] = k;
        MST[1][i] = near[k];
       near[k]=0;
       for(int t =1;t<V;++t)
       {

               if( near[t]!=0 && weigth_of_edge[t][k] < weigth_of_edge[t][near[t]] )
               {
                   near[t] = k;
               }

       }

    }
    cout << "Minimum Spanning Tree Edges:" << endl;
for (int i = 0; i < n-1; ++i) {
        int c= weigth_of_edge[MST[0][i]][MST[1][i]];
    cout << MST[0][i] << " - " << MST[1][i] << "  "<<c<<endl;
}



    return 0;
}
