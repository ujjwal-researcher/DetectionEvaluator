//
// Created by uujjwal on 7/21/21.
//

#include"BoundingBox.hxx"


BoundingBox::BoundingBox(BOXFORMAT box_format) : boxFormat(box_format) {}

BoundingBoxXYWH::BoundingBoxXYWH(std::array<float, 4> box, int category_id, bool is_crowd, bool is_normalized) :
        BoundingBox(BOXFORMAT::XYWH), boundingBox(box), categoryId(category_id), isCrowd(is_crowd),
        isNormalized(is_normalized) {
    boxHeight = boundingBox[3];
    boxWidth = boundingBox[2];
    boxArea = boxWidth * boxHeight;

}

std::array<float, 4> const &BoundingBoxXYWH::get_bbox() const {
    return boundingBox;
}

int const &BoundingBoxXYWH::get_category_id() const {
    return categoryId;
}

float const &BoundingBoxXYWH::get_height() const {
    return boxHeight;
}

float const &BoundingBoxXYWH::get_width() const {
    return boxWidth;
}

std::pair<float const &, float const &> BoundingBoxXYWH::get_height_width() const {
    return std::pair<const float &, const float &>(boxHeight, boxWidth);
}

float const &BoundingBoxXYWH::get_area() const {
    return boxArea;
}

bool const &BoundingBoxXYWH::is_normalized() const {
    return isNormalized;
}

bool const &BoundingBoxXYWH::is_crowded() const {
    return isCrowd;
}


BoundingBoxXYXY::BoundingBoxXYXY(std::array<float, 4> box, int category_id, bool is_crowd, bool is_normalized)
        : BoundingBox(BOXFORMAT::XYXY),
          boundingBox(box),
          categoryId(category_id),
          isNormalized(is_normalized),
          isCrowd(is_crowd) {
    boxHeight = boundingBox[3] - boundingBox[1];
    boxWidth = boundingBox[2] - boundingBox[0];
    boxArea = boxHeight * boxWidth;
}

std::array<float, 4> const &BoundingBoxXYXY::get_bbox() const {
    return boundingBox;
}

int const &BoundingBoxXYXY::get_category_id() const {
    return categoryId;
}

float const &BoundingBoxXYXY::get_height() const {
    return boxHeight;
}

float const &BoundingBoxXYXY::get_width() const {
    return boxWidth;
}

std::pair<float const &, float const &> BoundingBoxXYXY::get_height_width() const {
    return std::pair<const float &, const float &>(boxHeight, boxWidth);
}

float const &BoundingBoxXYXY::get_area() const {
    return boxArea;
}

bool const &BoundingBoxXYXY::is_normalized() const {
    return isNormalized;
}

bool const &BoundingBoxXYXY::is_crowded() const {
    return isCrowd;
}

std::unique_ptr<BoundingBox>
BoundingBoxFactory::make_bounding_box(BoundingBox::BOXFORMAT box_format, std::array<float, 4> box, int category_id, bool is_crowd, bool is_normalized ) {
    if (box_format == BoundingBox::BOXFORMAT::XYWH){
        return std::make_unique<BoundingBoxXYWH>(BoundingBoxXYWH(box, category_id, is_crowd, is_normalized));
    }
    else if (box_format == BoundingBox::BOXFORMAT::XYXY){
        return std::make_unique<BoundingBoxXYXY>(BoundingBoxXYXY(box, category_id, is_crowd, is_normalized));
    }
    else {
        throw std::invalid_argument("Invalid box_type.");
    }

}
