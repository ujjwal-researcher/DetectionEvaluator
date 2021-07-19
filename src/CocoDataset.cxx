//
// Created by uujjwal on 7/17/21.
//

#include "CocoDataset.hxx"
#include<simdjson.h>
#include<string>

COCODataset::COCODataset(const char *root_path, const char *year, COCODataset::SUBSET subset)
        : DatasetBase::DatasetBase(
        std::string("MSCOCO").append(std::string(year)).c_str()
), rootPath(root_path), subSet(subset), cocoYear(year) {
}

unsigned short int COCODataset::get_num_classes() {
    return 80;
}

char const *COCODataset::get_category_name_by_id(unsigned short int category_id) {
    return cocoutils::get_coco_name_from_id(category_id);
}

char const *COCODataset::get_subset() {
    if (subSet == COCODataset::TRAIN) {
        return "train";
    } else if (subSet == COCODataset::VAL) {
        return "val";
    } else if (subSet == COCODataset::TEST) {
        return "test";
    } else {
        return "test-dev";
    }
}

void COCODataset::read_annotation_file() {
    auto coco_subset{get_subset()};
    auto annotation_file{cocoutils::get_annotation_file(rootPath, coco_subset, cocoYear)};
    std::cout << annotation_file << std::endl;
    simdjson::ondemand::parser jsonParser;
    auto json = simdjson::padded_string::load(std::string(annotation_file));
    auto doc = jsonParser.iterate(json);
    simdjson::ondemand::object object = doc.get_object();

}



