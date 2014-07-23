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

   string intro = "This is one Classy Person!";


   GoItem myExerciseComp(demonstrateComponent,"",intro);

   myExerciseComp.ItemSelected();

   return 0;

}

/////////////////////////////person class//////////
class Person{
public:
   string name;
   int age;

   Person(string pName, int pAge):name(pName),age(pAge){};

   void having_birthday(){
      age++;
      cout << name << " is now " << age << " years old" << endl;
   }
};

Person getPerson(){
   cout << "lets make a person";
   //I was experimenting with using these input calls as arguments
   //the really interesting thing is that the second arguments function gets
   //called first.
   //this could easily be changed but i am leaving it as an example for myself
   return Person( swansonInput::GetString( "what will that person's name: " ),
         swansonInput::GetInt( "how old is that person: " ));
}

void demonstrateComponent(){
   Person myPerson = getPerson();

   while(swansonInput::yesNo("did the person have a birthday")){
      myPerson.having_birthday();
   }
}




