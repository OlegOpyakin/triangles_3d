#include "parsing_triangles.hpp"


void ParseNode(bool* flag_array, Node* node) {

    auto begin = node->triangles_list_.begin();
    auto end = node->triangles_list_.end();
    auto before_end = std::prev(node->triangles_list_.end());
    
    for(auto triangle1 = begin; triangle1 != before_end; ++triangle1)
    {
        for(auto triangle2 = std::next(triangle1); triangle2 != end; ++triangle2)
        {
            if(Intersection2Triangles(*triangle1, *triangle2) == true){
                flag_array[triangle1->number] = 1;
                flag_array[triangle2->number] = 1;
            }
        }
        ParseChildren(flag_array, node, *triangle1);
    }
    
    for(int i = 0; i < 8; i++){
        //if (!(node->active_node_mask_ & (1 << i)))
        //    continue;

        ParseNode(flag_array, node->childs_[i]);
    }
    
    return;
}

void ParseChildren(bool* flag_array, Node* const node, const Triangle& triangle1){
    for(int i = 0; i < 8; i++){
        for(auto triangle2 = node->childs_[i]->triangles_list_.begin(); triangle2 != node->childs_[i]->triangles_list_.end(); ++triangle2){
            if(Intersection2Triangles(triangle1, *triangle2) == true){
                flag_array[triangle1.number] = 1;
                flag_array[triangle2->number] = 1;
            }
        }
        ParseChildren(flag_array, node->childs_[i], triangle1);
    }
    return;
}