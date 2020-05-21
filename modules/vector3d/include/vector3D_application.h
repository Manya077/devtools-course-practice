// Copyright 2020 Baldin Alexey

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_APPLICATION_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_APPLICATION_H_

#include <string>

class Vector3DApplication {
 public:
    Vector3DApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const std::string appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const std::string appName);

    std::string message_;
};

#endif  // MODULES_VECTOR3D_INCLUDE_VECTOR3D_APPLICATION_H_
