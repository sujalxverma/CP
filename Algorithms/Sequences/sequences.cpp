
//  Recursive Function to Generate Subset
void subset(vector<int> &nums, vector<vector<int>> &ans, vector<int> output, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude the current element
    subset(nums, ans, output, index + 1);

    // Include the current element
    output.push_back(nums[index]);
    subset(nums, ans, output, index + 1);
}

// Recursive Function to Generate Subsequences
void subsequences(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }

    // Exclude current element
    generateSubsequences(index + 1, nums, current, result);

    // Include current element
    current.push_back(nums[index]);
    generateSubsequences(index + 1, nums, current, result);
    current.pop_back(); // backtrack
}

// Bitmasking Function to Generate Subsequences
void subsequencesBitmask(vector<int>& nums) {
   int size = nums.size();  // size of the array ,hence possible subsequences is 2^n.
   vector<vector<int>>subsequences;
   int totalCombinations = (1<<size);

   for(int mask = 0 ; mask < totalCombinations ; mask++){
    vector<int>ans;
    for(int i = 0 ; i < size ; i++){
        if(mask & (1<<i)){
            ans.push_back(nums[i]);
        }
    }
    subsequences.push_back(ans);
   }
}

// Recursive Function to generate all permutation.
// O(n!)
void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, result);
        swap(nums[start], nums[i]); // backtrack
    }
}

// Using next_permutation
vector<vector<int>> allPermutations(vector<int> nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());  // start from the smallest lexicographic permutation

    do {
        result.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    return result;
}


// if there any subset exist whose sum is target.
int subsetSum(int index ,int target){

    if(index < 0 ){
        return false;
    }
    if(index == 0){
        return (target == a[0] ? true : false);
    }
    bool nottake = subsetSum(index-1,target);
    bool take = (target - a[index] >= 0) ? subsetSum(index-1,target-a[index]) : false;
    return  take || nottake;
}

// Using Dynamic Programming | if there any subset exist whose sum is target.
vector<vector<int>>dp(n , vector<int>(target+1,-1));
int subsetSum(int index ,int target){
    if(index < 0 ){
        return false;
    }

    if(index == 0){
        return dp[index][target]= (target == a[0] ? true : false);
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    bool nottake = subsetSum(index-1,target);
    bool take = (target - a[index] >= 0) ? subsetSum(index-1,target-a[index]) : false;
    return dp[index][target] =  take|| nottake;
}