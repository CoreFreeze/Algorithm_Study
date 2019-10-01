#include <iostream>
using namespace std;

int N, M, DiceX, DiceY;

int map[21][21];
int face[6];

enum _eDiceFace {
    UP,
    RIGHT,
    TOP,
    BOTTOM,
    LEFT,
    DOWN
};

enum _eDir {
    moveRIGHT = 1,
    moveLEFT = 2,
    moveUP =3,
    moveDOWN =4
};

int dy[] = {0,0,0,-1,1};
int dx[] = {0,1,-1,0,0};

bool boundaryCheck(int x,int y){
    return ((0 <= x) && (0 <= y) && (x < M) && (y < N));
}

void moveDice (int Dir){
    int temp=0;

    switch (Dir)
    {
    case moveUP: {
            temp = face[UP];
            face[UP] = face[TOP];
            face[TOP] = face[DOWN];
            face[DOWN] = face[BOTTOM];
            face[BOTTOM] = temp;
            break;
    }
    case moveDOWN: {
            temp = face[UP];
            face[UP] = face[BOTTOM];
            face[BOTTOM] = face[DOWN];
            face[DOWN] = face[TOP];
            face[TOP] = temp;
            break;
    }
    case moveRIGHT: {
            temp = face[RIGHT];
            face[RIGHT] = face[TOP];
            face[TOP] = face[LEFT];
            face[LEFT] = face[BOTTOM];
            face[BOTTOM] = temp;
            break;
    }
    default: {
            temp = face[RIGHT];
            face[RIGHT] = face[BOTTOM];
            face[BOTTOM] = face[LEFT];
            face[LEFT] = face[TOP];
            face[TOP] = temp;
            break;
    }
    }

    if (map[DiceY][DiceX]==0) {
        map[DiceY][DiceX] = face[BOTTOM];
    }
    else {

        face[BOTTOM] = map[DiceY][DiceX];
        map[DiceY][DiceX] = 0;
    }
}


void createMap(){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> map[i][j];
        }
    }
}

int main (){

    int k, dir;

    cin >> N >> M >> DiceY >> DiceX >> k;

    createMap();

    for (int i = 0; i<k; ++i){
        cin >> dir;
        
        if (boundaryCheck(DiceX+dx[dir],DiceY+dy[dir])){
            DiceX+=dx[dir];
            DiceY+=dy[dir];
            moveDice(dir);
            cout << face[TOP] << endl;
        }
    }

    return 0;
}