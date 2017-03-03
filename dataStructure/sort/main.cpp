#include <iostream>
#include <vector>

using namespace std;
// bubble sort
void bubbleSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n-1; i++) {
        bool flag = true;
        for (int j = n-1; j >= i+1; j--) {
            if (nums[j-1] > nums[j]) { // steady
                int tmp = nums[j-1];  // swap(nums[j-1], nums[j]);
                nums[j-1] = nums[j];
                nums[j] = tmp;
                flag = false;
            }
        }
        if (flag) break;
    }
}


// insertion sort
void insertSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (nums[j] >= nums[j-1]) break;  // steady
            else swap(nums[j], nums[j-1]);
        }
    }
}

// selection sort
void selectSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n-1; i++) {
        int idx = i;
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[idx]) idx = j; // steady
        }
        if (idx != i) swap(nums[i], nums[idx]);
    }
}

// merge sort
void merge(vector<int> &nums, int start, int mid, int end) {
    vector<int> tmp(end-start, 0);
    int i = start, j = mid;
    int idx = 0;
    while (i<mid && j<end) {
        if (nums[i] <= nums[j]) tmp[idx++] = nums[i++];
        else tmp[idx++] = nums[j++];
    }
    if (i < mid) while (i < mid) tmp[idx++] = nums[i++];
    else while(j < end) tmp[idx++] = nums[j++];
    idx = 0;
    for (int i = start; i < end; i++) nums[i] = tmp[idx++];
}

void mergeSort(vector<int> &nums) {
    int n = nums.size();
    int base = 1;
    while (base < n) {
        int start = 0;
        while (start < n) { 
            if (start+2*base <= n) {
                merge(nums, start, start+base, start+2*base);
            }else if (start+base < n) merge(nums, start, start+base, n);
            start += 2*base;
        }
        base *= 2;
    }
}

void mergeRecursion(vector<int> &nums, int start, int end) {
    if (end-start == 1) return;
    int mid = start + (end-start)/2;
    mergeRecursion(nums, start, mid);
    mergeRecursion(nums, mid, end);

    vector<int> tmp(end-start);
    int i = start, j = mid, idx = 0;
    while (i<mid && j<end) {
        if (nums[i] <= nums[j]) tmp[idx++] = nums[i++];
        else tmp[idx++] = nums[j++];
    }
    while (i < mid) tmp[idx++] = nums[i++];
    while (j < end) tmp[idx++] = nums[j++];
    idx = 0;
    for (int i = start; i < end; i++) nums[i] = tmp[idx++];
}

void quickSort(vector<int> &nums, int start, int end) {
    if (end -start <= 1) return;
    int mid = start + (end-start)/2;
    swap(nums[start], nums[mid]);
    int pivot = start+1;
    for (int i = start+1; i < end; i++) {
        if (nums[i] < nums[start]) {
            swap(nums[pivot], nums[i]);
            pivot++;
        }
    }
    pivot--;
    swap(nums[start], nums[pivot]);
    quickSort(nums, start, pivot);
    quickSort(nums, pivot+1, end);
}

void heapFixUp(vector<int> &nums, int end) {
    int i = end, j = (i-1)/2;
    while (j <= 0) {
        if (nums[j] >= nums[i]) break;
        swap(nums[j], nums[i]);
        i = j;
        j = (i-1)/2;
    }
}

void heapFixDown(vector<int> &nums, int start, int n) {
    int i = start, j = 2*i+1;
    while (j < n) {
        if (j+1<n && nums[j+1] > nums[j]) j++;
        if (nums[i] >= nums[j]) break;
        swap(nums[i], nums[j]);
        i = j;
        j = 2*i+1;
    }
}

void makeMaxHeap(vector<int> &nums) {
    int n = nums.size();
    for (int i = (n-1)/2; i >= 0; i--) heapFixDown(nums, i, n);
}

void heapSort(vector<int> &nums) {
    makeMaxHeap(nums);
    int n = nums.size();
    for (int i = n-1; i >= 1; i--) {
        swap(nums[i], nums[0]);
        heapFixDown(nums, 0, i);
    }
}

int main(int argc, char**argv){
    vector<int> nums{99, 23, 89, 4 ,5, -13, 87, 98, 9, -908, 2345, 765, 879, 98};
    //quickSort(nums, 0, nums.size());
    heapSort(nums); 
    
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    
    return 0;
}
