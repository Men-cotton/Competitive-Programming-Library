#include <iostream>
#include <vector>
#include <queue>

#define p pair<int,int>
using namespace std;

int n;
vector<vector<p >> graph;
vector<int> dis;

void dijkstra(int s) {
    priority_queue<p, vector<p >, greater<>> que;
    dis = vector<int>(n, 1145141919);
    dis[s] = 0;
    que.push(p(s, 0));

    while (!que.empty()) {
        p now = que.top();
        que.pop();
        int nowv = now.first;

        if (dis[nowv] < now.second)continue;

        for (auto next:graph[nowv]) {
            if (dis[next.first] > dis[nowv] + next.second) {
                dis[next.first] = dis[nowv] + next.second;
                que.push(p(next.first, dis[next.first]));
            }
        }
    }
}

int main() {
    int m;
    cin >> n >> m;
    graph = vector<vector<p >>(n);
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(p(to, cost));
        graph[to].push_back(p(from, cost));
    }

    int start, end;
    cin >> start >> end;
    dijkstra(start);

    cout << dis[end] << endl;
    return 0;
}