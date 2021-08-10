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

# Sieve of Eratosthenes
>(From Wiki) In mathematics, the **sieve of Eratosthenes** is an ancient algorithm for finding all prime numbers up to any given limit.

1. It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with the first prime number 2. 
2. The mulitples of a given prime are generated as a sequence of numbers starting from that prime, with constant difference between them that is equal to that prime.
3. This is the sieve's key distinction from using trial division to sequentially test each candidate number for divisibility by each prime.
4. Once all the multiples of each discovered prime have been marked as composites, the remaining unmarked numbers are prime.
5. Pseudo Code:
```
algorithm Sieve of Eratosthenes is
    input: an integer n > 1.
    output: all prime numbers from 2 through n.

    Let A be an array of Boolean values, indexed by integers 2 to n, initially all set to true.

    for i = 2, 3, 4, ..., not exceeding sqrt(n) do
        if A[i] is true
            for j = i*i, i*i+i, i*i+2*i, i*i+3*i, ..., not exceeding n do
                A[j]:= false
    
    return all i such that A[i] is true.
```

6. This algorithm produces all primes not greater than n. It includes a common optimization, which is to start enumerating the multiples of each prime i from i*i. 
7. The time complexity of this algorithm is O(nloglogn).