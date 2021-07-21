//
// Created by uujjwal on 7/21/21.
//

#ifndef DETECTIONEVALUATOR_BOUNDINGBOX_HXX
#define DETECTIONEVALUATOR_BOUNDINGBOX_HXX

#include<iostream>
#include<array>
#include<utility>
#include<memory>

class BoundingBox{
public:
    enum BOXFORMAT : int {
        XYWH=1,
        XYXY=2
    };
    BOXFORMAT boxFormat;
    explicit BoundingBox(BOXFORMAT);
    [[nodiscard]] virtual std::array<float, 4> const & get_bbox() const=0;
    [[nodiscard]] virtual int const & get_category_id() const=0;
    [[nodiscard]] virtual float const & get_height() const=0;
    [[nodiscard]] virtual float const & get_width() const=0;
    [[nodiscard]] virtual std::pair<float const &, float const &> get_height_width() const=0;
    [[nodiscard]] virtual float const & get_area() const=0;
    [[nodiscard]] virtual bool const & is_normalized() const=0;
    [[nodiscard]] virtual bool const & is_crowded() const =0;
};

class BoundingBoxXYWH : public BoundingBox{
private:
    std::array<float,4> boundingBox;
    int categoryId;
    float boxArea;
    float boxHeight;
    float boxWidth;
    bool isNormalized;
    bool isCrowd;
public:
    BoundingBoxXYWH(std::array<float,4>, int, bool, bool);
    [[nodiscard]] std::array<float, 4> const & get_bbox() const override;
    [[nodiscard]] int const & get_category_id() const override;
    [[nodiscard]] float const & get_height() const override;
    [[nodiscard]] float const & get_width() const override;
    [[nodiscard]] std::pair<float const &, float const &> get_height_width() const override;
    [[nodiscard]] float const & get_area()  const override;
    [[nodiscard]] bool const & is_normalized() const override;
    [[nodiscard]] bool const & is_crowded() const override;

};

class BoundingBoxXYXY: public  BoundingBox{
private:
    std::array<float,4> boundingBox;
    int categoryId;
    float boxArea;
    float boxHeight;
    float boxWidth;
    bool isNormalized;
    bool isCrowd;
public:
    BoundingBoxXYXY(std::array<float,4>, int, bool, bool);
    [[nodiscard]] std::array<float, 4> const & get_bbox() const override;
    [[nodiscard]] int const & get_category_id() const  override;
    [[nodiscard]] float const & get_height() const override;
    [[nodiscard]] float const & get_width() const override;
    [[nodiscard]] std::pair<float const &, float const &> get_height_width() const override;
    [[nodiscard]] float const & get_area() const override;
    [[nodiscard]] bool const & is_normalized() const override;
    [[nodiscard]] bool const & is_crowded() const override;

};


class BoundingBoxFactory{
public:
    static std::unique_ptr<BoundingBox> make_bounding_box(BoundingBox::BOXFORMAT, std::array<float,4>, int, bool, bool);
};

#endif //DETECTIONEVALUATOR_BOUNDINGBOX_HXX
