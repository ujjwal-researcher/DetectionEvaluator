//
// Created by uujjwal on 7/15/21.
//

#include "bbox.hxx"

void BBOX::normalize(const int &image_height, const int &image_width) {
    float img_height = static_cast<float>(image_height);
    float img_width = static_cast<float>(image_width);
    bbox_info["xmin"] /= img_width;
    bbox_info["ymin"] /= img_height;
    bbox_info["width"] /= img_width;
    bbox_info["height"] /= img_height;
}

void BBOX::unnormalize(const int &image_height, const int &image_width) {
    float img_height = static_cast<float>(image_height);
    float img_width = static_cast<float>(image_width);
    bbox_info["xmin"] *= img_width;
    bbox_info["ymin"] *= img_height;
    bbox_info["width"] *= img_width;
    bbox_info["height"] *= img_height;
}

