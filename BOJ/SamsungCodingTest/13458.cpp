/* 13458 */
#include <iostream>
#include <vector>
using namespace std;

int B, C;
long long int sum;
/* 총감독관: B 부감독관: C*/

int main (){
    int N = 0;
    vector<int> room;
    int temp;
    cin >> N;
    room.resize(N);
    /* input number of student */
    for (int i = 0; i < N; ++i){
        cin >> room[i];
    }
    sum += N;

    cin >> B >> C;

    for (int i = 0; i < N; ++i) {
        int cur = 0;
        temp = room[i]-B;

        if (temp <= 0 ){
            continue;
        }
        else if (temp % C){
            cur = (temp/C) + 1;
        }
        else {
            cur = temp/C;
        }
        sum += cur;
    }

    cout << sum <<endl;

    return 0;
}