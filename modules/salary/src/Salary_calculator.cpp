// Copyright 2020 Petrov Anton

#include <sstream>
#include <string>

#include "include/Salary.h"
#include "include/Salary_calculator.h"

SalaryCalculator::SalaryCalculator() : message_("") {}

void SalaryCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a salary calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname +
        " <m_salary> <m_hours> <m_hours_over> <m_hours_admin> " +
        " Where <m_hours> <m_hours_over> <m_hours_admin> " +
        " arguments are unsigned integer numbers,"
        + " and <m_salary> is float";
}

bool SalaryCalculator::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

std::string SalaryCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.h_m_hours = static_cast<unsigned int>(std::stoul(argv[1]));
        args.h_m_hours_over = static_cast<unsigned int>(std::stoul(argv[2]));
        args.h_m_hours_admin = static_cast<unsigned int>(std::stoul(argv[3]));
        args.s_m_salary = std::stod(argv[4]);
    }
    catch (std::exception &error) {
        return std::string("Wrong number format!");
    }

    Salary sal;
    sal.setSalary(args.s_m_salary);
    sal.setHours(args.h_m_hours);
    sal.setOverHours(args.h_m_hours_over);
    sal.setAdminHours(args.h_m_hours_admin);
    std::ostringstream stream;

    stream << "payment = " << sal.payment();

    message_ = stream.str();

    return message_;
}
