/**
 *      Created on: 27 July 2018
 *   Last modified: 27 July 2018
 *          Author: Sona Praneeth Akula
 *         Details: Header for N dimensional matrix
 */

/**
 * Changelog
 *
 * Date (DD-MM-YYYY)            Author               Update
 * 27-07-2018             Sona Praneeth Akula    - Creation of file
 *
 */

#ifndef MATRIXND_H
#define MATRIXND_H

#include "DefaultHeaders.h"


namespace LinAlg
{

    template<typename T>
    class MatrixNd
    {
    private:

        std::string _MatrixNd_Print_Start = "|";
        std::string _MatrixNd_Print_End = "|";
        T *_CoOrd;
        size_t *_Dimension;

        size_t GetIndex(size_t Index, ...) const;

    public:

        explicit MatrixNd(const size_t &Dimension[], const T &InitValue = 0);

        MatrixNd(const MatrixNd<T> &MatrixNd);

        void
        Fill(const T &Value);

        ~MatrixNd();

    };
}

#endif //MATRIXND_H
