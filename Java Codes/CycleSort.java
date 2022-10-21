public class CycleSort {
    public static void main(String[] args) {
        int[] arr = {3,5,1,4,2};
     cyclicSort(arr);
     for(int i=0; i<arr.length; i++){
         System.out.println(arr[i]);
     }
    }
     static void cyclicSort(int[] arr){
         int i=0;
         while(i<arr.length){
             int correct = arr[i]-1;
          if(arr[i]!=arr[correct]){
                    swap(arr, i, arr[i]-1); 
                  }
                  else{ 
                  i++; 
             }
            }
         }
     static void swap(int[] arr, int first, int second){
        int temp=arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}