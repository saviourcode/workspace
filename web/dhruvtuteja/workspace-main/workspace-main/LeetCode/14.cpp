#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res = strs[0];
    
        for(size_t i = 0; i < res.size(); i++)
        {
            for(auto j : strs)
            {
                if(j.size() >= i && res[i] == j[i]);
                    
                else
                    return res.substr(0,i);
            }
        }
        return res;
    }
};

int main()
{
    Solution test;
    vector<string> svec = {"abc"};
    cout << test.longestCommonPrefix(svec);

    return 0;
}