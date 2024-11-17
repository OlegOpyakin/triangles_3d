#include "OctTree.hpp"

bool PointInNode(const Point& point, const Point& middle, const double& size){
    return( (middle.GetX() - size) < point.GetX() &&
            point.GetX() < (middle.GetX() + size) &&

            (middle.GetY() - size < point.GetY()) &&
            point.GetY() < (middle.GetY() + size) &&

            (middle.GetZ() - size < point.GetZ()) &&
            point.GetZ() < (middle.GetZ() + size) );
}

bool TriangleInNode(const Triangle& triangle, const Point& middle, const double& size)
{
    return( PointInNode(triangle.get_point_1(), middle, size) && 
            PointInNode(triangle.get_point_2(), middle, size) && 
            PointInNode(triangle.get_point_3(), middle, size) );
}

bool TrianglePartInNode(Triangle& triangle, Point& middle, double& size)
{
    return( PointInNode(triangle.get_point_1(), middle, size) ||
            PointInNode(triangle.get_point_2(), middle, size) || 
            PointInNode(triangle.get_point_3(), middle, size) );
}

void CreateChildren(Node* node)
{
    if (node->triangles_list_.size() < 8) // check if the node is last
        return;

    double new_size = node->size_/2;

    int num_of_triangles = node->triangles_list_.size();

    for (size_t i = 0; i < 8; i++)
    {
        double middle_x = node->centre_of_node_.GetX() + ((i & 1) ? new_size : -new_size);

        double middle_y = node->centre_of_node_.GetY() + ((i & 2) ? new_size : -new_size);

        double middle_z = node->centre_of_node_.GetZ() + ((i & 4) ? new_size : -new_size);

        node->childs_[i] = new Node(Point{middle_x, middle_y, middle_z}, new_size);
    }

    /*
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
    }*/
    int old_size = node->triangles_list_.size();

    auto it = node->triangles_list_.begin();

    auto last = node->triangles_list_.end();

    while(it != last)
    {
        bool exists = true;

        for(int i = 0; i < 8; i++)
        {
            if( TriangleInNode(*it, node->childs_[i]->centre_of_node_, node->childs_[i]->size_) ) //function to check if we in box
            {
                node->childs_[i]->triangles_list_.push_back(*it);

                node->triangles_list_.erase(it++);

                exists = false;

                break;
            }
        }
        if(exists) it++;
    }

    if(old_size - node->triangles_list_.size())
        node->is_leaf = false;
    /*
    if((num_of_triangles - node->triangles_list_.size()) == 0) node->is_emptey = true;
    else node->is_emptey = false;
    */

    for(int i = 0; i < 8; i++)
    {
        if(node->childs_[i]->triangles_list_.size())
        {
            node->active_node_mask_ |= (1 << i);
            CreateChildren(node->childs_[i]);
        }
    }
}

double MaxSize(Point p1, double size){
    if( size < std::max( std::max( p1.GetX(), p1.GetY() ), p1.GetZ() ) ) {
        size = std::max( std::max( p1.GetX(), p1.GetY() ), p1.GetZ() );
    }
    return size;
}