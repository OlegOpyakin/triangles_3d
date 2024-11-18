#include "parsing_triangles.hpp"


int ParseNode(bool* flag_array, const Node* node) {
    for(auto triangle1 = node->triangles_in_node_.begin(); triangle1 != std::prev(node->triangles_in_node_.end()); ++triangle1){
        for(auto triangle2 = std::next(triangle1); triangle2 != node->triangles_in_node_.end(); ++triangle2){
            if(Intersection2Triangles(*triangle1, *triangle2) == true){
                flag_array[triangle1->number] = 1;
                flag_array[triangle2->number] = 1;
            }
        }
        ParseChildren(flag_array, node, *triangle1);
    }
    
    for(int i = 0; i < 8; i++){
        if (!(node->active_node_mask_ & (1 << i))) continue;
        ParseNode(flag_array, node->childs_[i]);
    }
    
    return 0;
}


int ParseChildren(bool* flag_array, const Node* node, const Triangle& triangle1){

    if (node->emptey_|| node->active_node_mask_ == 0)
        return 0;

    for(int i = 0; i < 8; i++){
        if (!(node->active_node_mask_ & (1 << i)))
            continue;

        if (!TrianglePartInNode(triangle1, node->childs_[i]->centre_of_node_, node->childs_[i]->size_))
            continue;

        for (auto triangle2: node->childs_[i]->triangles_in_node_)
        {
            if (Intersection2Triangles(triangle1, triangle2) == true)
            {
                flag_array[triangle2.number] = 1;
                flag_array[triangle1.number]  = 1;
            }
        }

        ParseChildren(flag_array, node->childs_[i], triangle1);
    }
    return 0;
}