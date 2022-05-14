package sort;

import java.util.*;

class Student {
    int age;
    String name;

    Student(int age, String name) {
        this.age = age;
        this.name = name;
    }
}

public class BasicSort {

    // 버블 정렬
    public void bubbleSort() {
        int[] arr = {8, 3, 7, 5, 4, 2};
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j + 1] > arr[j]) {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        System.out.println(Arrays.toString(arr));
    }

    // 선택 정렬
    // 최솟값을 찾아서 swap을 진행한다.
    public void selectionSort() {
        int[] arr = {8, 3, 7, 5, 4, 2};
        for (int i = 0; i < arr.length; i++) {
            int minIndex = i;

            for (int j = i + 1; j < arr.length; j++) {
                if (arr[minIndex] > arr[j]) {
                    minIndex = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        System.out.println(Arrays.toString(arr));
    }

    // 삽입 정렬
    public void insertionSort() {
        int[] arr = {8, 3, 7, 5, 4, 2};

        for (int i = 1; i < arr.length; i++) {

            int target = arr[i];
            int j = i - 1;
            while (j >= 0 && target < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = target;
        }
        System.out.println("insertion :: " + Arrays.toString(arr));
    }

    // Custom 객체 정렬
    public void mySort() {
        List<Student> students = new ArrayList<>();
        students.add(new Student(30, "JinKweon Ko"));
        students.add(new Student(27, "SeoYoung Park"));
        students.add(new Student(27, "HaeJin Shin"));
        students.add(new Student(29, "KwangHoon_Lee"));
        students.add(new Student(28, "yongHoon_jeong"));

        Collections.sort(students, new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                if (o1.age == o2.age) {
                    return (o1.name).compareTo(o2.name);
                }
                return o1.age - o2.age;
            }
        });

        for (Student s : students) {
            System.out.println(s.age + ", " + s.name);
        }
    }

    public void mySort2() {
        Integer[] arr = {8, 3, 7, 5, 4, 2};
        Arrays.sort(arr, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1.compareTo(o2);
            }
        });
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String[] args) {
        BasicSort sort = new BasicSort();

        sort.bubbleSort();
        sort.selectionSort();
        sort.insertionSort();

        sort.mySort();
        sort.mySort2();

        Set<Student> set = new HashSet<>();
        set.add(new Student(21, "KO"));
        set.add(new Student(21, "KO"));
        System.out.println(set.size());
    }
}
