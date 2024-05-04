// NAME: Saxton Van Dalsen
// FILE: IntSet.h
// DESCRIPTION: Definition of the IntSet class.

#ifndef INTSET_H
#define INTSET_H

// Represents a set of integers from 1 to size.
class IntSet {

public:
  // Constructor: the argument represents the largest possible integer the set
  // can have in its domain.  If the argument is 5, then the domain of the set
  // is the integers 1-5.  The set that is being constructed however is empty.
  IntSet(int size);

  // Copy constructor
  IntSet(const IntSet& src);

  // Destructor
  ~IntSet();

  // Adds the specified integer to the set if not already an element.  
  void addElement(int num);

  // Removes the specified integer if it is in the set.  Note that nothing happens
  // if the element is in the domain but not in the set.
  void removeElement(int num);

  // Returns true if the specified integer is in the set.  Returns false otherwise.
  bool isElement(int num) const;

  // Displays the set to the screen in the format: {1, 3, 4}
  void display() const;

  // Returns the number of elements in the set.
  int numElements() const;

  // Returns a set that is the union of sets a and b.
  friend IntSet unions(const IntSet& a, const IntSet& b);

  // Returns a set that is the intersection of sets a and b.
  friend IntSet intersect(const IntSet& a, const IntSet& b);

  // Returns a set that is the difference a - b.
  friend IntSet difference(const IntSet& a, const IntSet& b);

  // Returns the complement of the set a.
  friend IntSet complement(const IntSet& a);

  // Returns true if the two sets are equal.
  friend bool isEqual(const IntSet& a, const IntSet& b);

private:
  // TODO: Complete the private section of the class.

  int* bitVector; // pointer to the dynamically allocated bit vector
  int domainSize; // size of the domain

  // Helper function to get the floor value of a number
  int floor(double num);
  
};

#endif