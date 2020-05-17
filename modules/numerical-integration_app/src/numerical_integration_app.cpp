// Copyright 2020 Devlikamov Vladislav

#include "include/numerical_integration.h"
#include "include/numerical_integration_app.h"

#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>

class func1 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return x * x;
     }
};

class func2 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return sin(x);
     }
};

class func3 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return x;
     }
};

NumericalIntegrationApp::NumericalIntegrationApp() : message_("") {
    methods.resize(6);
    methods[0] = new Left_rectangle_method();
    methods[1] = new Right_rectangle_method();
    methods[2] = new Middle_rectangle_method();
    methods[3] = new Trapezoid_method();
    methods[4] = new Simpsons_method();
    methods[5] = new Gauss_method();
}

NumericalIntegrationApp::~NumericalIntegrationApp() {
    for (unsigned int i = 0; i < methods.size(); i++) {
        delete methods[i];
    }
}

void NumericalIntegrationApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a numerical integration application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <left_bound> <right_bound> " +
          "<number_of_iteration> <number_of_function>" +
          "<number_of_algorithm>\n\n" +

          "Where <left_bound> and <right_bound> arguments" +
          "are double-precision numbers,\n"+
          "<number_of_iteration> is integer and <number_of_iteration>" +
          ">= 1 and <number_of_iteration> <= 1000000, \n" +
          "<number_of_function> is integer and takes value {1, 2, 3}\n" +
          "where 1.x^2, 2.sin(x), 3.x\n" +
          "<number_of_algorithm> is integer and takes value"+
          "{1, 2, 3, 4, 5, 6}\n" +
          "where 1.Left_rectangle_method, 2.Right_rectangle_method, " +
          "3.Middle_rectangle_method, " +
          "4.Trapezoid_method, 5.Simpsons_method, 6.Gauss_method\n";
}

bool NumericalIntegrationApp::validateNumberOfArguments(int argc,
                                                        const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

void NumericalIntegrationApp::set_vector(double a, double b) {
    for (unsigned int i = 0; i < methods.size(); i++) {
        methods[i]->Set_integration_borders(a, b);
    }
}

bool NumericalIntegrationApp::validateArguments(int argc,
                                                const char**argv) {
    Arguments args;

    args.N = static_cast<unsigned int>(std::stoul(std::string(argv[3])));
    args.num_function = std::stoi(std::string(argv[4]));
    args.method = std::stoi(std::string(argv[5]));

    if (args.N < 1 || args.N > 1000000) {
        help(argv[0], "Incorrect <number_of_iteration>\n\n");
        return false;
    } else if (args.num_function < 1 || args.num_function > 3) {
        help(argv[0], "Incorrect <number_of_function>\n\n");
        return false;
    } else if (args.method < 1 || args.method > 6) {
        help(argv[0], "Incorrect <number_of_algorithm>\n\n");
        return false;
    }
    return true;
}

std::string NumericalIntegrationApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a = std::stod(std::string(argv[1]));
        args.b = std::stod(std::string(argv[2]));
        args.N = static_cast<unsigned int>(std::stoul(std::string(argv[3])));
        args.num_function = std::stoi(std::string(argv[4]));
        args.method = std::stoi(std::string(argv[5]));
    }
    catch(std::invalid_argument& e) {
        return "Wrong number format!";
    }
    if (!validateArguments(argc, argv)) {
        return message_;
    }
    std::ostringstream stream;
    set_vector(args.a, args.b);
    func1 f1;
    func2 f2;
    func3 f3;
    switch (args.num_function) {
        case 1:
            stream << "Answer is ";
            stream << std::fixed << std::setprecision(4) <<
                      methods[args.method - 1]->Integration_method(&f1, args.N);
            break;
        case 2:
            stream << "Answer is ";
            stream << std::fixed << std::setprecision(4) <<
                      methods[args.method - 1]->Integration_method(&f2, args.N);
            break;
        default:
            stream << "Answer is ";
            stream << std::fixed << std::setprecision(4) <<
                      methods[args.method - 1]->Integration_method(&f3, args.N);
            break;
    }

    message_ = stream.str();

    return message_;
}
