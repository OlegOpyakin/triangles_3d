#include "func.hpp"

#pragma once

void ParseNode(bool* flag_array, Node* node);
/*
{
    for(auto triangle1 = node->triangles_list_.begin(); triangle1 != node->triangles_list_.end(); ++triangle1){
        for(auto triangle2 = std::next(triangle1); triangle2 != node->triangles_list_.end(); ++triangle2){
            if(Intersection2Triangles(*triangle1, *triangle2) == true){
                intersected_triangles->push_back(*triangle1);
                intersected_triangles->push_back(*triangle2);
                *count = *count + 1;
            }
        }
        ParseChildren(intersected_triangles, node, count, *triangle1);
    }

    for(int i = 0; i < 8; i++){
        ParseNode(intersected_triangles, node->childs_[i], count);
    }
    return;
}
*/

void ParseChildren(bool* flag_array, Node* node, const Triangle& triangle1);
/*
{
    for(int i = 0; i < 8; i++){
        for(auto triangle2 = node->childs_[i]->triangles_list_.begin(); triangle2 != node->childs_[i]->triangles_list_.end(); ++triangle2){
            if(Intersection2Triangles(triangle1, *triangle2) == true){
                intersected_triangles->push_back(triangle1);
                intersected_triangles->push_back(*triangle2);
                count++;
            }
        }
        ParseChildren(intersected_triangles, node->childs_[i], count, triangle1);
    }
    return;
}
*/