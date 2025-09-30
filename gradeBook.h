#pragma once
#include <vector>
#include "Student.h"
#define MAX_PROGRAMS 6
#define MAX_TESTS 4
//enum Choices {S,A,P,T,F,C,G,O,Q};
class Gradebook{
    public:
        Gradebook(); //constructor
        int numPrograms;
        int numTests;
        int numFinals; //either 0 or 1

        //will use standard 100% scale, not decimals
        int programWeight;
        int testWeight;
        int finalWeight;

        //prototype functions to setup gradebook
        void userMenu(); //done
        char userChoiceValidation(); //done
        void functionSelection(char); //done
        void setupSemester(); //done
        void addStudent(); //done, but does not read leading 0's: need to check trailing 0's
        void recordProgramGrade();
        void recordTestGrade();
        void recordFinalExamGrade();
        void changeGrade();
        double calculateFinalGrade();
        void displayGradebook();
        void printRoster();
        void quit();
        void clearBuffer();
        Student* findStudentById(int);
    private:
        std::vector<Student> studentRoster; //list of students
        //check if grades have been entered
        std::vector<bool> programGradeStatus;
        std::vector<bool> testGradeStatus; 
        bool finalExamGradeStatus;
};