#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    while(a>= 1 && b>=1){
        if(a>b)
            a = a % b;
        else // a <= b;
            b = b % a;
    }
    if(a >=1)
        return a;
    return b;
}

int main(){
    
    //N개의 수의 최대 공약수를 구하기 (유클리드 호제법)
    int N;
    cin >> N;

    vector<long long> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    long long gcds = gcd(nums[0], nums[1]);
    for (int i = 2; i < N; i++)
    {
        gcds = gcd(gcds, nums[i]);
        if(gcds == 1)
            break;
    }
    cout << gcds << endl;
    return 0;
}