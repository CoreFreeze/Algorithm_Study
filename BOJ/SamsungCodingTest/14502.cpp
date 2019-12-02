#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 8

int N, M, num, count, result;

int map[MAX][MAX];
int mapBack[MAX][MAX];
vector<pair<int,int>> virus;

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

void input(){

    cin >> N >> M;

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> map[i][j];
            if ( map[i][j] == 2 ){
                virus.push_back(make_pair(i,j));
                num++;
            }
        }
    }
}

void output(){

    cout << "\n\n";

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cout << map[i][j];
        }
        cout << '\n';
    }
}

bool isPossible(int y, int x){
    return !((x<0)||(y<0)||(x>=M)||(y>=N));
}

void moveVirus(){
    queue<pair<int,int>> q;

    for (int i = 0; i < num; ++i){
        q.push(virus[i]);
    }

    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        map[y][x] = 2;

        for (int i = 0; i < 4; ++i) {
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            if ((!isPossible(tempY,tempX)) || (map[tempY][tempX])) continue;
            q.push(make_pair(tempY,tempX));
        }
    }

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if (map[i][j] == 0) count++;
        }
    }

    result = max(count,result);
    count = 0;
}

void createWall(int y, int x, int index){

    if (index == 3){
        /* 3개를 세우면 virus를 움직임 */
        memcpy(mapBack,map,sizeof(map));
        moveVirus();
        memcpy(map,mapBack,sizeof(map));
        return;
    }

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if ((map[i][j] == 1) || (map[i][j] == 2)) continue; 
            map[i][j] = 1;
            createWall(i,j,index+1);
            map[i][j] = 0;
        }
    }
}

int main(){

    input();
    createWall(0,0,0);

    cout << result << '\n';

    return 0;
}