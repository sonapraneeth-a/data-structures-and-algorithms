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
 * 23-07-2018             Sona Praneeth Akula    - Moved from VectorNd<N, T> to VectorNd<T>
 *                                               - Updated constructor to accept dimension of the
 *                                                 vector
 */

#ifndef VECTORND_H
#define VECTORND_H

#include "DefaultHeaders.h"

// Reference: http://blog.ethanlim.net/2014/07/separate-c-template-headers-h-and.html

namespace LinAlg
{

    template<typename T>
    class VectorNd
    {
    private:

        std::string _Vector_Print_Start = "(";
        std::string _Vector_Print_End = ")";
        T *CoOrd;
        size_t N;

    public:

        explicit VectorNd(int Dimension, const T &InitValue = 0);

        VectorNd(const VectorNd<T> &Vector);

        size_t GetDimension() const;

        void
        Fill(const T &Value);

        double
        Distance(const VectorNd<T> &OtherVector);

        VectorNd<double>
        Normalize();

        T
        GetNthCoOrdinate(ULLI index);

        void
        SetNthCoOrdinate(ULLI index, T Value);

        std::string
        ToString() const;

        friend std::ostream &
        operator<<(std::ostream & os, VectorNd<T> const &Vector)
        {
            return os << Vector.ToString() << "\n";
        }

        VectorNd<T> operator + (VectorNd<T> const &SecondVector);
        void operator += (VectorNd<T> const &SecondVector);

        VectorNd<T> operator - (VectorNd<T> const &SecondVector);
        void operator -= (VectorNd<T> const &SecondVector);

        // Dot product
        VectorNd<T> operator * (VectorNd<T> const &SecondVector);
        void operator *= (VectorNd<T> const &SecondVector);

        // Reference: https://stackoverflow.com/questions/11066564/overload-bracket-operators-to-get-and-set
        T operator [](ULLI index) const;
        T& operator [](ULLI index);

        // Cross product
        // VectorNd<N, T> operator ^ (VectorNd<N, T> const &SecondVector);

        VectorNd<T>& operator = (VectorNd<T> const &SecondVector);

        bool operator == (VectorNd<T> const &SecondVector) const;

        ~VectorNd();

    };
}

#endif //VECTORND_H
