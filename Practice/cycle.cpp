#include <iostream>
#include <queue>
using namespace std;

bool graph[1000][1000];

queue<int> q;

int count = 0;
int count2 = 0;

void delit(bool **gr , int *back , int n)                               //deletes node with max cross edges
{
   int max = 0;
   int mind = 0;
   for(int i=0 ; i<n ; i++)
   {
      if(back[i] > max)
      {
         max = back[i];
         mind = i;
      }
   }

   //time to severe mind

   cout<<"deleting node : "<<mind<<endl;

   for(int i=0 ; i<n ; i++)
   {
      gr[mind][i] = 0;
      gr[i][mind] = 0;
   }
}

bool eqcheck(bool **gr , bool **tree , int n)                           //return true if graph == tree
{
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
      {
         if(gr[i][j] != tree[i][j])
            return false;
      }
   }

   return true;
}

void bfs(bool **gr , bool **tree , int *par , bool *vis , int node , int n )     //start
{
   if(vis[node]==1)
   {
      return;
   }
   vis[node] = 1;

   if(par[node] != -1)
   {
      tree[par[node]][node] = 1;
      tree[node][par[node]] = 1;
   }

   for(int i=0 ; i<n ; i++)
   {
      if(gr[node][i] == 1)
      {
         q.push(i);
         if(par[i] == -1 && vis[i] == 0)
            par[i] = node;
     }
   }
}

bool** bcheck(bool **gr , int n)                         //does bfs on gr of n nodes
{
   bool *vis = new bool[n];                             //visited array
   int *par = new int[n];
   bool **tree = new bool*[n];

   for(int i = 0 ; i<n ; i++)                         //declare graph
      tree[i] = new bool[n];

   for(int i=0 ; i<n ; i++)                           //init. vis
   {
      vis[i] = 0;
      par[i] = -1;
   }

   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         tree[i][j] = 0;
   }

   bfs(gr , tree , par , vis , 0 , n );                                    //first bfs run
   //vis[0] = 1;

   while(!q.empty())
   {
      bfs(gr , tree , par , vis , q.front() , n );
      q.pop();
   }

   return tree;
}

void backedge(bool **gr , bool **tree , int *back , int n)
{
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
      {
         if(gr[i][j] == 1 && tree[i][j] == 0)
         {
            back[i]++;
         }
      }
   }
   cout<<"\nback edge number : ";
   for(int i=0 ; i<n ; i++)
      cout<<back[i]<<" , ";
   cout<<"\n\n";
}

void init(bool **gr , int *back , int n)
{
   for(int i = 0 ; i<n ; i++)
   {
      for(int j = 0 ; j<n ; j++)
          gr[i][j] = 0;
      back[i] = 0;
   }
}

void clear(int *back , int n)
{
   for(int i=0 ; i<n ; i++)
      back[i] = 0;
}

void print(bool **gr , int n)
{
   cout<"\n\n graph\n";
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         cout<<gr[i][j]<<" ";
      cout<<endl;
   }
   cout<<endl;
}

void finprint(bool **gr , int n)
{
   bool *vis = new bool[n];
   for(int i=0 ; i<n ; i++)
      vis[i] = 0;

   cout<<"removed vertices : ";
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
      {
         if(gr[i][j] == 1)
         {
            if(vis[i] == 0)
            {
               vis[i] = 1;
               //cout<<" "<<(i+1)<<" ";
            }
            if(vis[j] == 0)
            {
               vis[j] = 1;
               //cout<<" "<<(j+1)<<" ";
            }
         }
      }
   }

   //print unvisited

   for(int i=0 ; i<n ; i++)
   {
      if(vis[i] == 0)
         cout<<" "<<(i+1)<<" ";
   }
   cout<<endl<<endl;
}
   
void inputga(bool **gr , int n)
{
   int m=0,a=0,b=0;
   cout<<"enter no. of edges : ";
   cin>>m;
   cout<<"enter u and v for each of the "<<m<<" edges (u,v) in form u <space> v [please note that edges are numbered 1,2,3,....,n ] : \n";
   for(int i=0 ; i<m ; i++)
   {
      cin>>a>>b;
      gr[a-1][b-1] = 1;
      gr[b-1][a-1] = 1;
   }
}

int main()
{
   cout<<"kk"<<endl;

   int n = 0;

   cout<<"enter number of vertices : ";
   cin>>n;

   bool **gr = new bool*[n];          //declare graph

   for(int i = 0 ; i<n ; i++)       //declare graph
      gr[i] = new bool[n];

   int *back = new int[n];       //no. of missing edges

   init(gr , back , n);

   inputga(gr , n);

   /*graph[0][1] = 1;
   graph[1][0] = 1;

   graph[1][2] = 1;
   graph[2][1] = 1;

   graph[1][3] = 1;
   graph[3][1] = 1;

   graph[3][4] = graph[4][3] = 1;

   graph[3][5] = graph[5][3] = 1;

   graph[5][6] = graph[6][5] = 1;

   graph[5][7] = graph[7][5] = 1;
   */

   //graph[0][1] = graph[1][0] = graph[1][2] = graph[2][1] = graph[2][3] = graph[3][2] = graph[3][4] = graph[4][3] = 1;

   //gr[0][1] = gr[1][0] = gr[0][2] = gr[2][0] = gr[1][2] = gr[2][1] = gr[2][3] = gr[3][2] = gr[1][3] = gr[3][1] = gr[0][3] = gr[3][0] = 1;

   //graph[0][1] = graph[1][0] = graph[1][2] = graph[2][1] = graph[2][3] = graph[3][2] = graph[0][4] = graph[4][0] = graph[4][5] = graph[5][4] = graph[5][6] = graph[6][5] = 1;

   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         cout<<gr[i][j]<<" ";
      cout<<endl;
   }

   //bfs(0 , 1 , 8);
   bool **tree = bcheck(gr , n);

   cout<<"\ntree\n";
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         cout<<tree[i][j]<<" ";
      cout<<endl;
   }

   if (!eqcheck(gr , tree , n))
   {

      print(gr , n);

      tree = bcheck(gr , n);

      cout<<"tree : \n";

      print(tree , n);

   }

   finprint(gr , n);

   return 0;
}
