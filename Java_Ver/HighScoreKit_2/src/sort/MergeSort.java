package sort;

import java.util.Arrays;

public class MergeSort {

    public int[] arr = {6, -8, 1, 12, 8, 15, 7, -7};
    public int[] tmp = new int[10];

    // 1. 주어진 배열을 절반으로 나누고,
    // 2. 나누어진 배열을 정렬하고,
    // 3. 합병.
    public void mergeSort(int start, int end) {
        // base condition
        if (start + 1 == end) {
            return;
        }
        int mid = (start + end) / 2;
        System.out.println(start + ", " + mid + ", " + end);
        mergeSort(start, mid);
        mergeSort(mid, end);
        merge(start, end);
    }

    public void merge(int start, int end) {

        int mid = (start + end) / 2;
        System.out.println("merge() : " + start + ", " + (mid + 1) + ", " + end);
        int leftIndex = start;
        int rightIndex = mid;

        for (int i = start; i < end; i++) {
            if (leftIndex == mid) {
                tmp[i] = arr[rightIndex++];
            } else if (rightIndex == end) {
                tmp[i] = arr[leftIndex++];
            } else if (arr[leftIndex] <= arr[rightIndex]) {
                tmp[i] = arr[leftIndex++];
            } else {
                tmp[i] = arr[rightIndex++];
            }
        }
        for (int i = start; i < end; i++) {
            arr[i] = tmp[i];
        }
        System.out.println(Arrays.toString(tmp));
    }

    public void printArray() {
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String[] args) {
        MergeSort sort =  new MergeSort();

        sort.mergeSort(0, sort.arr.length);
        sort.printArray();

    }
}
