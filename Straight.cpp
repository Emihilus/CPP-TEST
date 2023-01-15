#pragma once
#include "Straight.h"
#include "math.h"



template<class T>
bool Straight<T>::parallel(const Straight<T> &o1, const Straight<T> &o2)
{
            Vector<T> v1(o1.vx(), o1.vy(), o1.vz()), v2(o2.vx(),o2.vy(),o2.vz());
            Vector<T> res = Vector<T>::crossMultiply(v1,v2);
            if(res.lenght() == 0) return true;
            return false;
}

template<class T>
void Straight<T>::set0Point(const Point<T>& p)
{
    p_x = p.x();
    p_y = p.y();
    p_z = p.z();
}

template<class T>
void Straight<T>::set0Vector(const Vector<T>& v)
{
    v_x = v.x();
    v_y = v.y();
    v_z = v.z();
}

template<class T>
inline const T &Straight<T>::px() const
{
    return p_x;
}

template<class T>
inline void Straight<T>::setPX(const T &newX)
{
    p_x = newX;
}

template<class T>
const T &Straight<T>::py() const
{
    return p_y;
}

template<class T>
void Straight<T>::setPY(const T &newY)
{
    p_y = newY;
}

template<class T>
const T &Straight<T>::pz() const
{
    return p_z;
}

template<class T>
void Straight<T>::setPZ(const T &newZ)
{
    p_z = newZ;
}

template<class T>
inline const T &Straight<T>::vx() const
{
    return v_x;
}

template<class T>
inline void Straight<T>::setVX(const T &newX)
{
    v_x = newX;
}

template<class T>
const T &Straight<T>::vy() const
{
    return v_y;
}

template<class T>
void Straight<T>::setVY(const T &newY)
{
    v_y = newY;
}

template<class T>
const T &Straight<T>::vz() const
{
    return v_z;
}

template<class T>
void Straight<T>::setVZ(const T &newZ)
{
    v_z = newZ;
}

