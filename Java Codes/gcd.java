import java.util.Scanner;

public class gcd {
   static int gcd(int m, int n){
       while(m!=n){
           if(m>n){
               m=m-n;
           }else
               n=n-m;
       }
       return m;
   }
    public static void main(String[] args) {
       int a,b;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the two numbers");
        a= sc.nextInt();
        b=sc.nextInt();
       System.out.println(gcd(a,b));
    }
}
