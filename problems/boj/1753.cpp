#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 1000000

using namespace std;

int v, e, k;
vector<pair<int, int>> edges[20001];
int path[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> k;

    for(int i = 1; i <= v; i++){
        path[i] = INF;
    }
    path[k] = 0;

    for(int i = 0; i < e; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[from].push_back(make_pair(to, weight));
    }

    pq.push(make_pair(0, k));
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int distance = p.first, vertex = p.second;

        if(path[vertex] >= distance){
            path[vertex] = distance;
            for(pair<int, int>& e: edges[vertex]){
                int to = e.first, vertex_weight = e.second;
                if(distance + vertex_weight < path[to]){
                    path[to] = distance + vertex_weight;
                    pq.push(make_pair(path[to], to));
                }
            }
        }
    }

    for(int i = 1; i <= v; i++){
        if(path[i] == INF){
            cout << "INF" << '\n';
        } else {
            cout << path[i] << '\n';
        }
    }

    return 0;
}
