// Java Program to linearly Search an element in an Array Recursively
 
public class Search {
 
    static int searchRecursive(int arr[], int l, int r,
                               int x)
    {
        if (r < l)      //element is not present in the array
            return -1;
 
        if (arr[l] == x)
            return l;
 
        if (arr[r] == x)
            return r;

        return searchRecursive(arr, l + 1, r - 1, x);   // As the element is not found on both left most and rightmost positions,so now recurse the array to find position of x. 
    }
 
   

    public static void main(String[] args)
    {
        int x = 3;   // Element to be searched for

        int arr[] = new int[] { 25, 60, 18, 3, 10 };
        int index = searchRecursive(arr, 0, arr.length - 1, x);
        if (index != -1)
            System.out.println("Element " + x + " is present at index " + index); //if the element is present in the array
 
        else
            System.out.println("Element " + x + " is not present");  //if element is not present in the array
    }
}
