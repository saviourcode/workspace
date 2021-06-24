# Boyer - Moore majority vote Algorithm

1. It is an algorithm for finding the majority of a sequence of elements using linear time and constant space.

2. pseudo-code for the algorithm:

    1. Initialize an element `m` and a counter `i` with `i` = 0
    2. For each element `x` of the input sequence:
        1. if `i == 0`, then assign `m = x` and `i = 1`
        2. else if `m == x`, then assign `i = i+1`
        3. else assign `i = i-1`
    2. Return `m`

3. For reference visit: [Boyer-Moore Algorithm](cs.texas.edu/~moore/best-ideas/mjrty/)

# Finding the missing number in a array
1. Use Bit Manipulation technique given that the array elements value starts from 0.
2. Pseudo-code will be:
    1. Store the size of array in `len = nums.size()`
    2. Initialize a counter to zero, `i=0`
    3. For each element `num` of the input sequence:
        1. `len ^= num`
        2. `len ^= i`
        3. `i++`
    4. Return `len`

# Finding the missing numbers in a array
```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = abs(nums[i]);
            int index = temp - 1;
            if(nums[index] > 0)
                nums[index] *= -1;
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                res.push_back(i+1);
            }
        }
        return res;
    }
```
Firstly mark the elements which are present by mapping it to the respective indices.
