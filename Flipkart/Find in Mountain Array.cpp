/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int lb=0,ub=mountainArr.length()-1;

        int ans=-1;
        int peak=-1;
        while(lb<=ub)
        {
            int mid=lb+(ub-lb)/2;
            int ele=mountainArr.get(mid);
            int forw=mountainArr.get(mid+1);
            int back=mountainArr.get(mid-1);
            if(ele>forw and ele>back)
            {
                peak=mid;
                break;
            }
            else if(ele>forw)
            {
                ub=mid;
            }
            else
            {
                lb=mid;
            }
            cout<<ele<<" "<<mid<<"\n";
        }
        cout<<peak;
        lb=0,ub=peak;
        while(lb<=ub)
        {
            int mid=lb+(ub-lb)/2;
            int ele=mountainArr.get(mid);
            if(ele==target)
            {
                ans=mid;
                break;
            }
            else if(ele>target)
            {
                ub=mid-1;
            }
            else
            {
                lb=mid+1;
            }
        }
        if(ans!=-1)
        return ans;
        lb=peak,ub=mountainArr.length()-1;
        while(lb<=ub)
        {
            int mid=lb+(ub-lb)/2;
            int ele=mountainArr.get(mid);
            if(ele==target)
            {
                ans=mid;
                break;
            }
            else if(ele>target)
            {
                lb=mid+1;
            }
            else
            {
                ub=mid-1;
            }
        }
        return ans;
    }
};