/**
 *      Created on: 06 July 2018
 *   Last modified: 06 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for N dimensional vector
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 06-07-2018             Sona Praneeth Akula    - Creation of file
 *                                               - Added function signatures for the functions
 *                                                 Distance, Fill, Normalize, GetNthCoOrdinate,
 *                                                 ToString
 * 07-07-2018             Sona Praneeth Akula    - Added function signatures for functions
 *                                                 SetNthCoOrdinate, Copy constructor and operators
 *                                                 +, -, *, +=, -=, *=, []
 * 08-07-2018             Sona Praneeth Akula    - Added function signatures for operator ==
 */

#ifndef VECTORND_H
#define VECTORND_H

#include "DefaultHeaders.h"
#include <type_traits>

// References
// - https://www.ideone.com/nztTgG
// - https://www.ideone.com/Kex95V
// - https://stackoverflow.com/questions/165101/invalid-use-of-incomplete-type-error-with-partial-template-specialization
// - https://stackoverflow.com/questions/17200755/c-partial-template-specialization-in-combination-with-stdis-base-of-and-std
// - https://cpppatterns.com/patterns/class-template-sfinae.html
// - https://stackoverflow.com/questions/21973389/how-to-specialize-a-template-function-for-integral-and-floating-types-respective

#define EnableNumbers std::enable_if<std::is_floating_point<T>::value||std::is_integral<T>::value>::type

namespace Geometry
{

    template <ULLI N, typename T, typename Enable = void>
    class VectorNd {};

    template<ULLI N, typename T>
    class VectorNd<N, T, typename EnableNumbers>
    {
    private:

        std::string _Vector_Print_Start = "(";
        std::string _Vector_Print_End = ")";
        T *CoOrd = new T[N];

    public:

        explicit VectorNd(const T &InitValue = 0);

        VectorNd(const VectorNd<N, T> &Vector);

        void
        Fill(const T &Value);

        double
        Distance(const VectorNd<N, T> &OtherVector);

        VectorNd<N, double>
        Normalize();

        T
        GetNthCoOrdinate(ULLI index);

        void
        SetNthCoOrdinate(ULLI index, T Value);

        std::string
        ToString() const;

        friend std::ostream &
        operator<<(std::ostream & os, VectorNd<N, T> const &Vector)
        {
            return os << Vector.ToString() << "\n";
        }

        VectorNd<N, T> operator + (VectorNd<N, T> const &SecondVector);
        void operator += (VectorNd<N, T> const &SecondVector);

        VectorNd<N, T> operator - (VectorNd<N, T> const &SecondVector);
        void operator -= (VectorNd<N, T> const &SecondVector);

        // Dot product
        VectorNd<N, T> operator * (VectorNd<N, T> const &SecondVector);
        void operator *= (VectorNd<N, T> const &SecondVector);

        // Reference: https://stackoverflow.com/questions/11066564/overload-bracket-operators-to-get-and-set
        T operator [](ULLI index) const;
        T& operator [](ULLI index);

        // Cross product
        VectorNd<N, T> operator ^ (VectorNd<N, T> const &SecondVector);

        VectorNd<N, T>& operator = (VectorNd<N, T> const &SecondVector);

        bool operator == (VectorNd<N, T> const &SecondVector) const;

        ~VectorNd();

    };
}

#include "VectorNd.cpp"

#endif //VECTORND_H
