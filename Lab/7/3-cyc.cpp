#include <iostream>
#include <queue>
using namespace std;

bool graph[1000][1000];

bool vis[1000];

queue<int> q;
queue<bool> stat;

int count = 0;
int count2 = 0;

bool bfs(bool **gr , int node , bool parity , int n)     //start with parity 1
{
   if(vis[node]==1)
      return false;
   vis[node] = 1;

   if(parity == 1)
   	count++;

   for(int i=0 ; i<n ; i++)
   {
      if(gr[node][i] == 1)
      {
	 	q.push(i);
	 	stat.push(!parity);
	  }
   }

   return false;
}

int bcheck(bool **gr , int node , int dest , int n)
{
	bool k = bfs(gr , node , 0 , n);
	bool parity = 0;
   int num = 1;

   if(k)                                                 //found in first run
      return 1;

	while(!q.empty())
	{
		k = bfs(gr , q.front() , stat.front() , n);
		q.pop();
		stat.pop();
	}

   //q populated as per requirement
}

bool bfs_new(bool **gr , int dest , int *par , bool *vis , int node , int n )     //start
{
   if(vis[node]==1)
   {
      return false;
   }
   vis[node] = 1;

   /*if(par[node] != -1)
   {
      tree[par[node]][node] = 1;
      tree[node][par[node]] = 1;
   }*/

   for(int i=0 ; i<n ; i++)
   {
      if(gr[node][i] == 1)
      {
         //vis[i] = 1;
         //tree[node][i] = 1;
         //tree[i][node] = 1;
         q.push(i);
         if(par[i] == -1 && vis[i] == 0)
            {
               //cout<<"parent assigned for dest = "<<dest<<" at node = "<<node<<" to node number (i) = "<<i<<endl;
               par[i] = node;
            }
         else
         {
            //cout<<"here some node @ i = "<<i<<" , par[i] = "<<par[i]<<" , vis[i] = "<<vis[i]<<" for dest = "<<dest<<"at node = "<<node<<endl;
         }
         if(i == dest)
            return true;
         /*if(vis[i] == 0)
         {
            cout<<"node = "<<node<<" , i = "<<i<<endl;
            tree[node][i] = 1;
            tree[i][node] = 1;
         }*/
     }
   }

   return false;
}

int bcheck_new(bool **gr , int src , int dest , int n)                         //does bfs on gr of n nodes
{
   bool *vis = new bool[n];                             //visited array
   int *par = new int[n];
   //bool **tree = new bool*[n];

   /*for(int i = 0 ; i<n ; i++)                         //declare graph
      tree[i] = new bool[n];*/

   for(int i=0 ; i<n ; i++)                           //init. vis
   {
      vis[i] = 0;
      par[i] = -1;
   }

   /*for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         tree[i][j] = 0;
   }*/

   bool k = bfs_new(gr , dest , par , vis , src , n );                                    //first bfs run
   //vis[0] = 1;

   if(k)
      {
         //cout<<"lkol , returned 1 here...\n\n";
         return 1;
      }

   while(!q.empty())
   {
      k = bfs_new(gr , dest , par , vis , q.front() , n );
      q.pop();

      if(k)
      {
         //clear the queue
         while(!q.empty())
            q.pop();
         break;
      }
   }

   if(!k)
   {
      return -1;
   }

   int c_new = 0;

   int ind = dest;

   while(ind != src)
   {
      c_new++;
      //cout<<"ind = "<<ind<<" , parent = "<<par[ind]<<endl;
      if(par[ind] == -1)
         {
             for(int i=0 ; i<n ; i++)
               cout<<par[i]<<" , ";
            cout<<endl;
            break;
         }
      ind = par[ind];
   }

   /*cout<<"\n\n\n";

   for(int i=0 ; i<n ; i++)
      cout<<par[i]<<" , ";
   cout<<"\n\n";

   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         cout<<tree[i][j]<<" ";
      cout<<endl;
   }*/

   //return tree;
   return c_new;
}

void init( bool **gr , bool *vis , int n)
{
   for(int i = 0 ; i<n ; i++)
      for(int j = 0 ; j<n ; j++)
	        gr[i][j] = 0;

   for(int i = 0 ; i<n ; i++)
      vis[i] = 0;

}

void clear(bool *vis , int n)
{
   for(int i=0 ; i<n ; i++)
      vis[i] = 0;
}

void chng(bool **src , bool **dest , int fr , int to , int n)
{
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         dest[i][j] = src[i][j];
   }

   dest[fr][to] = 0;
   dest[to][fr] = 0;
}

void clear_dub(bool **gr , int n)
{
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         gr[i][j] = 0;
   }
}

void input(bool **gr , int n)
{
    int m=0;
    cout<<"enter no. of edges : ";
    cin>>m;
    cout<<"enter u <space> v that represents edge (u , v) in graph : \n";
    for(int i=0 ; i<m ; i++)
    {
        int a=0,b=0;
        cin>>a>>b;
        gr[a-1][b-1] = 1;
        gr[b-1][a-1] = 1;
    }
}

int main()
{
   cout<<"kk"<<endl;

   int n = 0;
   cout<<"enter no. of vertices : ";
   cin>>n;

   bool **gr = new bool*[n];          //declare graph

   for(int i = 0 ; i<n ; i++)       //declare graph
      gr[i] = new bool[n];

   bool **temp = new bool*[n];          //declare graph

   for(int i = 0 ; i<n ; i++)       //declare graph
      temp[i] = new bool[n];

   //bfs(0 , 1 , 8);
   //bcheck(8);

   clear_dub(gr , n);
   clear_dub(temp , n);

   //init();

   //graph[0][1] = graph[1][0] = graph[1][2] = graph[2][1] = graph[2][3] = graph[3][2] = graph[0][4] = graph[4][0] = graph[4][5] = graph[5][4] = graph[5][6] = graph[6][5] = 1;
   //gr[0][1] = gr[1][0] = gr[0][2] = gr[2][0] = gr[1][2] = gr[2][1] = gr[2][3] = gr[3][2] = gr[1][3] = gr[3][1] = gr[0][3] = gr[3][0] = 1;
   input(gr , n);

   /*for(int i=0 ; i<n ; i++)             //prints the graph
   {
      for(int j=0 ; j<n ; j++)
         cout<<gr[i][j]<<" ";
      cout<<endl;
   }*/

   //bcheck2(8);

   int arr[250][250] = {{0}};

   for(int i=0 ; i<n ; i++)                 //sets every arr(i)(j) = infinity
   {
       for(int j=0 ; j<n ; j++)
       {
           arr[i][j] = 99999;
       }
   }

   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
      {
         //cout<<"i = "<<i<<" , j = "<<j<<endl;
         if(gr[i][j]!=1)
            continue;

         chng(gr , temp , i , j , n);

         int p = bcheck_new(temp , i , j , n);
         if(p != (-1) && p < arr[i][j])
            arr[i][j] = p+1;

      }
   }

   for(int i = 0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         cout<<arr[i][j]<<" ";
      cout<<endl;
   }

   int min = arr[0][0];

   for(int i=0 ; i<n ; i++)
   {
       for(int j=0 ; j<n ; j++)
       {
           if(arr[i][j] == 3)
           {
               cout<<"C3 Exists!\n\n";
               return 0;
           }
       }
   }

    cout<<"C3 doesn't exist...  ->  (\n\n";
   //cout<<"min cycle is of length = "<<min<<endl<<endl;

   return 0;
}
