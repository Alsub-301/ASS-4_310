#pragma once
#include <string>
#include <vector>


class Student {
    public:
        //constructor for student class
        Student();
        std::string lastName, firstName; //both less or equal to 20 characters
        int studentID; //between 1-9999
        double programAvg;
        double testAvg;
        double finalSemesterGrade;
        void setInitialGrades(int, int);
        void setProgramGrade(int, double);
    private:
        //vectors to hold all grades for students
        std::vector<double> programGrades;
        std::vector<double> testGrades;
        double finalExamGrade;

};