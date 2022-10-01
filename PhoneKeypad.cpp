// Given a number N and a modern phone keypad. Find out all the 
// possible strings generated using that number.

// Sample Input: 23
// Output: AD,AE,AF,BD,BE,BF,CD,CE,CF


#include<bits/stdc++.h>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i=0){
    
    //base case
    if(input[i]=='\0'){
        cout<<output<<endl;
        return;
    }

    //recursive case
    int curr_digit = input[i] - '0';
    if(curr_digit == 0 or curr_digit == 1){
        printKeypadOutput(input, output, i+1);
    }

    for(int k=0;k<keypad[curr_digit].size();k++){
        printKeypadOutput(input, output+keypad[curr_digit][k], i+1);
    }
}

int main(){
    string input;
    cin>>input;
    string output;
    printKeypadOutput(input, output);
    return 0;
}