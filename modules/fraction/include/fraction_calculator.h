// Copyright 2020 Sokolov Nikolay

#ifndef MODULES_FRACTION_INCLUDE_FRACTION_CALCULATOR_H_
#define MODULES_FRACTION_INCLUDE_FRACTION_CALCULATOR_H_

#include <string>

class FractionOperation {
 public:
    virtual char parseOperation(std::string argv) = 0;
    virtual std::string operator()(const char** argv) = 0;
    virtual ~FractionOperation(){}
};

class FractionCalculator3Arg: public FractionOperation {
 public:
    FractionCalculator3Arg() {}
    std::string operator()(const char** argv);
 private:
    char parseOperation(std::string arg);
};

class FractionCalculator4Arg : public FractionOperation {
 public:
    FractionCalculator4Arg() {}
    std::string operator()(const char** argv);
 private:
    char parseOperation(std::string arg);
};

class FractionCalculator5Arg : public FractionOperation {
 public:
    FractionCalculator5Arg() {}
    std::string operator()(const char** argv);
 private:
    char parseOperation(std::string arg);
};

class FractionCalculator {
 public:
    FractionCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;
    void help(std::string appname, std::string message = "");
    bool validateNumberOfArguments(int argc, std::string str);
};

#endif  // MODULES_FRACTION_INCLUDE_FRACTION_CALCULATOR_H_
