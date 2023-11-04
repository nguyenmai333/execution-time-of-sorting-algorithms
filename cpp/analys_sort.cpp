#include <vector>
#include <iomanip>
#include "get_sort.h"
#include <chrono>
const int inputSize = 4;
const int AmountOfState = 3;

int test_run[inputSize + 2] = {1000, 3000, 10000, 30000, 100000};
string states[AmountOfState + 1] = {"Random", "Sorted", "Reversed"};
vector <float> vect;

int get_element() {
    return rand() % 100000;
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void create_array(int arr[], int n, string state) {
    if (state == "Random") {
        for (int i = 0; i < n; i ++) arr[i] = get_element();
    } else if (state == "Sorted") {
        for (int i = 0; i < n; i++) arr[i] = i;
    } else if (state == "Reversed") {
        for (int i = 0; i < n; i++) arr[i] = n - i - 1;
    }
}

void get_sort(int arr[], int n) {
    int *res;
    clock_t tStart = clock();
    res = selection_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = insertion_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = binary_insertion_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = bubble_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = shaker_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = shell_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = heap_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = merge_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = quick_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = counting_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = radix_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
    tStart = clock();
    res = flash_sort(arr, n);
    vect.push_back(float((clock() - tStart))/float((CLOCKS_PER_SEC))); free(res);
}

void get_ExecutionTime() {
    for (int i = 0; i < AmountOfState; i++) {
        for (int j = 0; j < inputSize; j++) {
            int n = test_run[j];
            int arr[n];
            create_array(arr, n, states[i]);
            get_sort(arr, n);
        }
    }
    //output
    cout << "Input State, Input Size, Selection, Insertion, Binary Insertion, Bubble, Shaker, Shell, Heap, Merge, Quick, Counting, Radix, Flash\n";
    for (int i = 0; i < AmountOfState; i++) {
        for (int j = 0; j < inputSize; j++) {
            cout << states[i] << ", " << test_run[j] << ", ";
            for (int k = 0; k < 12; k++) {
                cout << setprecision(3) << fixed <<vect[12*i*inputSize+12*j+k] << ", ";
            }
            cout << endl;
        }
    }
}

int main() {
    srand(time(NULL));
    get_ExecutionTime();
}
