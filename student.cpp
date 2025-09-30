#include "Student.h"
#include <iostream>
#include <string>
#include <vector>



//initializing all variables
Student::Student(){
    studentID = -1; //not yet initialized
    programAvg = 0.0;
    testAvg = 0.0;
    finalSemesterGrade = 0.0;
}

void Student::setInitialGrades(int numPrograms, int numTests){
    //setting vectors to -1 to indicate empty vectors or grades have not been entered
    this->programGrades.assign(numPrograms, -1.0);
    this->testGrades.assign(numTests, -1.0);
    this->finalExamGrade = -1.0;

}

void Student::setProgramGrade(int programNum, double grade){
    for (int i = 0; i < programGrades.size(); i++){
        int programIndex = programNum - 1;
        if (programIndex == i){
            this->programGrades.at(programIndex) = grade;
            std::cout << "Added " << grade << " to program " << programNum << "\n";
        } else {
            std::cout << "Program number not found!\n";
        }
    }

    std::cout << "FOR TESTING PURPOSES\n" << "Printing out current program grade vector\n";
    for (double tempGrade : programGrades){
        std::cout << tempGrade << "\n";
    }

}