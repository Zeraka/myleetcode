/*
nums = [2,11,7,15], target = 9
nums[0] + nums[2] = 2 + 7 = 9
return [0,2]
*/
#include <vector>
#include <unordered_map> //Use C++ unordered_map
#include <iostream>
//#include <ostream>

using namespace std;


class mylib{
    public:

    vector<int> TwoSum(vector<int>&sums, int target)
    {
        int i = 0;
        unordered_map<int, int> lookup;
        vector<int> res; 

        for(int n = 0; n < sums.size(); n++){
            lookup.insert(pair<int,int>(n,sums[n]));
        }
        for(int n =0; n < sums.size(); n++)
        {
            int num_to_find = target - sums[n];
            if(lookup.find(num_to_find)==lookup.end()){
                continue;
            }
            else
            {
                res.push_back(n);
                res.push_back(lookup[num_to_find]);
            }

            return res;
            
        }
    }
};

int main()
{
    vector<int> vct = {2,11,7,15};
    int target = 9;
     mylib ml;
    vector<int> res = ml.TwoSum(vct, target);
    
    std::cout<< res[0]<<","<<res[1] <<std::endl;
}
/*
First put the nums in Vector into a map container.
Second Find Target - n is existed in this container.
Because Using hashMap, so you can make it in O(n) + O(n).
*/