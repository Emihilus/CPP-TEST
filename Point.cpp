#pragma once
#include "Point.h"

#include "math.h"

template<class T>
T Point<T>::distance(const Point& o) const
{
    return sqrt(pow(m_x - o.x(), 2) + pow(m_y - o.y(), 2) + pow(m_z - o.z(), 2));
}

template<class T>
void Point<T>::setXYZ(const T &newX, const T &newY, const T &newZ)
{
    m_x = newX;
    m_y = newY;
    m_z = newZ;
}

template<class T>
inline const T &Point<T>::x() const
{
    return m_x;
}

template<class T>
inline void Point<T>::setX(const T &newX)
{
    m_x = newX;
}

template<class T>
const T &Point<T>::y() const
{
    return m_y;
}

template<class T>
void Point<T>::setY(const T &newY)
{
    m_y = newY;
}

template<class T>
const T &Point<T>::z() const
{
    return m_z;
}

template<class T>
void Point<T>::setZ(const T &newZ)
{
    m_z = newZ;
}
