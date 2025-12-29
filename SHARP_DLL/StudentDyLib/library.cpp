#include "library.h"

#include <iostream>
#include <boost/serialization/export.hpp>

using namespace std;

BOOST_CLASS_EXPORT_IMPLEMENT(Student)
BOOST_CLASS_EXPORT_IMPLEMENT(GroupLeader)


#define EXPORT __attribute__((visibility("default")))


Group group("АС-23-05");


extern "C"{
    struct StringArray {
        const char** data;
        int size;
    };

    EXPORT bool LoadStudentsFromFile(const char* pathToFile) {
        try {
            group.loadStudentsFromFile(pathToFile);
            return true;
        }
        catch (std::exception& e) {
            return false;
        }
    }

    EXPORT StringArray get_studentNames() {
        std::vector<std::string> names = group.get_studentNamesWithInfo();

        const char** nameList = (const char**)malloc(names.size() * sizeof(char*));

        for (size_t i = 0; i < names.size(); i++) {
            nameList[i] = strdup(names[i].c_str());
        }

        return {nameList, (int)names.size()};
    }

    EXPORT void free_string_array(StringArray arr) {
        for (int i = 0; i < arr.size; i++) {
            free((void*)arr.data[i]);
        }
        free(arr.data);
    }

    EXPORT HelpStruct GetStudent(int index) {
        return group.get_studentInfo(index);
    }

    EXPORT void FreeStudent(HelpStruct s) {
        free((void*)s.Name);
        free((void*)s.Surname);
        free((void*)s.Email);
        free((void*)s.PhoneNumber);
    }

    EXPORT void ClearAllStudents() {
        group.clearAllStudents();
    }
}