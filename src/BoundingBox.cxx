//
// Created by uujjwal on 7/22/21.
//

#include <BoundingBox.hxx>
#include <utility>
#include<spdlog/spdlog.h>

BoxCollection::BoxCollection(BoxCollection::BOXFORMAT format, std::string image_name, Eigen::ArrayX4f boxes,
                             Eigen::VectorXi category_ids, Eigen::VectorXf confidences, bool normalized) :
        boxFormat(format), imageName(std::move(image_name)), boundingBoxes(std::move(boxes)),
        boxCategoryIds(std::move(category_ids)), boxConfidences(std::move(confidences)),
        isNormalized(normalized) {}

Eigen::VectorXi const &BoxCollection::get_categoryids() const {
    return boxCategoryIds;
}

Eigen::ArrayX4f const &BoxCollection::get_boxes() const {
    return boundingBoxes;
}

Eigen::VectorXf const &BoxCollection::get_confidences() const {
    return boxConfidences;
}

std::string const &BoxCollection::get_imagename() const {
    return imageName;
}

BoxCollection::BOXFORMAT BoxCollection::get_boxformat() const {
    return boxFormat;
}

bool const &BoxCollection::is_normalized() const {
    return isNormalized;
}

bool BoxCollection::normalize_boxes(int const &image_height, int const &image_width) {
    auto normalizedBoxes = normalize(image_height, image_width);
    if (normalizedBoxes.size() == 0) {
        isNormalized = false;
        return false;
    } else {
        boundingBoxes = std::move(normalizedBoxes);
        isNormalized = true;
        return true;
    }

}


BoxCollectionXYWH::BoxCollectionXYWH(BoxCollection::BOXFORMAT format, std::string image_name, Eigen::ArrayX4f boxes,
                                     Eigen::VectorXi category_ids,
                                     Eigen::VectorXf confidences, bool normalized = false) : BoxCollection(

        format, std::move(image_name), std::move(boxes), std::move(category_ids), std::move(confidences), normalized) {
    boxHeights = get_boxes().col(3);
    boxWidths = get_boxes().col(2);
    boxAreas = boxHeights * boxWidths;

}

Eigen::VectorXf const &BoxCollectionXYWH::get_heights() const {
    return boxHeights;
}

Eigen::VectorXf const &BoxCollectionXYWH::get_widths() const {
    return boxWidths;
}

Eigen::VectorXf const &BoxCollectionXYWH::get_areas() const {
    return boxAreas;
}

Eigen::ArrayX4f BoxCollectionXYWH::normalize(const int &image_height, const int &image_width) const {
    Eigen::ArrayX4f normalizedBoxes = get_boxes();
    if (image_height <= 0 || image_width <= 0) {
        spdlog::error("Found image_height as {} and image_width as {}. Cannot normalize.", image_height, image_width);
        return Eigen::ArrayX4f();
    }
    normalizedBoxes.block<4, 1>(0, 0) /= image_width;
    normalizedBoxes.block<4, 1>(0, 1) /= image_height;
    normalizedBoxes.block<4, 1>(0, 2) /= image_width;
    normalizedBoxes.block<4, 1>(0, 3) /= image_height;
    return normalizedBoxes;
}


BoxCollectionXYXY::BoxCollectionXYXY(BoxCollection::BOXFORMAT format, std::string image_name, Eigen::ArrayX4f boxes,
                                     Eigen::VectorXi category_ids,
                                     Eigen::VectorXf confidences, bool normalized) : BoxCollection(

        format, std::move(image_name), std::move(boxes), std::move(category_ids), std::move(confidences), normalized) {
    boxHeights = get_boxes().col(3) - get_boxes().col(1);
    boxWidths = get_boxes().col(2) - get_boxes().col(0);
    boxAreas = boxHeights * boxWidths;

}

Eigen::VectorXf const &BoxCollectionXYXY::get_heights() const {
    return boxHeights;
}

Eigen::VectorXf const &BoxCollectionXYXY::get_widths() const {
    return boxWidths;
}

Eigen::VectorXf const &BoxCollectionXYXY::get_areas() const {
    return boxAreas;
}

Eigen::ArrayX4f BoxCollectionXYXY::normalize(const int &image_height, const int &image_width) const {
    Eigen::ArrayX4f normalizedBoxes = get_boxes();
    if (image_height <= 0 || image_width <= 0) {
        spdlog::error("Found image_height as {} and image_width as {}. Cannot normalize.", image_height, image_width);
        return Eigen::ArrayX4f();
    }
    normalizedBoxes.block<4, 1>(0, 0) /= image_width;
    normalizedBoxes.block<4, 1>(0, 1) /= image_height;
    normalizedBoxes.block<4, 1>(0, 2) /= image_width;
    normalizedBoxes.block<4, 1>(0, 3) /= image_height;
    return normalizedBoxes;
}
