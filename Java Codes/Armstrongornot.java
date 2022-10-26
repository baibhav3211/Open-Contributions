package com.aman;

import java.util.Scanner;

public class Armstrongornot {
    public static void main(String[] args) {
        int n,r,sum=0;
        Scanner sc= new Scanner(System.in);
        n=sc.nextInt();
        int c=n;
        while(c>0){
            r=c%10;
            int cube= r*r*r;
            sum=cube+sum;
            c=c/10;

        }if(sum==n){
            System.out.println("Number is Armstrong number");
        }
        else
            System.out.println("not an Armstong number");
    }
}
