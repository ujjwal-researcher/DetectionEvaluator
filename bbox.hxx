//
// Created by uujjwal on 7/15/21.
//

#ifndef DETECTIONEVALUATOR_BBOX_HXX
#define DETECTIONEVALUATOR_BBOX_HXX
#include<map>
#include<iostream>

class BBOX{
public:
    typedef std::map<std::string, float> bbox_info_type;
    bbox_info_type bbox_info;
    BBOX(float xmin, float ymin, float width, float height, int category_id, float area, bool is_crowd){
        bbox_info.insert(std::pair<std::string, float>("xmin", xmin));
        bbox_info.insert(std::pair<std::string, float>("ymin", ymin));
        bbox_info.insert(std::pair<std::string, float>("width", width));
        bbox_info.insert(std::pair<std::string, float>("height", height));
        bbox_info.insert(std::pair<std::string, float>("category_id", static_cast<float>(category_id)));
        bbox_info.insert(std::pair<std::string, float>("area", area));
        bbox_info.insert(std::pair<std::string, float>("is_crowd", static_cast<float>(is_crowd)));
    }
    inline float aspect_ratio(){
        return (bbox_info["height"] / bbox_info["width"]);
    }

    void normalize(const int&, const int&);
    void unnormalize(const int&, const int&);

};


#endif //DETECTIONEVALUATOR_BBOX_HXX
