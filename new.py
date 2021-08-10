A subsequence is created by deleting zero or more elements from a list while maintaining the order.
For example,the subsequence of [1,2,3] are [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3].
An inversion is a strictly decreasing subsequence of length 3. More formally, given an array , p = p[n], 
an inversion in the array is any time some p[i] > p[j] > p[k] such that i < j < k.
Given an array, find the number of inversions in the array.
Input:

Example 1:
n = 5
arr = [5, 3, 4, 2, ,1]
Output:
The array inversions are:
[5,3,2]
[5,3,1]
[5,4,2]
[5,4,1]
[5,2,1]
[3,2,1]
[4,2,1]


