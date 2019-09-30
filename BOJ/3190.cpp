/* 3190 */
#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 102

int map[MAX_SIZE][MAX_SIZE];
int N,K;

queue <pair<int,int>> q;

enum _eDir{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

 enum _eSnakeDir {
    snakeLEFT = 'L',
    snakeRIGHT = 'D'
};

class Snake {
    int dir;

    public: 
    Snake():dir(RIGHT){
        map[1][1]=1;
        q.push(pair<int,int>(1,1));
    }
    void changeDir(int snakeDir);
    bool move();
    int time;
};

void Snake::changeDir(int snakeDir){

        if (snakeDir=='D'){
            if (this->dir < 3){
                this->dir = this->dir + 1;
            }
            else {
                this->dir = RIGHT;
            }
        }
        else if(snakeDir == 'L'){
            /* Move head to LEFT */
            if (this->dir > 0) {
                this->dir = this->dir -1;
            }
            else {
                this->dir = UP;
            }
        }
        else {

        }
}

bool Snake::move(){

    /* Move head */
    int tempY = q.back().first + dy[this->dir];
    int tempX = q.back().second + dx[this->dir];

    this->time++;

    /* Game is ended */
    if ((map[tempY][tempX] == 1) || (map[tempY][tempX])=='#'){
        return false;
    }
    else {
        q.push(pair<int,int>(tempY,tempX));
    }

    /* Can't Eat apple */
    if (map[tempY][tempX]!='a'){
        map[q.front().first][q.front().second] = 0;
        q.pop();
    }
    else {
        /* Eat apple */
        /* No Operation */
    }

    map[tempY][tempX] = 1;

    return true;
}
Snake snake = Snake();

void createMap (){
    for (int i=0; i< N+2; ++i) {
        map[0][i] = '#';
        map[N+1][i] = '#';
        map[i][0] = '#';
        map[i][N+1] = '#';
    }
}

void addApple(){

    int indexX, indexY;
    for (int i =0; i < K; ++i){
        cin >> indexY >> indexX;
        map[indexY][indexX] = 'a';
    }
}

void checkMove(){
    int inputNum;
    int time=0;
    char inputDir=0;
    int i = 0;
    bool flag = true;
    cin >> inputNum;
    do {
        if (time == snake.time){
            snake.changeDir(inputDir);
            if (i < inputNum) {
                cin >> time >> inputDir;
                i++;
            }
        }
    }
    while(snake.move());
}



int main (){

    cin >> N >> K;

    createMap();
    addApple();
    checkMove();

    cout << snake.time <<endl;
    return 0;
}