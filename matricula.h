//
// Created by rrivas on 6/06/2025.
//

#ifndef MATRICULA_H
#define MATRICULA_H
#include <string>
#include <vector>

class Professor {
    std::string id;
    std::string name;
public:
    Professor(const std::string& id, const std::string& name);
    std::string get_id();
    std::string get_name();
};

class Laboratory {
    std::string id;
public:
    explicit Laboratory(const std::string& id);
    std::string get_id();
};

class Student {
    std::string id;
    std::string name;
public:
    Student(const std::string& id, const std::string& name);
    std::string get_id();
    std::string get_name();
};

class Course {
    std::string id;
    std::string name;
public:
    Course(const std::string& id, const std::string& name);
    std::string get_id();
    std::string get_name();
};

class Section {
private:
    Course* course = nullptr;
    Laboratory* laboratory = nullptr;
    Professor* professor = nullptr;
    std::vector<Student*> list_student;
    std::string id;
public:
    Section(const std::string& id, Course course, Laboratory laboratory, Professor professor);
    ~Section();
    void enroll(Student student);
    void retire(const std::string& id_student);
    void show_list();
    std::string get_id();
    Professor& get_professor();
    Course& get_course();
    Laboratory& get_laboratory();
};



#endif //MATRICULA_H
