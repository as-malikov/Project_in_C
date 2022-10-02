#include "my_math.h"

/*---------------------------------------------------
                    my_FACTORIAL
    is the product of all positive integers
    less than or equal to x
---------------------------------------------------*/
long double my_factorial(int x) {
    long double factorial = 1;
    for (int number = 1; number <= x; number++) {
        factorial = factorial * number;
    }
    return factorial;
}

/*---------------------------------------------------
                    my_TAYLORPOW

---------------------------------------------------*/
long double my_taylorpow(double x, int exp) {
    long double result = 1;
    for (int step = 0; step < exp; step++) {
        result *= x;
    }
    return result;
}

/*---------------------------------------------------
                    my_ABS
    computes absolute value of an integer value
---------------------------------------------------*/
long int my_abs(int x) {
    long int modulus = x;
    if (x <0) {
        modulus = x * (-1);
    }
    return modulus;
}

/*---------------------------------------------------
                    my_FABS
    computes absolute value of a
    floating-point value
---------------------------------------------------*/
long double my_fabs(double x) {
    long double modulus  = x;
    if (x < 0) {
        modulus = x * (-1);
    } else if (my_abs(x) < 0 && x != my_INFINITY) {
        modulus = my_NAN;
    }
    return modulus;
}

/*---------------------------------------------------
                    my_FMOD
    remainder of the floating-point
    division operations
---------------------------------------------------*/
long double my_fmod(double x, double y) {
    long double remainder = x;
    if (x != my_INFINITY && x != (my_INFINITY * -1)) {
      remainder = x;
      if (y != my_INFINITY && y != (my_INFINITY * -1)) {
        double division = x / y;
        long int integerDivision = division;
        remainder = y * (division - integerDivision);
      }
    }
    return remainder;
}

/*---------------------------------------------------
                    my_EXP
    returns e raised to the given power
---------------------------------------------------*/
long double my_exp(double x) {
    long double result = x;
    if (x < 710 && x > -15) {
        result = 1;
        for (int index = 1; index <= 1500; index++) {
            result = result + (my_taylorpow(x, index)/my_factorial(index));
        }
    } else if (x == (my_NAN * -1) || x <= -15) {
        result = 0;
    } else if (x >= 710) {
      result = my_INFINITY;
    }
    return result;
}


/*---------------------------------------------------
                    my_CEIL
    returns the nearest integer not less
    than the given value
---------------------------------------------------*/
long double my_ceil(double x) {
    long double result = x;
    if (my_fabs(x) != my_INFINITY && my_fabs(x) >= 0) {
      int whole_part = (int)x;
      result = whole_part;
      if (x - whole_part > 0) {
          whole_part++;
          result = whole_part;
      }
    }
    return result;
}

/*---------------------------------------------------
                    my_FLOOR
    returns the nearest integer not greater
    than the given value
---------------------------------------------------*/
long double my_floor(double x) {
    long double result = x;
    if (my_fabs(x) != my_INFINITY && my_fabs(x) >= 0) {
      int whole_part = (int)x;
      result = whole_part;
      if (x - whole_part < 0) {
          whole_part--;
          result = whole_part;
      }
    }
    return result;
}

/*---------------------------------------------------
                    my_POW
    raises a number to the given power
---------------------------------------------------*/
long double my_pow(double base, double exp) {
    if (my_fmod(exp, 2) == 0) {
        base = my_fabs(base);
    }
    long double result = exp;
    if (base == 0 && exp == 0) {
        result = 1;
    } else if (exp == (my_INFINITY * -1) && base != 0) {
      result = 0;
    } else if (exp != my_INFINITY) {
      result = my_exp(exp * my_log(base));
    }
    return result;
}

/*---------------------------------------------------
                    my_COS
                computes cosine
---------------------------------------------------*/
long double my_cos(double x) {
    long double res = my_NAN * (-1);
    x = my_fmod(x, 2 * my_PI);
    if (my_fabs(x) <= 2 * my_PI &&  my_fabs(x) != my_INFINITY) {
        res = 1;
        int factorial = 2;
        int sign = -1;
        while (my_taylorpow(x, factorial) / my_factorial(factorial) > 0.0000000000000001) {
            res = res + (sign * my_taylorpow(x, factorial)) / my_factorial(factorial);
            sign *= -1;
            factorial += 2;
        }
    } else if (x == 1/0.0 || x == -1/0.0) {
    } else {
        res = x;
    }
    return res;
}

/*---------------------------------------------------
                    my_ACOS
                computes arc cosine
---------------------------------------------------*/
long double my_acos(double x) {
    long double res = my_PI / 2;
    if (my_fabs(x) <= 1) {
        if (x == -1 || x == 1) {
            if (x == -1) {
                res = my_PI;
            } else {
                res = 0;
            }
        } else {
            int n = 1;
            int factorial_up = 2;
            int factorial_down = 1;
            res += -x;
            while (factorial_down <= 20) {
                res = res - ( (my_factorial(factorial_up) * my_taylorpow(x, 2 * n + 1))\
                    / (my_taylorpow(4, n) * my_taylorpow(my_factorial(factorial_down), 2) * (2 * n + 1)) );
                n += 1;
                factorial_up = 2*n;
                factorial_down = n;
            }
        }
    } else if (my_fabs(x) > 1) {
        res = my_NAN;
    } else {
        res = x;
    }
    return res;
}

/*---------------------------------------------------
                    my_ASIN
                computes arc sine
---------------------------------------------------*/
long double my_asin(double x) {
    long double res = my_PI / 2;
    if (my_fabs(x) <= 1) {
        if (x == -1 || x == 1) {
            if (x == -1) {
                res = -my_PI / 2;
            }
        } else {
            res = my_acos(-x) - my_PI / 2;
        }
    } else if (my_fabs(x) > 1) {
        res = my_NAN;
    } else {
        res = x;
    }
    return res;
}

/*---------------------------------------------------
                    my_ATAN
            computes arc tangent
---------------------------------------------------*/
long double my_atan(double x) {
    long double res = x;
    int n = 1;
    if (my_fabs(x) <= 1) {
        if (x == -1 || x == 1) {
            res = my_PI / 4;
            if (x == -1) {
                res = -my_PI / 4;
            }
        } else {
            while (n != 20) {
                res = res + ((my_taylorpow(-1, n) * my_taylorpow(x, 2 * n + 1)) / (2 * n + 1));
                n += 1;
            }
        }
    } else if (my_fabs(x) > 1) {
        if (x > 0) {
            res = my_PI / 2 - my_atan(1 / x);
        } else {
            res = -my_PI / 2 + my_atan(1 / -x);
        }
    } else {
        res = x;
    }
    return res;
}

/*---------------------------------------------------
                    my_SIN
                computes sine
 ---------------------------------------------------*/
long double my_sin(double x) {
    x = my_fmod(x, 2 * my_PI);
    long double buf = x;
    long double sign = -1;
    for (int i=3; i <= 1500; i += 2) {
        buf+=sign*(my_taylorpow(x, i)/my_factorial(i));
        sign *= -1;
    }
    return buf;
}

/*---------------------------------------------------
                    my_TAN
                 computes tangent
 ---------------------------------------------------*/

long double my_tan(double x) {
    x = my_fmod(x, my_PI);
    return (my_sin(x)/my_cos(x));
}

/*---------------------------------------------------
                    my_SQRT
                computes square root
 ---------------------------------------------------*/
long double my_sqrt(double x) {
    long double result = 0;
    if (x < 0) {
        result = (my_NAN * -1);
    } else {
        result = my_pow(x, 0.5);
    }
    return result;
}

/*---------------------------------------------------
                    my_LOG
                computes square root
---------------------------------------------------*/
long double my_lessOne(double x) {
    long double result = 0;
    long double isX = x;
    for (int i = 1; i < 101; i+=2) {
        result = result + (my_taylorpow(isX, i)/(double)i - my_taylorpow(isX, i+1)/(double)(i+1));
    }
    return result;
}

long double my_toRun(double x) {
    int logTenCount = 0;
    int logTowCount = 0;
    // LOG_10
    while (x >= 10) {
        x /= 10;
        logTenCount++;
    }
    // LOG_2
    while (x >= 2) {
        x /= 2;
        logTowCount++;
    }
    x = x - 1;
    long double result = logTenCount * my_LOG_10 + logTowCount * my_LOG_2 + my_lessOne(x);
    return result;
}

long double my_log(double x) {
    double result = 0;
    if (x == my_INFINITY) {
        result = my_INFINITY;
    } else if (x < 0) {
        result = my_NAN;
    } else if (x > 0) {
        result = my_toRun(x);
    } else if (x == 0) {
        result = my_INFINITY * (-1);
    } else {
        result = x;
    }
    return result;
}
