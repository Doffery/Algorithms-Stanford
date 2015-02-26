#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

#define VEXNUM 200
using std::vector;
using std::priority_queue;

struct Edge {
	int t, h; //tail, head
	int value;
	Edge() {}
	Edge(int x, int y) {
		h = x; value = y;
	}

};

struct Node {
	int p, i;//pre, index
	int dis;
	Node() {}
	Node(int x, int y) {
		p = x; value = y;
	}
	bool operator < (const Node rhs) const {
		return dis > rhs.dis;
	}
}

vector<Edge> edges[VEXNUM + 10];
priority_queue<Node> heap;

int dist[VEXNUM + 10];
bool visited[VEXNUM + 10];

void Dijkstra() {
	memset(visited, 0, sizeof(visited));
	int i, j;
	for(i = 0; i < edges[1].size(); ++i) {
		heap.push(Node(1, edges[1][i].h, edges[1][i].value));
	}
	visited[1] = true;
	dist[1] = 0;
	for(i = 1; i < VEXNUM; ++i) {
		while(visited[heap.top().i])
			heap.pop();
		Node o = heap.top();
		heap.pop();
		dist[o.i] = o.dis;
		visited[o.i] = true;
		for(j = 0; j < edges[o.i].size(); ++j) {
			heap.push(Node(o.i, edges[o.i][j], o.dis + edges[o.i][j].value));
		}
	}
}

int main() {
	freopen("int.txt", "r", stdin);

	int v = 0;
	char tstr[20], vstr[10];
	fscanf(vstr, "%d", ++v);
	while(v <= 200) {
		scanf("%s", tstr);
		if(strcmp(tstr, vstr)) {
			int e, v;
			sscanf(tstr, "%d,%d", &e, &v);
			edges[v].push_back(Edge(v, e, v));
		}
		else {
			fscanf(vstr, "%d", ++v);
			continue;
		}
	}

	Dijkstra();
}
