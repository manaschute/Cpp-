#include <iostream>

using namespace std;


void DFS(int G[7][7], int visit, int n)
{

    static int visited[7]= {0};
    if(visited[visit] == 0){
    cout<<visit<<endl;
    visited[visit]=1;
        for(int j =1;j<n;++j)
        {
            if(G[visit][j] == 1 && visited[j] == 0)
            {
                DFS(G,j,n);
            }
        }

    }


}






int main()
{

int G[7][7]={      {0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},
                   {0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0},
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0}};

                   DFS(G,5,7);
    return 0;
}
