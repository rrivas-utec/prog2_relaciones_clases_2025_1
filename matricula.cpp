//
// Created by rrivas on 6/06/2025.
//

#include "matricula.h"

Professor::Professor(const std::string& id, const std::string& name):id(id), name(name){
    // this->id = id;
    // this->name = name;
}

std::string Professor::get_id() {
    return id;
}

std::string Professor::get_name() {
    return name;
}

Laboratory::Laboratory(const std::string &id): id(id) {}

std::string Laboratory::get_id() {
    return id;
}

Student::Student(const std::string &id, const std::string &name): id(id), name(name) {}

std::string Student::get_id() {
    return id;
}

std::string Student::get_name() {
    return name;
}

Course::Course(std::string id, std::string name):id(id), name(name) { }

std::string Course::get_id() {
    return id;
}

std::string Course::get_name() {
    return name;
}

Section::Section(
    const std::string &id,
    Course course,
    Laboratory laboratory,
    Professor professor) {

    this->course = new Course{std::move(course)};
    this->professor = new Professor{std::move(professor)};
    this->laboratory = new Laboratory{std::move(laboratory)};
}

Section::~Section() {
    delete laboratory;
    delete professor;
    delete course;
}

void Section::enroll(Student student) {
    list_student.push_back(new Student(std::move(student)));
}

void Section::retire(const std::string &id_student) {
}

void Section::show_list() {
}

std::string Section::get_id() {
}

Professor & Section::get_professor() {
}

Course & Section::get_course() {
}

Laboratory & Section::get_laboratory() {
}
