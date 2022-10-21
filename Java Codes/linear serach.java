//A function to search a given element x in an array arr[] of n elements 

//If x is present then return its location, otherwise return -1

class searchArrayLinear {
    // This returns index of element x in arr[]
    static int searchArray(int arr[], int n, int x)
    {
        for (int i = 0; i < n; i++) {
            // Return the index of the element if it is found
            if (arr[i] == x)
                return i;
        }
  
        // return -1 if the element is not present.
        return -1;
    }
  
    public static void main(String[] args)
    {
        int[] arr = { 3, 4, 1, 7, 5 };
        int n = arr.length;
          
        int x = 4;
  
        int index = searchArray(arr, n, x);
        if (index == -1)
            System.out.println("Element is not present in the array");
        else
            System.out.println("Element is present at position " + index);
    }
}
