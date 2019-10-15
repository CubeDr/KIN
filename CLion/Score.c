//
// Created by HyunI on 2019-07-11.
//

typedef struct _Grade {
    int korean;
    int english;
    int math;
} Grade;

int gradeSum(const Grade * grade) {
    return grade->korean +
            grade->english +
            grade->math;
}

float gradeAverage(const Grade * grade) {
    return gradeSum(grade) / 3.0f;
}

typedef struct _Student {
    int number;
    Grade grade;
} Student;

Student

int main() {
    return 0;
}