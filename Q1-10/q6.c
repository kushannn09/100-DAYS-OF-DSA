/*You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.*/
int missingNum(int *arr, int size) {
    long long expected = (long long)(size + 1) * (size + 2) / 2;
    long long sum = 0;  
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return expected - sum;
}
