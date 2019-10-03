/* 15683 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 8
#define MAX_M 8

int map[MAX_N][MAX_M];
int N, M;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int result = 987654321;
int cameraNum = 0;
int count2 = 0;

struct _camera {
    int X;
    int Y;
    int dir;
}Camera[8];

enum _eXY {
    indexX,
    indexY
};

enum _ekinds {
    BLANK,
    CCTV1,
    CCTV2,
    CCTV3,
    CCTV4,
    CCTV5,
    WALL
};

enum _edir {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

void findMin(){
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (map[i][j]){

            }
            else {
                count++;
            }
        }
    }
    if ( count < result ){
        result = count;
    }
}

void input_map(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>map[i][j];
            if ( (map[i][j]>0) && (map[i][j]<6)) {
                // Write numbers of camera & location of camera
                Camera[cameraNum].X = j;
                Camera[cameraNum].Y = i;
                Camera[cameraNum].dir = UP;
                cameraNum++;
            }
        }
    }
}

void Output_map(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout<<map[i][j] << ' ';
        }
        cout << endl;
    }
}

void flagOneDir(int dir,int x, int y){

    if (dir > 3 ){
        dir -= 4;
    }

    //flag area on map
    switch (dir){
        case LEFT:
            //Move to left
            x+=dx[LEFT];
            y+=dy[LEFT];
            break;
        case RIGHT:
            //Move to right
            x+=dx[RIGHT];
            y+=dy[RIGHT];
            break;
        case UP:
            //Move to up
            x+=dx[UP];
            y+=dy[UP];
            break;
            
        default:
            //Move to dwon
            x+=dx[DOWN];
            y+=dy[DOWN];
            break;
    }
    // check condition
    if ( (map[y][x]==6) || (x < 0) || (y < 0) || (x >= M) || (y >= N)) {
        return;
    }

    //flag
    if(( map[y][x] > 0 ) && ( map[y][x] < 6)){

    }
    else {
        map[y][x]=9;
    }
    flagOneDir(dir, x, y);
}

void flagArea(int x,int y,int numOfCamera){
    
    switch (map[y][x])
    {
    case CCTV1:
        flagOneDir(Camera[numOfCamera].dir+1, x, y);
        break;
    case CCTV2:
        flagOneDir(Camera[numOfCamera].dir+1, x, y);
        flagOneDir(Camera[numOfCamera].dir+3, x, y);
        break;
    case CCTV3:
        flagOneDir(Camera[numOfCamera].dir, x, y);
        flagOneDir(Camera[numOfCamera].dir+1, x, y);
        break;
    case CCTV4:
        flagOneDir(Camera[numOfCamera].dir, x, y);
        flagOneDir(Camera[numOfCamera].dir+1, x, y);
        flagOneDir(Camera[numOfCamera].dir+3, x, y);
        break;
    case CCTV5:
        flagOneDir(Camera[numOfCamera].dir, x, y);
        flagOneDir(Camera[numOfCamera].dir+1, x, y);
        flagOneDir(Camera[numOfCamera].dir+2, x, y);
        flagOneDir(Camera[numOfCamera].dir+3, x, y);
        break;
    default:
        break;
    }
}

void dfs(int checkedCamera){
    // Check end condition
    if (checkedCamera == cameraNum){
        findMin();
        /*
        Output_map();
        cout << Camera[0].dir << endl;
        cout << Camera[1].dir << endl;
        cout << Camera[2].dir << endl;
        cout << ++count2 << ": "<<result << endl;
        */

        return;
    }

    int temp[MAX_N][MAX_M];

    memcpy(temp,map,sizeof(map));
    // check each dir
    for (int d = 0; d < 4; ++d){


        int tempX = Camera[checkedCamera].X;
        int tempY = Camera[checkedCamera].Y;

        Camera[checkedCamera].dir = d;
        flagArea(tempX,tempY,checkedCamera);
        dfs(checkedCamera+1);
        memcpy(map,temp,sizeof(map));
    }
}

int main(void)
{
    // Input map
    cin >> N >> M;
    input_map();
    dfs(0);

    cout << result << endl;
    //getchar();
    //getchar();
    return 0; 
}
