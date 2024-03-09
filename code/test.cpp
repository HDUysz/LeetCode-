#include<bits/stdc++.h>
#include<cmath>

using namespace std;

#define BigNum 1000000

int main() {
  double res = 1;
  long long n = BigNum;
  for (long long i = 1; i <= n; i++) {
    res *= (1 + static_cast<double>(i) / pow(2, i));
  }

  cout << "Res: " << res << endl;
}
