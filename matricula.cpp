//
// Created by rrivas on 6/06/2025.
//

#include "matricula.h"

#include <algorithm>
#include <iostream>
#include <ostream>

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

Course::Course(const std::string& id, const std::string& name):id(id), name(name) { }

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

// void Section::retire(const std::string &id_student) {
//     // Lambda
//     auto verify_student = [id_student](Student &student) {
//         return student.get_id() == id_student;
//     };
//
//     // Busca al alumno
//     auto iter = std::find_if(list_student.begin(), list_student.end(), verify_student);
//     // Verifica que exista y si existe lo borra
//     if (iter != list_student.end()) {
//         delete *iter;               // Borrar el alumno
//         list_student.erase(iter);   // Borrar la referencia del vector
//     }
// }

void Section::retire(const std::string &id_student) {
    // Busca al alumno
    for (auto it = list_student.begin(); it != list_student.end(); ++it) {
        if ((*it)->get_id() == id_student) {
            delete *it;
            list_student.erase(it);
        }
    }
}


void Section::show_list() {
    std::cout << "curso: " << course->get_id() << "-" << course->get_name() << std::endl;
    std::cout << std::string(40,'-') << std::endl;
    for (const auto& student : list_student) {
        std::cout << student->get_id() << " " << student->get_name() << std::endl;
    }
    std::cout << std::string(40,'-') << std::endl;
}

std::string Section::get_id() {
    return id;
}

Professor & Section::get_professor() {
    return *professor;
}

Course & Section::get_course() {
    return *course;
}

Laboratory & Section::get_laboratory() {
    return *laboratory;
}
