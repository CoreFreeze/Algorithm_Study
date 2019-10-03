/* 13460 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_SIZE 10

int N, M;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];

int rx, ry, bx, by;

enum _edir {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct Node{
    int ry;
    int rx;
    int by;
    int bx;
    int count;
    Node(int ry,int rx,int by,int bx,int count) : ry(ry),rx(rx),by(by),bx(bx),count(count) {}
};

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

void inputMap(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>map[i][j];
            if (map[i][j]=='R') {
                rx = j; ry = i;
                map[i][j] = '.';
            }
            if (map[i][j]=='B'){
                bx = j; by = i;
                map[i][j] = '.';
            }
        }
    }
}

int boundaryCheck (int x, int y){
    return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(){
    queue<Node> q;
    q.push(Node(ry,rx,by,bx,0));
    visited[ry][rx][by][bx] = true;

    while(!q.empty()){
        Node temp = q.front();
        q.pop();

        if (temp.count+1 > 10) {
            continue;
        }

        for (int i = 0; i < 4; ++i){
            rx = temp.rx+dx[i];
            ry = temp.ry+dy[i];
            bx = temp.bx+dx[i];
            by = temp.by+dy[i];


            while((boundaryCheck(rx,ry)) && (map[ry][rx] == '.')){
                rx += dx[i];
                ry += dy[i];
            }
            while((boundaryCheck(bx,by)) && (map[by][bx] == '.')){
                bx += dx[i];
                by += dy[i];
            }

            if (map[ry][rx] == 'O'&& map[by][bx] == 'O'){
                continue;
            }

            if (map[ry][rx] != 'O'&& map[by][bx] == 'O'){
                continue;
            }

            if (map[ry][rx] == 'O' && map[by][bx] != 'O'){
                return temp.count+1;
            }


            if (map[ry][rx] == '#'){
                ry -= dy[i];
                rx -= dx[i];
            }

            if (map[by][bx] == '#'){
                by -= dy[i];
                bx -= dx[i];
            }

            if ( (rx == bx) && (ry == by)){
                switch (i)
                {
                    case LEFT: {
                        if (temp.rx > temp.bx ){
                            rx = rx + dx[RIGHT];
                        }
                        else {
                            bx = bx + dx[RIGHT];
                        }
                        break;
                    }

                    case RIGHT:{
                        if (temp.rx < temp.bx ){
                            rx = rx + dx[LEFT];
                        }
                        else {
                            bx = bx + dx[LEFT];
                        }
                        break;
                    }

                    case UP:{
                        if (temp.ry > temp.by ){
                            ry = ry + dy[DOWN];
                        }
                        else {
                            by = by + dy[DOWN];
                        }
                        break;
                    }

                    default:{
                        if (temp.ry < temp.by ){
                            ry = ry + dy[UP];
                        }
                        else {
                            by = by + dy[UP];
                        }
                        break;
                    }
                }
            }

            if (visited[ry][rx][by][bx]) {
                    continue;
            }

            visited[ry][rx][by][bx] = true;

            q.push(Node(ry,rx,by,bx,temp.count+1));
        }
    }

    return -1;
}

int main (){

    cin >> N >> M;

    inputMap();

    cout << bfs() << endl;

    getchar();
    getchar();

    return 0;
}