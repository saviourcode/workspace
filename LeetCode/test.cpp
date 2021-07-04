#include <iostream>
#include <string>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

using namespace std;

class Solution {
public:
    
    int count = 0;
    cpp_int countGoodNumbers(long long n) {
        cpp_int a = (cpp_int)pow(20,25) % ((cpp_int)pow(10,9) + 7);
        return a;
    }
};

int main()
{
    Solution sol;
    cout << scientific << sol.countGoodNumbers(50);
}