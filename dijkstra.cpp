#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
    int to;
    int cost;
};

struct status {
    int cost;
    int v;

    bool operator<(const status &another) const { return cost < another.cost; };

    bool operator>(const status &another) const { return cost > another.cost; };
};

vector<int> dijkstra(int s, int n, vector<vector<edge>> &graph) {
    priority_queue<status, vector<status>, greater<>> que;
    vector<int> dis(n, 1145141919);
    dis[s] = 0;
    que.push({0, s});

    while (!que.empty()) {
        status now = que.top();
        que.pop();

        if (dis[now.v] < now.cost)continue;

        for (auto next:graph[now.v]) {
            if (dis[next.to] > dis[now.v] + next.cost) {
                dis[next.to] = dis[now.v] + next.cost;
                que.push({dis[next.to], next.to});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }

    int start, end;
    cin >> start >> end;
    vector<int> dis = dijkstra(start, n, graph);

    cout << dis[end] << endl;
    return 0;
}
