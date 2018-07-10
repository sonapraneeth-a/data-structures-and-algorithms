//
// Created by pranas on 7/10/2018.
//

#ifndef BITS_H
#define BITS_H

#include "Utilities.h"

namespace Math
{
    /**
     *
     * @param Number
     * @param Size
     * @return
     */
    inline std::string
    ToBinary(LLI Number, LLI Size)
    {
        std::string temp = "", answer = "";
        LLI BinaryIndex = 0;
        while(Number)
        {
            temp += ((Number%2)+'0');
            Number /= 2; BinaryIndex++;
        }
        while( BinaryIndex != Size )
        {
            temp += '0';
            BinaryIndex++;
        }
        LLI len = temp.size(), StringIndex = len-1;
        while( StringIndex > -1 )
        {
            answer += temp[StringIndex];
            StringIndex--;
        }
        return answer;
    }
}

#endif //BITS_H
