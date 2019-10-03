/* 12100 */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

enum _edir{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

int map[21][21];
int N;
int result=-1;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void input_map(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
        }
    }
}

void checkMax(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (result<=map[i][j]){
                /* No operation */
                result = map[i][j];
            }
            else{
                
            }
        }
    }
}

void moveBlock (queue <int> &q, int indexX, int indexY, int dir){
    while(!q.empty()){
        /* Check block */
        if(map[indexY][indexX]) {
            /* If value is same */
            if (map[indexY][indexX]==q.front()){
                map[indexY][indexX] += q.front();
                q.pop();
            }
            indexX += dx[dir];
            indexY += dy[dir];
            
        }
        else {
            map[indexY][indexX] = q.front();
            q.pop();
        }
    }
}

void dfs(int level){
    // Stop condition
    if(level == 5){
        //Check max value
        checkMax();
        return;
    }

    int temp[21][21];

    // Move block (4ways)
    for (int d = 0; d < 4; ++d){

        // back up map
        memcpy(temp,map,sizeof(map));

        // Move block (select col)
        queue<int> q;
        for (int i = 0; i < N; ++i){
            // Check dir
            switch (d)
            {
                /* queue data */
                case LEFT:
                    /* Left to Right */
                    for (int j=0; j<N; j++){
                        /* If data is exist */
                        if (map[i][j]) q.push(map[i][j]);
                        map[i][j] = 0;
                    }
                    /* Move block */
                    moveBlock(q,0,i,RIGHT);
                    break;
                case RIGHT:
                    /* Right to left */
                    for (int j=N-1; j>=0; j--){
                        /* If data is exist */
                        if (map[i][j]) q.push(map[i][j]);
                        map[i][j] = 0;
                    }
                    /* Move block */
                    moveBlock(q,N-1,i,LEFT);
                    break;
                case UP:
                    /* Up to Down */
                    for (int j=0; j<N; j++){
                        /* If data is exist */
                        if (map[j][i]) q.push(map[j][i]);
                        map[j][i] = 0;
                    }
                    /* Move block */
                    moveBlock(q,i,0,DOWN);
                    break;
                default:
                    /* Down to Up */
                    for (int j=N-1; j>=0; j--){
                        /* If data is exist */
                        if (map[j][i]) q.push(map[j][i]);
                        map[j][i] = 0;
                    }
                    /* Move block */
                    moveBlock(q,i,N-1,UP);
                    break;
            }
        }
    // Call Next level
    dfs(level+1);

    //restore map
    memcpy(map,temp,sizeof(map));
    }
}

int main(void)
{
    // Input map
    cin >> N;
    input_map();

    //dfs
    dfs(0);

    cout << result <<endl;

    getchar();

    getchar();
    return 0;
}
