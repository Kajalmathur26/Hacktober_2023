class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans , vector<int> ds , unordered_map<int,bool> &mp){
        int i ;
        for( i =0 ; i<nums.size();i++){
            if(mp[i]==false){
                ds.push_back(nums[i]);
                mp[i] = true ; 
                solve(nums , ans, ds ,  mp);
                mp[i]= false;
                ds.pop_back();
            }
        }
        if(ds.size()==nums.size())
        ans.push_back(ds);
        return ;
        
    }
    void solve_2(vector<int>& nums , int index ,vector<vector<int>> &ans ){
        if(index == nums.size())ans.push_back(nums);
        else{
            for(int i=index ;i<nums.size();i++){
                swap(nums[i], nums[index]);
                solve_2(nums, index+1, ans);
                swap(nums[i], nums[index]);
            }
        }
        return ;
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ; 
        solve_2(nums,0, ans);
        return ans ;
    }
};
