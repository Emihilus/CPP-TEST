#pragma once
#include "Point.h"
#include "Vector.h"


template <class  T>
class Straight
{
public:
    static bool parallel(const Straight<T>& o1, const Straight<T>& o2);

    template <class Q> Straight(Q px =0, Q py =0, Q pz =0, Q vx =0, Q vy =0, Q vz =0) : p_x(px), p_y(py), p_z(pz), v_x(vx), v_y(vy), v_z(vz) {}
    template <class Q> Straight(const Point<Q>& p, const Vector<Q>& v) : p_x(p.x()), p_y(p.y()), p_z(p.z()), v_x(v.x()), v_y(v.y()), v_z(v.z()) {}
    template <class Q> Straight(const Point<Q>& p1, const Point<Q>& p2): p_x(p1.x()), p_y(p1.y()), p_z(p1.z()) {
        Vector<Q> tmpV(p1,p2);
        v_x = tmpV.x();
        v_y = tmpV.y();
        v_z = tmpV.z();
    }

    template <class Q> Straight(const Straight& o) : p_x(o.px), p_y(o.py), p_z(o.pz), v_x(o.vx), v_y(o.vy), v_z(o.vz) {}
    template <class Q> Straight& operator =( const Straight& o) {
        if (this != &o){
            p_x = o.px;
            p_y = o.py;
            p_z = o.pz;
            v_x = o.vx;
            v_y = o.vy;
            v_z = o.vz;
        }
        return * this;
    }

    bool operator==(const Straight<T>& o) {
        Vector<T> v1(v_x, v_y, v_z), v2(o.vx(),o.vy(),o.vz());
        Vector<T> res = Vector<T>::crossMultiply(v1,v2);
        if(res.lenght() != 0) return false;
        Vector<T> vp(Point<T>{p_x, p_y, p_z}, Point<T>{o.px(), o.py(), o.pz()});
        res = Vector<T>::crossMultiply(v1, vp);
        if(res.lenght() != 0) return false;
        return true;
    }

    void set0Point(const Point<T>&);
    void set0Vector(const Vector<T>&);

    const T &px() const;
    void setPX(const T &newX);

    const T &py() const;
    void setPY(const T &newY);

    const T &pz() const;
    void setPZ(const T &newZ);

    const T &vx() const;
    void setVX(const T &newX);

    const T &vy() const;
    void setVY(const T &newY);

    const T &vz() const;
    void setVZ(const T &newZ);

private:
    T p_x;
    T p_y;
    T p_z;
    T v_x;
    T v_y;
    T v_z;
};

template class Straight<double>;
template class Straight<float>;

