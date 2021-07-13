//
// Created by uujjwal on 7/12/21.
//

#include<iostream>
#include<boost/filesystem.hpp>

inline bool folder_exists(const std::string * folder_name){
    boost::filesystem::path folder_path{*folder_name};
    if ( boost::filesystem::is_directory(folder_path) )
        return true;

    return false;
}

inline bool file_exists(const std::string * file_name){
    boost::filesystem::path file_path{*file_name};
    if ( boost::filesystem::is_regular_file(file_path))
        return true;

    return false;
}



