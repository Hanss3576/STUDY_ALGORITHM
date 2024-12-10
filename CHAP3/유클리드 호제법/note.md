## 유클리드 호제법

```cpp 
int gcd(int a, int b){
  while(b){
    a %= b;
    swap(a,b);
  }
  return a;
}
```

### 이해하기
두 수 A,B가 있다고 하자(A,B는 모두 양의 정수)  
이때 A,B의 최대공약수를 d라고 할때, `A = ad(a!=0), B = bd(b!=0)`라고 할 수 있다.  
이때 A보다 B가 더 크다고 가정하고, `B = QA + R` → ***`B % A = R`*** 이라고 할 수 있다.  
`R = B - QA = bd - Qad = d(b - Qa)`라고 할 수 있다.  
그렇기에, `gcd(A,B) = d` 이고 `gcd(A,R) = d`이다.

### 활용!
- N개의 수의 최대공약수 구하기
- N개의 수의 최소공배수 구하기
