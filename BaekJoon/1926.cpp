#include <iostream>

using namespace std;

const int MAX = 500;
const int dx[4] = {0 , 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
bool adj[MAX][MAX];
int maxArea = 0, count1 = 0, n, m;

int dfs(int i, int j) {
    int ret = 1;
    adj[i][j] = 0;

    for(int di = 0; di < 4; di++) {
        int ii = i + dy[di], jj = j + dx[di];
        if(ii < 0 || jj < 0 || ii >= n || jj >= m || !adj[ii][jj]) {
            continue;
        }
        ret += dfs(ii, jj);
    }
    return ret;
}
void dfsAll() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(adj[i][j]){
                maxArea = max(maxArea, dfs(i, j));
                count1++;
            }
        }
    }
    printf("%d\n%d", count1, maxArea);
}

int main() {
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    dfsAll();
}