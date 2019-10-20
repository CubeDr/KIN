package a1910151234;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Time {
    public static void main(String[] args) throws ParseException {
        // 입력받은 문자열
        String a = "11:11:11";
        String b = "01:01:01";

        // 문자열의 형식
        SimpleDateFormat format = new SimpleDateFormat("HH:mm:ss");

        // Date로 변환
        Date d1 = format.parse(a);
        Date d2 = format.parse(b);

        // 연산을 위해 Calendar로 변환
        Calendar c1 = Calendar.getInstance();
        c1.setTime(d1);

        Calendar c2 = Calendar.getInstance();
        c2.setTime(d2);

        // 두 시간 더하기
        c1.add(Calendar.HOUR, c2.get(Calendar.HOUR));
        c1.add(Calendar.MINUTE, c2.get(Calendar.MINUTE));
        c1.add(Calendar.SECOND, c2.get(Calendar.SECOND));

        // 문자열 형식에 맞춰 출력
        String formatted = format.format(c1.getTime());
        System.out.println(formatted);
    }
}
