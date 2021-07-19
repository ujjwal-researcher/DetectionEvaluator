//
// Created by uujjwal on 7/17/21.
//

#include"coco_utils.hxx"
#include<boost/filesystem.hpp>
#include<glog/logging.h>
#include<string>

const char *cocoutils::get_coco_name_from_id(unsigned short int category_num) {
    if (category_num < 1 || category_num > 80) {
        LOG(FATAL) << "category number in MSCOCO must be in the range [1,80].";
    }
    return cocoutils::COCO_CLASSES[category_num - 1];
}

char const *cocoutils::COCO_CLASSES[80] = {
        "person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat", "traffic light",
        "fire hydrant",
        "stop sign", "parking meter", "bench", "bird", "cat", "dog",
        "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe",
        "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee",
        "skis", "snowboard", "sports ball", "kite", "baseball bat",
        "baseball glove", "skateboard", "surfboard", "tennis racket",
        "bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl",
        "banana", "apple", "sandwich", "orange", "broccoli", "carrot",
        "hot dog", "pizza", "donut", "cake", "chair", "couch", "potted plant",
        "bed", "dining table", "toilet", "tv", "laptop", "mouse", "remote",
        "keyboard", "cell phone", "microwave", "oven", "toaster", "sink",
        "refrigerator", "book", "clock", "vase", "scissors", "teddy bear",
        "hair drier", "toothbrush"
};

char const *cocoutils::get_annotation_file(const char *coco_path, const char *coco_subset, const char *coco_year) {
    boost::filesystem::path annotation_path =
            boost::filesystem::path(coco_path) / boost::filesystem::path("annotations");
    std::string annotation_file{};
    if (std::strcmp(coco_subset, "train") == 0) {
        annotation_file = std::string("instances_train") + std::string(coco_year) + std::string(".json");

    } else if (std::strcmp(coco_subset, "val") == 0) {
        annotation_file = std::string("instances_val") + std::string(coco_year) + std::string(".json");
    } else if (std::strcmp(coco_subset, "test") == 0) {
        annotation_file = std::string("image_info_test") + std::string(coco_year) + std::string(".json");
    } else {
        annotation_file = std::string("instances_test-dev") + std::string(coco_year) + std::string(".json");
    }
    annotation_path = annotation_path / boost::filesystem::path(annotation_file);
    return annotation_path.c_str();
}
