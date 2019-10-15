package a1910132147;

import java.util.Scanner;

public class Primes {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // 최대 값 입력
        System.out.print("max: ");
        int max = in.nextInt();

        // 각 인덱스가 소수인지 아닌지를 저장하는 배열
        boolean[] isPrime = new boolean[max + 1];
        for(int i=0; i<=max; i++)
            isPrime[i] = true;
        isPrime[0] = isPrime[1] = false;

        // 모든 숫자를 검사하면서
        for (int i = 2; i <= max; i++) {
            if (!isPrime[i]) continue;

            // 소수의 배수들에게 소수가 아님을 표시
            for (int j = 2*i; j <= max; j += i)
                isPrime[j] = false;
        }

        // 소수 표시가 되어있는 숫자들 출력
        for(int i=0; i<=max; i++)
            if(isPrime[i])
                System.out.println(i);
    }
}
