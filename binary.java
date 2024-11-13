import java.util.Scanner;

public class BinarySearch {
    // Binary search method
    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            // Check if target is present at mid
            if (array[middle] == target) {
                return middle;
            }

            // If target is greater, ignore the left half
            if (array[middle] < target) {
                left = middle + 1;
            }
            // If target is smaller, ignore the right half
            else {
                right = middle - 1;
            }
        }

        // Target was not found in the array
        return -1;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        // Get array size from the user
        System.out.print("Enter the number of elements in the array: ");
        int n = s.nextInt();
        int[] array = new int[n];

        // Input sorted array elements from the user
        System.out.println("Enter " + n + " sorted elements:");
        for (int i = 0; i < n; i++) {
            array[i] = s.nextInt();
        }

        // Get the target element to search for
        System.out.print("Enter the number to search for: ");
        int target = s.nextInt();

        // Perform binary search and display the result
        int result = binarySearch(array, target);

        if (result == -1) {
            System.out.println("Element not found in the array.");
        } else {
            System.out.println("Element found at index: " + result);
        }

        s.close();
    }
}
