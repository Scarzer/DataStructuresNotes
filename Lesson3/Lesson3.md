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
            // Book verison => void init( double initX, double initY);
            void setPositon (double x, double y); //Same function as above, but a more accept naming convention
            void shift( double dx, double dy);
            double getX() const;    // Tells the compiler to keep the variables constant!
            double getY() const;
            // All the function bodies will be somewhere else

        private: // This is so that the only way to access the values, is using functions! Typically getter/setters
            double _x;
            double _y;
    };
    // Do not forget to put the semicolon
    ```
        * Keep variables private, keep the member functions out in the public!
    * The header file is where we are going to be keeping the Postconditions and the Preconditions. This is going to be the documetntations
    * The actual shtuffz are going to be in .cpp files! 

* .cpp files
    * The CPP file will hold all the important crap that you need

    ``` c++
    #include <iostream.h>
    #include <stdlib.h>
    #include "point.h"
    // The '< >' tells you it is a system file
    // The '""' tells you that it is in the local directory

    int main(){
        // We're creating the objects. Instancing them
        point p1;
        point p2;

        // Now they're doing something
        p1.setPosition(-1.0, 0.8);
        cout << p1.x() << p1.y() << endl;
        p2.setPosition(p1.x(), p1.y());
        cout << p2.x() << p2.y() << endl;
        p2.shift(1.3, -1.4);
        cout << p2.x() << p2.y() << endl;

        }
    ```
## What do we know about Objects?

* Class = Data + Member Functions
* We know how to define a new class type (Look above) and than define it in a header file
* We know how to use a header file, which declares instances of the class type
* We know how to "activate" the functions
* We now have to learn how to implement our functuons

### Creating Functions
* The Memember functions of a class are found inside of a .cpp file
* BE VERY CAREFUL WHEN YOU CHANGE PUBLIC STUFF!!!! Thats the interface to the outside world!

* .cpp body
    * First Function
    ``` c++
        // We need to set up "point::" because this signifies the namespace for the function
        // This is what the compiler uses to keep track of what functions that are being used at the moment
        void point::setPosition(double x, double y)
        {
            _x = x;
            _y = y;
        }
