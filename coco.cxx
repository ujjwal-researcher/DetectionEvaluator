//
// Created by uujjwal on 7/12/21.
//

#include"coco.hxx"
#include"bbox.hxx"
#include<fstream>
#include<json/json.h>
#include<json/reader.h>
#include<glog/logging.h>
#include<thread>


Coco::Coco(const std::string& dataset_path, std::string dataset_year) : DetectionDataset(std::string("MSCOCO").append(dataset_year)),
                                                                        coco_path{dataset_path},
                                                                        coco_year{std::move(dataset_year)}
                                                                        {

    if (!folder_exists(&dataset_path))
    {
        throw std::invalid_argument("The MSCOCO path " + coco_path + " was not found.");
    }
}

void Coco::read_gt(const std::string filename){
    if (!file_exists(&filename)){
        throw std::invalid_argument("The file " + filename + " ws not found." );
    }
    std::ifstream file(filename, std::ifstream::binary);
    Json::Value root;
    LOG(INFO) << "HERE";
    file >> root;
    Json::Value images = root["images"];
    unsigned int total_images = static_cast<unsigned int>(images.size());
    Json::Value annotations = root["annotations"];
    std::vector<std::thread> threads;
    const auto processer_count = std::thread::hardware_concurrency();
    threads.reserve(processer_count);
    for(unsigned int i = 0; i < processer_count; ++ i){
        if (i + total_images / processer_count > total_images ){
            threads.emplace_back(&Coco::add_one_image, this, images, annotations, i, total_images);
        }
        else{
            threads.emplace_back(&Coco::add_one_image, this, images, annotations, i, i + total_images / processer_count);
        }
    }
    for (int i = 0; i < processer_count; ++i){
        threads[i].join();
    }
    return;
}

void Coco::add_one_image(const Json::Value images, const Json::Value annotations, int start_idx, int end_idx) {
    unsigned int image_id{};
    unsigned int image_width{};
    unsigned int image_height{};
    std::vector<BBOX> box_annotations;
    for(int iter = start_idx; iter < end_idx; ++iter){
        image_id = images[iter]["id"].asUInt();
        image_width = images[iter]["width"].asUInt();
        image_height = images[iter]["height"].asUInt();
        box_annotations.clear();
        for(auto ann : annotations){
            if ( ann["image_id"].asUInt() != image_id){
                continue;
            }
            BBOX bbox(ann["bbox"][0].asFloat(),
                      ann["bbox"][1].asFloat(),
                      ann["bbox"][2].asFloat(),
                      ann["bbox"][3].asFloat(),
                      ann["category_id"].asInt(),
                      ann["area"].asFloat(),
                      ann["is_crowd"].asBool()
                      );
            box_annotations.push_back(bbox);
        }
        Coco::coco_gt[images["file_name"].asString()] = box_annotations;
        LOG(INFO) << "For " << images["file_name"].asString() << "there are " << box_annotations.size() << " annotations.";

    }
}
