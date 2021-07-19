//
// Created by uujjwal on 7/17/21.
//

#ifndef DETECTIONEVALUATOR_COCODATASET_HXX
#define DETECTIONEVALUATOR_COCODATASET_HXX

#include"DatasetBase.hxx"
#include "coco_utils.hxx"

class COCODataset : public DatasetBase{
public:
    enum SUBSET : unsigned short int {
        TRAIN=0,
        VAL=1,
        TEST=2
    };
    COCODataset(char const *, char const *, SUBSET);
    unsigned short int get_num_classes() override;
    char const * get_category_name_by_id(unsigned short int) override;
    char const * get_subset() override;
    void read_annotation_file();

private:
    char const * rootPath;
    char const * cocoYear;
    SUBSET subSet;

};

#endif //DETECTIONEVALUATOR_COCODATASET_HXX
