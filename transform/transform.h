//
// Created by user on 7/27/26.
//

#ifndef ECSPROJ_TRANSFORM_H
#define ECSPROJ_TRANSFORM_H

#endif //ECSPROJ_TRANSFORM_H

class Transform {
private:
    double m_transformX{0};
    double m_transformY{0};

public:

    Transform(double x, double y) : m_transformX{x}, m_transformY{y} {};

    [[nodiscard]] double getTransformX() const { return m_transformX; };
    [[nodiscard]] double getTransformY() const { return m_transformY; };

    void setTransformX(double x) { m_transformX = x; };
    void setTransformY(double y) { m_transformY = y; };
};
