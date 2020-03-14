//
// Created by Osip on 2020-03-09.
//

#ifndef VECTORHORIVERT_UNITTESTS_H
#define VECTORHORIVERT_UNITTESTS_H

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#include "VectorFactory.h"
#include "TestRunner.h"
#include "Rational.h"

void TestConstructor();
void TestIndexOperator();

void TestAddition();
void TestSubtraction();
void TestMultiplication();

void TestVerticalPrint();
void TestHorizontalPrint();

void TestVerticalFactory();
void TestHorizontalFactory();

void TestAll();



#endif //VECTORHORIVERT_UNITTESTS_H
