#include <iostream>
#include <queue>
using namespace std;



int main() {
    int N,M,K;
    cin>>N>>M>>K;

    vector<vector<pair<int,int>>> g(N+1);

    for(int i =0; i < M; ++i){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    vector<long long> dist(N+1,98765432198765);
    dist[K] =0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
    q.push({0,K});

    while(!q.empty()){
        auto [weight, u] = q.top(); q.pop();

        if(dist[u] < weight) continue;

        for(int i = 0 ; i < g[u].size(); ++i){
            auto [v,curr_weight] = g[u][i];
            if(dist[v] > weight+curr_weight){
                dist[v] = weight+curr_weight;
                q.push({dist[v], v});
            }
        }

    }


    for(int i =1; i <=N; ++i){
        if(dist[i]==98765432198765) cout<<-1<<endl;
        else cout<<dist[i]<<endl;
    }


    return 0;
}