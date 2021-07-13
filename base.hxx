#ifndef DETECTIONEVALUATOR_BASE_HXX
#define DETECTIONEVALUATOR_BASE_HXX
#include<iostream>
#include<map>
class DetectionDataset{
private:
    const std::string db_name;

public:
    typedef std::map<unsigned short int, std::string> CATEGORY_DICT;
    DetectionDataset(std::string& name): db_name(name) {}
    inline const std::string get_name(){
        return db_name;
    }
    virtual unsigned short int num_classes() =0;
    virtual const CATEGORY_DICT * get_category_dict() = 0;
    virtual const std::string get_category_name_by_id(unsigned short int) const=0;



};



#endif //DETECTIONEVALUATOR_BASE_HXX
