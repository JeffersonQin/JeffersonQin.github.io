#include <iostream>

using namespace std;

const int MAXN = 100005;

int n;
int a[MAXN], temp[MAXN];

template<typename T>
void merge_sort(T arr, T temp, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(arr, temp, l, mid);
    merge_sort(arr, temp, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
        temp[k ++] = arr[i] < arr[j] ? arr[i ++] : arr[j ++];
    while (i <= mid)
        temp[k ++] = arr[i ++];
    while (j <= r)
        temp[k ++] = arr[j ++];
    for (register int i = l; i <= r; i ++) arr[i] = temp[i];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    merge_sort(a, temp, 1, n);
    for (int i = 1; i <= n; i ++) cout << a[i] << " ";
    cout << endl;
    return 0;
}