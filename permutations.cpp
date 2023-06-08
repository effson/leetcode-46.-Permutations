//In this problem, the difficulty is mainly how to find the value that has not been used, that is, the value that has not been used to fill the previous position.In this question, I used the method of exchanging elements, and used the example of filling the first element of vector<int> tmp:
//When filling for the first time (index==0), you can fill in the number of size (number of elements), because all the numbers are not used. If you fill in the first number (nums[0]), nums[ 1] to nums[size-1] are not used; fill in the second number (nums[1]), then nums[0] and nums[2] to nums[size-1] are not used, 
//if exchange nums [0] and nums[1], then in this case the second filling (index==2) the range of optional numbers is also nums[1] to nums[size-1],
//Fill in the i-th number (nums[i]), then nums[0] to nums[i-1] and nums[i+1] to nums[size-1] are not used, if exchange nums[0 ] and nums[i], then in this case the second filling (index==2) the range of selectable numbers is the same as nums[1] to nums[size-1].
//Fill the n-th element of tmp (index==n) in the same way;
//在这个问题中，难点主要是如何找出还没有被使用的值，也就是没有被用来填充之前的位置的值.本题我使用了交换元素的方法，用填充vector<int> tmp 的第一个元素举例：
//第一次填充时（index==0），可以填size(元素个数)个数，因为所有的数均未被使用.如果填入第一个数（nums[0]）,nums[1]到nums[size-1]未被使用；填入第二个数（nums[1]），那么nums[0]和nums[2]到nums[size-1]未被使用，如果交换nums[0]和nums[1],那么在这种情况下第二次填充（index==2）可选择的数的范围也为nums[1]到nums[size-1]，
//填入第i个数（nums[i]），那么nums[0]到nums[i-1]和nums[i+1]到nums[size-1]未被使用，如果交换nums[0]和nums[i],那么在这种情况下第二次填充（index==2）可选择的数的范围一样为nums[1]到nums[size-1]。
//填充tmp的第n个元素（index==n）同理；
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> res;
        dfs(nums,res,0,tmp);
        return res;
    }
    void dfs(vector<int>& nums,vector<vector<int>>& res,int index,vector<int> tmp){
        if(index==nums.size()){
            res.push_back(tmp);
        }
        for(int i=index;i<nums.size();i++){
            tmp.push_back(nums[i]);
            swap(nums[i],nums[index]);
            dfs(nums,res,index+1,tmp);
            swap(nums[i],nums[index]);
            tmp.pop_back();
        }
    }
};
