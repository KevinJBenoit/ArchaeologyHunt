/****************************************************************************************
** Program name: inputValidate.hpp
** Author: Kevin Benoit
** Date: 6/02/2019
** Description: Contains the prototype for the functions involving input validation of
different types and ranges. Has #include guard to prevent double inclusion.
****************************************************************************************/

#ifndef INPUTVALIDATE_HPP
#define INPUTVALIDATE_HPP

int inputValidateInteger();
int inputValidateIntegerAndRange(int min, int max);

double inputValidateDouble();
double inputValidateDoubleAndRange(double min, double max);

char inputValidateChar();
char inputValidateCharArray(char arrayIn[], int size);

#endif