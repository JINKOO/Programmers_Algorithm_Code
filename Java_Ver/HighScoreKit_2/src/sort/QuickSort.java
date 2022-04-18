package sort;

import java.util.Arrays;

public class QuickSort {

    int[] arr = {6, -8, 1, 12, 8, 3, 7, -7};

    public void quickSort(int start, int end) {
        if (start + 1 >= end) {
            return;
        }
        printSortedArray();
        int pivot = arr[start];
        int leftIndex = start + 1;
        int rightIndex = end - 1;
        System.out.println(start + ", " + leftIndex + ", " + rightIndex + ", " + end);

        while(true) {
            while(leftIndex <= rightIndex && arr[leftIndex] <= pivot) {
                leftIndex++;
            }
            while(leftIndex <= rightIndex && arr[rightIndex] > pivot) {
                rightIndex--;
            }
            if (leftIndex > rightIndex) {
                break;
            }
            swap(leftIndex, rightIndex);
        }
        swap(start, rightIndex);
        quickSort(start, rightIndex);
        quickSort(rightIndex + 1, end);
    }

    public void swap(int e1, int e2) {
        int temp = arr[e1];
        arr[e1] = arr[e2];
        arr[e2] = temp;
    }

    public void printSortedArray() {
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String[] args) {
        QuickSort sort = new QuickSort();

        sort.quickSort(0, 8);
        sort.printSortedArray();
    }
}
