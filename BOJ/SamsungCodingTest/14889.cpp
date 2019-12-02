#include <iostream>
#include <vector>
using namespace std;

int N;
int status[20][20];
int visited[20];
int count;
int result=1e9;

void input(){
    cin >> N;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> status[i][j];
        }
    }
}

void dfs(int index){

    if ( index == N && count==N/2){
        vector<int> a,b;
        /* 모든 원소를 분류했을 경우 */
        for (int i = 0; i < N; ++i){
            if (visited[i]) a.push_back(i); //분류된 숫자를 넣기.
            else b.push_back(i);
        }
        int suma = 0;
        for (int i = 0; i<N/2; ++i){
            for (int j = 0; j<N/2; ++j){
                suma+=status[a[i]][a[j]];
            }
        }
        int sumb = 0;
        for (int i = 0; i<N/2; ++i){
            for (int j = 0; j<N/2; ++j){
                sumb+=status[b[i]][b[j]];
            }
        }
        result = min(result,abs(suma-sumb));
        return;
    }
    else if(index == N){
        return;
    }

    visited[index] = true;
    count++;
    dfs(index+1);
    count--;
    visited[index] = false;
    dfs(index+1);
}

int main (){

    input();
    dfs(0);
    cout << result << endl;

    return 0;
}