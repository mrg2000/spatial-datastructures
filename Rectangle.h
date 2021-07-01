#pragma once

namespace utec
{
namespace spatial
{

template<typename Point>
struct Rectangle{
    Rectangle(Point min, Point max):_min(min),_max(max){}
    Point _min;
    Point _max;

    bool is_inside(Point p){
        if(p.get(0) < this->_min.get(0) || p.get(0) > this->_max.get(0)) return false;
        if(p.get(1) < this->_min.get(1) || p.get(1) > this->_max.get(1)) return false;
        return true;
    }
};

} //spatial
} //utec