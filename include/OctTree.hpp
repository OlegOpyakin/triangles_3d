#include "triangle.hpp"
#include <list>

#pragma once

class Node{
public:
    Node(const Point& centre_of_node, const double& size): centre_of_node_(centre_of_node), size_(size) {};
    ~Node(){}

    std::list<Triangle> triangles_list_ {};

    std::array<Node*, 8> childs_ = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

    Node* parent_ = nullptr;

    const Point centre_of_node_ = {NAN, NAN, NAN};

    bool is_leaf = true;

    size_t active_node_mask_ = 0;

    const double size_ = 0;
};


bool PointInNode(const Point& point, const Point& middle, const double& size);


bool TriangleInNode(const Triangle& triangle, const Point& middle, const double& size);

bool TrianglePartInNode(Triangle& triangle, Point& middle, double& size);

void CreateChildren(Node* node);


class OctTree{
public:
    OctTree(std::list<Triangle>& all_triangles, double max_size){

        Point middle(0, 0, 0);

        root_ = new Node(middle, max_size);

        if(root_ = nullptr) return;

        auto start = all_triangles.begin();
        auto end = all_triangles.end();

        while(start != end){
            root_->triangles_list_.push_back(*start);
        }

        /*
        for(auto i: all_triangles){
            root_->triangles_list_.push_back(i);
        }
        */

        CreateChildren(root_);
    };

    ~OctTree(){
        DeleteNodes(root_);
        delete root_;
    };
    
    void DeleteNodes(Node* node){
        for(int i = 0; i < 8; i++){
            if(node->childs_[i]){
                DeleteNodes(node->childs_[i]);
            }
        }
        for(int i = 0; i < 8; i++){
            delete node->childs_[i];
        }
    }

    Node* root_;
};


double MaxSize(Point p1, double size);