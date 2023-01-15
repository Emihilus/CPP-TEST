#pragma once

#include "Point.h"


template <class  T>
class Vector
{
public:
    static Vector<T> add(const Vector<T>& o1, const Vector<T>& o2);
    static Vector<T> subtract(const Vector<T>& o1, const Vector<T>& o2);
    static Vector<T> crossMultiply(const Vector<T>& o1, const Vector<T>& o2);


    template <class T> Vector(T x =0, T y =0, T z =0) : m_x(x), m_y(y), m_z(z) {updateLenght();}
//    template <class Q> Vector(const Straight <Q>& s) : m_x(s.vx()), m_y(s.vy()), m_z(s.vz()) {updateLenght();}
    template <class Q> Vector(const Point<Q>& p1, const Point<Q>& p2) : m_x(p2.x() - p1.x()), m_y(p2.y() - p1.y()), m_z(p2.z() - p1.z()) {updateLenght();}


    template <class Q> Vector(const Vector& o) : m_x(o.x), m_y(o.y), m_z(o.z) {updateLenght();}
    template <class Q> Vector& operator =( const Vector& o) {
        if (this != &o){
            m_x = o.x;
            m_y = o.y;
            m_z = o.z;
        }
        updateLenght();
        return * this;
    }
    bool operator==(const Vector& o) {return m_x==o.x() && m_y==o.y() && m_z==o.z();}


    T lenght() const;

    void setXYZ(const T &newX, const T &newY, const T &newZ);

    const T &x() const;
    void setX(const T &newX);

    const T &y() const;
    void setY(const T &newY);

    const T &z() const;
    void setZ(const T &newZ);

private:
    void updateLenght();

    T m_x;
    T m_y;
    T m_z;
    T m_lenght;
};

template class Vector<double>;
template class Vector<float>;
