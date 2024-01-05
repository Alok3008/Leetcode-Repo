class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> tail;

    for (const int num : nums)
      if (tail.empty() || num > tail.back())
        tail.push_back(num);
      else
        tail[firstGreaterEqual(tail, num)] = num;

    return tail.size();
  }

 private:
  int firstGreaterEqual(const vector<int>& A, int target) {
    return lower_bound(begin(A), end(A), target) - begin(A);
  }
};