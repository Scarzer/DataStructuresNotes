# ADT and C++ Classes (I)
* ADT -> Abstract Data Types

## A Review of C++ Classes
* OPP, ADTs, and Classes
* Class Definitions
* Other bullshit crapz

## OOP
* OPP is the typical approch to programming which supports the creation ofnew data types andoperations to manipulate those types

* Difference between C and C++ 
** C++ is just C structures with members as well as methods that work on those members

* Class
    * Mechanism to create objects and member functions
    * Support information hiding

* Abstract Data Types (ADTs)
    * Mathematical Data Type
    * Class as an ADT tht programmers can use without knowing how the member functions are implemented. i.e with information hiding 

### A Point ADT
* A data type to store and manipulate a single point on a plane
* Manipuations
    * Initialize the point. Tell it exactly where it has to go!
    * Retrieval Coordinates. Get that shit back!
    * Shift Coordinates. Move it around so that it is actually useful!

* .h files
    * How can we implement the point? We use a class
    ```c++
    class point{
    // This all goes into a .h header file!!
        public: // Public variables that EVERYBODY can get a turn with :P
            void init( double initX, double initY);
            void shift( double dx, double dy);
            double getX() const;
            double getY() const;
            // All the function bodies will be somewhere else

        private: // This is so that the only way to access the values, is using functions! Typically getter/setters
            double x;
            double y;
    };
    ```
    * The header file is where we are going to be keeping the Postconditions and the Preconditions. This is going to be the documetntations
    * The actual shtuffz are going to be in .cpp files! 

* .cpp files
    * The CPP file will hold all the important crap that you ned
    ```c++
    #include <iostream.h>
    #include <stdlib.h>
    #include "point.h"

    int main(){
        // We're creating the objects. Instancing them
        point p1;
        point p2;

        // Now they're doing something
        p1.init(-1.0, 0.8);
        
        }
    ```
    

    }
