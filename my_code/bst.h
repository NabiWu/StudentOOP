#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;
        
        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
        
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }
    
public:
    Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
    : data(d), parent(p), left(l), right(r) {}
    
    Bst<T>* insert(const T d) {
        if (d == data) return nullptr;
        else if (d < data) {
            if (!left) {
                left = new Bst(d, this);
                return left;
            }
            else {
                return left->insert(d);
            }
        }
        else {   // d > data
            if (!right) {
                right = new Bst(d, this);
                return right;
            }
            else {
                return right->insert(d);
            }
        }
    }
    
    Bst<T>* search(const T d) {
        if (d == data) return this;
        else if (d < data) {
            if (!left) {
                return nullptr;
            }
            else {
                return left->search(d);
            }
        }
        else {   // d > data
            if (!right) {
                return nullptr;
            }
            else {
                return right->search(d);
            }
        }
    }
    
    Bst<T>* predecessor(const T d){
        Bst<T>* node = search(d);
        if (node->left){
            //            return min((node->right).get_val());
            return search(node->left->max());
    
        }
        else{
            Bst<T>* parent = node->parent;
            
            while(parent){
                if(parent->get_val() < node->get_val()){
                    break;
                }
                parent = parent->parent;
            }
            return parent;
        }
        
    };
    
    Bst<T>* sucessor(const T d){
        Bst<T>* node = search(d);
        if (node->right){
//            return min((node->right).get_val());
             return search(node->right->min());
            
        }
        else{
            Bst<T>* parent = node->parent;
            
            while(parent){
                if(parent->get_val() > node->get_val()){
                    break;
                }
                parent = parent->parent;
            }
            return parent;
        }
        
    };
    
    
    T max(){
        if (!right) return data;
        return right->max();
        
    }
    
    
    T min(){
        if (!left) return data;
        return left->min();
    }
    
    
    T get_val() const { return data; }
    
    Bst<T>* find(const T d) const {
        return nullptr;
    }
    
private:
    T data;
    Bst* parent;
    Bst* left;
    Bst* right;
};





//template <typename T>
//void print_bst(const Bst<T>& bst) {
//void print_bst(Bst<int> bst) {
//    std::cout << "data: " << bst.data << "; left: ";
//
//    if (!bst.left) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.left);
//    }
//    std::cout << "; right: ";
//    if (!bst.right) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.right);
//    }
//    std::cout << std::endl;
//}

