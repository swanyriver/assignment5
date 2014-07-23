/*
 * exerciseComponents.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: brandon
 */

#include <iostream>
#include "SwansonObjects/menu.hpp"
#include "SwansonObjects/CompileMenuItem.hpp"
#include <string>
#include <list>

using namespace std;

int main() {

   list<string> myExercises;

   myExercises.push_back("personStruct");
   myExercises.push_back("structPointer");
   myExercises.push_back("pointerArray");
   myExercises.push_back("command bob tim jake sally thomas joseph reed");
   myExercises.push_back("personClass");
   myExercises.push_back("privateVar");
   myExercises.push_back("object");

   /*
    * personStruct.cpp
      structPointer.cpp
      pointerArray.cpp
      command.cpp
      personClass.cpp
      privateVar.cpp
      object.cpp
    *
    */

   while(true) {
      AutoCompileMenu myMenu(myExercises);

      myMenu.showMenu();
   }


}

