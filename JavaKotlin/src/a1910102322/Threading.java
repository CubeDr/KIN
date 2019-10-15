package a1910102322;

import javafx.util.Pair;

import java.util.Scanner;

public class Threading {

    private static Pair<Integer, Integer> inputData() {
        System.out.println("예) a+b=c");

        Scanner in = new Scanner(System.in);
        System.out.print("1_숫자를 입력하세요. >>");
        int a = in.nextInt();
        System.out.println("2_숫자를 입력하세요. >>");
        int b = in.nextInt();
        in.close();

        return new Pair<>(a, b);
    }

    private static double add(int a, int b) {
        return a + b;
    }

    private static double substract(int a, int b) {
        return a - b;
    }

    private static double divide(int a, int b) {
        return a / b;
    }

    private static double rest(int a, int b) {
        return a * b;
    }

    public static void main(String[] args) {
        Pair<Integer, Integer> input = inputData();
        Thread th1 = new Thread(new Arithmetic(input.getKey(), input.getValue()));

        long startTime = System.currentTimeMillis();
        th1.start();
        long endTime = System.currentTimeMillis();
        System.out.println("\\n\\n -- WorkingTime: " + (endTime - startTime)/1000.0 + " sec --");
    }

    static class Arithmetic implements Runnable {
        private int a, b;

        public Arithmetic(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public void run() {
            System.out.printf("\n add : %.1f \\n substract : %.1f \\n divide : %.1f \\n rest %.1f",
                    add(a, b), substract(a, b), divide(a, b), rest(a, b));
        }
    }
}
