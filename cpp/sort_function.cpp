#include <iostream>
#include <math.h>
#include <string>
#include <functional>
#include <ctime>
using namespace std;

int *get_array(int arr[], int n) {
    int *newArray = new int[n];
    for (int i = 0; i < n; i++) *(newArray + i) = arr[i];
    return newArray;
}


int *selection_sort(int a[], int n) {
    int *arr = get_array(a, n);
    for (int i = 0; i < n - 1; i ++) {
        int pos = i;
        for (int j = i + 1; j < n; j ++) {
            if (*(arr + j) < *(arr + pos)) {
                    pos = j;
            }
        }
        swap(*(arr + pos), *(arr + i));
    }

    return (arr);
}

int *insertion_sort(int a[], int n) {
    int *arr = get_array(a, n);
    for (int i = 1; i < n; i ++) {
        int key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j -= 1;
        }
        *(arr + j + 1)= key;
    }

    return (arr);
}
int *binary_insertion_sort(int a[], int n) {
    int *arr = get_array(a, n);

    auto binarySearch = [](int a[], int key, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (key == *(a + mid)) return mid + 1;
                else if (key > *(a + mid)) low = mid + 1;
                    else high = mid - 1;
        }
        return low;
    };

    int i, loc, j, k, selected;
    for (int i = 1; i < n; i++) {
        j = i - 1;
        selected = *(arr + i);
        loc = binarySearch(arr, selected, 0, j);

        while (j >= loc) {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = selected;
    }

    return (arr);
}

int *bubble_sort(int a[], int n) {
    int *arr = get_array(a, n);
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }

    return (arr);
}

int *shaker_sort(int a[], int n) {
    int *arr = get_array(a, n);
    int low = 0;
    int high = n - 1;
    int k = 0;
    while (low < high) {
        for (int i = low; i < high; i++) {
            if (*(arr + i) > *(arr + i + 1)) {
                swap(*(arr + i), *(arr + i + 1));
                k = i;
            }
        }
        high = k;
        for (int i = high; i > low; i --) {
            if (*(arr + i) < *(arr + i - 1)) {
                swap(*(arr + i), *(arr + i - 1));
                k = i;
            }
        }
        low = k;
    }

    return (arr);
}

int *shell_sort(int a[], int n){
    int *arr = get_array(a, n);
    int interval, temp, i, j;
    for (interval = n / 2; interval > 0; interval /= 2){
        for (i = interval; i < n; i ++) {
            temp = *(arr + i);
            for (j = i; j >= interval && *(arr + j - interval) > temp; j -= interval){
                *(arr + j) = *(arr + j - interval);
            }
            *(arr + j) = temp;
        }
    }

    return (arr);
}

int *heap_sort(int a[], int n) {
    int *arr = get_array(a, n);
    auto heapify = [&](int *arr, int n, int i, auto&& heapify) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && *(arr + largest) < *(arr + left)) largest = left;
        if (right < n && *(arr + largest) < *(arr + right)) largest = right;

        if (i == largest) return;
            else {
                swap(*(arr + largest), *(arr + i));
                heapify(arr, n, largest, heapify);
        }
    };

    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, heapify);
    for (int i = n - 1; i >= 0; i--) {
        swap(*(arr + 0), *(arr + i));
        heapify(arr, i, 0, heapify);
    }

    return (arr);
}

int *merge_sort(int a[], int n) {
    int *arr = get_array(a, n);
    auto merge_ = [](int *arr, int left, int mid, int right) {
        int n1 = (mid - left + 1);
        int n2 = right - mid;
        int l[n1], r[n2];
        //khoi tao 2 mang trai va phai
        for (int i = 0; i < n1; i++) l[i] = *(arr + i + left);
        for (int i = 0; i < n2; i++) r[i] = *(arr + i + mid + 1);
        //swap
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (l[i] <= r[j]) {
                *(arr + k) = l[i];
                i++;
            } else {
                *(arr + k) = r[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            *(arr + k) = l[i];
            i++;
            k++;
        }
        while (j < n2) {
            *(arr + k) = r[j];
            j++;
            k++;
        }
    };

    auto mergeSort = [&](int *arr, int left, int right, auto && mergeSort) {
        if (left >= right) return;
            else {
                int mid = (left + right) / 2;
                mergeSort(arr, left, mid, mergeSort);
                mergeSort(arr, mid + 1, right, mergeSort);
                merge_(arr, left, mid, right);
        }
    };

    mergeSort(arr, 0, n - 1, mergeSort);

    return (arr);
}

int *quick_sort(int a[], int n) {
    int *arr = get_array(a, n);

    auto Partition = [](int arr[], int left, int right) {
        int pivot = right;
        int j = left - 1;
        for (int i = left; i < right; i++)
            if (arr[i] <= arr[pivot]) {
                j++;
                swap(arr[i], arr[j]);
        }
        swap(arr[j+1], arr[pivot]);
        return j + 1;
    };

    auto Quick_Sort = [&](int arr[], int left, int right, auto &&Quick_Sort) {
        if (left >= right) return;
            else {
                int pivot = Partition(arr, left, right);
                Quick_Sort(arr, left, pivot - 1, Quick_Sort);
                Quick_Sort(arr, pivot + 1, right, Quick_Sort);
        }
    };

    Quick_Sort(arr, 0, n - 1, Quick_Sort);

    return (arr);
}

int *counting_sort(int a[], int n) {
    int *arr = get_array(a, n);
    int output[n];
    int Max = *(arr + 0);
    int Min = *(arr + 0);

    for (int i = 1; i  < n; i++) {
        if (*(arr + i) > Max) {
            Max = *(arr + i);
        } else if (*(arr + i) < Min) {
            Min = *(arr + i);
        }
    }

    int k = Max - Min + 1;

    int count_array[k] = {0};

    for (int i = 0; i < n; i ++) {
        count_array[*(arr + i) - Min]++;
    }

    for (int i = 1; i < k; i ++) {
        count_array[i] += count_array[i - 1];
    }

    for (int i = 0; i < n; i ++) {
        output[count_array[*(arr + i) - Min] - 1] = *(arr + i);
        count_array[*(arr + i) - Min]--;
    }

    for (int i = 0; i < n; i ++) *(arr + i) = output[i];

    return (arr);
}

int *radix_sort(int a[], int n) {
    int *arr = get_array(a, n);

    auto getMax = [](int *arr, int n) {
        int _max_ = *(arr + 0);
        for (int i = 1; i < n; i++)
            if (*(arr + i) > _max_) _max_ = *(arr + i);
        return _max_;
    };

    auto countSort = [](int *arr, int n, int exp){
        int output[n];
        int cnt[10] = {0};
        for (int i = 0; i < n; i ++) {
            cnt[(arr[i] / exp) % 10] ++;
        }

        for (int i = 1; i < 10; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[cnt[(*(arr + i) / exp) % 10] - 1] = *(arr + i);
            cnt[(*(arr + i) / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) *(arr + i) = output[i];
    };

    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) countSort(arr, n, exp);

    return (arr);
}

int *flash_sort(int a[], int n) {
    int *arr = get_array(a, n);

    int m = (0.45 * n);
    int b[n]{0}; // amount of bucket
    int Max = 0;
    int Min = *(arr + 0);

    for (int i = 0; i < n; i ++) {
        Max = max(Max, *(arr + i));
        Min = min(Min, *(arr + i));
    }

    for (int i = 0; i < n; i ++) {
        int k = (m - 1)*(*(arr + i) - Min) / (Max - Min);
        b[k] += 1;
    }

    for (int i = 1; i < m; i++) b[i] += b[i-1];

    int hold = *(arr + 0);
    int Move = 0;
    int flash = 0;
    int k = 0, t = 0, j = 0;

    while (Move < n - 1) {
        while (j > (b[k] - 1)) {
            j ++;
            k = (m - 1) * (*(arr + j) - Min) / (Max - Min);
        }

        flash = *(arr + j);
        while (j != b[k]) {
            k = (m - 1) * (*(arr + j) - Min) / (Max - Min);
            t = --b[k];
            hold = *(arr + t);
            *(arr + t) = hold;
            flash = hold;
            Move ++;
        }
    }

    for (int j = 1; j < n; j ++) {
        hold = *(arr + j);
        int i = j - 1;
        while (i >= 0 && *(arr + i) > hold) {
            *(arr + i + 1) = *(arr + i--);
        }
        *(arr + i + 1) = hold;
    }
    return arr;
}
