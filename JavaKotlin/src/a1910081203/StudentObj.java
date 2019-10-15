package a1910081203;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.Scanner;
public class StudentObj {
    public static void main(String[] arg) throws IOException{

        Scanner scan = new Scanner(System.in);

        int stdID = 0;
        String firstName = null;
        String lastName = null;
        String[] Course = new String[1];

        try {
            //student라는 파일에 저장
            FileOutputStream fos = new FileOutputStream(new File("Student.std"));
            ObjectOutputStream os = new ObjectOutputStream(fos);

            //입력
            System.out.println("Student ID");
            stdID = scan.nextInt();
            scan.nextLine();

            System.out.print("First Name : ");
            firstName = scan.nextLine();

            System.out.print("Last Name : ");
            lastName = scan.nextLine();
            System.out.print("Course : ");
            Course[0] = scan.nextLine();

            Student student = new Student(stdID, firstName, lastName, Course);
            os.writeObject(student);
            os.close();
        }catch(IOException e) {
            System.out.println(e.getMessage());
        }

    }
}