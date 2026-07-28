class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int l = 0;
        int r = n1;

        //bs on smaller array
        while(l <= r){
            int c1 = l + (r-l)/2;
            int c2 = (n1 + n2 + 1)/2 - c1; // if c1 big it might be neg. so only on smaller array

            int l1 = (c1 == 0)? INT_MIN: nums1[c1 - 1];
            int l2 = (c2 == 0)? INT_MIN: nums2[c2 - 1];
            int r1 = (c1 == n1)? INT_MAX: nums1[c1];
            int r2 = (c2 == n2)? INT_MAX: nums2[c2];

            if(r1 >= l2 && r2 >= l1){//found out cut
                if((n1+n2)%2 == 0){
                    return (min(r1,r2) +  max(l1,l2)) / 2.0;
                }else{
                    return max(l1,l2);
                }
            }else if(l1 > r2){
                r = c1 - 1;
            }else{
                l = c1 + 1;
            }
        }

        return 0.0;
    }
};