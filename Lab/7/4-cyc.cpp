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

bool bfs_new(bool **gr , int dest , int *par , bool *vis , int node , bool parity , int n )     //start with parity false
{
   if(vis[node]==1)
   {
      return false;
   }
   /*if(!parity)
   {
       return false;
   }*/

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
         //q.push(i);
         //stat.push(!parity);
         //cout<<"pushed into queue i = "<<i<<" , having parity = "<<parity<<endl<<endl<<endl;
         if(par[i] == -1 && vis[i] == 0)
            {
               //cout<<"parent assigned for dest = "<<dest<<" at node = "<<node<<" to node number (i) = "<<i<<endl;
               par[i] = node;
               //cout<<"set parent of i = "<<i<<" as node = "<<node<<endl<<endl;
            }
         else
         {
            //cout<<"here some node @ i = "<<i<<" , par[i] = "<<par[i]<<" , vis[i] = "<<vis[i]<<" for dest = "<<dest<<"at node = "<<node<<endl;
         }
         bool kk = 0;
         if(i == dest)
          {
              if(!parity)
              {
                  //q.pop();
                  //stat.pop();
                  kk = 1;
                  par[i] = -1;
                  vis[i] = 0;
                  /*cout<<"found "<<dest<<" and removed from list cause of parity reasons at node = "<<node<<"\n\n";
                  cout<<"parent of dest = "<<dest<<" = "<<par[dest]<<" , and vis[dest] = "<<vis[dest]<<"\n\n\n";
                  cout<<"now , front of queue = "<<q.front()<<endl<<endl<<endl;*/
                  //return false;
              }
              else
              {
                  //cout<<"found "<<dest<<" at right parity of "<<parity<<" lel node = "<<node<<"\n\n";
                  //q.push(i);
                  //stat.push(!parity)
                  return true;
              }
          }
          if(kk == 0)
          {
              q.push(i);
              stat.push(!parity);
          }
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

    //cout<<"into bcheck_new\n\n";

   for(int i=0 ; i<n ; i++)                           //init. vis
   {
      vis[i] = 0;
      par[i] = -1;
   }

   bool k = bfs_new(gr , dest , par , vis , src , false , n );                                    //first bfs run
   //vis[0] = 1;
   bool parity = false;

   if(k)
      {
         cout<<"lkol , returned 1 here...\n\n";
         return 1;
      }

   while(!q.empty())
   {
      k = bfs_new(gr , dest , par , vis , q.front() , stat.front() , n );
      q.pop();
      stat.pop();

      if(k)
      {
         //clear the queue
        while(!q.empty())
        {
            q.pop();
            stat.pop();
        }
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
      if(par[ind] == -1)
      {
          cout<<"here in unsafe state\n";
          break;
      }
      ind = par[ind];
   }

   /*cout<<"\n\n\n";

   for(int i=0 ; i<n ; i++)
      cout<<par[i]<<" , ";
   cout<<"\n\n";*/

   /*for(int i=0 ; i<n ; i++)
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

void chng(bool **src , bool **dest , int mid , int fr , int to , int n)         //severes fr->mid and mid->to
{
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         dest[i][j] = src[i][j];
   }

   dest[fr][mid] = 0;
   dest[mid][fr] = 0;
   dest[to][mid] = 0;
   dest[mid][to] = 0;
}

void clear_dub(bool **gr , int n)                       //clears gr to all zeros
{
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
         gr[i][j] = 0;
   }
}

void input(bool **gr , int n)                           //accepts input
{
    int m=0;
    cout<<"enter no. of edges : ";
    cin>>m;
    cout<<"enter edges in form u v to represent an edge (u,v) and (v,u) in the graph (i.e : u <space> v) : \n";
    for(int i=0 ; i<m ; i++)
    {
        int a=0 , b=0;
        cin>>a>>b;
        gr[a-1][b-1] = 1;
        gr[b-1][a-1] = 1;
    }
}

int main()
{
   int n = 0;

   cout<<"enter no. of vertices : ";
   cin>>n;

   bool **gr = new bool*[n];          //declare graph

   for(int i = 0 ; i<n ; i++)       //declare graph
      gr[i] = new bool[n];

   bool **temp = new bool*[n];          //declare graph

   for(int i = 0 ; i<n ; i++)       //declare graph
      temp[i] = new bool[n];

    clear_dub(gr , n);
    clear_dub(temp , n);

    input(gr , n);;

   int arr[250][250] = {{0}};

   for(int i=0 ; i<n ; i++)                         //does main work of filling arr
   {
      for(int j=0 ; j<n ; j++)
      {
         //cout<<"i = "<<i<<" , j = "<<j<<endl;
         if(gr[i][j]!=1)
            continue;

         for(int k=0 ; k<n ; k++)
         {
             if(gr[i][k] != 1)
                continue;
            if(j==k)
                continue;

            chng(gr , temp , i , j , k , n);

            //cout<<"hararaha"<<endl;

            int p = bcheck_new(temp , j , k , n);
            if(p != (-1))
                arr[j][k] = p + 2;

            /*if(j == 0 && k == 3)
            {
                cout<<"j = 0 & k = 3 for i = "<<i<<" , p = "<<p<<endl<<endl;
            }*/

         }
      }
   }

   /*chng(gr , temp , 2 , 0 , 1 , 4);

    for(int i=0 ; i<n ; i++)
    {
       for(int j=0 ; j<n ; j++)
       {
           cout<<temp[i][j]<<" ";
       }
       cout<<endl;
    }
   cout<<"\n\n";

   int p = bcheck_new(temp , 0 , 1 , 4);
   cout<<" p = "<<p<<endl;*/


   /*for(int i = 0 ; i<n ; i++)                       //prints arr
   {
      for(int j=0 ; j<n ; j++)
         cout<<arr[i][j];
      cout<<endl;
   }*/

   for(int i=0 ; i<n ; i++)
   {
       for(int j=0 ; j<n ; j++)
       {
           if(arr[i][j] == 4)
           {
               cout<<"C4 Exists!\n\n";
               return 0;
           }
       }
   }

   cout<<"No C4 Exists...  ->  :(\n\n";

   return 0;
}
