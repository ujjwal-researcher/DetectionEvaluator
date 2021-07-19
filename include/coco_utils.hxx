//
// Created by uujjwal on 7/17/21.
//

#ifndef DETECTIONEVALUATOR_COCO_UTILS_HXX
#define DETECTIONEVALUATOR_COCO_UTILS_HXX

#include<iostream>

namespace cocoutils {
    extern char const *COCO_CLASSES[80];

    char const *get_coco_name_from_id(unsigned short int);

    char const *get_annotation_file(char const *, char const *, char const *);


}


#endif //DETECTIONEVALUATOR_COCO_UTILS_HXX
