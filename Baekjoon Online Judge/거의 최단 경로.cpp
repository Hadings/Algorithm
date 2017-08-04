/*
다익스트라 알고리즘 참고 사이트 : https://lyzqm.blogspot.kr/2017/06/dijkstra-5719.html

거의 최단 경로


*/

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
#define INF 987654321

int N, M, S, D;
vector<vector<pair<int, int>>> adj, rev;
vector<vector<bool>> visit;
vector<int> dist;

void di(int start, int end) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	fill(dist.begin(), dist.end(), INF);
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int here = pq.top().second;
		pq.pop();
		for (auto n : adj[here]) {
			int next = n.second;
			int cost = n.first + dist[here];
			if (dist[next] > cost && visit[here][next]) {
				dist[next] = cost;
				pq.push({ dist[next], next });
			}
		}
	}
}

void bfs(int start, int end) {

	queue<int> q;
	q.push(end);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == start) continue;
		for (auto n : rev[here]) {
			int next = n.second;
			if (dist[here] == dist[next] + n.first) {
				visit[next][here] = false;
				q.push(next);
			}
		}
	}
}

int main() {

	scanf("%d%d", &N, &M);
	while (!(N == 0 && M == 0)) {
		adj = vector<vector<pair<int, int>>> (N, vector<pair<int, int>>());
		rev = vector<vector<pair<int, int>>> (N, vector<pair<int, int>>());
		visit = vector<vector<bool> >(N, vector<bool>(N, true));
		dist = vector<int>(N, INF);
		scanf("%d%d", &S, &D);
		for (int m = 0; m < M; m++) {
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			adj[u].push_back({ d, v });
			rev[v].push_back({ d, u });
		}
		di(S, D);
		bfs(S, D);
		di(S, D);

		if (dist[D] != INF) 
			printf("%d\n", dist[D]);
		else 
			printf("-1\n");
	}
	return 0;
}
