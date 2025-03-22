class Solution {
    public:
        int idx(const int N, int v) {
            return v + N;
        }
        vector<vector<int>> threeSum(vector<int>& nums) {
            const int N = 2 * 1e5 + 7;
            sort(nums.begin(), nums.end());
            int m = nums.size();
            int rep = 1;
            for (int i = 1; i < m; ++i) {
                if (nums[i] == 0) {
                    if (rep > 2) {
                        if (nums[i] == nums[rep-1] && nums[i] == nums[rep-2] && nums[i] == nums[rep-3]) {
                            
                        } else nums[rep++] = nums[i];
                    } else nums[rep++] = nums[i];
                } else {
                    if (rep > 1) {
                        if (nums[i] == nums[rep-1] && nums[i] == nums[rep-2]) {
    
                        } else nums[rep++] = nums[i];
                    } else nums[rep++] = nums[i];
                }
            }
            vector<pair<int,int>> mp[2*N + 7];
            // map<int, vector<pair<int,int>>> mp;
            int n = rep;
            vector<vector<int>> ans;
            for (int k = 1; k < n; ++k) {
                for (auto x: mp[idx(N, -nums[k])]) {
                    vector<int> cur;
                    cur.emplace_back(x.first);
                    cur.emplace_back(x.second);
                    cur.emplace_back(nums[k]);
                    ans.emplace_back(cur);
                }
                for (int i = 0; i < k; ++i) {
                    mp[idx(N, nums[i] + nums[k])].emplace_back(make_pair(nums[i], nums[k]));
                }
            }
            set<vector<int>> st(ans.begin(), ans.end());
            return vector<vector<int>>(st.begin(), st.end());
        }
    };