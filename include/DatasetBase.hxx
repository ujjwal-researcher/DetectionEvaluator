//
// Created by uujjwal on 7/17/21.
//

#ifndef DETECTIONEVALUATOR_DATASETBASE_HXX
#define DETECTIONEVALUATOR_DATASETBASE_HXX

#include<iostream>

class DatasetBase{
private:
    char const * name;
public:
    DatasetBase(char const * );
    virtual unsigned short int get_num_classes() =0;
    char const * get_name();
    virtual char const * get_category_name_by_id(unsigned short int) = 0;
    //virtual unsigned short int get_num_images()=0;
    virtual const char * get_subset()=0;
};

#endif //DETECTIONEVALUATOR_DATASETBASE_HXX
