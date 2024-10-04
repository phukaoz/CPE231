#include <bits/stdc++.h>

using namespace std;

int HoarePartition(std::vector<int>& array, int l, int r)
{
    int p = array[l];
    int i = l;
    int j = r+1;
    while(i < j)
    {
        while(1)
        {
            i++;
            if(array[i] >= p) break;
        }
        

        while(1)
        {
            j--;
            if(array[j] <= p) break;
        }

        std::swap(array[i], array[j]);
    }
    std::swap(array[i], array[j]);
    std::swap(array[l], array[j]);

    return j;
}

void QuickSort(std::vector<int>& array, int l, int r)
{
    if(l < r)
    {
        int s = HoarePartition(array, l, r);
        QuickSort(array, l, s-1);
        QuickSort(array, s+1, r);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    QuickSort(v, 0, n-1);

    for(int i=0;i<n;i++){
        if(v[i] != v[i+1])
            cout << v[i] << ' ';
    }
}