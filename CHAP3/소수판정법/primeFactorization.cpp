#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int N;
    vector<int> primeFactor;

    cin >> N;
    if(N == 1)
        return 0;
    int LIMIT = sqrt(N);
    int divisor = 2;
    
    while (divisor <= LIMIT)
    {
        if (N % divisor == 0)
        {
            primeFactor.push_back(divisor);
            // cout << "N : " << N << " / divisor : " << divisor << endl;
            N = N / divisor;
            continue;
        }
        else{
            divisor++;
        }
    }

    if(N>LIMIT){
        primeFactor.push_back(N);
    }

    // if(primeFactor.empty())
    //     primeFactor.push_back(N);

    vector<int>::iterator ptr;
    for (ptr = primeFactor.begin(); ptr != primeFactor.end(); ++ptr){
        cout << *ptr << endl;
    }
}