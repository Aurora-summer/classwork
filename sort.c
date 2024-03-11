#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mergeSort(int arr[], int begin, int end);
void merge(int arr[], int begin, int mid, int end);
void  InsertSort(int arr[], int n);
void BubbleSort(int arr[], int n);
int Partition(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high);
void SelectSort(int arr[], int n);
//数组输出
void func(int arr[], int n);
int main() {
    clock_t begin_time = clock();
    int n = 100;
    srand((unsigned int)time(0));
    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr) {
        for (int i = 0; i < n; i++) arr[i] = rand() % n + 1;
    }
    else printf("空间申请失败\n");
    //int arr[] = {7,6,5,4,3,2,1};
    //int n = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, n - 1);
    //InsertSort(arr, n);
    //BubbleSort(arr, n);
    //QuickSort(arr, 0, n - 1);
    SelectSort(arr, n);
    clock_t end_time = clock();
    int time = (end_time - begin_time);
    printf("time=%d\n", time);
    return 0;
}
//数组的输出
void func(int arr[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        printf("%4d", arr[i]);
        cnt++;
        if (cnt % 10 == 0) printf("\n");
    }
}
//选择排序
void SelectSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int t = i;
        int min = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                t = j;
            }
        }
        arr[t] = arr[i];
        arr[i] = min;
    }
}
//快速排序
int Partition(int arr[], int low, int high) {
    int t = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= t) high--;
        arr[low] = arr[high];
        while (low < high && arr[low] <= t) low++;
        arr[high] = arr[low];
    }
    arr[low] = t;
    return low;
}
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int c = Partition(arr, low, high);
        QuickSort(arr, low, c - 1);
        QuickSort(arr, c + 1, high);
    }
}
//冒泡排序
void BubbleSort(int arr[], int n) {
    int cnt = 0;
    for (int m = 1; m <= n - 1; m++) {
        cnt = 0;
        for (int j = 0; j < n - m; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                cnt++;
            }//if
        }//for j
        if (cnt == 0) break;
    }//for m
}
//插入
void  InsertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int t = arr[i];
        int j = i - 1;
        for (j; j >= 0; j--) {
            if (arr[j] > t) arr[j + 1] = arr[j];
            else break;
        }
        arr[j + 1] = t;
    }
}
//归并
void mergeSort(int arr[], int begin, int end) {
    int mid = (end + begin) / 2;
    if (end > begin) {
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}
void merge(int arr[], int begin, int mid, int end) {
    int* temp = (int*)malloc(sizeof(int) * (end - begin + 1));
    if (temp) {
        int i = begin;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= end) {
            if (arr[i] < arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }
        if (i <= mid)
            for (i; i <= mid; i++) temp[k++] = arr[i];
        if (j <= end)
            for (j; j <= end; j++) temp[k++] = arr[j];
        k = 0;
        for (int t = begin; t <= end; t++) arr[t] = temp[k++];
        //free(temp);

    }
}
