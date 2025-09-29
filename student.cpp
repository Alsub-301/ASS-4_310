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