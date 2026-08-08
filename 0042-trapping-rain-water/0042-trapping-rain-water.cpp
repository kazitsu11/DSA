class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int leftmax=height[left];
        int rightmax=height[right];
        int water=0;

        while(left<right){
            leftmax=max(leftmax,height[left]);
            rightmax=max(rightmax,height[right]);
            if(leftmax<=rightmax){
              water+=leftmax-height[left];
              left++;
            }
            else if(rightmax<=leftmax){
             water+=rightmax-height[right];
             right--;
            }
        }
        return water;
    }
};