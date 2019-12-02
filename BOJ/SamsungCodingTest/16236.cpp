#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[20][20];
int time;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

struct shark{
    int x;
    int y;
    int size;
    int ate;
    shark(int x, int y):x(x),y(y),size(2),ate(0){}
};
struct Node{
    int x;
    int y;
    int count;
    Node(int x, int y,int count):x(x),y(y),count(count){}
};

bool isPossible(int x, int y){
    return !((0>x)||(0>y)||(x>=N)||(y>=N));
}


struct shark s = shark(0,0);

int check(){
    int posX = s.x;
    int posY = s.y;
    bool visited[20][20];
    fill(&visited[0][0],&visited[19][20],false);
    visited[posY][posX] = true;
    queue<Node> q;
    q.push(Node(posX,posY,0));
    bool found = false;
    Node temp = Node(0,0,1e9);
    while(!q.empty()){
        posX = q.front().x;
        posY = q.front().y;
        int count = q.front().count;
        q.pop();

        if ((map[posY][posX]<s.size)&&(map[posY][posX]!=0)){
            /* 이동, 먹기 */
            if (temp.count > count){
                temp.y=posY;
                temp.x=posX;
                temp.count = count;
            }
            else if (temp.count == count){
                if (temp.y > posY) {
                    temp.y=posY;
                    temp.x=posX;
                }
                else if (temp.y == posY) {
                    if (temp.x > posX) {
                        temp.y=posY;
                        temp.x=posX;
                    }
                }
            }
            found = true;
            continue;
        }
        else if (map[posY][posX] > s.size){
            continue;
        }

        for (int i = 0; i < 4; ++i){
            int tempX = posX + dx[i];
            int tempY = posY + dy[i];
            if((!isPossible(tempX,tempY))||(visited[tempY][tempX])) continue;
            visited[tempY][tempX] = true;
            q.push(Node(tempX,tempY,count+1));
        }
    }
    if (found){
        map[temp.y][temp.x] = 0;
        s.x = temp.x;
        s.y = temp.y;
        s.ate += 1;
        if(s.ate==s.size) {
            s.size += 1;
            s.ate = 0;
        }
        return temp.count;
    }
    return 0;
}

int main (){

    cin >> N;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> map[i][j];
            if (map[i][j]==9){
                s.x = j;
                s.y = i;
                map[i][j]=0;
            }
        }
    }
    /* check */

    while (1){
        int temp=0;
        if ((temp = check())!=0) time+=temp;
        else break;
    }

    cout << time << endl;

    return 0;
}
