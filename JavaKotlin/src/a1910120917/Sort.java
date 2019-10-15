package a1910120917;

import java.util.Arrays;
import java.util.Random;

public class Sort {
    public static void main(String[] args) {
        int[] arr = new int[6];
        Random r = new Random();
        for(int i=0; i<6; i++) {
            int v;
            boolean success = true;

            do {
                success = true;
                v = r.nextInt(20) + 1;
                for(int j=0; j<i; j++) {
                    if(arr[j] == v) {
                        success = false;
                        break;
                    }
                }
            } while(!success);

            arr[i] = v;
        }

        System.out.println("원본: ");
        for(int v: arr) System.out.print(v + " ");
        System.out.println();

        Arrays.sort(arr);

        System.out.println("정렬: ");
        for(int v: arr) System.out.print(v + " ");
        System.out.println();
    }
}
