class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap(nums.begin(), nums.end());

        double numsSum = 0;
        for (double n : nums) {
            numsSum += n;
        }
        double numsSumHalf = numsSum/2;

        int count = 0;

        while(numsSumHalf < numsSum) {
            count++;

            double reduceNum = (heap.top()/2); heap.pop();
            heap.push(reduceNum);

            numsSum -= reduceNum;
        }

        return count;
    }
};

// 성공

// 시간복잡도 : O(nlog(n))