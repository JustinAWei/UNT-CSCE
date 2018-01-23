/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE1004
Instructor: Keathly
Date: 2/10/17
Description: Function Implementation
*/

#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
#include "functions.h"

using namespace std;

// 'Controller' structs
Students * students = new Students;
Courses * courses = new Courses;
Enrollments * enrollments = new Enrollments;

//Grades Constructor
Grades::Grades() {
  cout << "Creating Grades...\n";
  size = 0;
  head = tail = NULL;
}

//Grades Destructor
Grades::~Grades() {
  cout << "Destroying Grades...\n";
  Grade * cur = head;
  while (cur != NULL) {
    Grade * tail = cur;
    cur = cur->next;
    delete tail;
  }
}

//Students Constructor
Students::Students() {
  cout << "Creating Students...\n";
  size = 0;
  head = tail = NULL;
}

//Students Destructor
Students::~Students() {
  cout << "Destroying Students...\n";
  Student * cur = head;
  while (cur != NULL) {
    Student * tail = cur;
    cur = cur->next;
    delete tail;
  }
}

//Courses Constructor
Courses::Courses() {
  cout << "Creating Courses...\n";
  size = 0;
  head = tail = NULL;
}

//Courses Destructor
Courses::~Courses() {
  cout << "Destroying Students...\n";
  Course * cur = head;
  while (cur != NULL) {
    Course * tail = cur;
    cur = cur->next;
    delete tail;
  }
}

//Enrollments Constructor
Enrollments::Enrollments() {
  cout << "Creating Enrollments...\n";
  size = 0;
  head = tail = NULL;
}

//Enrollments Destructor
Enrollments::~Enrollments() {
  cout << "Destroying Enrollments...\n";
  Enrollment * cur = head;
  while (cur != NULL) {
    Enrollment * tail = cur;
    cur = cur->next;
    delete tail->grades;
    delete tail;
  }
}

void add(Student * student) {
  cout << "Adding Student...\n";
  students->size++;
  if (students->head == NULL) {
    students->head = student;
    students->tail = students->head;
  } else {
    students->tail->next = student;
    students->tail = students->tail->next;
  }
  cout << "Done!\n";
}

void add(Course * course) {
  cout << "Adding Course...\n";
  courses->size++;
  if (courses->head == NULL) {
    courses->head = course;
    courses->tail = courses->head;
  } else {
    courses->tail->next = course;
    courses->tail = courses->tail->next;
  }
  cout << "Done!\n";
}

void add(int student_id, int course_id, int count, int * grade_array) {
  cout << "Adding grades...\n";
  Enrollment * enrollment = enrollments->head;
  Grades * grades = NULL;

  //Find the enrollment object link between the sutdent and course
  while (enrollment != NULL) {
    if (enrollment->student->id == student_id && enrollment->course->id == course_id) {
      cout << "Found Enrollment...\n";
      grades = enrollment->grades;
      grades->size += count;
      break;
    }
    enrollment = enrollment->next;
  }

  //Add the grades array to the grades linkedlist
  for (int i = 0; i < count; i++) {
    Grade * grade = new Grade;
    grade->value = grade_array[i];
    if (grades->head == NULL) {
      grades->head = grade;
      grades->tail = grades->head;
    } else {
      grades->tail->next = grade;
      grades->tail = grades->tail->next;
    }
    cout << "Added Grade: " << grade->value << endl;
  }
  cout << "Done!\n";
}

void add(int student_id, int course_id) {
  cout << "Adding Student to Course...\n";
  Enrollment * enrollment = new Enrollment;
  enrollment->grades = new Grades;
  Student * student = students->head;
  Course * course = courses->head;

  //Find student
  for (int i = 0; i < students->size && student != NULL; i++) {
    if (student->id == student_id) {
      cout << "Found Student...\n";
      enrollment->student = student;
      break;
    }
    student = student->next;
  }

  //Find Course
  for (int i = 0; i < courses->size && course != NULL; i++) {
    if (course->id == course_id) {
      cout << "Found Course...\n";
      enrollment->course = course;
      break;
    }
    course = course->next;
  }

  //Create enrollment object link between student and course
  //and add to linkedlist
  enrollments->size++;
  if (enrollments->head == NULL) {
    enrollments->head = enrollment;
    enrollments->tail = enrollments->head;
  } else {
    enrollments->tail->next = enrollment;
    enrollments->tail = enrollments->tail->next;
  }
  cout << "Done!\n";
  return;
}

void print_students(int course_id) {
  cout << "Printing Students from a Course...\n";
  Enrollment * cur = enrollments->head;
  while (cur != NULL) {
    if (cur->course->id == course_id) {
      Student * s = cur->student;
      printf("ID: %5d Name: %20s\n", s->id, s->name.c_str());
    }
    cur = cur->next;
  }
  cout << "Done!\n";
}

void print_grades(int student_id, int course_id) {
  cout << "Printing Grades from a Student in a Course...\n";
  Enrollment * cur = enrollments->head;

  //Find enrollment object link between student and course
  while (cur != NULL) {
    if (cur->student->id == student_id && cur->course->id == course_id) {
      cout << cur->student->id << " " << cur->student->name << " : ";
      Grade * cur_grade = cur->grades->head;

      //Print all of the grades
      for (int i = 0; i < cur->grades->size && cur_grade != NULL; i++) {
        cout << cur_grade->value << " ";
        cur_grade = cur_grade->next;
      }
      cout << endl;
      return;
    }
    cur = cur->next;
  }
  cout << "Done!\n";
};

void print_all_students() {
  cout << "Printing All Students...\n";
  Student * cur = students->head;
  for (int i = 0; i < students->size && cur != NULL; i++) {
    printf("ID: %5d Name: %20s\n", cur->id, cur->name.c_str());
    cur = cur->next;
  }
  cout << "Done!\n";
}

void print_all_courses() {
  cout << "Printing All Courses...\n";
  Course * cur = courses->head;
  for (int i = 0; i < courses->size && cur != NULL; i++) {
    printf("ID: %5d Name: %20s\n", cur->id, cur->name.c_str());
    cur = cur->next;
  }
  cout << "Done!\n";
}

float average(int student_id, int course_id) {
  cout << "Calculating average for student in a course...\n";
  Enrollment * cur = enrollments->head;

  //Find enrollment object link between student and course
  while (cur != NULL) {
    if (cur->student->id == student_id && cur->course->id == course_id) {
      cout << "Found Enrollment...\n";
      float total = 0;
      Grade * cur_grade = cur->grades->head;

      //Sum up all grades
      for (int i = 0; i < cur->grades->size; i++) {
        total += cur_grade->value;
        cur_grade = cur_grade->next;
      }
      cout << endl;

      //return avg
      return total / static_cast < float > (cur->grades->size);
    }
    cur = cur->next;
  }
}

float average(int course_id) {
  cout << "Calculating average of a course...\n";
  Enrollment * cur = enrollments->head;
  float total = 0, count = 0;

  //Find all enrollments links containing course
  while (cur != NULL) {
    if (cur->course->id == course_id) {

      //Sum up averages of students in course
      total += average(cur->student->id, course_id);
      count++;
    }
    cur = cur->next;
  }
  //return avg
  return total / count;
}

void store_gradebook(string filename) {
  cout << "Storing Gradebook\n";
  ofstream fout(filename.c_str());

  Student * cur_student = students->head;

  //Print list of students
  for (int i = 0; i < students->size && cur_student != NULL; i++) {
    fout << "STUDENT: " << cur_student->id << " " << cur_student->name << endl;
    cur_student = cur_student->next;
  }
  fout << "\n\n\n";

  //Loop through all courses
  Course * cur_course = courses->head;
  for (int i = 0; i < courses->size && cur_course != NULL; i++) {
    fout << "COURSE: \t" << cur_course->id << "\t" << cur_course->name << endl;
    Enrollment * cur = enrollments->head;

    //Find all students in current course
    while (cur != NULL) {
      if (cur->course->id == cur_course->id) {
        Student * s = cur->student;
        fout << "ENROLLED: " << s->id << "\t" << s->name << "\t COUNT: " << cur->grades->size << "\t\t";

        //Print all grades for student in current course
        Grade * cur_grade = cur->grades->head;
        cout << cur->grades->size << " ";
        for (int i = 0; i < cur->grades->size; i++) {
          fout << cur_grade->value << " ";
          cur_grade = cur_grade->next;
        }

        //Print average of grades
        fout << "\t\tAVG: " << average(s->id, cur_course->id) << endl;
      }
      cur = cur->next;
    }
    fout << "\n\n\n";
    cur_course = cur_course->next;
  }
  cout << "Done!\n";
}

void load_gradebook(string filename) {
  cout << "Loading Gradebook...\n";
  ifstream fin(filename.c_str());
  int id, course_id;
  string name, type;

  //Stream "TYPE: ID NAME" from file
  while (fin >> type >> id >> name) {
    cout << type << id << " " << name << endl;

    if (type == "STUDENT:") {
      Student * student = new Student;
      student->id = id;
      student->name = name;
      add(student);
    }

    if (type == "COURSE:") {
      Course * course = new Course;
      course->id = id;
      course->name = name;
      add(course);
      course_id = id;
    }

    else if (type == "ENROLLED:") {
      add(id, course_id);
      string s;
      float avg;

      //Create grade array from file stream
      int grade = 0, max_size = 0;
      fin >> s >> max_size;
      int * grades_array = new int[max_size];
      for (int size = 0; size < max_size; size++) {
        fin >> grade;
        grades_array[size] = grade;
      }
      fin >> s >> avg;

      //Add grades to enrollment object link between student and course
      add(id, course_id, max_size, grades_array);
    }
  }
  return;
}

void print_menu() {
  cout << " 0. Exit.\n";
  cout << " 1. Add a new course\n";
  cout << " 2. Add a new student\n";
  cout << " 3. Add a student to a course\n";
  cout << " 4. Add grades for a student in a course\n";
  cout << " 5. Print a list of all grades for a student in a course\n";
  cout << " 6. Print a list of all students in a course\n";
  cout << " 7. Compute the average for a student in a course\n";
  cout << " 8. Print a list of all courses\n";
  cout << " 9. Print a list of all students\n";
  cout << " 10. Compute the average for a course\n";
  cout << " 11. Store Grade book (to a disk file)\n";
  cout << " 12. Load Grade book (from a disk file)\n";
  return;
}

void print_student_info() {
  cout << "\nName: Justin Wei\n";
  cout << "Email: JustinWei@my.unt.edu\n";
  cout << "Course: CSCE 1040\n";
  cout << "Instructor: Keathly\n";
  cout << "EUID: jaw0561\n\n\n";
  return;
}

void input_integer(int &x){
  x = -1;
  do{
    cin >> x;
    if(cin.fail()){
      x = -1;
      cin.clear();
      cin.ignore(32676, '\n');
    }
  }while(x < 0);
}


void clean_up(){
  delete students;
  delete courses;
  delete enrollments;

  cout << "Done!\n";
  return;
}
