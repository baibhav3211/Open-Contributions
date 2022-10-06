import java.util.*;

public class Solution {
    public static boolean isMatch(String s, String p) {
        int m=s.length();
        int n=p.length();
        boolean dp[][]=new boolean[n+1][m+1];
        for(int i=dp.length-1;i>=0;i--){
            for(int j=dp[0].length-1;j>=0;j--){
                if(i==dp.length-1 && j==dp[0].length-1){
                    dp[i][j]=true;
                }
                else if(j==dp[0].length-1){
                    if(p.charAt(i)=='*')dp[i][j]=dp[i+1][j];
                    else dp[i][j]=false;
                }
                else if(i==dp.length-1){
                    dp[i][j]=false;
                }
                else{
                    if(p.charAt(i)==s.charAt(j))dp[i][j]=dp[i+1][j+1];
                    else if(p.charAt(i)=='?')dp[i][j]=dp[i+1][j+1];
                    else if(p.charAt(i)=='*')dp[i][j]=dp[i][j+1] || dp[i+1][j];
                    else dp[i][j]=false;
                }
            }
        }
        return dp[0][0];
    }

    public static void main(String[] args) {
        String s="aa";
        String t="*";
        System.out.println(isMatch(s,t));
    }
}