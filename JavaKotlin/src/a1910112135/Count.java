package a1910112135;

import java.util.Scanner;

public class Count {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("enter students grade:");
        String grade = input.next();
        input.nextLine();
        int aCount = 0;
        int bCount = 0;
        int cCount = 0;
        int dCount = 0;
        switch (grade) {
            case "A":
                ++aCount;
                break;
            case "B":
                ++bCount;
                break;
            case "C":
                ++cCount;
                break;
            case "D":
                ++dCount;
                break;
        }
        System.out.printf("%n%s%n%s%d%n%s%d%n%s%d%n%s%d%n",
                "number of students who received each grade:",
                "A:", aCount,
                "B:", bCount,
                "C:", cCount,
                "D:", dCount);
    }
}
