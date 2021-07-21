//
// Created by uujjwal on 7/21/21.
//

#include"Dataset.hxx"
#include"genutils.hxx"
#include<fstream>
#include<sstream>
#include<vector>
#include<boost/algorithm/string/trim.hpp>
#include<boost/algorithm/string.hpp>
#include<spdlog/spdlog.h>
const char *Dataset::get_name() const {
    return name;
}

Dataset::SUBSET Dataset::which_subset() const {
    return subSet;
}

Dataset::Dataset(const char *name, SUBSET subset, bool is_gt) : name(name), subSet(subset), isGT(is_gt) {}

bool Dataset::is_gt() const {
    return isGT;
}

EvaluatorDatasetOffline::EvaluatorDatasetOffline(const char *name, const char *file_list, const BoundingBox::BOXFORMAT &box_format,
                                   const Dataset::SUBSET &subset, bool is_gt) : Dataset(name, subset, is_gt), fileList(file_list),
                                                                    boxFormat(box_format) {
    read_listfile();
}

void EvaluatorDatasetOffline::read_listfile() {
    if (!file_exists(fileList)){
        spdlog::error("The list file {} was not found." , fileList);
    }
    int lineNum{};
    int emptyLineCount{};
    std::string line{};
    std::vector<std::string> annotationFiles{};
    std::ifstream listFile(fileList);
    while(std::getline(listFile, line)){
        ++lineNum;
        if(line.empty()){
            ++emptyLineCount;
            continue;
        }
        annotationFiles.push_back(line);
    }

    spdlog::info("{} has a total of {} lines out of which {} are empty.",fileList, lineNum, emptyLineCount);

}

void EvaluatorDatasetOffline::read_single_annotation(const std::string & filename) {
    if(!file_exists(filename.c_str())){
        spdlog::error("The annotation file {} was not found.", filename);
    }
    std::string line{};
    std::string imageFileName{};
    std::ifstream inStream(filename);
    std::vector<std::string> results{};
    int numLines{};
    int emptyLineCount{};
    bool firstLine{false};
    size_t numElements{};
    auto numValidElements = [this] () constexpr->int {
        if (this->is_gt()){
            return 5;
        }
        else{
            return 6;
        }
    };

    while(std::getline(inStream, line)){
        ++numLines;
        if(line.empty()){
            ++emptyLineCount;
            continue;
        }
        boost::algorithm::trim(line);
        if(!firstLine){
            imageFileName = line;
            firstLine = true;
            continue;
        }
        boost::algorithm::split(results, line, boost::is_any_of(","));
        numElements = results.size();
        if(numElements != numValidElements()){
            spdlog::error("Each annotation line after the first line should have {} elements. {} were found.", numValidElements(), numElements);
        }




    }

}


