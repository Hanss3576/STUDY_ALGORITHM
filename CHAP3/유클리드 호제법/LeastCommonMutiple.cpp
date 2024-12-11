#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a , long long b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}
int main(){
    int N;
    cin >> N;
    vector<long long> nums(N);
    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }
    long long gcds = gcd(nums[0], nums[1]);
    long long lcm = nums[0];
    for (int i = 1; i < N; i ++){
        gcds = gcd(lcm, nums[i]);
        lcm = (nums[i] / gcds) * lcm;
    }
    cout << lcm;
}