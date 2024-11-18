#include "triangle.hpp"
#include <list>
#include <array>

#pragma once

// code idea taken from there https://habr.com/ru/articles/334990/
// also used this as a source https://habr.com/ru/articles/312882/

class Node{
public:
    Node(const Point& centre_of_node, const double& size = NAN): centre_of_node_(centre_of_node), size_(size) {};
    ~Node() = default;

    std::list<Triangle> triangles_in_node_{};
    std::array<Node*, 8> childs_ = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

    const Point centre_of_node_; // middle of our node

    bool emptey_ = true; // if there any triangles

    size_t active_node_mask_ = 0; // bits mask to have less comparasions(as in reference)

    const double size_ = 0;
};


bool PointInNode(const Point& point, const Point& middle, const double& size);

bool TriangleInNode(const Triangle& triangle, const Point& middle, const double& size);

bool TrianglePartInNode(const Triangle& triangle, const Point& middle, const double& size);

void CreateChildren(Node* node);


class OctTree{
public:
    OctTree(const std::list<Triangle>& all_triangles, double max_size);
    ~OctTree();
    
    void DeleteNodes(Node* node);

    Node* root_ = nullptr;
};


double MaxSize(Point p1, double size);