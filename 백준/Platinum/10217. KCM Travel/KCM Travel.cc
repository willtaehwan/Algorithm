#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1000000000

int N,M,K;
vector<pair<int,pair<int,int>>>v[101];
int dist[101][10001];

void dijkstra()
{
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{1,0}});
    dist[1][0] = 0;
    
    while(!q.empty())
    {
        int curtime = q.front().first;
        int cur = q.front().second.first;
        int curcost = q.front().second.second;
        q.pop();
        if(dist[cur][curcost] < curtime)    continue;
        for(int i=0; i<v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nextcost = v[cur][i].second.first + curcost;
            int nexttime = v[cur][i].second.second + curtime;
            if(nextcost <= M && dist[next][nextcost] > nexttime)
            {
                for(int j=nextcost+1; j<=M; j++)
                {
                    if(dist[next][j] <= nexttime)    break;
                    dist[next][j] = nexttime;
                }
                dist[next][nextcost] = nexttime;
                q.push({nexttime,{next,nextcost}});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> M >> K;
        for(int i=0; i<K; i++)
        {
            int from,to,cost,t;
            cin >> from >> to >> cost >> t;
            v[from].push_back({to,{cost,t}});
        }
        
        for(int i=1; i<=N; i++)
        {
            for(int j=0; j<=M; j++) dist[i][j] = INF;
        }
        
        dijkstra();
        
        int ans = INF;
        for(int i=0; i<=M; i++)
        {
            if(dist[N][i] < ans)
            {
                ans = dist[N][i];
            }
        }
        if(ans == INF)  cout<<"Poor KCM";
        else    cout<<ans;
    }
}