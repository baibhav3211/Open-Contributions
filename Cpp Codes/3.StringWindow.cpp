// Given two strings, one big string and one small string, find 
// the 'smallest window' in the big string that contains all
// characters of the small string.
// - Window can have additional characters than req.
// - If small string has duplicates, then those duplicates 
// must be present with same or higher count in window.

// Input: 
// s1=hello_world
// s2=lol
// Output:
// lloaa 

// s1=fizzbuzz
// s2=fuzz 

// Output: fizzbu

#include<bits/stdc++.h>
using namespace std;

string find_window(string s, string p){

    // Array as a freq map or you can use hashmap
    int FP[256] = {0};
    int FS[256] = {0};

    for(int i=0;i<p.length();i++){
        FP[p[i]]++;
    }
    int cnt = 0;
    int start = 0;  // left contraction
    int start_idx = -1; //start_idx for best window
    int min_so_far = INT_MAX;
    int window_size;

    // Sliding window algo.
    for(int i=0;i<s.length();i++){
        //exapmd the window by including curr char
        char ch = s[i];
        FS[ch]++;

        //count how many chars have been matches till now(string and patter)
        if(FP[ch]!=0 and FS[ch]<=FP[ch]){
            cnt+=1;
        }
        // if all the chars of the pattern are found in curr. window then you can start contracting
        if(cnt == p.length()){
            //start contracting from left to remove unwanted chars
            while(FP[s[start]] == 0 or FS[s[start]]> FP[s[start]]){
                FS[s[start]]--;
                start++;
            }
            //note the window size
            window_size = i - start +1;
            if(window_size < min_so_far){
                min_so_far = window_size;
                start_idx = start;
            }

        }

    }
    if(start_idx == -1){
        return NULL;
    }else{
        return s.substr(start_idx, min_so_far);
    }

}

int main(){

    string s,p;
    cin>>s>>p;
    cout<<find_window(s,p)<<endl;

    return 0;
}