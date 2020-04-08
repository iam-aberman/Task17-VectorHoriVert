//
// Created by Osip on 2020-03-09.
//

#include "UnitTests.h"

void TestConstructor() {
    VECTOR_HORI_VERT::VectorHori<Rational> testHori(3);
    VECTOR_HORI_VERT::VectorVert<Rational> testVert(3);

    AssertEqual(testHori.size(), 3);
    AssertEqual(testVert.size(), 3);

    std::vector<Rational> expected = {
            Rational(),
            Rational(),
            Rational()
    };

    AssertEqual(testHori.getElements(), expected);
    AssertEqual(testVert.getElements(), expected);
}

void TestIndexOperator() {
    VECTOR_HORI_VERT::VectorHori<Rational> test(3);

    for (int i = 0; i < 3; ++i) {
        test[i] = Rational(i + 1, i + 2); // (1/2, 2/3, 3/4)
    }

    std::vector<Rational> expected = {
            Rational(1, 2),
            Rational(2, 3),
            Rational(3, 4)
    };

    AssertEqual(test.getElements(), expected);
}

void TestAddition() {
    VECTOR_HORI_VERT::VectorVert<Rational> lhs(3), rhs(3);

    for (int i = 0; i < 3; ++i) {
        lhs[i] = Rational(i + 1, i + 2); // (1/2, 2/3, 3/4)
        rhs[i] = Rational(i + 2, i + 3); // (2/3, 3/4, 4/5)
    }

    VECTOR_HORI_VERT::VectorVert<Rational> result = lhs + rhs;

    std::vector<Rational> expected = {
            Rational(7, 6),
            Rational(17, 12),
            Rational(27, 20)
    };

    AssertEqual(result.getElements(), expected);
}

void TestSubtraction() {
    VECTOR_HORI_VERT::VectorHori<Rational> lhs(3), rhs(3);

    for (int i = 0; i < 3; ++i) {
        lhs[i] = Rational(i + 2, i + 3); // (2/3, 3/4, 4/5)
        rhs[i] = Rational(i + 1, i + 2); // (1/2, 2/3, 3/4)
    }

    VECTOR_HORI_VERT::VectorHori<Rational> result = lhs - rhs;

    std::vector<Rational> expected = {
            Rational(1, 6),
            Rational(1, 12),
            Rational(1, 20)
    };

    AssertEqual(result.getElements(), expected);
}

void TestMultiplication() {
    VECTOR_HORI_VERT::VectorHori<Rational> lhs(3), rhs(3);

    for (int i = 0; i < 3; ++i) {
        lhs[i] = Rational(i + 2, i + 3); // (2/3, 3/4, 4/5)
        rhs[i] = Rational(i + 1, i + 2); // (1/2, 2/3, 3/4)
    }

    VECTOR_HORI_VERT::VectorVert<Rational> result = lhs * rhs;

    std::vector<Rational> expected = {
            Rational(1, 3),
            Rational(1, 2),
            Rational(3, 5)
    };

    AssertEqual(result.getElements(), expected);
}

void TestVerticalPrint() {
    VECTOR_HORI_VERT::VectorVert<Rational> test(3);

    for (int i = 0; i < 3; ++i) {
        test[i] = Rational(i + 1, i + 2); // (1/2, 2/3, 3/4)
    }

    std::stringstream output;
    test.Print(output);

    std::string expected = "(1/2)\n(2/3)\n(3/4)";

    AssertEqual(output.str(), expected);
}

void TestHorizontalPrint() {
    VECTOR_HORI_VERT::VectorHori<Rational> test(3);

    for (int i = 0; i < 3; ++i) {
        test[i] = Rational(i + 1, i + 2); // (1/2, 2/3, 3/4)
    }

    std::stringstream output;
    test.Print(output);

    std::string expected = "(1/2) (2/3) (3/4)";

    AssertEqual(output.str(), expected);
}

void TestVerticalFactory() {
    VECTOR_HORI_VERT::VertFactory<Rational> factory;

    std::shared_ptr<VECTOR_HORI_VERT::Vector<Rational>> ptr;
    ptr = factory.Create(3);

    for (int i = 0; i < 3; ++i) {
        (*ptr)[i] = Rational(i + 1, i + 2); // (1/2, 2/3, 3/4)
    }

    std::stringstream output;
    ptr->Print(output);

    std::string expected = "(1/2)\n(2/3)\n(3/4)";

    AssertEqual(output.str(), expected);
}

void TestHorizontalFactory() {
    VECTOR_HORI_VERT::HoriFactory<Rational> factory;

    std::shared_ptr<VECTOR_HORI_VERT::Vector<Rational>> ptr;
    ptr = factory.Create(3);

    for (int i = 0; i < 3; ++i) {
        (*ptr)[i] = Rational(i + 1, i + 2); // (1/2, 2/3, 3/4)
    }

    std::stringstream output;
    ptr->Print(output);

    std::string expected = "(1/2) (2/3) (3/4)";

    AssertEqual(output.str(), expected);
}

void TestAll() {
    TestRunner testRunner;

    testRunner.RunTest(TestConstructor, "TestConstructor");
    testRunner.RunTest(TestIndexOperator, "TestIndexOperator");

    testRunner.RunTest(TestAddition, "TestAddition");
    testRunner.RunTest(TestSubtraction, "TestSubtraction");
    testRunner.RunTest(TestMultiplication, "TestMultiplication");

    testRunner.RunTest(TestVerticalPrint, "TestVerticalPrint");
    testRunner.RunTest(TestHorizontalPrint, "TestHorizontalPrint");

    testRunner.RunTest(TestVerticalFactory, "TestVerticalFactory");
    testRunner.RunTest(TestHorizontalFactory, "TestHorizontalFactory");
}
