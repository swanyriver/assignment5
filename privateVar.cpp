/***********************************************************
 *
 * * Author: Brandon Swanson
 *
 * * Date Created: 07-22-2014
 *
 * * Last Modification Date: 07-25-2014
 *
 * * Filename: privateVar.cpp
 *
 *
 * * Overview: Week 5 Exercise Component
 * *
 * * Input: Person name and age
 * *
 * * Output: Info about person
 * *
 * ***********************************************************/


#include <iostream>
#include <string>
#include "SwansonObjects/menu.hpp"
#include "SwansonLibs/swansonInput.hpp"

using namespace std;

void demonstrateComponent();



int main(){

   string intro = "This is one Private Person!";


   GoItem myExerciseComp(demonstrateComponent,"",intro);

   myExerciseComp.ItemSelected();

   return 0;

}

/////////////////////////////person class//////////
class Person{
private:
   string name;
   int age;

public:

   Person(string pName, int pAge):name(pName),age(pAge){};

   void having_birthday(){
      age++;
     // cout << name << " is now " << age << " years old" << endl;
   }

   int GetAge(){
      return age;
   }

   string GetName(){
      return name;
   }

};

Person *myPersonPoint; //global pointer to my person

/***********************************************************************
 *Purpose: construct a person, using input from user
 *
 *Entry: none
 *
 *Exit: A fully constructed person
 *
 **********************************************************************/
Person getPerson(){
   cout << "lets make a person";
   string pName = swansonInput::GetString( "what will that person's name: " );
   int pAge = swansonInput::GetInt( "how old is that person: ", 0 );
   return Person( pName, pAge);
}

/***********************************************************************
 *Purpose: use accessor methods of person to display their info
 *
 *Entry: myPersonPoint initialized
 *
 *Exit: display info
 *
 **********************************************************************/
void DisplayInfoAboutPerson(){
   cout << myPersonPoint->GetName() <<" is "
         << myPersonPoint->GetAge() << " years old" << endl;
}

/***********************************************************************
 *Purpose: use mutator method of person to increment age
 *
 *Entry: myPersonPoint initialized
 *
 *Exit: person age is 1 more
 *
 **********************************************************************/
void PersonHasBirthday(){
   myPersonPoint->having_birthday();
}

void demonstrateComponent(){
   Person realPerson = getPerson();
   myPersonPoint = &realPerson;

   Menu personMenu("What should we do with " + myPersonPoint->GetName());

   personMenu.addItem(new GoItem(DisplayInfoAboutPerson, "Display age", ""));
   personMenu.GetLastItem()->hasIntro=false;
   personMenu.GetLastItem()->itemRepeat=false;
   personMenu.addItem(new
         GoItem(PersonHasBirthday, "Have a Birthday", "Happy Birthday"));
   personMenu.GetLastItem()->itemRepeat=false;

   personMenu.clearScreenON = false;
   personMenu.showMenu();

}




