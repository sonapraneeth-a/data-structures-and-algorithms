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
 */

#ifndef POINT_H
#define POINT_H

#include "DefaultHeaders.h"


namespace Geometry
{

    template<ULLI N, typename T>
    class VectorNd
    {
    private:

        std::string _Vector_Print_Start = "(";
        std::string _Vector_Print_End = ")";
        T CoOrd[N];

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
            return os << Vector.ToString();
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
        // virtual VectorNd<N, T> operator ^ (VectorNd<N, T> const &SecondVector);

        VectorNd<N, T> operator = (VectorNd<N, T> const &SecondVector);

    };
}

#endif //POINT_H
