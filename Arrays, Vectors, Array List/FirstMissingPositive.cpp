#include <iostream>
#include <vector>
using namespace std;
//In this problem we first sorted the nmbers then we pushed negative numbers at the end
// and at last we checked that which number was missing
class Solution {
    public:
    int firstMissingPositive(vector<int>& nums) {
        int j = 0;

        for(int i = 0; i < nums.size(); i++){
            for(int k = 0; k < nums.size() - i - 1; k++){
                if(nums[k + 1] < nums[k]){
                    swap(nums[k+1],nums[k]);
                }
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        for(int i = 1; i < j; i++){
            if(nums[i - 1] != i){
                cout << nums[i];
                return i;
            }
        }

        return j+1;
    }
};


int main() {
    // Write C++ code here
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(1);
    

    return 0;
}