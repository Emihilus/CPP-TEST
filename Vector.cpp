#pragma once

#include "Vector.h"
//#include "Straight.h"

#include "math.h"

template<class T>
T Vector<T>::lenght() const
{
    return m_lenght;
}

template<class T>
void Vector<T>::setXYZ(const T &newX, const T &newY, const T &newZ)
{
    m_x = newX;
    m_y = newY;
    m_z = newZ;
}

template<class T>
inline const T &Vector<T>::x() const
{
    return m_x;
}

template<class T>
inline void Vector<T>::setX(const T &newX)
{
    m_x = newX;
}

template<class T>
const T &Vector<T>::y() const
{
    return m_y;
}

template<class T>
void Vector<T>::setY(const T &newY)
{
    m_y = newY;
}

template<class T>
const T &Vector<T>::z() const
{
    return m_z;
}

template<class T>
void Vector<T>::setZ(const T &newZ)
{
    m_z = newZ;
}

template<class T>
void Vector<T>::updateLenght()
{
    m_lenght = sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
}

template<class T>
Vector<T> Vector<T>::add(const Vector<T> &o1, const Vector<T> &o2)
{
    return Vector<T>(o1.x() + o2.x(), o1.y() + o2.y(), o1.z() + o2.z());
}

template<class T>
Vector<T> Vector<T>::subtract(const Vector<T> &o1, const Vector<T> &o2)
{
    return Vector<T>(o1.x() - o2.x(), o1.y() - o2.y(), o1.z() - o2.z());
}

template<class T>
Vector<T> Vector<T>::crossMultiply(const Vector<T> &o1, const Vector<T> &o2)
{
    return Vector<T>((o1.y()*o2.z() - o2.y()*o1.z()),
                     (o1.z()*o2.x() - o2.z()*o1.x()),
                     (o1.x()*o2.y() - o2.x()*o1.y()));
}
