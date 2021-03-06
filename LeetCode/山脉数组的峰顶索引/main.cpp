// https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/

#include "../common/common.h"

// 二分查找
class Solution1
{
public:
    Solution1(const vector<int>& nums) : nums(nums) {}

    int solve()
    {
        int low = 0, high = nums.size() - 1;

        while (high - low > 3)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1]) low = mid;
            else high = mid;
        }

        for (int i = low + 1; i <= high; ++i)
        {
            if (nums[i] < nums[i - 1]) return i - 1;
        }

        return high;
    }

private:
    vector<int> nums;
};

// 三分法
class Solution2
{
public:
    Solution2(const vector<int>& nums) : nums(nums) {}

    int solve()
    {
        int low = 0, high = nums.size() - 1;

        while (high - low > 3)
        {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;
            if (nums[mid1] < nums[mid2]) low = mid1;
            else high = mid2;
        }

        for (int i = low + 1; i <= high; ++i)
        {
            if (nums[i] < nums[i - 1]) return i - 1;
        }

        return high;
    }

private:
    vector<int> nums;
};

class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& nums) 
    {
        //return Solution1(nums).solve();
        return Solution2(nums).solve();
    }
};

int main()
{
    Cases<vector<int>, int> cases
    {
        {{0,1,0}, 1},
        {{0,2,1,0}, 1},
        {{1,2,3,4,5,6,5,4,3}, 5},
    };

    test(&Solution::peakIndexInMountainArray, cases);

	return 0;
}