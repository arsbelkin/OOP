//
// Created by Арсений Белкин on 15.12.2025.
//

#ifndef STUDENTDYLIB_GROUP_H
#define STUDENTDYLIB_GROUP_H

#include "Student.h"
#include "GroupLeader.h"
#include <string>
#include <vector>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>


class Group {
    std::string title;
    std::vector<std::shared_ptr<Student>> students;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& students;
    }
public:
    bool loadStudentsFromFile(const std::string &pathToFile);

    void set_current_studentID() const;
};



#endif //STUDENTDYLIB_GROUP_H
