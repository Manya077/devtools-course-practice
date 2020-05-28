// Copyright 2020 Suchkov Makar

#include "include/bitfield.h"
#include "include/bitfield-app.h"

#include <string>
#include <random>
#include <stdexcept>
#include <sstream>

Bitfieldapp::Bitfieldapp() : message_("") {}

void Bitfieldapp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a Bitfield application.\n\n" +
          "Please provide arguments in the following format:\n\n"+
          "  $ " + appname + " <type> <bitfield_size> " +
          "<position>\n" +
          "Where all arguments are positive integer numbers, \n" +
          "set <type> to 1 to create bitfield and set" +
          "in <position> flag, " +
          "set <type> to 2 to create bitfield and set\n" +
          "and random set flag and unset in <position>\n" +
          "set <type> to 3 to create bitfield and set\n" +
          "all flags up and unset in <position>; \n" +
          "you can use multi up flags if " +
          "use some argiments <position>\n\n";
}

bool Bitfieldapp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 4 && argc > 1) {
        help(argv[0], "ERROR: Should be three arguments.\n\n");
        return false;
    }
    return true;
}

std::string Bitfieldapp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.type = static_cast<unsigned int>(std::stoul(argv[1]));
        args.bitfield_size = static_cast<unsigned int>(std::stoul(argv[2]));
        if (argc == 4) {
            args.position = static_cast<unsigned int>(std::stoul(argv[3]));
        } else {
            for (int i = 0; i < argc - 3; i++) {
            args.arr[i] = static_cast<unsigned int>(std::stoul(argv[i + 3]));
            }
        }
    } catch (std::invalid_argument) {
        return std::string("ERROR: Wrong number format!");
    }

    Bitfield bitf(args.bitfield_size);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 9999999);
    std::ostringstream stream;

    if (argc == 4) {
        switch (args.type) {
         case 1:
            bitf.set(args.position);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         case 2:
           for (unsigned int i = 0; i < bitf.get_size(); i++) {
                if (dist(mt) % 2 == 0) {
                bitf.set(i);
                }
            }
            bitf.unset(args.position);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         case 3:
            bitf.fill();
            bitf.unset(args.position);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         default:
           stream << "ERROR: unknow operation " <<
           "Operation type arguments is integer number " <<
            "There are 1, 2, 3. No more \n\n" << std::endl;
        }
    } else if (argc > 4) {
        switch (args.type) {
         case 1:
            bitf.set(args.arr);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         case 2:
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                if (dist(mt) % 2 == 0) {
                    bitf.set(i);
                }
            }
            bitf.unset(args.arr);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         case 3:
            bitf.fill();
            bitf.unset(args.arr);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         default:
            stream << "ERROR: unknow operation " <<
            "Operation type arguments is integer number " <<
            "There are 1, 2, 3. No more \n\n" << std::endl;
        }
    }

    message_ = stream.str();

    return message_;
}
