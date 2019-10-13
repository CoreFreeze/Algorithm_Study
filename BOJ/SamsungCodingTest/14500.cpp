#include <iostream>
using namespace std;

#define MAX 500

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];

int result = -1;

bool isPossible(int y, int x){
    return !((x < 0) || ( y < 0 ) || (x >= M)||(y >= N));
}

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

void dfs(int y, int x, int count, int sum){
    if (count == 4) {
        result = max(sum,result);
        return;
    }

    visited[y][x] = true;
    sum+=map[y][x];

    for (int i = 0; i < 4; ++i){
        int TempX = x + dx[i];
        int TempY = y + dy[i];
        if (!isPossible(TempY,TempX)) continue;
        if (visited[TempY][TempX]) continue;


        //visited[TempY][TempX] = true;
        dfs(TempY,TempX,count+1,sum);
        //visited[TempY][TempX] = false;
    }
    visited[y][x] = false;
}

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> map[i][j];
        }
    }
}

int main (){
    input();
    for (int y = 0; y < N; ++y){
        for (int x = 0; x < M; ++x){
            dfs(y,x,0,0);

            if (isPossible(y-1,x) && isPossible(y+1,x) && isPossible(y,x+1)) result = max(map[y][x]+map[y-1][x]+map[y+1][x]+map[y][x+1],result);
            if (isPossible(y-1,x) && isPossible(y+1,x) && isPossible(y,x-1)) result = max(map[y][x]+map[y-1][x]+map[y+1][x]+map[y][x-1],result);
            if (isPossible(y-1,x) && isPossible(y,x-1) && isPossible(y,x+1)) result = max(map[y][x]+map[y-1][x]+map[y][x-1]+map[y][x+1],result);
            if (isPossible(y+1,x) && isPossible(y,x-1) && isPossible(y,x+1)) result = max(map[y][x]+map[y+1][x]+map[y][x-1]+map[y][x+1],result);
        }
    }

    cout << result << '\n';

    return 0;
}