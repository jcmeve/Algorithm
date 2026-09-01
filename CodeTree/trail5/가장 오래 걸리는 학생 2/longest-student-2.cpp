#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N,M;
    cin>>N>>M;
    
    vector<vector<pair<int,int>>> g(N+1);

    for(int i =0; i < M; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        g[b].push_back({a,c});
    }

    vector<int> dist(N+1, 987654321);
    dist[N] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,N});

    while(!q.empty()){
        auto [weight, u] = q.top();q.pop();

        if(dist[u] < weight) continue;

        for(int i = 0; i < g[u].size(); ++i){
            auto [v,curr_weight] = g[u][i];

            if(dist[v] > weight+curr_weight){
                dist[v] = weight+curr_weight;
                q.push({dist[v], v});
            }
        }
    }

    int maxValue = -1;
    for(int i =1; i < N; ++i){
        if(maxValue < dist[i]){
            maxValue = dist[i];
        }
    
    }

    cout<<maxValue;

    return 0;
}