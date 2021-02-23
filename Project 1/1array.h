///---------------------------------------------------------------------------
/// ARRAY.H
/// Simple class Array (for integers)
/// Authors: Deitel/Deitel (Additional comments by Olson and Zander)
///---------------------------------------------------------------------------
/// Array class:  like an int array (retains all functionality) but also
///   includes additional features:
///   -- allows input and output of the whole array
///   -- allows for comparison of 2 arrays, element by element
///   -- allows for assignment of 2 arrays
///   -- size is part of the class (so no longer needs to be passed)
///   -- includes range checking, program terminates for out-of-bound subscripts
///
/// Implementation and assumptions:
///   -- size defaults to a fixed size of 10 if size is not specified
///   -- array elements are initialized to zero
///   -- user must enter valid integers when using >>
///   -- in <<, integers are displayed 10 per line
///---------------------------------------------------------------------------

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;


class Array {
///---------------------------------------------------------------------------
/// operator>>  Overloaded input operator for class Array; inputs values for entire array.
/// @return returns input from istream
/// @pre Preconditions:   a.ptr must point to an array with size at least a.size
/// @post Postconditions:  The first a.size elements of a.ptr are filled with
///           integers read from the input istream
friend istream& operator>>(istream &, Array &);

///---------------------------------------------------------------------------
/// operator<<  Overloaded output operator for class Array
/// @return returns output to ostream
/// @pre Preconditions:   a.ptr must point to an array with size at least a.size
/// @post Postconditions:  The first a.size elements of a.ptr are sent to the 
///            output istream 10 per line with a trailing endl
friend ostream& operator<<(ostream &, const Array &);

public:
///---------------------------------------------------------------------------
/// Default constructor 
/// @pre Preconditions:   None
/// @post Postconditions:  ptr points to an array of size arraySize and all
///       elements of the array have been initialized to zero.
/// 		 arrayCount is incremented
///       Negative input values result in the default size of 10
Array(int = 10); 

///---------------------------------------------------------------------------
/// Copy constructor 
/// @pre Preconditions:   init.ptr points to an array of size at least init.size
/// @post Postconditions:  init is copied into *this, arrayCount is incremented
Array(const Array &); 

///---------------------------------------------------------------------------
/// Destructor 
/// @pre Preconditions:   ptr points to memory on the heap
/// @post Postconditions:  Array for ptr is deallocated, arrayCount is decremented
~Array(); 

///---------------------------------------------------------------------------
/// getSize  returns the size of the array
/// @return getSize returns the size of the array
/// @pre Preconditions:   None
/// @post Postconditions:  Returns the size of the array
int getSize() const; 

///---------------------------------------------------------------------------
/// operator=  Overwrites left parameter with right parameter
/// @return ptr of this 
/// @pre Preconditions:   right.ptr points to an array of size at least right.size
/// @post Postconditions:  *this is assigned the same array as right
const Array& operator=(const Array &); 

///---------------------------------------------------------------------------
/// operator==  Determine if two arrays are equal.
/// @return boolean true or false depending on size
/// @pre Preconditions:  ptr and right.ptr point to arrays with size at least
///          size and right.size, respectively
/// @post Postconditions:  true is returned if the arrays have the same size and 
///          elements false is return otherwise
bool operator==(const Array &) const; 

///---------------------------------------------------------------------------
/// operator!=  Determine if two arrays are not equal.
/// @return boolean true or false depending on size
/// @pre Preconditions:   ptr and right.ptr point to arrays with size at least
///          size and right.size, respectively
/// @post Postconditions:  false is returned if the arrays have the same size and 
///          elements true is return otherwise
bool operator!=(const Array &) const;

///---------------------------------------------------------------------------
/// operator[]  Overloaded subscript operator, terminates if subscript out of range error
/// @return returns ptr 
/// @pre Preconditions:   0 <= subscript < size
/// @post Postconditions:  Returns the array value at position "subscript"
int& operator[](int); 

///---------------------------------------------------------------------------
/// getArrayCount  Return the number of Array objects instantiated
/// @return returns number of arrays in arrayCount
/// @pre Preconditions:   None
/// @post Postconditions:  Returns the number of arrays
static int getArrayCount(); 

private:
   int* ptr;                          // pointer to first element of array
   int size;                          // size of the array
   static int arrayCount;             // # of Arrays instantiated
};

#endif

