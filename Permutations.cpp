void dfs(vector<vector<int>> &ans, vector<int> &mynum, vector<int> &nums, bool use[], int k)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        if (!use[i])
        {
            mynum.push_back(nums[i]);
            use[i] = true;
            if (k == nums.size())
                ans.push_back(mynum);
            else
                dfs(ans, mynum, nums, use, k + 1);
            use[i] = false;
            mynum.pop_back();
        }
    }
}

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (!nums.size())
            return vector<vector<int>>{{}};
        vector<vector<int>> ans;
        vector<int> mynum;
        bool use[nums.size()];
        memset(use, false, sizeof(use));
        dfs(ans, mynum, nums, use, 1);
        return ans;
    }
};