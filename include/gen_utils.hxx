//
// Created by uujjwal on 7/17/21.
//

#ifndef DETECTIONEVALUATOR_GEN_UTILS_HXX
#define DETECTIONEVALUATOR_GEN_UTILS_HXX

#include<cstring>

namespace genutils{
    char const * join(char const * str1, char const * str2){
        int bufferSize = strlen(str1) + strlen(str2) + 1;
        char * concatString = new char[bufferSize];
        strcpy(concatString, str1);
        strcpy(concatString, str2);
        return concatString;
    }
}

#endif //DETECTIONEVALUATOR_GEN_UTILS_HXX
