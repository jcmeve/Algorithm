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
        g[a].push_back({b,c});
    }

    vector<int> dist(N+1, 987654321);
    dist[1] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,1});

    while(!q.empty()){
        auto [weight, dest] = q.top();
        q.pop();

        if(weight>dist[dest]) continue;

        for(auto& edge : g[dest]){
            if(dist[edge.first] > dist[dest] + edge.second){
                dist[edge.first] = dist[dest] + edge.second;
                q.push({dist[edge.first], edge.first});
            }
        }
    }

    for(int i =2; i <= N; ++i){
        if(dist[i]==987654321) cout<<-1<<endl;
        else cout<<dist[i]<<endl;
    }



    return 0;
}