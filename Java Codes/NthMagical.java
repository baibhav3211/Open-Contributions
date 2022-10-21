public class NthMagical {
    public static void main(String[] args) {
        System.out.println(Magic(1,2,3));
    }
    static int Magic(int n,int a,int b){
        int i=1,k=0;
        while(i!=0){
       if(i%a==0 || i%b==0){
        k++;
       }
       if(k==n){
        break;
       }
       i++;
        }
        return i;
    }
}
