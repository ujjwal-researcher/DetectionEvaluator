//
// Created by uujjwal on 7/17/21.
//

#ifndef DETECTIONEVALUATOR_BOUNDINGBOX_HXX
#define DETECTIONEVALUATOR_BOUNDINGBOX_HXX

#include<iostream>
#include<array>


class BoundingBox{
private:
    enum BOXFORMAT : int {
        VOC=0,
        COCO=1
    };
    BOXFORMAT boxType;
    bool normalized;
public:
    BoundingBox( int, bool);
    int get_box_type();
    virtual std::array<float, 4> const * get_box() = 0;
    virtual std::pair<float const *, float const * > get_height_width() = 0;
    virtual float const * get_area() = 0;
    virtual unsigned short int const * get_category_id()=0;
    virtual char const * get_category_name_by_id()=0;

};


class COCOBoundingBox : public BoundingBox{
private :
    std::array<float, 4> box{};
unsigned short int categoryId;
float area;
bool isCrowd;

public:
    COCOBoundingBox(float, float, float, float, unsigned short int, float, bool);
    std::array<float, 4> const * get_box() override;
    std::pair<float const * , float const * > get_height_width() override;
    float const * get_area() override;
    unsigned short int const * get_category_id() override;
    char const * get_category_name_by_id() override;
    bool const * is_crowded();
};

#endif //DETECTIONEVALUATOR_BOUNDINGBOX_HXX
