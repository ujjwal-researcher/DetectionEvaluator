//
// Created by uujjwal on 7/21/21.
//

#ifndef DETECTIONEVALUATOR_DATASET_HXX
#define DETECTIONEVALUATOR_DATASET_HXX

#include<iostream>
#include<boost/filesystem.hpp>
#include<Eigen/Core>
#include<map>
#include"BoundingBox.hxx"

namespace fs = boost::filesystem;

class Dataset{
private:
    char const * name;
    bool isGT;
public:
    enum SUBSET : int {
        TRAIN=1,
        VAL=2,
        TEST=3,
        TEST_DEV=4
    };
    Dataset(char const *, SUBSET, bool);
    [[nodiscard]] char const * get_name() const;
    [[nodiscard]] SUBSET which_subset() const;
    virtual int get_num_images() =0;
    [[nodiscard]] bool is_gt() const;

private:
    SUBSET subSet;
};


class EvaluatorDatasetOffline : public Dataset{
private:
    char const * fileList;
    int numImages;
    BoundingBox::BOXFORMAT boxFormat;
    typedef std::map<std::string, Eigen::MatrixX4d> ANNOTATIONS;
    ANNOTATIONS annotations;
    void read_listfile();
    void read_single_annotation(std::string const &);


public:
    EvaluatorDatasetOffline(char const *, char const *, BoundingBox::BOXFORMAT const &,  Dataset::SUBSET const &, bool);
    int get_num_images() override{
        return 1;
    }

};

#endif //DETECTIONEVALUATOR_DATASET_HXX
