/***********************************************************
 *
 * * Author: Brandon Swanson
 *
 * * Date Created: 07-22-2014
 *
 * * Last Modification Date: 07-22-2014
 *
 * * Filename: personStruct.cpp
 *
 *
 * * Overview: Week 5 Exercise Component
 * *
 * * Input:age and name of person
 * *
 * * Output:info about person
 * *
 * ***********************************************************/


#include <iostream>
#include <string>
#include "SwansonObjects/menu.hpp"
#include "SwansonLibs/swansonInput.hpp"

using namespace std;

void demonstrateComponent();

struct person{
   string name;
   int age;
};

person new_person();

int main(){

   string intro = "Lets make a new person";


   GoItem myExerciseComp(demonstrateComponent,"",intro);

   myExerciseComp.ItemSelected();

   return 0;

}

void demonstrateComponent(){

   person ourPerson = new_person();
   cout << "Our new person is named " << ourPerson.name << " and is "
         << ourPerson.age << " years old" << endl;
}

/***********************************************************************
 *Purpose: construct a person, using input from user
 *
 *Entry: none
 *
 *Exit: A fully constructed person
 *
 **********************************************************************/
person new_person(){
   person myPerson;
   myPerson.name = swansonInput::GetString("what will be your name: ");
   myPerson.age = swansonInput::GetInt("what is your age: ", 0);

   return myPerson;
}



