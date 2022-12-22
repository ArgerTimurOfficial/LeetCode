class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int size = prices.size();
        if(size==0) return 0;
        int maxProf [k+1][size];
        for(int i = 0 ; i<=k; i++)
        {
            int prevMax = INT_MIN ; 
            for(int j = 0 ; j<size ; j++)
            {
                if( i ==0 || j==0) maxProf[i][j] =0;
                else{
                    int profit =  maxProf[i-1][j-1]- prices [j-1];
                    prevMax = max(prevMax , profit);
                    maxProf[i][j] = max(maxProf[i][j-1] , prevMax + prices[j]);
                }
            }
        }
        return maxProf[k][size-1];
    }
};