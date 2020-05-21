// Copyright 2020 Kudryashov Nikita

#include <string>
#include <vector>
#include <utility>
#include "../include/triangle_param.h"
#include "../include/triangle_param_calculator.h"

std::string TriangleParamCalculator::help() {
    std::string syntax = "Follow syntax rules:\n1.";
    syntax += "First, one must write 3 points for triangle ";
    syntax += "A, B, C in this way: ";
    syntax += "A < x value of A > < y value of A > ";
    syntax += "B < x value of B > < y value of B > ";
    syntax += "C < x value of C > < y value of C >\n2.";
    syntax += "Second, one must write his requests to calculate";
    syntax += "in any order, each followed by space.\n";
    syntax += " 2.1 List of all possible requests:\n";
    syntax += "   < LengthAB > for AB length's side\n";
    syntax += "   < LengthBC > for BC length's side\n";
    syntax += "   < LengthAC > for AC length's side\n";
    syntax += "   < CornerA > for A corner value\n";
    syntax += "   < CornerB > for B corner value\n";
    syntax += "   < CornerC > for C corner value\n";
    syntax += "   < Perimeter> for triangle perimiter value\n";
    syntax += "   < Square > for triangle square value\n";
    syntax += "   < All > for all available parameters\n";
    syntax += "Example: A 0.1 2.2 B 4.3 3.2 C 3.3 10.1 Square ";
    syntax += "LengthAB CornerA";
    return syntax;
}

std::vector<std::string> TriangleParamCalculator::
        parseData(int argc, const char** argv) {
    unsigned int size = argc - 1;
    std::vector<std::string> res(size);
    for (unsigned int i = 0; i < res.size(); ++i) {
        res[i] = argv[i + 1];
    }

    return res;
}

bool TriangleParamCalculator::
        isTopNamesValid(const std::vector<std::string> &data) {
    if (data[0] == "A" && data[3] == "B" && data[6] == "C") {
        arg.names_top.push_back("A");
        arg.names_top.push_back("B");
        arg.names_top.push_back("C");

        return true;
    } else {
        return false;
    }
}

bool TriangleParamCalculator::
        isNumberTypeRight(const std::vector<std::string> &data) {
    std::pair<double, double> a, b, c;
    try {
        // A point.
        a.first = std::stod(data[1]);
        a.second = std::stod(data[2]);

        // B point.
        b.first = std::stod(data[4]);
        b.second = std::stod(data[5]);

        // C point.
        c.first = std::stod(data[7]);
        c.second = std::stod(data[8]);

        arg.tops.push_back(a);
        arg.tops.push_back(b);
        arg.tops.push_back(c);
    } catch(...) {
        return false;
    }

    return true;
}

bool TriangleParamCalculator::
        isRequestsValid(const std::vector<std::string> &data) {
    for (unsigned int i = 9; i < data.size(); ++i) {
        if (data[i] != "LengthAB" &&
            data[i] != "LengthBC" &&
            data[i] != "LengthAC" &&
            data[i] != "CornerA" &&
            data[i] != "CornerB" &&
            data[i] != "CornerC" &&
            data[i] != "Perimeter" &&
            data[i] != "Square" &&
            data[i] != "All") {
                return false;
        } else {
            arg.operations.push_back(data[i]);
        }
    }

    return true;
}

bool TriangleParamCalculator::
        canCreateTriangle(const std::vector<std::string> &data) {
    try {
        Triangle tr(arg.tops[0], arg.tops[1], arg.tops[2]);
    } catch (const int e) {
        return false;
    }

    return true;
}

void TriangleParamCalculator::
        isDataValid(const std::vector<std::string> &data) {
    if (!isTopNamesValid(data)) {
        throw std::string
            ("Wrong top names arguments. Please, follow the syntax.\n");
    }

    if (!isNumberTypeRight(data)) {
        throw std::string
            ("Wrong number type arguments. Please, follow the syntax.\n");
    }

    if (!canCreateTriangle(data)) {
        throw std::string
            ("Three of your points are in the same line\n.");
    }

    if (!isRequestsValid(data)) {
       throw std::string
            ("Wrong requests arguments. Please, follow the syntax.\n");
    }
}

std::string TriangleParamCalculator::
        doRequest(Triangle t, std::string req) {
    if (req == "LengthAB") {
        return (std::to_string(t.side(t.getTopA(), t.getTopB())) + "\n");
    }

    if (req == "LengthBC") {
        return(std::to_string(t.side(t.getTopB(), t.getTopC())) + "\n");
    }

    if (req == "LengthAC") {
        return (std::to_string(t.side(t.getTopA(), t.getTopC())) + "\n");
    }

    if (req == "CornerA") {
        return (std::to_string(t.cornA()) + "\n");
    }

    if (req == "CornerB") {
        return (std::to_string(t.cornB()) + "\n");
    }

    if (req == "CornerC") {
        return (std::to_string(t.cornC()) + "\n");
    }

    if (req == "Perimeter") {
        return (std::to_string(t.perimetr()) + "\n");
    }

    if (req == "Square") {
        return (std::to_string(t.square()) + "\n");
    }

    if (req == "All") {
        std::string allAns;
        allAns += ("LengthAB = "
            + std::to_string(t.side(t.getTopA(), t.getTopB())) + "\n");
        allAns += ("LengthBC = "
            + std::to_string(t.side(t.getTopB(), t.getTopC())) + "\n");
        allAns += ("LengthAC = "
            + std::to_string(t.side(t.getTopA(), t.getTopC())) + "\n");
        allAns += ("CornerA = " + std::to_string(t.cornA()) + "\n");
        allAns += ("CornerB = " + std::to_string(t.cornB()) + "\n");
        allAns += ("CornerC = " + std::to_string(t.cornC()) + "\n");
        allAns += ("Perimeter = " + std::to_string(t.perimetr()) + "\n");
        allAns += ("Square = " + std::to_string(t.square()) + "\n");
        return allAns;
    }

    return "Non existing request.";
}

std::string TriangleParamCalculator::
        calculate(int argc, const char** argv) {
    std::string answer;
    std::vector<std::string> data;

    if (argc < 9) {
        return help();
    }

    data = parseData(argc, argv);

    try {
        isDataValid(data);
    } catch(std::string &err) {
        return err;
    }

    Triangle t(arg.tops[0], arg.tops[1], arg.tops[2]);
    answer += "Requested calculations:\n";
    for (unsigned int i = 9; i < data.size(); ++i) {
        if (data[i] != "All") {
            answer += (std::to_string(i - 8) + ". " + data[i] + " = ");
        } else {
            answer += (std::to_string(i - 8) + ". " + data[i] + "\n");
        }

        answer += doRequest(t, data[i]);
    }

    return answer;
}

