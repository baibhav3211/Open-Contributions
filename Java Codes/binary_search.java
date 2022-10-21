// Java implementation of recursive Binary Search

class SearchBinary
{
    // Returns index of x if it is present in arr[l… r], else return -1
    int SearchBinary(int arr[], int l, int r, int x)
    {
        if (r>=l)
        {
            int mid_value = l + (r - l)/2;
   
            // If the element is present at the middle value itself
            if (arr[mid_value] == x)
               return mid_value;
   
            // If element is smaller than mid_value, then it means it can only be present in left subarray
            if (arr[mid_value] > x)
               return SearchBinary(arr, l, mid_value-1, x);
   
            // Else the element can only be present in right subarray
            return SearchBinary(arr, mid_value+1, r, x);
        }
   
        // if the element is not present in array
        return -1;
    }
   
    
public static void main(String args[])
    {
        SearchBinary object = new SearchBinary();
        int arr[] = {2,3,4,10,40};
        int n = arr.length;
        int x = 10;
        int result = object.SearchBinary(arr,0,n-1,x);
        if (result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element is present at index " + 
                                                 result);
    }
}
