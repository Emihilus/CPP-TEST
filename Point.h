#pragma once

template <class  T>
class Point
{
public:
    template <class Q> Point(Q x =0, Q y =0, Q z =0) : m_x(x), m_y(y), m_z(z) {}
    template <class Q> Point(const Point& o) : m_x(o.x), m_y(o.y), m_z(o.z) {}
    template <class Q> Point& operator =( const Point& o) {
        if (this != &o){
            m_x = o.x;
            m_y = o.y;
            m_z = o.z;
        }
        return * this;
    }
    bool operator==(const Point& o) {return m_x==o.x() && m_y==o.y() && m_z==o.z();}


    T distance(const Point&) const;

    void setXYZ(const T &newX, const T &newY, const T &newZ);

    const T &x() const;
    void setX(const T &newX);

    const T &y() const;
    void setY(const T &newY);

    const T &z() const;
    void setZ(const T &newZ);

private:
    T m_x;
    T m_y;
    T m_z;
};

template class Point<double>;
template class Point<float>;
