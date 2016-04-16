#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:
    Pixel(const int r, const int g, const int b);
    virtual ~Pixel();
    bool operator!=(const Pixel &second) const;
    bool operator==(const Pixel &second) const;
    int getr() const;
    int getg() const;
    int getb() const;
    void setr(int in);
    void setg(int in);
    void setb(int in);
    bool isWhite();
    

private:
    int r,g,b;
};

#endif // PIXEL_H
