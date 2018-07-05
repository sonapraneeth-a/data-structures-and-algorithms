//
// Created by pranas on 7/5/2018.
//

ULLI
Math::ExponentiationRecursive(ULLI number, ULLI exponent)
{
    if (number == 0 || number == 1)
        return number;
    if (exponent == 0)
        return 1;
    return number*Math::ExponentiationRecursive(number, exponent-1);
}