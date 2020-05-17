// Copyright 2020 Sokolov Nikolai

#include "include/vector3D.h"
#include <string>

Vector3D::Vector3D(const double& _x,
    const double& _y,
    const double& _z) : X(_x), Y(_y), Z(_z) {}

Vector3D::Vector3D(const Vector3D& _v) {
    X = _v.X;
    Y = _v.Y;
    Z = _v.Z;
}

double Vector3D::getX()const {
    return X;
}

double Vector3D::getY()const {
    return Y;
}

double Vector3D::getZ()const {
    return Z;
}

void Vector3D::setX(const double& _x) {
    X = _x;
}

void Vector3D::setY(const double& _y) {
    Y = _y;
}

void Vector3D::setZ(const double& _z) {
    Z = _z;
}

Vector3D& Vector3D::operator=(const Vector3D& v) {
    if (this != &v) {
        X = v.X;
        Y = v.Y;
        Z = v.Z;
    }
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D& _v) {
    return Vector3D(this->X + _v.X, this->Y + _v.Y, this->Z + _v.Z);
}

Vector3D Vector3D::operator-(const Vector3D& _v) {
    return Vector3D(this->X - _v.X, this->Y - _v.Y, this->Z - _v.Z);
}

double Vector3D::norm()const {
    return sqrt(ScalarProduct(*this, *this));
}

void Vector3D::normalization() {
    double _nrm = norm();
    if (_nrm == 0) {
        throw std::string("can`t be zero. norm = 0. Use 1");
    } else {
        X /= _nrm;
        Y /= _nrm;
        Z /= _nrm;
    }
}

    Vector3D normalization(const Vector3D& _v) {
        if (_v.norm() == 0) {
            throw std::string("can`t be zero. norm = 0. return null vector");
        } else {
            return Vector3D(_v.getX() / _v.norm(),
                            _v.getY() / _v.norm(),
                            _v.getZ() / _v.norm());
        }
    }

    double ScalarProduct(const Vector3D&_v1, const Vector3D&_v2) {
        return  _v1.getX() * _v2.getX() +
                _v1.getY() * _v2.getY() +
                _v1.getZ() * _v2.getZ();
    }

    Vector3D VectorProduct(const Vector3D& _v1, const Vector3D& _v2) {
        return Vector3D(_v1.getY() * _v2.getZ() - _v1.getZ() * _v2.getY(),
                        _v1.getZ() * _v2.getX() - _v1.getX() * _v2.getZ(),
                        _v1.getX() * _v2.getY() - _v1.getY() * _v2.getX());
    }
