#include <iostream>
#include <string>
using namespace std;

int findmin(int a, int b, int c) {
    int min_num = a;
    if (b < min_num) {
        min_num = b;
    }
    if (c < min_num) {
        min_num = c;
    }
    return min_num;
}

class STUDENT {
private:
    string name;
    float subject1_marks;
    float subject2_marks;
    float subject3_marks;

public:
    static int roll_number;
    
    void read_student_data(string name, float subject1_marks, float subject2_marks, float subject3_marks) {
        this->name = name;
        this->subject1_marks = subject1_marks;
        this->subject2_marks = subject2_marks;
        this->subject3_marks = subject3_marks;
        roll_number++;
    }

    void display_avg_marks() {
        float total = subject1_marks + subject2_marks + subject3_marks;
        float avg = (total - findmin(subject1_marks, subject2_marks, subject3_marks)) / 2;
        cout << "Average marks is " << avg << endl;
    }

    void display_student_info() {
        cout << "Student - " << name << ", roll number " << roll_number << endl;
    }
};

int STUDENT::roll_number = 0; // Initialize the static variable

int main() {
    STUDENT s1;
    s1.read_student_data("John", 90, 95, 96);
    s1.display_avg_marks();
    s1.display_student_info();
    STUDENT s2;
    s2.read_student_data("Alex", 80, 96, 94);
    s2.display_avg_marks();
    s2.display_student_info();

    STUDENT studentArray[2];
    studentArray[0] = s1;
    studentArray[1] = s2;
    return 0;
}
