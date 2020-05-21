// Copyright 2020 Maximova Irina

#include "include/segments_app.h"

#include <cmath>
#include <sstream>
#include <string>
#include <utility>

#include "include/segments.h"

Segment_app::Segment_app() : message("") {}

void Segment_app::help(const char* appname, const char* _message) {
  message = std::string(_message) +
            "This is an intersecting segments application.\n" +
            "Please provide arguments in the following format:\n\n" + "  $ " +
            appname + " <number_operation> <points_1_x> " +
            "<points_1_y> <points_2_x> " + "<points_2_y>  ...\n\n\n" +
            "Where <number_operation>:\n\t" +
            "1 - Calculate triangle area. Number coordinates = 3.\n\t" +
            "2 - Determination of the point position regarding the vector." +
            "Number coordinates = 3. First coordinate - point coordinate.\n\t" +
            "3 - Check segments for intersection. Number coordinates = 4.\n" +
            "All coordinates are double-precision numbers\n";
}

bool Segment_app::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  }

  bool validate = false;
  switch (std::stoi(argv[1])) {
    case 1: {
      validate = argc == 8;
      break;
    }
    case 2: {
      validate = argc == 8;
      break;
    }
    case 3: {
      validate = argc == 10;
      break;
    }
    default: {
      message = "ERROR: Number operation must be 1 or 2 or 3.";
      return false;
    }
  }

  if (!validate) message = "ERROR: Incurrect number arguments.";
  return validate;
}

std::string Segment_app::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message;
  }

  vector args;

  try {
    std::pair<double, double> temp_pair;
    for (int i = 2; i < argc; i += 2) {
      temp_pair = std::make_pair(std::stod(argv[i]), std::stod(argv[i + 1]));
      args.push_back(temp_pair);
    }
  } catch (std::string& str) {
    return str;
  }

  std::ostringstream stream;

  switch (std::stoi(argv[1])) {
    case 1: {
      message = calculateTriangleArea(args);
      break;
    }
    case 2: {
      message = relationPoint(args);
      break;
    }
    case 3: {
      message = segmentIntersection(args);
      break;
    }
  }

  stream << message;
  return message;
}

std::string Segment_app::calculateTriangleArea(const vector args) const {
  double x = args[0].first;
  double y = args[0].second;
  Segment line(args[1], args[2]);

  return "Triangle area = " + std::to_string(std::abs(line.area(x, y)));
}

std::string Segment_app::relationPoint(const vector args) const {
  double x = args[0].first;
  double y = args[0].second;
  Segment line(args[1], args[2]);

  double area = line.area(x, y);
  if (area < 0)
    return "Point to the right of the vector.";
  else if (area > 0)
    return "Point to the left of the vector.";
  else
    return "Point on the vector.";
}

std::string Segment_app::segmentIntersection(const vector args) const {
  Segment line_1(args[0], args[1]);
  Segment line_2(args[2], args[3]);

  if (line_1.isIntersect(line_2))
    return "Segments do intersect";
  else
    return "Segments do not intersect";
}
