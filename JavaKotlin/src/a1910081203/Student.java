package a1910081203;

import java.io.*;
import java.util.Arrays;

public class Student implements Serializable{
    private static final long serialVersionUID = 1L;
    private int stdID;
    private String firstName;
    private String LastName;
    private String[] Course;

    public Student() { }

    public Student(int stdID, String firstName, String LastName, String[] Course) {
        this.stdID = stdID;
        this.firstName = firstName;
        this.LastName = LastName;
        // 배열의 복사
        this.Course = Arrays.copyOf(Course, Course.length);
    }
    public int getsSdID() {
        return stdID;

    }
    public String getFName() {
        return firstName;
    }
    public String getLName() {
        return LastName;
    }
    public String[] getCourse() {
        // 복사하여 반환
        return Arrays.copyOf(Course, Course.length);
    }
}