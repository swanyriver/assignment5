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

int main () {

   string intro = "welcome to People with Friends";

   GoItem myExerciseComp( demonstrateComponent , "" , intro );

   myExerciseComp.ItemSelected();

   return 0;

}

void demonstrateComponent () {
   const int NUM_PERSONS = 5;

   /////////////////////PART B/////////////////
   cout << "first we will make a person with a pointer to them";
   person ourPerson = new_person();
   person *pointPerson = &ourPerson;
   /////////////////////PART C & D/////////////////
   cout << "Our new person is named " << pointPerson->name << " and is "
         << pointPerson->age << " years old" << endl;

   /////////////////////PART E/////////////////
   person friends[NUM_PERSONS];

   /////////////////////problem 3////////////////////////////////
   person *friend_pointers[NUM_PERSONS];

   cout << "now we will make some friends for our person" << endl;

   for ( int index = 0 ; index < NUM_PERSONS ; ++index ) {
      friends[index].name = swansonInput::GetString(
            "what is friend " + swansonString::GetString( index + 1 )
                  + "'s name: " );
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
}

person new_person () {
   person myPerson;
   myPerson.name = swansonInput::GetString( "what will be your name: " );
   myPerson.age = swansonInput::GetInt( "what is your age: " );

   return myPerson;
}

