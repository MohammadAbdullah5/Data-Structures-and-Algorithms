#include<vector>
#include<stack>

// --------------------- Problem 1 ----------------------
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        while(s[i] != '\0'){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']' || st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else {
                st.push(s[i]);
            }
            i++;
        }
        if(st.empty() == true){
            return true;
        }

        else{
            return false;
        }
    }
};

// --------------------- Problem 2 ----------------------
class MinStack {
private:
    vector<int> array;
    vector<int> minimum;
public:
    MinStack() {
        minimum.push_back(2147483647);
    }
    
    void push(int val) {
        if(val <= minimum[minimum.size() - 1]){
            minimum.push_back(val);
        }
        array.push_back(val);
    }
    
    void pop() {
        if(minimum[minimum.size() - 1] == array[array.size() - 1]){
            minimum.pop_back();
        }
        array.pop_back();
    }
    
    int top() {
        return array[array.size() - 1];
    }
    
    int getMin() {
        return minimum[minimum.size() - 1];
    }
};

// --------------------- Problem 3 ----------------------
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 1;
        int right = height.size() - 2;
        int leftMax = height[0];
        int rightMax = height[height.size() - 1];
        int water = 0;

        while(left <= right){
            if(height[left] >= leftMax){
                leftMax = height[left];
                left++;
            }

            else if(height[right] >= rightMax){
                rightMax = height[right];
                right--;
            }

            else if(leftMax <= rightMax && height[left] < leftMax){
                water += leftMax - height[left];
                left++;
            }

            else if(leftMax >= rightMax && height[right] < rightMax){
                water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }
};

// --------------------- Problem 4 ----------------------
class Solution {
public:
    string decodeString(string s) {
        stack<int> numbers;
        stack<string> words;
        string line = "";
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(isDigit(s[i])){
                count = (count * 10) + (int(s[i]) - 48);
            }

            else if(s[i] == '['){
                numbers.push(count);
                words.push(line);
                line = "";
                count = 0;
            }

            else if(s[i] == ']'){
                int repetition = numbers.top();
                string previous = words.top();
                words.pop();
                numbers.pop();

                for(int j = 0; j < repetition; j++){
                    previous += line;
                }
                line = previous;
            }

            else{
                line += s[i];
            }
        }
        return line;
    }

    bool isDigit(char ch){
        if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9'){
            return true;
        }
        return false;
    }
};

// --------------------- Problem 5 ----------------------
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while(left < right){
            int waterLevel = min(height[left], height[right]);
            int waterWidth = right - left;
            maxArea = max(maxArea, waterLevel * waterWidth);

            if(height[left] < height[right]){
                left++;
            }

            else{
                right--;
            }
        }
        return maxArea;
    }
};

// --------------------- Problem 6 ----------------------
class MyStack {
private: 
    queue<int> primary;
    queue<int> secondary;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        while(!primary.empty()){
            secondary.push(primary.front());
            primary.pop();
        }

        primary.push(x);

        while(!secondary.empty()){
            primary.push(secondary.front());
            secondary.pop();
        }
    }
    
    int pop() {
        int temp = primary.front();
        primary.pop();
        return temp;
    }
    
    int top() {
        return primary.front();
    }
    
    bool empty() {
        return primary.empty();
    }
};

// --------------------- Problem 7 ----------------------
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentsQueue;
        stack<int> sandwichStack;

        for(int i = 0; i < students.size(); i++){
            studentsQueue.push(students[i]);
            sandwichStack.push(sandwiches[sandwiches.size() - 1 - i]);
        }

        int count;
        for(int i = 0; i < studentsQueue.size(); i++){
            count = 0;
            while(studentsQueue.size() != 0 && count < studentsQueue.size()){
                if(studentsQueue.front() == sandwichStack.top()){
                    studentsQueue.pop();
                    sandwichStack.pop();
                    count = 0;
                }

                else{
                    studentsQueue.push(studentsQueue.front());
                    studentsQueue.pop();
                    count++;
                }
            }
        }
        return count; 
    }
};

// --------------------- Problem 8 ----------------------
class FrontMiddleBackQueue {
private:
    deque<int> deq;
    int size;
public:
    FrontMiddleBackQueue() {
        size = 0;
    }
    
    void pushFront(int val) {
        deq.push_front(val);
        size++;

    }
    
    void pushMiddle(int val) {
        if(size == 0){
            deq.push_back(val);
            size++;
        }
        
        else{
            stack<int> st;
            for(int i = 0; i < size / 2; i++){
                st.push(deq.front());
                deq.pop_front();
            }
            deq.push_front(val);
            while(!st.empty()){
                deq.push_front(st.top());
                st.pop();
            }
            
            size++;
        }
    }
    
    void pushBack(int val) {
        deq.push_back(val);
        size++;
        
    }
    
    int popFront() {
        if(deq.size()==0){
            return -1;
        }
        int temp = deq.front();
        deq.pop_front();
        size--;
        return temp;
    }
    
    int popMiddle() {
        if(deq.size()==0){
            return -1;
        }
        else{
            int temp = 0;
            stack<int> st;
            int index = size / 2;
            if(size % 2 == 0){
                for(int i = 0; i < (size / 2) - 1; i++){
                    st.push(deq.front());
                    deq.pop_front();
                }
                temp = deq.front();
                deq.pop_front();
                while(st.size() != 0){
                    deq.push_front(st.top());
                    st.pop();
                }
                size--;
                return temp;
            }

            else{
                for(int i=0; i < size/2; i++){
                    st.push(deq.front());
                    deq.pop_front();
                }
                temp=deq.front();
                deq.pop_front();
                while(st.size()!=0){
                    deq.push_front(st.top());
                    st.pop();
                }
                size--;
                return temp;
            }
        }
    }
    
    int popBack() {
        if(deq.size() == 0){
            return -1;
        }
        int temp = deq.back();
        deq.pop_back();
        size--;
        return temp;
    }
};

// --------------------- Problem 9 ----------------------
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maximumNonCircular = maxNonCircularSubarray(nums);
        int minimumNonCircular = minNonCircularSubarray(nums);
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }

        if(totalSum == minimumNonCircular){
            return maximumNonCircular;
        }
        int circularMaximum = totalSum - minimumNonCircular;
        return max(circularMaximum, maximumNonCircular);
    }

    int maxNonCircularSubarray(vector<int> nums){
        int current = nums[0];
        int maximum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            current = max(nums[i], current + nums[i]);
            maximum = max(current, maximum);
        } 
        return maximum;
    }

    int minNonCircularSubarray(vector<int> nums){
        int current = nums[0];
        int minimum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            current = min(nums[i], current + nums[i]);
            minimum = min(current, minimum);
        } 
        return minimum;
    }
};

// --------------------- Problem 10 ---------------------
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> output;
        for(int i = 0; i < asteroids.size(); i++){
            if(st.empty() || asteroids[i] > 0){
                st.push(asteroids[i]);
            }

            else{
                while(!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top()){
                    st.pop();
                }

                if(!st.empty() && st.top() > 0 && abs(asteroids[i]) == st.top()){
                    st.pop();
                }
                else if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                
                }
            }
        }
        while (!st.empty()) {
        output.insert(output.begin(), st.top());
        st.pop();
        }
        return output;
    }
};


int main(){
    return 0;
}