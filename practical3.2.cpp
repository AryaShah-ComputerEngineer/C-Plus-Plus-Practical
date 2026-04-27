#include <iostream>
#include <vector>
using namespace std;

long long recSteps = 0;
long long itrSteps = 0;

long long recSum(vector<int>& a, int l, int r) {
    recSteps++;
    if (l > r) return 0;
    if (l == r) return a[l];
    int m = (l + r) / 2;
    return recSum(a, l, m) + recSum(a, m + 1, r);
}

long long itrSum(vector<int>& a) {
    long long s = 0;
    for (int i = 0; i < a.size(); i++) {
        itrSteps++;
        s += a[i];
    }
    return s;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long r = recSum(arr, 0, n - 1);
    long long i = itrSum(arr);

    cout << r << endl;
    cout << i << endl;
    cout << recSteps << endl;
    cout << itrSteps << endl;

    return 0;
}