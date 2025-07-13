#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
  map<int, int> mp;
  for(int i =0; i< nums.size();i++) {
    int complement = target - nums[i];
    if(mp.find(complement) != mp.end()) {
      return {mp[complement], i};
    }
    mp[nums[i]] = i;
  }
}
int main(int argc, char *argv[])
{

  vector<int> v = {2, 7, 11, 15};

  vector<int> res = twoSum(v, 9);
  cout << res[0] << " - " << res[1] << endl;

  return 0;
}
