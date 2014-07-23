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

Person getPerson(){
   cout << "lets make a person";
   string pName = swansonInput::GetString( "what will that person's name: " );
   int pAge = swansonInput::GetInt( "how old is that person: " );
   return Person( pName, pAge);
}

void DisplayInfoAboutPerson(){
   cout << myPersonPoint->GetName() <<" is "
         << myPersonPoint->GetAge() << " years old" << endl;
}
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




