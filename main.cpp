/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2
 
 Create a branch named Part1
 
 Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.
 
 Pointers
 
 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 
 
 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)              X
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
 note the name of the variable used in the compare function                                                         X
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().        X
 note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value                X
 be sure to make it work with the pointer semantics being used in the if statements.            X
 see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
 Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.     X
 Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works                             X
 
 8) call f.compare() with the correct arguments, based on 2) and 5)                             X
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
 the possible return values of the compare() function should give you a hint.                   X
 
 10) complete the implementation for the static function in <structName2>                       X
 
 11) call the <structName2> static function correctly in main()                                 X
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?  --> check for nullptr
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.
 
 send me a DM to check your pull request
 
 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    int value;
    std::string name;
    
    T(int v, const char* n) : value(v), name(n) {}
};

struct Comparator                                //4
{
    T* compare(T* a, T* b) //5
    {
        if (a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float nameOne { 0.f }, nameTwo { 0.f };
    
    float staticFunctionReplicate(float* updatedValue )        //12
    {
        if (updatedValue != nullptr)
        {
            std::cout << "U's nameOneRepl value: " << this->nameOne << std::endl;
            this->nameOne = *updatedValue;
            
            std::cout << "U's nameOneRepl updated value: " << this->nameOne << std::endl;
            
            while(std::abs(this->nameTwo - this->nameOne) > 0.001f)
            {
                /*
                 write something that makes the distance between that->nameTwo and that->nameOne get smaller
                 */
                this->nameTwo -= 0.001f;
            }
            std::cout << "U's nameTwoRepl updated value: " << this->nameTwo << std::endl;
            
            return this->nameTwo * this->nameOne;
        }
        
        std::cout << "updated val is nullptr!" << std::endl;
        return 0;
    }
};

struct StructNameTwo
{
    static float staticFunctionA(U* that, float* updatedValue )        //10
    {
        
        if (that != nullptr || updatedValue != nullptr)
        {
            std::cout << "U's nameOne value: " << that->nameOne << std::endl;
            that->nameOne = *updatedValue;
            std::cout << "U's nameOne updated value: " << that->nameOne << std::endl;
            while( std::abs(that->nameTwo - that->nameOne) > 0.001f )
            {
            /*
            write something that makes the distance between that->nameTwo and that->nameOne get smaller
             */
            that->nameTwo -= 0.001f;
            }
            std::cout << "U's nameTwo updated value: " << that->nameTwo << std::endl;
        
            return that->nameTwo * that->nameOne;
        }
                  
        return 0.f;
    }
};

        
int main()
{
    T rabbit(2, "Osterhase" );                                             //6
    T dolphin(10, "Flipper" );                                             //6
    
    Comparator f;                                            //7
    auto* smaller = f.compare(&rabbit, &dolphin);                              //8
    
    if (smaller != nullptr)
        std::cout << "\nthe smaller one is << " << smaller->name << std::endl; //9
    
    U nameThree;
    float updatedValue = 5.f;
    std::cout << "[static func] nameThree's multiplied values: " << StructNameTwo::staticFunctionA(&nameThree, &updatedValue ) << std::endl;                  //11
    
    U nameFour;
    std::cout << "[member func] nameFour's multiplied values: " << nameFour.staticFunctionReplicate( &updatedValue ) << std::endl;
}