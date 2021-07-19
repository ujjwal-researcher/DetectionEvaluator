//
// Created by uujjwal on 7/17/21.
//

#include "DatasetBase.hxx"

const char * DatasetBase::get_name() {
    return name;
}

DatasetBase::DatasetBase(const char * dataset_name) {
    name = dataset_name;
}