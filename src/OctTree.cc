#include "OctTree.hpp"


OctTree::OctTree(const std::list<Triangle>& all_triangles, double max_size){
    Point middle(0, 0, 0);
    root_ = new Node(middle, max_size);
    for(auto i: all_triangles){
        root_->triangles_in_node_.push_back(i);
    }
    CreateChildren(root_);
};


void OctTree::DeleteNodes(Node* node){
    for(int i = 0; i < 8; i++){
        if(node->childs_[i]){
            DeleteNodes(node->childs_[i]);
        }
    }
    for(int i = 0; i < 8; i++){
        delete node->childs_[i];
    }
}


OctTree::~OctTree(){
    DeleteNodes(root_);
    delete root_;
}


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

bool TrianglePartInNode(const Triangle& triangle, const Point& middle, const double& size)
{
    return( PointInNode(triangle.get_point_1(), middle, size) ||
            PointInNode(triangle.get_point_2(), middle, size) || 
            PointInNode(triangle.get_point_3(), middle, size) );
}

void CreateChildren(Node* node)
{
    if (node->triangles_in_node_.size() < 8) // check if the node is last
        return;

    double new_size = node->size_/2;
    int num_of_triangles = node->triangles_in_node_.size();
    
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

    auto iterator = node->triangles_in_node_.begin();
    auto end = node->triangles_in_node_.end();

    while(iterator != end){
        bool exists = true;
        for(int i = 0; i < 8; i++){
            if( TriangleInNode(*iterator, node->childs_[i]->centre_of_node_, node->childs_[i]->size_) ) //function to check if we in box
            {
                node->childs_[i]->triangles_in_node_.push_back(*iterator);
                node->triangles_in_node_.erase(iterator++);
                exists = false;
                break;
            }
        }
        if(exists) iterator++;
    }

    if(node->triangles_in_node_.size() > 0)
        node->emptey_ = false;

    for(int i = 0; i < 8; i++){
        if(node->childs_[i]->triangles_in_node_.size()){
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