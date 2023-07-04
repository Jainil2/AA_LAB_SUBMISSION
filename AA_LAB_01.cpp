#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int p, int r, int &c)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        c++;
        if (arr[j] <= x)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int random_partition(int arr[], int p, int r, int &c)
{
    int i = rand() % (r - p + 1) + p;
    swap(arr[i], arr[r]);
    return (partition(arr, p, r, c));
}

void quick_sort(int arr[], int p, int r, int &c)
{
    if (p < r)
    {
        int q = random_partition(arr, p, r, c);
        quick_sort(arr, p, q - 1, c);
        quick_sort(arr, q + 1, r, c);
    }
}

int main()
{
    int count1 = 0, count2 = 0, count3 = 0;

    srand(time(0));
    int *arr1 = new int[1000];
    for (int i = 0; i < 1000; i++)
    {
        arr1[i] += i;
    }
    int *arr2 = new int[1000];
    for (int i = 999; i >= 0; i--)
    {
        arr2[i] += i;
    }

    int arr3[] = {1, 3, 4, 2, 7, 8, 9, 0, 5, 6, 5, 6, 2, 7, 8, 2, 5, 8, 4, 99, 11, 24, 73, 573, 293, 19237, 452, 18345, 173, 4732, 3468, 111};
    int p = 0;
    auto t_start1 = std::chrono::high_resolution_clock::now();
    quick_sort(arr1, p, 999, count1);
    auto t_end1 = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms1 = std::chrono::duration<double, std::milli>(t_end1 - t_start1).count();
    cout << "Time for arr1 : " << elapsed_time_ms1 << endl;

    auto t_start2 = std::chrono::high_resolution_clock::now();
    quick_sort(arr2, p, 999, count2);
    auto t_end2 = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms2 = std::chrono::duration<double, std::milli>(t_end2 - t_start2).count();
    cout << "Time for arr2 : " << elapsed_time_ms2 << endl;

    auto t_start3 = std::chrono::high_resolution_clock::now();
    quick_sort(arr3, p, sizeof(arr3) / sizeof(arr3[0]), count3);
    auto t_end3 = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms3 = std::chrono::duration<double, std::milli>(t_end3 - t_start3).count();
    cout << "Time for arr3 : " << elapsed_time_ms3 << endl;
    cout << endl;

    cout << "count of comparisons in arr1: " << count1 << endl;
    cout << "count of comparisons in arr2: " << count2 << endl;
    cout << "count of comparisons in arr3: " << count3 << endl;
    cout << endl;

    for (int i = 0; i < 1000; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << endl;
    for (int i = 0; i < 1000; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << endl;
    for (int i = 0; i < (int)(sizeof(arr3) / sizeof(arr3[0])); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    cout << endl;
    return 0;
}
