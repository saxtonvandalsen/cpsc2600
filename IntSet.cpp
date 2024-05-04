// NAME: Saxton Van Dalsen
// FILE: IntSet.cpp
// DESCRIPTION: Implementation of the IntSet class.

#include <iostream>
#include <cstdlib>
using namespace std;

#include "IntSet.h"

const int ELEM_BITS = 32;

// Constructor: the argument represents the largest possible integer the set
// can have in its domain.  If the argument is 5, then the domain of the set
// is the integers 1-5.  The set that is being constructed however is empty.
IntSet::IntSet(int sizeArg)
{
    domainSize = sizeArg;

    // Calculating the number of integers needed for the bit vector
    int numIntegers = floor((double)domainSize / ELEM_BITS);
    
    // Dynamically allocate memory and initialize bit vector to the given size and empty values
    bitVector = new int[numIntegers]();
}

// Copy constructor
IntSet::IntSet(const IntSet& src)
{
    // Copying the domain size
    domainSize = src.domainSize;

    // Calculating the number of integers needed for the bit vector
    int numIntegers = floor((double)domainSize / ELEM_BITS);

    // Dynamically allocate memory to the given copied size
    bitVector = new int[numIntegers]();

    // Copy over the elements of source (src) to the new bit vector
    for (int i = 0; i < numIntegers; i++) {
        bitVector[i] = src.bitVector[i];
    }
}

// Destructor
IntSet::~IntSet()
{
    // Deallocate memory from array
    delete[] bitVector;
}

// Adds the specified integer to the set if not already an element.
void IntSet::addElement(int num)
{
    // Calculate the index of num in the bit vector
    int index = num / ELEM_BITS;

    // Calculating the position of the bit within the integer
    int position = num % ELEM_BITS;

    // To account for domain of the set from 1 to domainSize
    if (num == domainSize) {
        domainSize++;
    }

    // Checking if num is already in the set
   if ((bitVector[index] >> position) & 1) {

        // If it exists then return
        return;
    }

    // If the integer is not in the set then add it
    bitVector[index] |= (1 << position);
}

// Removes the specified integer if it is in the set.  Note that nothing happens
// if the element is in the domain but not in the set.
void IntSet::removeElement(int num)
{
    // Checking if element num is within the domain of the set or not
    if (num > domainSize || num < 1) {
        return;
    }

    // Calculate the index of num in the bit vector
    int index = num / ELEM_BITS;

    // Calculating the position of the bit within the integer
    int position = num % ELEM_BITS;

    // Checking if num is already in the set
    if (!((bitVector[index] >> position) & 1)) {

        // If it doesn't exist then return
        return;
    }

    // If the integer is in the set then remove it
    bitVector[index] &= ~(1 << position);
}

// Returns true if the specified integer is in the set.  Returns false otherwise.
bool IntSet::isElement(int num) const
{
    // Checking if element num is within the domain of the set
    if (num > domainSize || num < 1) {
        return false;
    }

    // Calculate the index of num in the bit vector
    int index = num / ELEM_BITS;

    // Calculating the position of the bit within the integer
    int position = num % ELEM_BITS;

    return (bitVector[index] >> position) & 1;
}

// Displays the set to the screen in the format: {1, 3, 4}
void IntSet::display() const
{
    // Checking if the bit vector set is empty or not
    bool checkEmpty = true;
    for (int i = 0; i < domainSize; i++) {
        if (bitVector[i] != 0) {
            checkEmpty = false;
            break;
        }
    }

    // If it's empty, return "{}"
    if (checkEmpty) {
        cout << "{}" << endl;
        return;
    }

    cout << "{";

    // Using a boolean value to check for comma placement
    bool checkElement = false;

    // Iterating over each integer in the bit vector
    for (int i = 0; i < domainSize; i++) {
        
        // Calculate the index and position of the bit for the current integer
        int index = i / ELEM_BITS;
        int position = i % ELEM_BITS;

        // Check if bit for the element is set in the bit vector
        if ((bitVector[index] >> position) & 1) {

            // If it's not the first element, add a comma
            if (checkElement) {
                cout << ", ";
            }

            cout << i;

            checkElement = true; // Update after the first element
        }
    }
    cout << "}";
}

// Returns the number of elements in the set.
int IntSet::numElements() const
{
    int count = 0; // For the number of elements

    // Iterating through the set to check the elements within it
    for (int i = 0; i < domainSize; ++i) {
        
        // Calculating the index and position for the set
        int index = i / ELEM_BITS;
        int position = i % ELEM_BITS;

        // Checking if an element is in the set at the current position
        // in the bit vector. If it is then increment count
        if (bitVector[index] & (1 << position)) {
            count++;
        }
    }
    return count;
    }

// Helper function to get the floor value of a number
int IntSet::floor(double num) {
    
    // Truncate decimal while converting floating point to an integer
    int intPart = (int)num;

    // Checking if the number has a decimal point or not
    if (num = intPart) {
        return intPart;
    } else {
        // Returning the next integer inclusive to account for all
        // values 1 to domain size
        return intPart + 1;
    }
    //return intPart;
}

// Returns a set that is the union of sets a and b.
IntSet unions(const IntSet& a, const IntSet& b)
{
    // New IntSet object for the union set
    IntSet unionSet(a.domainSize);

    // Iterating through the overall domain
    for (int i = 1; i <= a.domainSize; i++) {

        bool isElementInA = a.isElement(i);
        bool isElementInB = b.isElement(i);

        if (isElementInA || isElementInB) {
            unionSet.addElement(i);
        }
    }

    return unionSet;
}

// Returns a set that is the intersection of sets a and b.
IntSet intersect(const IntSet& a, const IntSet& b)
{
    IntSet intersectionSet(a.domainSize);

    // Iterating through the size of "a" to compare with elements of "b"
    for (int i = 1; i <= a.domainSize; i++) {

        // Getting the element in "a"
        if (a.isElement(i)) {

            // Checking if the same element is in "b"
            if (b.isElement(i)) {

                // If it exists in both then add it to the set
                intersectionSet.addElement(i);
            }
        }
    }
    return intersectionSet;
}

// Returns a set that is the difference a - b.
IntSet difference(const IntSet& a, const IntSet& b)
{
    // Creating a new set object for difference a - b
    IntSet differenceSet(a.domainSize);

    // Iterating through all element in set a
    for (int i = 1; i <= a.domainSize; i++) {

        // Checking if the element is in a and not in b
        if (a.isElement(i) && !b.isElement(i)) {

            // Add element if its in a and not b
            differenceSet.addElement(i);
        }
    }
    return differenceSet;
}

// Returns the complement of the set a.
IntSet complement(const IntSet& a)
{
    // Creating a new set object for the complement set
    IntSet complementSet(a.domainSize);

    // Iterating through the domain size of a
   for (int i = 1; i <= a.domainSize; i++) {

        // Checking if the element is not in set a
        if (!a.isElement(i)) {
            // If the element is not in the set then add it to the comlementSet
            complementSet.addElement(i);
        }
    }
    return complementSet;
}

// Returns true if the two sets are equal.
bool isEqual(const IntSet& a, const IntSet& b)
{
    // Creating a new set object for two equal sets
    IntSet isEqualSet(a.domainSize);

    // Iterating through to compare between the sets
    for (int i = 1; i <= a.domainSize; i++) {

        // If an is not present in both sets, then return false
        if (a.isElement(i) != b.isElement(i)) {
            return false;
        }
    }
    return true;
}