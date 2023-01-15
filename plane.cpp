#pragma once

#include "Point.h"
#include "Vector.h"
class Plane {
  private: double x0,
  y0,
  z0;
  double x1,
  y1,
  z1;
  double length;

  public:
    Plane(double X0 = 0, double Y0 = 0, double Z0 = 0,
      double X1 = 0, double Y1 = 0, double Z1 = 0, double Length = 0)
    {
      x0 = X0;
      y0 = Y0;
      z0 = Z0;
      x1 = X1;
      y1 = Y1;
      z1 = Z1;
      length = Length;
    }

  Plane(Point <double> point, Vector <double> vector)
  {
    x0 = point.x();
    y0 = point.y();
    z0 = point.z();
    x1 = vector.x();
    y1 = vector.y();
    z1 = vector.z();
    length = vector.lenght();
  }

  double getX0()
  {
    return x0;
  }

  void setX0(const double & newX0)
  {
    x0 = newX0;
  }

  double getY0()
  {
    return y0;
  }

  void setY0(const double & newY0)
  {
    y0 = newY0;
  }

  double getZ0()
  {
    return z0;
  }

  void setZ0(const double & newZ0)
  {
    z0 = newZ0;
  }

  double getX1()
  {
    return x1;
  }

  void setX1(const double & newX1)
  {
    x1 = newX1;
  }

  double getY1()
  {
    return y1;
  }

  void setY1(const double & newY1)
  {
    y1 = newY1;
  }

  double getZ1()
  {
    return z1;
  }

  void setZ1(const double & newZ1)
  {
    z1 = newZ1;
  }

  double getLength()
  {
    return length;
  }

  void setLength(const double & newLength)
  {
    length = newLength;
  }
};
