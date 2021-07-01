#include "QuadTree.h"
#include <memory>
#include <iostream>
#include <vector>

namespace utec
{
namespace spatial
{

template<typename Node, typename Rectangle, typename Point>
QuadTree<Node, Rectangle, Point>::QuadTree(){
    this->root=nullptr;
}

template<typename Node, typename Rectangle, typename Point>
void QuadTree<Node, Rectangle, Point>::insert(Point new_point){
    std::shared_ptr<Node>& target = search(new_point, this->root);
    if(target==nullptr){
        target=std::make_shared<Node>(new_point);
    }
}

template<typename Node, typename Rectangle, typename Point>
std::shared_ptr<Node>& QuadTree<Node, Rectangle, Point>::search(Point target, std::shared_ptr<Node>& node){
    if(node == nullptr){
        return node; //not found
    } else if(node->get_point() == target){
        return node;
    }
    
    auto cur_point = node->get_point();

    const int x=0, y=1;

    if(target.get(x) < cur_point.get(x)){
        if(target.get(y) > cur_point.get(y))
            return search(target, node->NW());
        else
            return search(target, node->SW());
    }else{
        if(target.get(y) > cur_point.get(y))
            return search(target, node->NE());
        else
            return search(target, node->SE());
    }
}

template<typename Node, typename Rectangle, typename Point>
std::shared_ptr<Node> QuadTree<Node, Rectangle, Point>::search(Point target){
    return search(target, this->root);
}

template<typename Node, typename Rectangle, typename Point>
std::vector<Point> QuadTree<Node, Rectangle, Point>::range(Rectangle region){
    std::vector<Point> query_result_vector;
    range_query_aux(region, this->root, query_result_vector);
    return query_result_vector;
}

template<typename Node, typename Rectangle, typename Point>
void QuadTree<Node, Rectangle, Point>::range_query_aux(Rectangle region, std::shared_ptr<Node>& node_shared_ptr, std::vector<Point>& query_result_vector){
    // Recursion base case
    if(node_shared_ptr == nullptr) return;
    Point point = node_shared_ptr->get_point();

    // Range validation
    if(region.is_inside(point)) query_result_vector.push_back(point);

    // Recursion in each child
    if(node_shared_ptr->NW()) range_query_aux(region, node_shared_ptr->NW(), query_result_vector);
    if(node_shared_ptr->NE()) range_query_aux(region, node_shared_ptr->NE(), query_result_vector);
    if(node_shared_ptr->SW()) range_query_aux(region, node_shared_ptr->SW(), query_result_vector);
    if(node_shared_ptr->SE()) range_query_aux(region, node_shared_ptr->SE(), query_result_vector);
}

template<typename Node, typename Rectangle, typename Point>
Point QuadTree<Node, Rectangle, Point>::nearest_neighbor(Point reference){
    // TODO
}

} //spatial
} //utec
