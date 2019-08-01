namespace Algorithms.Lib
{
    public static class Factorization
    {
        /// <summary>
        /// This property always returns a value &lt; 1.
        /// </summary>
        public static long EuclideanGCDIterative(long numOne, long numTwo)
        {
            // Negativity of a number does not affect the final result
            // GCD(-a, -b) = GCD(-a, b) = GCD(a, -b) = GCD(a, b)
            if (numOne < 0) { numOne = -numOne; }
            if (numTwo < 0) { numTwo = -numTwo; }
            long greater = (numOne >= numTwo) ? (long)numOne : (long)numTwo;
            long lesser = (numOne < numTwo) ? (long)numOne : (long)numTwo;
            // GCD(a, a) = a;
            if (greater == lesser) { return lesser; }
            // GCD(a, 0) = GCD(0, a) = a;
            if (lesser == 0) { return greater; }
            long remainder = 0;
            while (lesser != 0)
            {
                // GCD(a, b) = GCD(b, a%b) for a >= b
                remainder = greater % lesser;
                greater = lesser;
                lesser = remainder;
            }
            return greater;
        }

        public static long NaiveGCD(long numOne, long numTwo)
        {
            // Negativity of a number does not affect the final result
            // gcd(-a, -b) = gcd(-a, b) = gcd(a, -b) = gcd(a, b)
            if (numOne < 0) { numOne = -numOne; }
            if (numTwo < 0) { numTwo = -numTwo; }
            long greater = (numOne >= numTwo) ? (long)numOne : (long)numTwo;
            long lesser = (numOne < numTwo) ? (long)numOne : (long)numTwo;
            // gcd(a, a) = a;
            if (greater == lesser) { return lesser; }
            // gcd(a, 0) = gcd(0, a) = a;
            if (lesser == 0) { return greater; }
            long gcd = 1;
            // Loop through all the divisors until the smallest of the two numbers.
            // Smallest because any number greater than the smallest number does not divide
            // the smallest number
            for (long divisor = 2; divisor <= lesser; divisor++)
            {
                if (greater % divisor == 0 && lesser % divisor == 0)
                {
                    gcd = divisor;
                }
            }
            return gcd;
        }

    }
}
