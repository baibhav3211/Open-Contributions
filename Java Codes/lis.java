import java.util.*;
public class MyClass {
    public static void main(String args[]) {
       int arr[]={10,9,2,5,3,7,101,18};
       System.out.println(lengthOfLIS(arr));
    }
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        List<Integer> l=new ArrayList<>();
        for(int i=0;i<n;i++){
            if(l.isEmpty()){
                l.add(nums[i]);
            }
            else if(l.get(l.size()-1)<nums[i]){
                l.add(nums[i]);
            }
            else{
                int ind=f(l,nums[i]);
                l.set(ind,nums[i]);    
            }
        }
        return l.size();
    }
    public int f(List<Integer> l,int x){
        int i=0;
        int j=l.size()-1;
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(l.get(mid)>=x){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
}