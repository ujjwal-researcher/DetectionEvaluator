//
// Created by uujjwal on 7/13/21.
//

#include"coco.hxx"
#include<glog/logging.h>

int main(){
    google::InitGoogleLogging("INFO");
    Coco db_coco("/data/stars/share/STARSDATASETS/COCO17", "2017");
    //auto num_classes = db_coco.num_classes();
    const std::string filename{"/data/stars/share/STARSDATASETS/COCO17/annotations/instances_val2017.json"};
    db_coco.read_gt(filename);

}



