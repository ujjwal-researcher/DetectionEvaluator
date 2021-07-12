//
// Created by uujjwal on 7/12/21.
//

#include"coco.hxx"
#include"base.hxx"

Coco::Coco(const std::string& dataset_path, std::string dataset_year) : DetectionDataset("MSCOCO" + dataset_year),
                                                                        coco_path{dataset_path},
                                                                        coco_year{std::move(dataset_year)}
                                                                        {

    if (!folder_exists(&dataset_path))
    {
        throw std::invalid_argument("The MSCOCO path " + coco_path + " was not found.");
    }
}