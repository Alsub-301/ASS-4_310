#include <iostream>
#include "Gradebook.h"
#include <vector>
#include <string>
//using specific
using std::cout;
using std::cin;
using std::string;
using std::vector;

Student stu;
//THIS IS A MUST FIX FOR 09/30
/*
    REMOVE GLOBAL STUDENT VARIABLE FROM setupSemester();- STUDENT stu
    ADD INITIALIZATION FUNCTION IN addStudent(); - SETS STUDENT ROSTER WITH STUDENT INFORMATION + ADDS IN #PROGRAMS + #TESTS + #FINALS
    RETURN STUDENTROSTER FROM addStudent() - THIS WILL THEN BE USED TO ADD IN THE GRADES BASED ON EACH STUDENT

*/


//clearing buffer function
void Gradebook::clearBuffer(){
    cin.clear();
    cin.ignore(100, '\n');
}

Gradebook::Gradebook(){
    numPrograms = 0;
    numTests = 0;
    numFinals = 0;
    programWeight = 0;
    testWeight = 0;
    finalWeight = 0;
}

//creating user menu with all options
void Gradebook::userMenu(){
    cout << "\n\tGradebook Menu\n";
    cout << "Please select an option Below\n";
    cout << "S: Setup a new Semester\n" <<
            "A: Add a student\n" <<
            "P: Record programming assignment grade\n" <<
            "T: Record test grade\n" <<
            "F: Record final exam grade\n" <<
            "C: Change grade\n" <<
            "G: Calculate final grades\n" <<
            "O: Output all grades\n" <<
            "Q: Quit Program\n";
}
char Gradebook::userChoiceValidation(){
    string input;
    char choice;
    char upperChoice;
    vector<char> options = {'S','A','P','T','F','C','G','O','Q'};
    while(true){
        cout << "Please enter option: ";
        getline(cin, input);
        if (input.length() == 1 && isalpha(input[0])){
            choice = input[0];
            upperChoice = toupper(choice);

            //check if the command is valid
            bool validChoice = false;
            for (char validOption : options){
                if (upperChoice == validOption){
                    validChoice = true;
                    //break;
                }
            }
            if (validChoice){
                return upperChoice;
            } else {
                cout << upperChoice << " is not a valid option\n";
                cout << "\n";
            }
        } else {
            cout << "Please enter a single letter. \n";
            cout << "\n";
        }
    }
}

void Gradebook::functionSelection(char option){
    switch (option)
    {
    case 'S':
        setupSemester();
        //cout << "Call setupSemester()\n";
        break;
    case 'A':
        addStudent();
        //cout << "Call addStudent()\n";
        break;
    case 'P':
        recordProgramGrade();
        //cout << "Call recordProgramGrade()\n";
        break;
    case 'T':
        //recordTestGrade();
        cout << "Call recordTestGrade()\n";
        break;
    case 'F':
        //recordFinalExamGrade();
        cout << "Call recordFinalExamGrade()\n";
        break;
    case 'C':
        //changeGrade();
        cout << "Call changeGrade()\n";
        break;
    case 'G':
        //calculateFinalGrade();
        cout << "Call calculateFinalGrade()\n";
        break;
    case 'O':
        //displayGradebook();
        cout << "Call displayGradebook()\n";
        break;
    }
}

//setting up gradebook for the semester
//VALIDATION - NEED TO CHECK IF SEMESTER IS ALREADY SETUP OR ELSE WILL OVERWRITE PREVIOUS DATA
void Gradebook::setupSemester(){
    int weightSum = 0;

    //prompt user num of programs + validation
    while(true){
        cout << "Please enter in the total number of programming assignments (0-6 only): ";
        cin >> numPrograms;
        if(cin.fail() || numPrograms < 0 || numPrograms > MAX_PROGRAMS){
            cout << "Please enter a number from 1 to 6\n";
            cout << "\n";
        } else {
            clearBuffer();
            break;
        }
        clearBuffer();
    }

    //prompt user num of test + validation
    while(true){
        cout << "Please enter in the total number of tests (0-4 only): ";
        cin >> numTests;
        if(cin.fail() || numTests < 0 || numTests > MAX_TESTS){
            cout << "Please enter a number from 1 to 4\n";
            cout << "\n";
        } else {
            clearBuffer();
            break;
        }
        clearBuffer();
    }

    //prompt user num of finals + validation
    while(true){
        cout << "Please enter in the total number of final exams (0-1 only): ";
        cin >> numFinals;
        if(cin.fail() || numFinals < 0 || numFinals > 1){
            cout << "Please enter a number from 0 to 1\n";
            cout << "\n";
        } else {
            clearBuffer();
            break;
        }
        clearBuffer();
    }
    
    //assigning numPrograms and numTests to student grade vectors for size
    //NEW(09/29) - NEED TO REMOVE AND ADD TO ADDSTUDENT();
    stu.setInitialGrades(numPrograms, numTests);

    //prompt user weight of programs + validation
    cout << "Please enter weights for programming assignments, tests and final exam\n";
    cout << "NOTE: All weights must not exceed 100%\n";
    cout << "\n";
    while(true){
        //getting weight of programming assignments
        //if no programming assignments, weight will be 0%
        while(true){
            if (numPrograms == 0){
                programWeight = 0; //if no programming assignments, then weight will be 0
                break;
            } else {
                cout << "Please enter weight for programming assignments: ";
                cin >> programWeight;
                if (cin.fail() || programWeight < 0 || programWeight > 100){
                    cout << "Please enter a vaild weight, from 0 to 100\n";
                    cout << "\n";
                } else {
                    clearBuffer();
                    break;
                }
            }
            clearBuffer();
        }
        //weight of tests
        while(true){
            if (numTests == 0){ //if there are no tests then weight will be 0
                testWeight = 0;
                break;
            } else {
                cout << "Please enter weight for tests: ";
                cin >> testWeight;
                if (cin.fail() || testWeight < 0 || testWeight > 100){
                    cout << "Please enter a vaild weight, from 0 to 100\n";
                    cout << "\n";
                    clearBuffer();
                } else {
                    break;
                }
            }
            clearBuffer();
        }
        //weight of final exam
        while(true){
            if (numFinals == 0){
                finalWeight = 0; //if no final then weight will be 0
                break;
            } else {
                cout << "Please enter weight for final exam: ";
                cin >> finalWeight;
                if (cin.fail() || finalWeight < 0 || finalWeight > 100){
                    cout << "Please enter a vaild weight, from 0 to 100\n";
                    cout << "\n";
                    clearBuffer();
                } else {
                    break;
                }
            }
            clearBuffer();
        }
        
        //calculating the sum all weights from programming assignments, tests, and final exam
        weightSum = programWeight + finalWeight + testWeight;

        //checking if weights add up to 100%
        if (weightSum > 100){ //checking if weight is over 100%
            cout << "Please enter weights again\n";
            cout << "Reminder that total weight from programming assignments + tests + final cannot exceed 100%\n";
            cout << "\n";
        }else if(weightSum < 100){ //checking if weight is under 100%
            if (numPrograms == 0 && numTests == 0 && numFinals == 0){
                cout << "Please enter at least 1 programming assignment, 1 test or 1 final exam\n";
                cout << "Please try to resetup the semester, command 'S'\n";
                break;
            } else {
                cout << "Please ensure that all weights add up to 100%\n";
                cout << "\n";
            }
        } else {
            clearBuffer();
            break;           
        }
    }
}

void Gradebook::addStudent(){
    //NEW (09/29) ADD IN INITIALIZATION FUNCTION  PRIOR TO ADDING IN TO STUDENTROSTER
    //creating student class object

    //asking user to enter lastName
    cout << "Please enter students full name\n" << "I.e. Doe, John: ";
    getline(cin, stu.lastName, ',');
    getline(cin, stu.firstName);
    //cout << "Last Name: " << s.lastName;
    //cout << "\nFirst Name: " << s.firstName;
    cout << "\n";

    while (true){
        cout << "Please enter students ID(1-9999): ";
        cin >> stu.studentID;

        //checking if id is valid
        if (cin.fail() || stu.studentID < 1 || stu.studentID > 9999){
            cout << "Please enter a valid student ID: 1-9999\n";
            cout << "\n";
        } else {
            clearBuffer();
            break;
        }

        //NEED TO VERIFY BEFORE COMMTTING
        stu.setInitialGrades(numPrograms, numTests);
        clearBuffer();
    }
    studentRoster.push_back(stu); //possibly chanage since this will add to end of vector

}

void Gradebook::printRoster(){
    for (Student eachStudent : studentRoster){
        cout << "Student Name: " << eachStudent.lastName << ", " << eachStudent.firstName << "\n";
        cout << "Student ID: " << eachStudent.studentID << "\n";
    }
}

//recording program grade based on user program choice
//TASK - need to create student roster before adding in grade
//VALIDATION - need to check if student roster empty/created
void Gradebook::recordProgramGrade(){
    int programNum;
    int pID;
    double grade;
    if (numPrograms == 0){
        cout << "Please ensure there is at least 1 program assignment\n";
    } else {
        if (studentRoster.empty()){
            cout << "Please create a student before proceeding\n";
        } else {
            //NEED TO BE ABLE TO SEARCH BASED ON STUDENTS FIRST/LAST NAME OR ID
            //FOR NOW WILL ONLY CHECK FOR ID
            cout << "Please enter student id: ";
            cin >> pID;
            for (Student tempID : studentRoster){
                if (pID == tempID.studentID){
                    cout << "Please enter in program number (1-" << numPrograms << "): ";
                    cin >> programNum;
                    if (cin.fail() || programNum > numPrograms){
                        cout << "Please enter in a valid program number between 1-" << numPrograms << "\n";
                    } else {
                        cout << "Please enter in grade for program " << programNum << ": ";
                        cin >> grade;
                    }
                    stu.setProgramGrade(programNum, grade);
                }
            }

            /*cout << "Please enter in program number 1-" << numPrograms << ": ";
            cin >> programNum;
            if ( programNum > numPrograms || programNum < 0){
                cout << "Please enter a valid program number!\n";
            }

            cout << "Please enter in grade for program " << programNum << ": ";
            cin >> grade;*/
            clearBuffer();
        }
    }
}