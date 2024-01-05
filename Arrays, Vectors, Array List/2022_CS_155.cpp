#include <iostream>
#include <vector>
using namespace std;

// ------------------------------- Problem 1 -------------------------------
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> array(nums.size());

        for(int outer = 0; outer < nums.size(); outer++){
            int count = 0;
            for(int inner = 0; inner < nums.size(); inner++){
                if(nums[outer] > nums[inner]){
                    count++;
                }
            }
            array[outer] = count;
        }
        return array;
    }
};

// ------------------------------- Problem 2 -------------------------------
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};


// ------------------------------- Problem 3 -------------------------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int left = 0;
       int right = matrix.size() * matrix[0].size() - 1;
       while(left <= right){
           int mid = left + (right - left) / 2;
           if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] == target){
               return true;
           }

           if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] < target){
               left = mid + 1;
           }

           if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] > target){
               right = mid - 1;
           }
       } 
       return false;
    }
};


// ------------------------------- Problem 4 -------------------------------
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[counter - 1]){
                nums[counter] = nums[i];
                counter++;
            }
        }
        return counter;
    }
};

// ------------------------------- Problem 5 -------------------------------
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = 0;
        int result = -10000;

        for(int i = 0; i < nums.size(); i++){
            maxi += nums[i];
            result = max(result, maxi);
            if(maxi < 0){
                maxi = 0;
            }
        }
        return result;
    }
};

// ------------------------------- Problem 6 -------------------------------
class Solution {
public:
    int firstBadVersion(int n) {
    for(int i = n; i >= 0; i--){
        if(isBadVersion(i) == false){
            return i+1;
        }
    }        
    return 1;
    }
};

// ------------------------------- Problem 7 -------------------------------
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int j = 0;
        
        while(j < nums.size()){
    if(nums[j] > 0 && nums[j] <= nums.size() && nums[nums[j] - 1] != nums[j]){
            swap(nums[j], nums[nums[j] - 1]);
            }

            else{
                j++;
            }
        }

        for(int i = 0; i < j; i++){
            if(nums[i] != i + 1){
                cout << nums[i];
                return i + 1;
            }
        }
        return j + 1;
    }
};

int main(){
	return 0;
}
