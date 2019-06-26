#ifndef tvector_h
#define tvector_h




const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;


template <typename DATA>
class MyVec {
public:
    MyVec(){
        sz = 0;
        capacity = DEF_CAPACITY;
        data = new DATA[DEF_CAPACITY];
    }
    
    
    MyVec(int sz, DATA val){
        this->sz = sz;
        capacity = std::max(DEF_CAPACITY, sz * CAPACITY_MULT);
        data = new DATA[capacity];
        for (size_t i = 0; i < sz; i++) data[i] = val;
    }
    
    // copy control:
    MyVec(const MyVec<DATA>& v2){
        capacity = v2.capacity;
        sz = v2.sz ;
        
        data = new DATA[capacity];
        //copy over existing data
        for (int i =0;i<size();i++){
            data[i] = v2.data[i];
        }
    }
    
    
    ~MyVec(){
         delete[] data;
    }
    
    
    MyVec& operator=(const MyVec<DATA>& v2){
        if (&v2 != this){
            delete[] data;
            capacity = v2.capacity;
            sz = v2.size() ;
            data = new DATA[capacity];
            for (int i =0;i<size();i++){
                data[i] = v2.data[i];
            }
        }
        return *this;
    }
    
    void push_back(DATA val){
        if (sz == capacity){
            std::cout<<"Increasing capacity\n";
            //get new array of capacity *2
            
            capacity *= 2;
            DATA* new_data = new DATA[capacity];
            //copy over existing data
            for (int i =0;i<size();i++){
                new_data[i] = data[i];
                
            }
            //delete old array
            delete[] data;
            //set pointer to new array
            data = new_data;
        }
        //post increment increase the size and set the val
        data[sz++] = val;
    }
    
    
    int size() const { return sz; }
    
    
    DATA operator[](int i) const{
        return data[i];
    }
    
    
    
  DATA& operator[](int i){
      return data[i];
      
  }
    
private:
    void copy(const MyVec<DATA>& v2){
        sz = v2.sz;
        capacity = v2.capacity;
        data = new DATA[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
    DATA* data;
    int sz;
    int capacity;
};


template <typename DATA>
void print_vector(const MyVec<DATA>& v){
    for(int i=0;i<v.size();i++){
        //std::cout << "printing";
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}


template <typename DATA>
bool operator==(MyVec<DATA>& v1, MyVec<DATA>& v2){
    if (v1.size() == v2.size()){
        for (int i =0; i <v1.size();i++){
            if (v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}










#endif
