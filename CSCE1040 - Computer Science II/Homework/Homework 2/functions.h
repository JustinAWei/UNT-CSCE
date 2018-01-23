/*
Name: Justin Wei
Email: JustinWei@my.unt.edu
Course: CSCE1004
Instructor: Keathly
Date: 2/10/17
Description: Header file for functions
*/


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*
Name: add
Parameters: Student pointer
Returns: Nothing
Description: Adds a student
*/
void add(Student* student);


/*
Name: add
Parameters: course pointer
Returns: Nothing
Description: Adds a course
*/
void add(Course* course);

/*
Name: add
Parameters: student id, courseid, count, grade pointer array
Returns: Nothing
Description: Adds grades to a student in a course
*/
void add(int student_id, int course_id, int count, int* grade_array);


/*
Name: add
Parameters: Studentid, courseid
Returns: Nothing
Description: Adds a studens to a course
*/
void add(int student_id, int course_id);


/*
Name: print students
Parameters: course id
Returns: Nothing
Description: prints students of a course
*/
void print_students(int course_id);


/*
Name: print grades
Parameters: student id and course id
Returns: Nothing
Description: prints grades of a student in a course
*/
void print_grades(int student_id, int course_id);


/*
Name: print all students
Parameters: none
Returns: Nothing
Description: prints all students
*/
void print_all_students();


/*
Name: print all courses
Parameters: none
Returns: Nothing
Description: prints all coursest
*/
void print_all_courses();


/*
Name: average
Parameters: student id and courseid
Returns: float
Description: calculates the average of a student in a course
*/
float average(int student_id, int course_id);

/*
Name: average
Parameters: course id
Returns: float
Description: calculates the average of a course
*/
float average(int course_id);


/*
Name: store gradebook
Parameters: string for filename
Returns: Nothing
Description: stores a gradebook from a file
*/
void store_gradebook(string filename);

/*
Name: load gradebook
Parameters: string for filename
Returns: Nothing
Description: reads a gradebook from a file
*/
void load_gradebook(string filename);


/*
Name: print menu
Parameters: none
Returns: Nothing
Description: prints the menu
*/
void print_menu();
/*
Name: print student info
Parameters: none
Returns: Nothing
Description: prints student info
*/
void print_student_info();

/*
Name: input integer
Parameters: int reference
Returns: Nothing
Description: stores integer into x
*/
void input_integer(int &x);

/*
Name: clean up
Parameters: nothing
Returns: Nothing
Description: deallocates memory
*/
void clean_up();
#endif
