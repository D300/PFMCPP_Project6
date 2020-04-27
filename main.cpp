/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    
    float staticFunctionReplicate(const float& updatedValue )        //12
    {
        // if (updatedValue != nullptr)
        // {
            std::cout << "U's nameOneRepl value: " << this->nameOne << std::endl;
            this->nameOne = updatedValue;
            
            std::cout << "U's nameOneRepl updated value: " << this->nameOne << std::endl;
            
            // abs(0 - 5) > 1
            while(std::abs(this->nameTwo - this->nameOne) > 1.f)
            {
                /*
                 write something that makes the distance between that->nameTwo and that->nameOne get smaller
                 */
                auto tempOne = std::abs(this->nameTwo - this->nameOne);
                std::cout << "shrinking distance: " << tempOne << std::endl;

                this->nameTwo += 0.1f;  
            }
            std::cout << "U's nameTwoRepl updated value: " << this->nameTwo << std::endl;
            
            return this->nameTwo * this->nameOne;
        // }
        
        // std::cout << "updated val is nullptr!" << std::endl;
        // return 0;
    }
};

struct StructNameTwo
{
    static float staticFunctionA(U& that, const float& updatedValue )        //10
    {
        std::cout << "U's nameOne value: " << that.nameOne << std::endl;
        that.nameOne = updatedValue;
        
        std::cout << "U's nameOne updated value: " << that.nameOne << std::endl;


        while( std::abs(that.nameTwo - that.nameOne) > 0.001f )
        {
            /*
              
            write something that makes the distance between that->nameTwo and        that->nameOne get smaller
            */
            auto tempTwo = std::abs(that.nameTwo - that.nameOne);
        
            that.nameTwo += 0.1f;

            std::cout << "shrinking distance\n" << tempTwo << std::endl;
        }
        std::cout << "U's nameTwo updated value: " << that.nameTwo << std::endl;
        
        return that.nameTwo * that.nameOne;
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
    const float updatedValue = 5.f;
    std::cout << "[static func] nameThree's multiplied values: " << StructNameTwo::staticFunctionA(nameThree, updatedValue ) << std::endl;                  //11
    
    U nameFour;
    std::cout << "[member func] nameFour's multiplied values: " << nameFour.staticFunctionReplicate( updatedValue ) << std::endl;

        

    // StructNameTwo::staticFunctionA(nullptr, &updatedValue );
    // StructNameTwo::staticFunctionA(&nameThree, nullptr );

    std::cout << "this is the end" << std::endl;
}
