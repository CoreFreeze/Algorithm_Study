#include <iostream>
#include <vector>
using namespace std;

int N;
int A[11];
bool visited[10];
int op[10];
vector<int> v;
int resultMax = -1e9;
int resultMin = 1e9;
int sum;

void input(){
    cin >> N;

    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }

    for (int i = 1,j = 0, count; i < 5; ++i){
        cin >> count;
        for (;count > 0; count--, ++j) op[j] = i;
    }
}

void dfs(){

    if(v.size() == N-1){
        sum+=A[0];
        for (int i = 0; i < N-1; ++i ){
            switch (v[i])
            {
                case 1:
                    sum = sum + A[i+1];
                    break;
                case 2:
                    sum = sum - A[i+1];
                    break;
                case 3:
                    sum = sum * A[i+1];
                    break;
                case 4:
                    sum = sum / A[i+1];
                    break;
                default:
                    break;
            }
        }
        resultMin = min(resultMin, sum);
        resultMax = max(resultMax, sum);
        sum = 0;
        return;
    }

    for (int i = 0; i < N-1; ++i){
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(op[i]);
        dfs();
        v.pop_back();
        visited[i] = false;
    }

}

int main (){

    input();
    dfs();

    cout << resultMax << '\n';
    cout << resultMin << '\n';

    return 0;
}