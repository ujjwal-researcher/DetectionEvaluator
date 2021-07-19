//
// Created by uujjwal on 7/17/21.
//

#include "BoundingBox.hxx"
#include "coco_utils.hxx"

BoundingBox::BoundingBox(int box_type, bool is_normalized) {
    if ( box_type == 0){
        boxType = BOXFORMAT::VOC;
    }
    else if ( box_type == 1) {
        boxType = BOXFORMAT::COCO;
    }
    normalized = is_normalized;
}

int BoundingBox::get_box_type() {
    if ( boxType == BOXFORMAT::VOC){
        return 0;
    }
    else {
        return 1;
    }
}

COCOBoundingBox::COCOBoundingBox(float xmin, float ymin, float width, float height, unsigned short int category_num, float box_area, bool is_crowd)
: BoundingBox(1, false) {
    box[0] = xmin;
    box[1] = ymin;
    box[2] = width;
    box[3] = height;
    categoryId = category_num;
    area = box_area;
    isCrowd = is_crowd;
}

std::array<float, 4> const * COCOBoundingBox::get_box() {
    return &box;
}

std::pair<float const *, float const *> COCOBoundingBox::get_height_width() {
    return std::pair<float const *, float const *>(&box[2], &box[3]);
}

float const *COCOBoundingBox::get_area() {
    return &area;
}

unsigned short int const *COCOBoundingBox::get_category_id() {
    return &categoryId;
}

char const *COCOBoundingBox::get_category_name_by_id() {
    return cocoutils::get_coco_name_from_id(categoryId);
}

bool const *COCOBoundingBox::is_crowded() {
    return &isCrowd;
}




