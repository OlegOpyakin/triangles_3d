#include "triangle.hpp"
#include <list>

#pragma once

class Node{
public:
    Node(Point centre_of_node, double size): centre_of_node_(centre_of_node), size_(size) {};
    ~Node(){}

    std::list<Triangle> triangles_list_ = {};
    std::array<Node*, 8> childs_ = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    Node* parent_ = nullptr;
    Point centre_of_node_ = {NAN, NAN, NAN};

    bool is_emptey = false;
    double size_ = 0;
};


bool PointInNode(const Point point, const Point middle, double size);
/*
{
    return( (middle.GetX() - size) < point.GetX() &&
            point.GetX() < (middle.GetX() + size) &&

            (middle.GetY() - size < point.GetY()) &&
            point.GetY() < (middle.GetY() + size) &&

            (middle.GetZ() - size < point.GetZ()) &&
            point.GetZ() < (middle.GetZ() + size) );
}*/


bool TriangleInNode(Triangle& triangle, Point& middle, double& size);
/*
{
    return( PointInNode(triangle.get_point_1(), middle, size) && 
            PointInNode(triangle.get_point_2(), middle, size) && 
            PointInNode(triangle.get_point_3(), middle, size) );
}
*/

void CreateChildren(Node* node);
/*
{
    if (node->triangles_list_.size() < 8) // check if the node is last
        return;

    double new_size = node->size_/2;
    int num_of_triangles = node->triangles_list_.size();
    
    for(int i = 0; i < 8; i++){
        double new_x;
        double new_y;
        double new_z;

        if(i & 1){ new_x = node->centre_of_node_.GetX() + new_size; }
        else { new_x = node->centre_of_node_.GetX() - new_size; }

        if(i & 2){ new_y = node->centre_of_node_.GetY() + new_size; }
        else { new_y = node->centre_of_node_.GetY() - new_size; }

        if(i & 4){ new_z = node->centre_of_node_.GetZ() + new_size; }
        else { new_z = node->centre_of_node_.GetZ() - new_size; }

        node->childs_[i] = new Node(Point{new_x, new_y, new_z}, new_size);
    }

    auto it = node->triangles_list_.begin();
    auto last = node->triangles_list_.end();

    while(it != last){
        int flag = 0;
        for(int i = 0; i < 8; i++){
            bool hit = TriangleInNode(*it, node->childs_[i]->centre_of_node_, node->childs_[i]->size_); //function to check if we in box
            if(hit){
                node->childs_[i]->triangles_list_.push_back(*it);
                node->triangles_list_.erase(it++);
                flag = 1;
                break;
            }
        }
        if(flag == 0) it++;
    }
    
    if((num_of_triangles - node->triangles_list_.size()) == 0) node->is_emptey = true;
    else node->is_emptey = false;

    for(int i = 0; i < 8; i++){
        if(node->childs_[i]->triangles_list_.size()){
            CreateChildren(node->childs_[i]);
        }
    }
}
*/

class OctTree{
public:
    OctTree(std::list<Triangle> all_triangles, double max_size): all_triangles_(all_triangles){
        Point middle(0, 0, 0);

        root_ = new Node(middle, max_size);
        for(auto i: all_triangles){
            root_->triangles_list_.push_back(i);
        }
        
        CreateChildren(root_);
    };

    ~OctTree(){
        DeleteNodes(root_);
        delete root_;
    };
    
    void DeleteNodes(Node* node){
        for(int i = 0; i < 8; i++){
            if(node->childs_[i] != nullptr){
                DeleteNodes(node->childs_[i]);
            }
        }
        for(int i = 0; i < 8; i++){
            delete node->childs_[i];
        }
    }
    
    std::list<Triangle> all_triangles_;

    Node* root_;
};

double MaxSize(Point p1, double size);