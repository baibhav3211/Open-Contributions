package com.aman;

import java.util.Scanner;

public class gp {
    public static void main(String[] args) {
        int a,r,n;
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the first term");
        a=sc.nextInt();
        System.out.println("Enter the Common ratio");
        r=sc.nextInt();
        System.out.println("Enter the number of terms");
        n= sc.nextInt();
        for(int i=1,j=1;i<=n;i++,j=j*r){
            System.out.print(a+",");
            a=a*r;
        }
    }
}
