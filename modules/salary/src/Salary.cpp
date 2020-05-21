// Copyright 2020 Savin Dmitry
#include "include/Salary.h"

Salary::Salary() {
    m_salary = 0;
    m_hours = 0;
    m_hours_over = 0;
    m_hours_admin = 0;
}


float Salary::payment() {
    if (m_hours <= 0 || m_salary <= 0 ||
        m_hours_admin < 0 || m_hours_over < 0) {
        return 0.0f;
    }
    float paymentPerHour = m_salary / m_hours;
    float payment = (m_hours - m_hours_admin) * paymentPerHour;
    float paymentOver;
    if (m_hours_over <= 2) {
        paymentOver = paymentPerHour * 1.5f * m_hours_over;
    } else {
        paymentOver = paymentPerHour * 2.f * (m_hours_over - 2) +
            paymentPerHour * 1.5f * 2;
    }
    payment += paymentOver;
    return payment;
}

bool Salary::setSalary(float s) {
    if (s > 0) {
        m_salary = s;
        return true;
    } else {
        return false;
    }
}

bool Salary::setHours(int h) {
    if (h > 0) {
        m_hours = h;
        return true;
    } else {
        return false;
    }
}

bool Salary::setOverHours(int h) {
    if (h >= 0) {
        m_hours_over = h;
        return true;
    } else {
        return false;
    }
}

bool Salary::setAdminHours(int h) {
    if (h >= 0) {
        m_hours_admin = h;
        return true;
    } else {
        return false;
    }
}
