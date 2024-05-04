// NAME: Saxton Van Dalsen
// FILE: main.cpp
// DESCRIPTION: Tests IntSet class

#include <iostream>
using namespace std;

#include "IntSet.h"

int main()
{
  // Creating IntSet objects from A-K using the set of positive
  // integers less than or equal to 100
  IntSet A(100);
  IntSet B(100);
  IntSet C(100);
  IntSet D(100);
  IntSet E(100);
  IntSet F(100);
  IntSet G(100);
  IntSet H(100);
  IntSet I(100);
  IntSet J(100);
  IntSet K(100);

  // *** 1. a. ***
  for (int i = 1; i <= 100; i++) {
    
    // Checking if the number is evenly divisible by 6
    if (i % 6 == 0) {
        A.addElement(i); // Adding the number to the set if it is
    }
  }

  // Output for the set A
  cout << "A: ";
  A.display();
  cout << endl << "Number of Elements: " << A.numElements() << endl << endl;

  // *** 1. b. ***
  for (int i = 1; i <= 100; i++) {

    // Checking if the number is greater than or equal to 40 and
    // less than or equal to 50
    if (i >= 40 && i <= 50) {
      B.addElement(i); // Adding the number to the set if it is
    }
  }

  // Output for the set B
  cout << "B: ";
  B.display();
  cout << endl << "Number of Elements: " << B.numElements() << endl << endl;

  // 1. c.
  for (int i = 1; i <= 100; i++) {
    
    // Checking if the number is a factor of 96
    if (96 % i == 0) {
      C.addElement(i);
    }
  }

  // Output for the set C
  cout << "C: ";
  C.display();
  cout << endl << "Number of Elements: " << C.numElements() << endl << endl;

  // *** 2. a. ***
  // Getting the complement of set A
  IntSet complementA = complement(A);

  // Iterating through the complement of set A
  for (int i = 1; i <= 100; i++) {

    // Adding the complement elements of A into D
    if (complementA.isElement(i)) {
      D.addElement(i);
    }
  }

  // Output for the set D
  cout << "D: ";
  D.display();
  cout << endl << "Number of Elements: " << D.numElements() << endl << endl;

  // *** 2. b. ***
  // Getting the union of set B and set A
  IntSet unionOfBA = unions(B, A);

  // Iterating through the union of set B and A
  for (int i = 1; i <= 100; i++) {

    // Adding each element within the union of set B and A
    // into set E
    if (unionOfBA.isElement(i)) {
      E.addElement(i);
    }
  }

  // Output for the set E
  cout << "E: ";
  E.display();
  cout << endl << "Number of Elements: " << E.numElements() << endl << endl;

  // *** 2. c. ***
  // Getting the uinon of set A and set D
  IntSet unionOfAD = unions(A, D);

  // Iterating through the union of set A and D
  for (int i = 1; i <= 100; i++) {

    // Adding each element within the union of set A and D 
    // into set F
    if (unionOfAD.isElement(i)) {
      F.addElement(i);
    }
  }

  // Output for the set F
  cout << "F: ";
  F.display();
  cout << endl << "Number of Elements: " << F.numElements() << endl << endl;

  // *** 2. d. ***
  // Getting the intersection of set A and set B
  IntSet intersectionOfAB = intersect(A, B);

  // Iterating through the intersection of set A and B
  for (int i = 1; i <= 100; i++) {

    // Adding each element within the intersection of set A and B 
    // into set G
    if (intersectionOfAB.isElement(i)) {
      G.addElement(i);
    }
  }

  // Output for the set G
  cout << "G: ";
  G.display();
  cout << endl << "Number of Elements: " << G.numElements() << endl << endl;

  // *** 2. e. ***
  // Getting the intersection of set B and C
  IntSet intersectionOfBC = intersect(B, C);

  // Iterating through the intersection of set B and C
  for (int i = 1; i <= 100; i++) {

    // Adding each element within the intersection of set B and C 
    // into set H
    if (intersectionOfBC.isElement(i)) {
      H.addElement(i);
    }
  }

  // Output for the set H
  cout << "H: ";
  H.display();
  cout << endl << "Number of Elements: " << H.numElements() << endl << endl;

  // *** 2. f. ***
  // Getting the set that is the difference C - A
  IntSet differenceCA = difference(C, A);

  // Iterating through set that is the difference C - A
  for (int i = 1; i <= 100; i++) {

    // Adding each element within the set that is the difference
    // C - A into set I
    if (differenceCA.isElement(i)) {
      I.addElement(i);
    }
  }

  // Output for the set I
  cout << "I: ";
  I.display();
  cout << endl << "Number of Elements: " << I.numElements() << endl << endl;
  
  // *** 2. g. ***
  // Getting the set that is the difference B - D
  IntSet differenceBD = difference(B, D);

  // Iterating through set that is the difference B - D
  for (int i = 1; i <= 100; i++) {

    // Adding each element within the set that is the difference
    // B - D into set J
    if (differenceBD.isElement(i)) {
      J.addElement(i);
    }
  }

  // Output for the set J
  cout << "J: ";
  J.display();
  cout << endl << "Number of Elements: " << J.numElements() << endl << endl;

  // *** 2. h. ***
  // Getting the set that is the difference B - E
  IntSet differenceBE = difference(B, E);

  // Iterating through set that is the difference B - E
  for (int i = 1; i <= 100; i++) {

    // Adding each element within the set that is the difference
    // B - E into set K
    if (differenceBE.isElement(i)) {
      K.addElement(i);
    }
  }

  // Output for the set K
  cout << "K: ";
  K.display();
  cout << endl << "Number of Elements: " << K.numElements() << endl << endl;

  // *** 4. a. ***
  // Checking if 42 is an element within the set A
  bool is42inA = A.isElement(42);
  cout << "4. a. Is 42 an element of set A?" << endl;
  
  // Displayin either true or false
  if (is42inA) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  // *** 4. b. ***
  // Checking if 42 is an element within the set C
  bool is42inC = C.isElement(42);
  cout << "4. b. Is 42 an element of set C?" << endl;
  
  // Displayin either true or false
  if (is42inC) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  // *** 4. c. ***
  // Checking if set C is equal to set I
  bool isCEqualToI = isEqual(C, I);
  cout << "4. c. Is the set C equal to the set I?" << endl;
  
  // Displayin either true or false
  if (isCEqualToI) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  // *** 4. d. ***
  // Checking if set G is equal to set J
  bool isGEqualToJ = isEqual(G, J);
  cout << "4. d. Is the set G equal to the set J?" << endl;
  
  // Displayin either true or false
  if (isGEqualToJ) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  return 0;
}