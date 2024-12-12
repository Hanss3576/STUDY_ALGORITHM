/*
N개의 카드가 존재할때, 각 카드(Ai)는 1~99999 사이의 숫자를 가지고 있다.
이때, 2개의 카드를 뽑고, 각 카드에 적힌 숫자의 합이 10e4가 되는 경우의 수를 구하시오.
N(1<=N<=200000)과 Ai는 입력를 받는다.
실행 제한 시간은 1초이다.
*/ 

#include <iostream>
#include <map>
#define SUM 100000

using namespace std;

long long factorial(int n){
    if(n==0 || n == 1)
        return 1;
    long long res = 1;
    
    for (int i = 2; i <= n; i++){
        res *= i;
    }
    return res;
}
long long combination(int n , int r){
    if (n==r)
        return 1;
    if (r==2)
        return n * (n - 1) / 2;
    long long res;
    res = (factorial(n) / factorial(r)) / factorial(n - r);
    return res;
}

int main(){
    int N;
    cin >> N;
    map<int, int> A;

    for (int i = 0; i < N; i++)
    {
        int keys;
        cin >> keys;
        A[keys]++; // O(logN)
    }

    long long res = 0;
    for(auto m : A){
        if(m.second == 0)
            continue;
        if (m.first == SUM / 2)
        {
            res += (long long)combination(m.second, 2);
            continue;
        }
        else
        {
            int pair = SUM - m.first;
            if(A.find(pair) == A.end()){ // SUM 충족시키는 값이 없다면 pass
                continue;
            } //존재한다면 res += m.second * A[pair] (만족시키는 각 카드들의 더미에서 하나씩 선택함으로)
            res += (long long)(m.second * A[pair]);
            A[pair] = 0; // 중복방지
        }
    }
    cout << res << endl;
}