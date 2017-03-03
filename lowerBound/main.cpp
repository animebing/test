#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &nums, int target) {
    int low = 0, high = nums.size(); // high not be nums.size() to void that all elements less than target, then nums.size() return
    while (low < high) {  // if low <= high, maybe infinite loop
        //cout << "bingbing" << endl;
        int mid = low + (high-low)/2;
        if (target > nums[mid]) low = mid+1;
        else high = mid;
    }
    return low;
}

int main(int argc, char**argv) {
    vector<int> nums {2, 3, 4, 4, 6};
    int idx = lowerBound(nums, 6);
    cout << idx << endl;
    return 0;
}
