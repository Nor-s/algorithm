## 매크로

`#define all(x) (x).begin(), (x).end()`
`#define compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())`

## 함수

- `void* memset(void* ptr, int value, size_t num);`

  - `cstring`

- 소수점
  - `cout << fixed;`
    - `cout.precision(6);`

## 실수

- for문에 음수들어갈 때 size_t 조심

- bfs에서 visit 체크는 push할 때!!!

##

```cpp
#include <iostream>
#include <queue>

using namespace std;

auto compare = [](int a, int b){
    if(abs(a)==abs(b)) {
        return a > b;
    }
   return abs(a) > abs(b);
};
priority_queue<int,vector<int>, decltype(compare)> pq(compare);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int a;
        cin>>a;
        if(a!=0){
        pq.push(a);
        }
        else
        {
            if(pq.empty()) {
                cout<<"0\n";
                continue;
            }
           cout<<pq.top()<<"\n";
            pq.pop();
        }
    }
}

```

- 크루스칼

```cpp
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <tuple>

using namespace std;
int N, M;
int board[102][102];
int dy[] = { 1, 0, -1, 0};
int dx[] = { 0, 1, 0, -1};
int kind = 2;

void dfs(int y, int x, int kind) {
	board[y][x] = kind;
	for (int i = 0; i < 4; i++) {
		int yy = y +  dy[i];
		int xx = x + dx[i];
		if (board[yy][xx] == 1) {
			dfs(yy, xx, kind);
		}
	}
}

void dfsAll() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 1) {
				dfs(i, j, kind);
				kind++;
			}
		}
	}
}

class UF {
public:
	vector<int> parent;
	vector<int> rank;
	UF(int n) {
		parent = vector<int>(n);
		rank = vector<int>(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}
	int find(int u) {
		if (u == parent[u] ) {
			return u;
		}
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) {
			return;
		}
		if (rank[u] > rank[v]) {
			int tmp = v;
			v = u;
			u = tmp;
		}
		parent[u] = v;
		rank[v] = std::max(rank[v], rank[u] + 1);
	}
};

vector<tuple<int, int, int>> edges;

void makeEdges() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 0) {
				continue;
			}

			for (int k = 0; k < 2; k++) {
				int src = board[i][j];
				int nx = j + dx[k];
				int ny= i + dy[k];

				int count = 2;
				int dist = 0;

				int dst = board[ny][nx];

				while (dst == 0)
				{
					ny = i + dy[k]*count;
					nx = j + dx[k]*count;
					dst = board[ny][nx];
					dist++;
					count++;
				}

				if (1 < dst && src != dst && dst != -1 && dist != 1) {
					edges.push_back({ dist, src, dst });
				}
			}
		}
	}
}


int kruskal() {
	makeEdges();
	UF uf(kind);
	sort(edges.begin(), edges.end());
	int ret = 0;

	for (int i = 0; i < edges.size(); i++) {
		int d = get<0>(edges[i]);
		int src = get<1>(edges[i]);
		int dest = get<2>(edges[i]);
		src = uf.find(src);
		dest = uf.find(dest);
		if (src != dest) {
			uf.merge(src, dest);
			ret += d;
		}
	}
	int tmp = uf.find(2);
	for (int i = 2; i < kind; i++) {
		if (tmp != uf.find(i)) {
			return 0;
		}
	}
	return ret;
}


int main() {
	memset(board, -1, sizeof board);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
	dfsAll();

	int a = kruskal();
	if (a == 0) {
		cout << -1;
	}
	else {
		cout << a;
	}
}
```
