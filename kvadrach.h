//! @brief  Square equation solver

#ifndef KVADRACH
#define KVADRACH
//#define TEST

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <TXLib.h>

//! @brief   Number of roots

enum Roots
{   NO_ROOT = 0,    //!< No roots
    ONE_ROOT = 1,   //!< One root
    TWO_ROOTS = 2,  //!< Two roots
    ALL_ROOTS = 3   //!< All real are roots
};

//! @brief   Small double for compare

const double EPSILON = 0.0001;

//! @brief   Max symbols in line

const int MAXLINE = 1000;

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Gets coefficient
//!
//! @param   k       Name of coefficient
//!
//! @return  Gets coefficient. If the input is incorrect, it tries to count again
//!
//! @usage @code
//!          double a = getCoeff('a');         // Gets a
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

double getCoeff(char k);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Comparison
//!
//! @param   a       First number
//! @param   b       Second number
//!
//! @return  Returns 1 if the modulus of the difference between numbers is small or they are both NAN, otherwise 0
//!
//! @usage @code
//!          compare(NAN, NAN);           // Returns 1
//!          compare(0.0, 0.0);           // Returns 1
//!          compare(1, 0);               // Returns 0
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int compare(double a, double b);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Line equation solver
//!
//! @param[in]   a       Coefficient a
//! @param[in]   b       Coefficient b
//! @param[out]  x1      Root
//!
//! @warning If there is no root, returns NAN
//!
//! @return  Returns the number of roots. If there are an infinite number of roots, returns 3
//!
//! @usage @code
//!          nRoots = solveLinear(0, 0, &x1);     // nRoots is 3, x1 is NAN
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int solveLinear(double a, double b, double *x1);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Solution of square equation
//!
//! @param[in]   a       Coefficient a
//! @param[in]   b       Coefficient b
//! @param[in]   c       Coefficient c
//! @param[out]  x1      Less root
//! @param[out]  x2      Bigger root
//!
//! @warning a must not be 0
//!
//! @warning If there are no roots, x1 and x2 are NAN. If there is only one root, its value is written to x1, and NAN is written to x2
//!
//! @return  Returns the number of roots
//!
//! @usage @code
//!          nRoots = solveSquare(0, 0, 5, &x1, &x2);     // nRoots is 0, x1 and x2 are NAN
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int solveSquare(double a, double b, double c, double *x1, double *x2);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Print solution
//!
//! @param   nRoot          Number of roots
//! @param   x1             Less root
//! @param   x2             Bigger root
//}----------------------------------------------------------------------------------------------------------------

void printSolution(enum Roots nRoots, double x1, double x2);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Fix of zero
//!
//! @param   a       Number
//!
//! @return  If a is -0, makes it zero
//!
//! @usage @code
//!          double a = -0;
//!          fixZero(&a);       // now a is 0
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

void fixZero(double *a);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Solution of the 2nd degree equation
//!
//! @param[in]   a       Coefficient a
//! @param[in]   b       Coefficient b
//! @param[in]   c       Coefficient c
//! @param[out]  nRoot   Number of roots
//! @param[out]  x1      Less root
//! @param[out]  x2      Bigger root
//!
//! @warning a must not be 0
//!
//! @warning If there are no roots or infinitely, x1 and x2 are equal to NAN. If there is only one root, its value is written to x1, and NAN is written to x2
//!
//! @usage @code
//!          solveEq(1, 2, 1, &nRoot, &x1, &x2);   // nRoot is ONE_ROOT, x1 is -1, x2 is NAN
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

void solveEq(double a, double b, double c, enum Roots *nRoot, double *x1, double *x2);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Start testing
//!
//! @param   path       Test file name
//}----------------------------------------------------------------------------------------------------------------

void testAll(char *path);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Тест
//!
//! @param   a              Coefficient a
//! @param   b              Coefficient b
//! @param   c              Coefficient c
//! @param   testnRoots     The number of roots that should be with the entered parameters; 3 if the solutions must be all numbers
//! @param   testx1         Smaller root with the entered parameters
//! @param   testx2         Bigger root with the entered parameters
//!
//! @return  Returns 0 if the test fails, 1 otherwise
//!
//! @usage @code
//!          test(0, 0, 0, 3, NAN, NAN)         // Returns 1
//!          test(0, 0, 0, 1, 0, 0);            // Returns 0
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int test(double a, double b, double c, int testnRoots, double testx1, double testx2);

#endif
