class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size () == 0)return 0;
        int res = 1; 
        int index = nextDifferentCharacterIndex(nums, 1);
        int i = 1;
        while(index < nums.size()){
            res ++;
            nums[i] = nums[index];
			i++;
			index++;
            index = nextDifferentCharacterIndex(nums, index);
        }
        return res;
    }
 
private:
    int nextDifferentCharacterIndex(const vector<int> &nums, int p){
        for( ; p < nums.size() ; p ++ )
            if( nums[p] != nums[p - 1] )break;
        return p;
    }
};