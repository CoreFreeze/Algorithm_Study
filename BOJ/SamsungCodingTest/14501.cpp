#include <iostream>
#include <vector>
using namespace std;
#define MAX 15

int N; 
int T[MAX]; 
int P[MAX];
int result;
vector<int> v;

void checkSum(int index, int sum,int addValue){

    if (index >= N){
        if(index==N) sum+=addValue;
        result = max(result, sum);
        return;
    }

    sum+=addValue;

    for (int i = index; i < N; ++i){
        checkSum(i+T[i],sum, P[i]);
    }
}

int main (){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> P[i];
    }

    checkSum(0,0,0);

    cout << result <<'\n';

    return 0;
}