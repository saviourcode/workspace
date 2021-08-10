#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
    
    int count = 0;
    int countGoodNumbers(long long n) {
        for(long long num = 0; num < pow(10,n); num++)
        {
            string old_string = to_string(num);
            string new_string = string(n - old_string.length(), '0') + old_string;
            
            int even = 0;
            int prime = 0;
            
            for(int i = 0; i < n; i++){
                int k = new_string[i] - '0';
                if(i%2 == 0 && k%2==0)
                    even++;
                else if(i%2 == 1 && (k == 2 || k == 3 || k == 5 || k == 7))
                    prime++;
            }
                        
            if(even+prime == n)
            {
                count++;
            }
            
        }
        
        return count;
    }
};

int main()
{
    Solution sol;
    cout << sol.countGoodNumbers(50);

}