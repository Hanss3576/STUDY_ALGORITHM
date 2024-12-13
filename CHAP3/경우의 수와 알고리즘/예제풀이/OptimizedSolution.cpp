#include <iostream>
#include <vector>
#define SUM 100000

/*
N개의 카드가 존재할때, 각 카드(Ai)는 1~99999 사이의 숫자를 가지고 있다.
이때, 2개의 카드를 뽑고, 각 카드에 적힌 숫자의 합이 10e4가 되는 경우의 수를 구하시오.
N(1<=N<=200000)과 Ai는 입력를 받는다.
실행 제한 시간은 1초이다.
*/ 

using namespace std;
long long combination(int n, int r){
    long long res = 1;
    if (r == 0 || r == n)
        return res;
    else if (r == 2)
        return (long long)n * (n - 1)/2;
    r = min(r, n - r); // r = n - r > r ? r : n - r;
    for (int i = 1; i <= r; i++){
        res *= (n + 1 - i);
        res /= (long long) i;
    }
    return res;
}
int main()
{
    int N;
    cin >> N;
    vector<int> cards(100001, 0);
    for (int i = 0; i < N; i++){
        int val;
        cin >> val;
        cards[val]++;
    }
    long long res = 0;
    for (int i = 1; i < SUM / 2; i++)
    {
        if(cards[i] == 0 || cards[SUM-i]==0)
            continue;
        res += (cards[i] * cards[SUM - i]);
    }
    if(cards[SUM/2] > 1)
     res += combination(cards[SUM / 2], 2);
    cout << res;
    return 0;
}
