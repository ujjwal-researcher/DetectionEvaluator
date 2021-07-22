//
// Created by uujjwal on 7/22/21.
//

#ifndef DETECTIONEVALUATOR_BOUNDINGBOX_HXX
#define DETECTIONEVALUATOR_BOUNDINGBOX_HXX

#include<iostream>
#include<Eigen/Core>

class BoxCollection {
public:
    enum BOXFORMAT : int {
        XYWH = 1,
        XYXY = 2
    };
private:
    BOXFORMAT boxFormat;
    std::string imageName;
    Eigen::ArrayX4f boundingBoxes;
    Eigen::VectorXi boxCategoryIds;
    Eigen::VectorXf boxConfidences;
    bool isNormalized;

    virtual Eigen::ArrayX4f normalize(int const &, int const &) const = 0;

public:
    BoxCollection(BOXFORMAT format, std::string, Eigen::ArrayX4f, Eigen::VectorXi, Eigen::VectorXf, bool);

    [[nodiscard]] Eigen::ArrayX4f const &get_boxes() const;

    [[nodiscard]] Eigen::VectorXi const &get_categoryids() const;

    [[nodiscard]] Eigen::VectorXf const &get_confidences() const;

    [[nodiscard]] std::string const &get_imagename() const;

    [[nodiscard]] bool const &is_normalized() const;

    [[nodiscard]] BOXFORMAT get_boxformat() const;

    virtual Eigen::VectorXf const &get_heights() const = 0;

    virtual Eigen::VectorXf const &get_widths() const = 0;

    virtual Eigen::VectorXf const &get_areas() const = 0;

    [[nodiscard]] bool normalize_boxes(int const &, int const &);


};

class BoxCollectionXYWH : public BoxCollection {
private:
    Eigen::VectorXf boxHeights;
    Eigen::VectorXf boxWidths;
    Eigen::VectorXf boxAreas;

    Eigen::ArrayX4f normalize(int const &, int const &) const override;

public:
    BoxCollectionXYWH(BOXFORMAT, std::string, Eigen::ArrayX4f, Eigen::VectorXi, Eigen::VectorXf, bool);

    [[nodiscard]] Eigen::VectorXf const &get_heights() const override;

    [[nodiscard]] Eigen::VectorXf const &get_widths() const override;

    [[nodiscard]] Eigen::VectorXf const &get_areas() const override;
};


class BoxCollectionXYXY : public BoxCollection {
private:
    Eigen::VectorXf boxHeights;
    Eigen::VectorXf boxWidths;
    Eigen::VectorXf boxAreas;

    Eigen::ArrayX4f normalize(int const &, int const &) const override;


public:
    BoxCollectionXYXY(BOXFORMAT, std::string, Eigen::ArrayX4f, Eigen::VectorXi, Eigen::VectorXf, bool);

    [[nodiscard]] Eigen::VectorXf const &get_heights() const override;

    [[nodiscard]] Eigen::VectorXf const &get_widths() const override;

    [[nodiscard]] Eigen::VectorXf const &get_areas() const override;
};


class BoxCollectionFactory{
public:
    static BoxCollection * make_box_collection(BoxCollection::BOXFORMAT, std::string, Eigen::ArrayX4f, Eigen::VectorXi, Eigen::VectorXf, bool);
};

#endif //DETECTIONEVALUATOR_BOUNDINGBOX_HXX
