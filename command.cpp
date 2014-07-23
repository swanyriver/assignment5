/***********************************************************
 *
 * * Author: Brandon Swanson
 *
 * * Date Created: 07-22-2014
 *
 * * Last Modification Date: 07-22-2014
 *
 * * Filename:
 *
 *
 * * Overview: Week 5 Exercise Component #
 * *
 * * Input:
 * *
 * * Output:
 * *
 * ***********************************************************/

#include <iostream>
#include <string>
#include "SwansonObjects/menu.hpp"
#include "SwansonLibs/swansonInput.hpp"

using namespace std;

void demonstrateComponent ();

/////////////////////PART A/////////////////
struct person {
   string name;
   int age;
};

person new_person ();

int numArgs;
char** arguments;

int main (int argc, char** argv) {

   numArgs = argc;
   arguments = argv;

   string intro = "Lets Make A person and then give him command line friends";

   GoItem myExerciseComp( demonstrateComponent , "" , intro );

   myExerciseComp.ItemSelected();


   return 0;


}

void demonstrateComponent () {
   int NUM_PERSONS = numArgs-1;

   /////////////////////PART B/////////////////
   //cout << "first we will make a person with a pointer to them";
   person ourPerson = new_person();
   person *pointPerson = &ourPerson;
   /////////////////////PART C & D/////////////////
   cout << "Our new person is named " << pointPerson->name << " and is "
         << pointPerson->age << " years old" << endl;

   /////////////////////PART E/////////////////
   person *friends = new person[NUM_PERSONS];

   /////////////////////problem 3////////////////////////////////
   person *friend_pointers[NUM_PERSONS];

   cout << "now lets get their friends from the command line" << endl;

   ////////////////////////COMMAND.CPP///////////////////
   for ( int index = 0 ; index < NUM_PERSONS ; ++index ) {
      friends[index].name = string(arguments[index+1]);
      /////////////////////problem 3////////////////////////////////
      friend_pointers[index] = &friends[index];
      ////or
      friend_pointers[index] = friends+index;
   }

   cout << pointPerson->name << " has " << NUM_PERSONS << " friends, They are:";
   for ( int index = 0 ; index < NUM_PERSONS ; ++index ) {
      /////////////////////problem 3////////////////////////////////
      cout << endl << friend_pointers[index]->name;
   }

   delete[] friends;

}

person new_person () {
   person myPerson;
   myPerson.name = swansonInput::GetString( "what will be your name: " );
   myPerson.age = swansonInput::GetInt( "what is your age: " );

   return myPerson;
}

