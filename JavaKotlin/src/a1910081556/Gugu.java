package a1910081556;

import java.util.Scanner;

public class Gugu {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(true) {
            // 메뉴 입력
            System.out.println("1. 구구단 출력");
            System.out.println("2. 프로그램 종료");
            int menu = in.nextInt();
            if(menu == 2) break;
            if(menu != 1) {
                System.out.println("잘못 입력하셨습니다.");
                continue;
            }

            System.out.println("출력할 구구단의 단을 입력하세요.");
            int gugu = in.nextInt();
            if(gugu < 2 || gugu > 9) {
                System.out.println("잘못 입력하셨습니다. 다시 입력하세요.");
                continue;
            }
            for(int i=1; i<=9; i++)
                System.out.println(gugu + " * " + i + " = " + (gugu * i));
        }

        System.out.println("이용해주셔서 감사합니다.");
    }
}
