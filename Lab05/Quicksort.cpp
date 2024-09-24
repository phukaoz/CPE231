#include <bits/stdc++.h>

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
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for(int& x : v)
    {
        std::cin >> x;
    }

    QuickSort(v, 0, n-1);
    for(int& x : v)
    {
        std::cout << x << ' ';
    }
}