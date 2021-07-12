//
// Created by uujjwal on 7/12/21.
//

#ifndef DETECTIONEVALUATOR_COCO_HXX
#define DETECTIONEVALUATOR_COCO_HXX

#include<stdexcept>
#include"base.hxx"
#include "utils.hxx"


const char* COCO_CLASSES[80] = {
        "person","bicycle","car","motorcycle","airplane","bus"
        ,"train","truck","boat","traffic light","fire hydrant",
        "stop sign","parking meter","bench","bird","cat","dog",
        "horse","sheep","cow","elephant","bear","zebra","giraffe",
        "backpack","umbrella","handbag","tie","suitcase","frisbee",
        "skis","snowboard","sports ball","kite","baseball bat",
        "baseball glove","skateboard","surfboard","tennis racket",
        "bottle","wine glass","cup","fork","knife","spoon","bowl",
        "banana","apple","sandwich","orange","broccoli","carrot",
        "hot dog","pizza","donut","cake","chair","couch","potted plant",
        "bed","dining table","toilet","tv","laptop","mouse","remote",
        "keyboard","cell phone","microwave","oven","toaster","sink",
        "refrigerator","book","clock","vase","scissors","teddy bear",
        "hair drier","toothbrush"
};



class Coco : public DetectionDataset{
private:
    static const CATEGORY_DICT create_coco_dict(){
        unsigned short int class_label{1};
        CATEGORY_DICT category_dict;
        for(const std::string& category : COCO_CLASSES){
            category_dict[class_label] = category;
        }

        return category_dict;
    }
    const std::string coco_path;
    const std::string coco_year;
    static inline const CATEGORY_DICT coco_dict = create_coco_dict();



public:
    Coco(const std::string&, std::string);
    const std::string * get_year(){
        return &coco_year;
    }

    inline unsigned short num_classes() override{
        return coco_dict.size();
    }

    inline const CATEGORY_DICT * get_category_dict() override{
        return &coco_dict;
    }

    inline const std::string * get_category_name_by_id(unsigned short int class_label) override{
        if (coco_dict.find(class_label) != coco_dict.end()){
            return &coco_dict[class_label];
        }
    }


};



#endif //DETECTIONEVALUATOR_COCO_HXX
