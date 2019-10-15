package a1910141117;

public class Count {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4, 5, 1, 1, 1, 2 };

        int c_1 = 0;
        int c_2 = 0;

        for(int v: nums) {
            if(v == 1) c_1++;
            else if(v == 2) c_2++;
        }

        System.out.println("Total occurrence of 1 is " + c_1);
        System.out.println("Total occurrence of 2 is " + c_2);
    }
}
