/**
 *      Created on: 06 July 2018
 *   Last modified: 15 July 2018
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
 * 15-07-2018             Sona Praneeth Akula    - Moved from namespace Geometry to LinAlg
 */

#ifndef VECTORND_H
#define VECTORND_H

#include "DefaultHeaders.h"

// Reference: http://blog.ethanlim.net/2014/07/separate-c-template-headers-h-and.html

namespace LinAlg
{

    template<ULLI N, typename T>
    class VectorNd
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
        // VectorNd<N, T> operator ^ (VectorNd<N, T> const &SecondVector);

        VectorNd<N, T>& operator = (VectorNd<N, T> const &SecondVector);

        bool operator == (VectorNd<N, T> const &SecondVector) const;

        ~VectorNd();

    };
}

#endif //VECTORND_H
