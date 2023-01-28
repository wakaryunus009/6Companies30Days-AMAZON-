//Most Popular Video Creator
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) 
    {
        int n = ids.size();
        map<string, vector<pair<int, string>>>mp1;
        map<string, long long>mp2; 
        for (int i = 0; i < n; i++)
        {
            mp2[creators[i]] += views[i]; 
            mp1[creators[i]].push_back({views[i], ids[i]}); 
        }
        long long mxPopularity = 0;
        for (auto it : mp2)
        {
            long long popularity = it.second;
            mxPopularity = max(mxPopularity, popularity);
        }
        vector<vector<string>>ans;
        for (auto it : mp2)
        {
            string creator = it.first;
            long long popularity = it.second;
            if (popularity == mxPopularity)
            {
                 sort(mp1[creator].begin(), mp1[creator].end(), [](pair<int, string>& a, pair<int, string>& b)->bool{
                    if (a.first > b.first) return true;
                    else if (a.first < b.first) return false;
                    else return (a.second < b.second);
                });
                string mostViewed = mp1[creator][0].second;
                ans.push_back({creator, mostViewed});
            }
        }
      return ans;
        
    }
};