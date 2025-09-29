#include <iostream>
#include "Gradebook.h"
#include "Student.h"

using namespace std;


int main(){
    Gradebook gb;
    char user;

    while (user != 'Q'){
        gb.userMenu();
        user = gb.userChoiceValidation();
        gb.functionSelection(user);
    }
    gb.printRoster();
}