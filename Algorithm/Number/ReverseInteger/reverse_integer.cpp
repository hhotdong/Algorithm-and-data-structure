#include <cstdint>
#include <climits>
#include <stdexcept>
#include <iostream>
#include <cassert>

/* Problem:
Given a 64bit integer, reverse its (decimal) digits.
If the reversed number cannot be represented, throw std::domain_error.
*/

// Your solution:
/*
int64_t pow(int64_t base, int64_t exp) {
    int64_t pow = 1;
    for (int i = 0; i < exp; ++i)
        pow *= base;
    return pow;
}

int64_t reverse(int64_t value) {
    int num_digits = 0;
    int64_t digit_counter = INT64_MAX;
    for (; digit_counter != 0; digit_counter /= 10)
        ++num_digits;
    
    int sign = value < 0 ? -1 : 1;

    int i = num_digits - 1;
    for (; i >= 0; --i) {
        int digit_ones_place = (value / pow(10, i)) % 10;
        if (digit_ones_place != 0)
            break;
    }

    int j = i;
    int64_t sum = 0;
    for (; i >= 0; --i) {
        int64_t digit_ith_place = (value / pow(10, i)) % 10;
        int64_t multiplier      = pow(10, j - i);
        sum += digit_ith_place * multiplier * sign;
    }
    return sum * sign;
} 
*/

// Proposed solution:
int64_t reverse(int64_t value) {
    int64_t result = 0;
    do {
        int64_t digit = value % 10;
        if ((result > INT64_MAX/10 ||
             (result == INT64_MAX/10 && digit > INT64_MAX%10)) || 
            (result < INT64_MIN/10 ||
             (result == INT64_MIN/10 && digit < INT64_MIN%10)))
            throw std::domain_error("The reversed number cannot "
                                    "be represented.");
        result = result*10 + digit;
        value /= 10;
    } while (value != 0);

    return result;
}

int main() {
    assert(reverse(0) == 0);
    assert(reverse(-1) == -1);
    assert(reverse(1) == 1);

    assert(reverse(123) == 321);
    assert(reverse(-123) == -321);

    assert(reverse(123456789) == 987654321);
    assert(reverse(-123456789) == -987654321);

    assert(reverse(100) == 1);
    assert(reverse(-100) == -1);
    assert(reverse(101010) == 10101);
    assert(reverse(-101010) == -10101);

    assert(reverse(7085774586302733229) == INT64_MAX);
    assert(reverse(INT64_MAX) == 7085774586302733229);
    assert(reverse(-8085774586302733229) == INT64_MIN);
    assert(reverse(INT64_MIN) == -8085774586302733229);

    auto check_throws = [](int64_t input) {
        try {
            reverse(input);
        } catch(const std::domain_error& err) {
            return true;
        }
        return false;
    };

    assert(check_throws(8085774586302733229));
    assert(check_throws(7185774586302733229));
    assert(check_throws(-9085774586302733229));
    assert(check_throws(-8185774586302733229));
}
