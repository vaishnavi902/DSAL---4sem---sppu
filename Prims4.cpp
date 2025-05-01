#include<iostream>
using namespace std;
class Graph{
    public:
    int graph[10][10];
    int n;
    
    Graph()
    {
        for(int i = 0 ; i < n ;i++)
        {
            for(int j = 0 ; j < n ;j++)
            {
                graph[i][j] = 0;
            }
        }
    }
    
    void create()
    {
        int v1,v2,cost,ans;
        cout<<"enter the number of vertices:"<<endl;
        cin>>n;
        do{
            cout<<"enter the edge:"<<endl;
            cin>>v1>>v2;
            cout<<"enter the cost of edge:"<<endl;
            cin>>cost;
            graph[v1][v2] = cost;
            graph[v2][v1] = cost;
            cout<<"one more edge?"<<endl;
            cin>>ans;
        }while(ans == 1);
    }
    
    void display()
    {
        cout<<"adjacency matrix is:"<<endl;
        for(int i = 0 ; i < n ;i++)
        {
            for(int j = 0 ; j < n ;j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void prims()
    {
       int selected[10] = {0};
        int no = 0;
        int totalcost = 0;
        selected[0] = 1;
        
       while(no < n -1)
       {
           int x,y = 0;
           int min = 999;
           
           for(int i=0; i < n;i++)
           {
                if(selected[i])
                {
                    for(int j = 0 ;j<n ;j ++)
                    {
                        if(!selected[j] && graph[i][j])
                        {
                            if(min > graph[i][j])
                            {
                                min = graph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
           }
           cout<<x<<"-"<<y<<graph[x][y];
           selected[y] = 1;
           totalcost+= graph[x][y];
           no++;
       }
      cout<<"minimum cost is:"<<totalcost;  
    }
};

int main(){
    Graph g;
    g.create();
    g.display();
    g.prims();
    return 0 ; 
}