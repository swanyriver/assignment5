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
#include <map>
#include <iterator>
#include <list>
#include "SwansonObjects/menu.hpp"
#include "SwansonLibs/swansonInput.hpp"

using namespace std;

void demonstrateComponent ();

int main () {

   string intro = "Lets make a lot of people!";

   GoItem myExerciseComp( demonstrateComponent , "" , intro );

   myExerciseComp.ItemSelected();

   return 0;

}

/////////////////////////////person class//////////
class Person {
private:
   string name;
   int age;

public:

   Person ( string pName , int pAge ) :
         name( pName ), age( pAge ) {
   }


   void having_birthday () {
      age++;
      cout << "Happy Birthday " << name << endl;
   }

   int GetAge () {
      return age;
   }

   string GetName () {
      return name;
   }

};

Person getPerson () {
   cout << "lets make a person";
   string pName = swansonInput::GetString( "what will that person's name: " );
   int pAge = swansonInput::GetInt( "how old is that person: ", 0 );
   return Person( pName , pAge );
}

void demonstrateComponent () {

   map<string, Person*> myPeople;

   //this array is unesecary to compliment our map, but for the sake of
   //exercise here it is.
   Person **myPeopleArray;
   int numpeople;

   do {
      Person myPerson = Person( getPerson() );

      //this line is very similar to a copy constructor
      myPeople[myPerson.GetName()] = new Person( myPerson.GetName() ,
            myPerson.GetAge() );

   } while ( swansonInput::yesNo( "make another person" ) );

   //make dynamic object array and fill it (backwards)
   numpeople = myPeople.size();
   myPeopleArray = new Person*[numpeople];

   std::map<string, Person*>::iterator it = myPeople.begin();

   for ( int i = 0 ; i < numpeople ; i++ ) {
      myPeopleArray[i] = it->second;
      it++;
      //cout << myPeopleArray[i]->GetName() <<" was added to an array" << endl;
   }

   //this was used to test map, notice the double -> ->
   /*for(it=myPeople.begin();it!=myPeople.end();it++)
    cout << it->second->GetName() << endl;*/

   for ( int i = 0 ; i < numpeople ; i++ ) {
      cout << myPeopleArray[i]->GetName() << "'s age is "
            << myPeopleArray[i]->GetAge() << endl;
   }

   while ( swansonInput::yesNo( "should one of them have a birthday" ) ) {
      string birthdayName = swansonInput::GetString( "who:" );
      while ( myPeople.count( birthdayName ) == 0 ) {
         birthdayName = swansonInput::GetString(
               "That isn't one of our friends\nwho should have a birthday:" );
      }

      myPeople[birthdayName]->having_birthday();

      for ( int i = 0 ; i < numpeople ; i++ ) {
         cout << myPeopleArray[i]->GetName() << "'s age is "
               << myPeopleArray[i]->GetAge() << endl;
      }
   }

   delete[] myPeopleArray;

}

