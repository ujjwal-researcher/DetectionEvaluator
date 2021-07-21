//
// Created by uujjwal on 7/21/21.
//

#ifndef DETECTIONEVALUATOR_GENUTILS_HXX
#define DETECTIONEVALUATOR_GENUTILS_HXX
#include<iostream>
#include<boost/filesystem.hpp>

bool file_exists(const char * filename){
    if (!boost::filesystem::is_regular_file(filename)){
        return false;
    }
    else{
        return true;
    }
}

bool directory_exists(char const * directory){
    if (!boost::filesystem::is_directory(directory)){
        return false;
    }
    else{
        return true;
    }
}

#endif //DETECTIONEVALUATOR_GENUTILS_HXX
