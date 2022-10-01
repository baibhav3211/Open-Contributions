/* A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

Favorite question for Microsoft, Amazon and google
*/
/*
First of all we need to check for an annoying edge cases - a leading '0', which is not valid and if so we just return 0 combinations; similarly, any other single character (ie: other than '0', since we put the second condition after that check) will always mean just 1 combination.

Then we declare our support variables:

len will store the length of our input;
dp is an array of length len where we will store our precomputed results as we parse the string.
But first we want to initialise dp a bit:

at index 0, we can be sure we will have just 1 possible combination to consider (since we excluded a leading 0 before);
at index 1 things are a bit more complicated and we need to start using our main logic in 2 steps:
if the first and the second character compose a number in the 10 - 26 range, we store 1, 0 otherwise;
similarly, any character != '0' will mean one extra combination obtained here.
We can see it in other ways: if the first two digits are in the valid range, that means we we can read them in 2 different ways (for example: "13" can be seen as either the character with index 13 or the characters with indexes 1 and 3); that is always the case, unless the second digit is a '0', since that cannot be alone to make a valid combination.

You can also see the code as adding 2 if the first two digits are in the 10 - 26 range and, in case, subtracting 1 when the s[1] == '0', for the reason explained above.

With this ground prepared, we can move on with the main loop, going with i from 2 up to len (excluded) to populate dp. At each step, we will:

first of all check if we encountered the second consecutive '0', in which case there is no point in moving forward and we can just return 0, as done above for invalid coded strings;
we will then give the value of dp[i - 1] (the previous value) to dp[i], unless our current character is a '0', in which case we just set it to 0, since no single character combination can be counted this way;
if the last two digits are in the valid 10 -26 range, then we will also add the value of two positions before (dp[i - 2]) to dp[i] - again try to think in terms of a Fibonacci sequence if that helps you make more sense of it.
Once we are done, we can return dp[len - 1] as the correct result of all the cumulated combinations :)

The code:

*/
#include<bits/stdc++.h>
using namespace std;
    int numDecodings(string s) {
        // edge cases out - leading zero and single character string
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        // support variables
        int len = s.size(), dp[len];
        // preparing dp
        dp[0] = 1;
        dp[1] = (s[0] == '1' || s[0] == '2' && s[1] < '7' ? 1 : 0) + (s[1] != '0');
        for (int i = 2; i < len; i++) {
            // edge case: we quit for 2 consecutive zeros
            if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0')) return 0;
            // base case: we always keep the previous set of combinations, unless we met a 0
            dp[i] = s[i] != '0' ? dp[i - 1] : 0;
            // we go and look 2 positions behind if we can make a digit in the 10-26 range
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7') dp[i] += dp[i - 2];
        }
        return dp[len - 1];
    }
int main(){
 cout<<"Enter the String"<<endl;
   string str;
   cin>>str;
   int number_decode_ways = numDecodings(str);
   cout<<"Number of the decode ways :" <<number_decode_ways<<endl;
   return 0;
 }

/* But, wait a moment: can we do better?

Well, after all we need only the last 3 values of dp at each step, so I will declare it to have only 3 slots and adjust the rest with some neat modulo operation; saving even more memory:
*/
#include<bits/stdc++.h>
using namespace std;
    int numDecodings(string s) {
        // edge cases out - leading zero and single character string
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        // support variables
        int len = s.size(), dp[3];
        // preparing dp
        dp[0] = 1;
        dp[1] = (s[0] == '1' || s[0] == '2' && s[1] < '7' ? 1 : 0) + (s[1] != '0');
        for (int i = 2, curr, prev; i < len; i++) {
            curr = i % 3;
            prev = curr ? curr - 1 : 2;
            // edge case: we quit for 2 consecutive zeros
            if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0')) return 0;
            // base case: we always keep the previous set of combinations, unless we met a 0
            dp[curr] = s[i] != '0' ? dp[prev] : 0;
            // we go and look 2 positions behind if we can make a digit in the 10-26 range
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7') dp[curr] += dp[prev ? prev - 1 : 2];
        }
        return dp[(len - 1) % 3];
    }
 int main(){
 cout<<"Enter the String"<<endl;
   string str;
   cin>>str;
   int number_decode_ways = numDecodings(str);
   cout<<"Number of the decode ways :" <<number_decode_ways<<endl;
   return 0;
 }
