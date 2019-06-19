#ifndef image_h
#define image_h

class Image {
public:
    Image(int w, int h, std::string flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();
    
    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
    virtual std::string display(std::string s);
    /*
     * If we don't want virtual method lookup, we
     * could just declare:
     * void display();
     * */
    
    int get_height() { return height; }
    int get_width() { return width; }
    
private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image& img2);
};


class Gif : public Image{
public:
    Gif(int w, int h, std::string flnm, int cl=0): Image(w,h,flnm),compress_level(cl){}
    std::string display(std::string s);
private:
    int compress_level;
};

const int HIGH = 3;
const int MEDIUM = 2;
const int LOW = 1;

class Jpeg :public Image{
public:
    Jpeg(int w, int h, std::string flnm, int q=HIGH): Image(w,h,flnm),quality(q){}
    std::string display(std::string s);
private:
    int quality;
    
};





class Png :public Image{
public:
    Png(int w, int h, std::string flnm, int cl=0): Image(w,h,flnm),compress_level(cl){}
    
private:
    int compress_level;
    
    
};



#endif 
