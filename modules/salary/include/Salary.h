// Copyright 2020 Savin Dmitry
#ifndef MODULES_SALARY_INCLUDE_SALARY_H_
#define MODULES_SALARY_INCLUDE_SALARY_H_
class Salary {
 public:
    Salary();
    float payment();
    bool setSalary(float s);
    bool setHours(int h);
    bool setOverHours(int h);
    bool setAdminHours(int h);
 private:
    float m_salary;
    unsigned int m_hours;
    unsigned int m_hours_over;
    unsigned int m_hours_admin;
};
#endif  // MODULES_SALARY_INCLUDE_SALARY_H_
