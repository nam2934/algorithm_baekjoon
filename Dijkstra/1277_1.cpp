#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N,W;
double M;
pair<int, int> plants[1001];
vector<pair<double, int> > linked[1001];
priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
double dist[1001];
const double INF = 987654321.0;

void dijk()
{
   while(!pq.empty())
   {
      int here = pq.top().second;
      double cost = pq.top().first;
      //cout<<here<<' '<<cost<<endl;
      pq.pop();
      if(here == N)
         return;
      if(dist[here] < cost)
         continue;
      for(int i=0; i<linked[here].size(); i++)
      {
         int there = linked[here][i].second;
         double nextD = cost + linked[here][i].first;
         if(dist[there] > nextD)
         {
            dist[there] = nextD;
            pq.push(make_pair(nextD, there));
         }
      }
   }
}

void make_graph()
{
   for(int i=1; i<=N; i++)
   {
      long long y = plants[i].first;
      long long x = plants[i].second;
      for(int j=1; j<=N; j++)
      {
         if(i==j)
            continue;
         long long ty = plants[j].first;
         long long tx = plants[j].second;
         double temp = sqrt((y-ty)*(y-ty) + (x-tx)*(x-tx));
         if(temp <= M)
            linked[i].push_back(make_pair(temp, j));
      }
   }
}

int main()
{
   //freopen("input.txt", "r", stdin);
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   cin>>N>>W;
   cin>>M;
   int x,y;
   for(int i=1; i<=N; i++)
   {
      cin>>x>>y;
      plants[i] = make_pair(y,x);
      dist[i] = INF;
   }
   for(int i=0; i<W; i++)
   {
      cin>>x>>y;
      linked[x].push_back(make_pair(0.0, y));
      linked[y].push_back(make_pair(0.0, x));
   }
   make_graph();
   pq.push(make_pair(0.0, 1));
   dist[1] = 0.0;
   dijk();
   cout<<floor(dist[N]*1000);
}