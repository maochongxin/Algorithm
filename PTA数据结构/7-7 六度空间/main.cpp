#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int N,M;
int cnt;
int map[9999][9999],book[9999];

struct Node {
	int n;
	int dis;	//记录距离	
};

void bfs(int n) {
	queue<Node> que;
	Node nd;
	nd.n = n;	nd.dis = 0;
	book[n] = 1;
	que.push(nd);
	while (!que.empty()) {
		Node t = que.front();
		que.pop();
		cnt++;
		if (t.dis == 6) {
			continue;
		}
		for (int i = 0; i < N; i++) {
			if (book[i] == 1) { continue; }
			if (map[t.n][i] == 0) { continue; }
			Node t2;
			t2.n = i;	t2.dis = t.dis + 1;
			book[i] = 1;
			que.push(t2);
		}
	}
}

int main(int argc, char *argv[]) {
	
	cin >> N >> M;
	int a,b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a - 1][b - 1] = map[b - 1][a - 1] = 1;
	}
	for (int i = 0; i < N; i++) {
		memset(book, 0, sizeof(book));
		cnt = 0;
		bfs(i);
		printf("%d: %.2lf%%\n",i + 1, cnt * 100.0 / N);
	}
	return 0;
}
