package a1910081203;

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class ReadStudent {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        //파일 읽어옴
        FileInputStream fs = new FileInputStream("Student.txt");
        ObjectInputStream os = new ObjectInputStream(fs);

        // 파일의 끝에 도달하면 false
        boolean isReading = true;
        while (isReading) {
            try {
                Student stu =  (Student) os.readObject();
                System.out.println("이름: " + stu.getFName() + " " + stu.getLName());
                System.out.println("학번: " + stu.getsSdID());
                System.out.println("수강 과목: " + stu.getCourse()[0]);
            } catch(EOFException eof) {
                // 파일의 끝
                isReading = false;
            }
        }
    }
}
