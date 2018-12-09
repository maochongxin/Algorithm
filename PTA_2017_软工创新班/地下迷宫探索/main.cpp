#include <stdio.h>
#include <string.h>

int n,m,s;
int map[1005][1005];
int path[3000];
int vis[1005];
int len;

void dfs(int s) {
    for(int i = 1; i <= n; i++){
        if(!vis[i] && map[s][i] == 1) {
            vis[i] = 1;
            path[len++] = i;
            dfs(i);
            path[len++] = s;
        }
    }
}
int main(int argc, char* args[]) {
    scanf("%d%d%d",&n,&m,&s);
    int x,y;
    for(int i = 0; i < m; i++){
        scanf("%d%d",&x,&y);
        map[x][y] = 1;
        map[y][x] = 1;
    }
    path[0] = s;
    len++;
    vis[s] = 1;
    dfs(s);
    int flag = 1;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            flag = 0;
            break;
        }
    }
    if(!flag){
        for(int i = 0; i < len; i++){
            if(i == 0) {
                printf("%d",path[i]);
            } else {
                printf(" %d",path[i]);
            }
        }
        printf(" 0");
    } else {
        for(int i = 0; i < len; i++){
            if(i == 0) {
                printf("%d",path[i]);
            } else {
                printf(" %d",path[i]);
            }
        }
    }
    return 0;
}
