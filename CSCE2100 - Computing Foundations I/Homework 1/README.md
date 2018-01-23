# Homework 1
# Justin Wei

### File:
```c++
	student.h
	student.cpp
	program_01_11133006.cpp
	readme.txt
```
### Compile:
```
  g++ -std=c++11 -o student.out program_01_11133006.cpp student.cpp
```

### Run:
```
	./student.out
```


### Sample Run 1:
```
  justin$ g++ -std=c++11 -o student.out program_01_11133006.cpp student.cpp
  justin$ ./student.out
  Initialzing students a, b, and c
  Created the following student object using constructor 1:
  Name:    ID:    GPA: 0.00
  Input properties for student b:
  Enter the name of the student:A
  Enter the id of the student:1
  Enter the GPA of student:2
  Created student object b using constructor 2:
  Name: A   ID: 1   GPA: 2.00
  Created student object c using constructor 3:
  Name: A   ID: 1   GPA: 2.00
  Creating two more student objects:

  Enter the name of the student:B
  Enter the id of the student:2
  Enter the GPA of student:3
  Created student object d using constructor 2:
  Name: B   ID: 2   GPA: 3.00
  Enter the name of the student:C
  Enter the id of the student:3
  Enter the GPA of student:4
  Created student object e using constructor 2:
  Name: C   ID: 3   GPA: 4.00
  1. Name:    ID:    GPA: 0.00
  2. Name: A   ID: 1   GPA: 2.00
  3. Name: A   ID: 1   GPA: 2.00
  4. Name: B   ID: 2   GPA: 3.00
  5. Name: C   ID: 3   GPA: 4.00
  Which student object would you like to edit? (1 - 5): 1
  How would you like to edit the student object?
  a) Input your own student information.
  b) Use another student's information
  a
  Enter the name of the student:D
  Enter the id of the student:4
  Enter the GPA of student:3.5
  Sucessfully updated!
  Here is the updated student list.
  1. Name: D   ID: 4   GPA: 3.50
  2. Name: A   ID: 1   GPA: 2.00
  3. Name: A   ID: 1   GPA: 2.00
  4. Name: B   ID: 2   GPA: 3.00
  5. Name: C   ID: 3   GPA: 4.00
  Continue? (y/n):y
  1. Name: D   ID: 4   GPA: 3.50
  2. Name: A   ID: 1   GPA: 2.00
  3. Name: A   ID: 1   GPA: 2.00
  4. Name: B   ID: 2   GPA: 3.00
  5. Name: C   ID: 3   GPA: 4.00
  Which student object would you like to edit? (1 - 5): 3
  How would you like to edit the student object?
  a) Input your own student information.
  b) Use another student's information
  a
  Enter the name of the student:E
  Enter the id of the student:5
  Enter the GPA of student:2.2
  Sucessfully updated!
  Here is the updated student list.
  1. Name: D   ID: 4   GPA: 3.50
  2. Name: A   ID: 1   GPA: 2.00
  3. Name: E   ID: 5   GPA: 2.20
  4. Name: B   ID: 2   GPA: 3.00
  5. Name: C   ID: 3   GPA: 4.00
  Continue? (y/n):n

  The student with the highest GPA:
  Name: C   ID: 3   GPA: 4.00
```


### Sample Run 2:
```

  justin$ g++ -std=c++11 -o student.out program_01_11133006.cpp student.cpp
  justin$ ./student.out
  Initialzing students a, b, and c
  Created the following student object using constructor 1:
  Name:    ID:    GPA: 0.00
  Input properties for student b:
  Enter the name of the student:Justin
  Enter the id of the student:1
  Enter the GPA of student:4.00
  Created student object b using constructor 2:
  Name: Justin   ID: 1   GPA: 4.00
  Created student object c using constructor 3:
  Name: Justin   ID: 1   GPA: 4.00
  Creating two more student objects:

  Enter the name of the student:Thomas
  Enter the id of the student:2
  Enter the GPA of student:3.8
  Created student object d using constructor 2:
  Name: Thomas   ID: 2   GPA: 3.80
  Enter the name of the student:Julio
  Enter the id of the student:3
  Enter the GPA of student:3.6
  Created student object e using constructor 2:
  Name: Julio   ID: 3   GPA: 3.60
  1. Name:    ID:    GPA: 0.00
  2. Name: Justin   ID: 1   GPA: 4.00
  3. Name: Justin   ID: 1   GPA: 4.00
  4. Name: Thomas   ID: 2   GPA: 3.80
  5. Name: Julio   ID: 3   GPA: 3.60
  Which student object would you like to edit? (1 - 5): 2
  How would you like to edit the student object?
  a) Input your own student information.
  b) Use another student's information
  b
  Enter the number of the student you want to copy: 2
  Sucessfully updated!
  Here is the updated student list.
  1. Name:    ID:    GPA: 0.00
  2. Name: Justin   ID: 1   GPA: 4.00
  3. Name: Justin   ID: 1   GPA: 4.00
  4. Name: Thomas   ID: 2   GPA: 3.80
  5. Name: Julio   ID: 3   GPA: 3.60
  Continue? (y/n):y
  1. Name:    ID:    GPA: 0.00
  2. Name: Justin   ID: 1   GPA: 4.00
  3. Name: Justin   ID: 1   GPA: 4.00
  4. Name: Thomas   ID: 2   GPA: 3.80
  5. Name: Julio   ID: 3   GPA: 3.60
  Which student object would you like to edit? (1 - 5): 2
  How would you like to edit the student object?
  a) Input your own student information.
  b) Use another student's information
  b
  Enter the number of the student you want to copy: 1
  Sucessfully updated!
  Here is the updated student list.
  1. Name:    ID:    GPA: 0.00
  2. Name:    ID:    GPA: 0.00
  3. Name: Justin   ID: 1   GPA: 4.00
  4. Name: Thomas   ID: 2   GPA: 3.80
  5. Name: Julio   ID: 3   GPA: 3.60
  Continue? (y/n):y
  1. Name:    ID:    GPA: 0.00
  2. Name:    ID:    GPA: 0.00
  3. Name: Justin   ID: 1   GPA: 4.00
  4. Name: Thomas   ID: 2   GPA: 3.80
  5. Name: Julio   ID: 3   GPA: 3.60
  Which student object would you like to edit? (1 - 5): 3
  How would you like to edit the student object?
  a) Input your own student information.
  b) Use another student's information
  b
  Enter the number of the student you want to copy: 1
  Sucessfully updated!
  Here is the updated student list.
  1. Name:    ID:    GPA: 0.00
  2. Name:    ID:    GPA: 0.00
  3. Name:    ID:    GPA: 0.00
  4. Name: Thomas   ID: 2   GPA: 3.80
  5. Name: Julio   ID: 3   GPA: 3.60
  Continue? (y/n):y
  1. Name:    ID:    GPA: 0.00
  2. Name:    ID:    GPA: 0.00
  3. Name:    ID:    GPA: 0.00
  4. Name: Thomas   ID: 2   GPA: 3.80
  5. Name: Julio   ID: 3   GPA: 3.60
  Which student object would you like to edit? (1 - 5): 4
  How would you like to edit the student object?
  a) Input your own student information.
  b) Use another student's information
  b
  Enter the number of the student you want to copy: 3
  Sucessfully updated!
  Here is the updated student list.
  1. Name:    ID:    GPA: 0.00
  2. Name:    ID:    GPA: 0.00
  3. Name:    ID:    GPA: 0.00
  4. Name:    ID:    GPA: 0.00
  5. Name: Julio   ID: 3   GPA: 3.60
  Continue? (y/n):n

  The student with the highest GPA:
  Name: Julio   ID: 3   GPA: 3.60
```


### Sample Run 3:
```

  justin$ g++ -std=c++11 -o student.out program_01_11133006.cpp student.cpp
  justin$ ./student.out
  Initialzing students a, b, and c
  Created the following student object using constructor 1:
  Name:    ID:    GPA: 0.00
  Input properties for student b:
  Enter the name of the student:A
  Enter the id of the student:2
  Enter the GPA of student:/
  Sorry there was an error with your input
  Enter the name of the student:A
  Enter the id of the student:1
  Enter the GPA of student:4
  Created student object b using constructor 2:
  Name: A   ID: 1   GPA: 4.00
  Created student object c using constructor 3:
  Name: A   ID: 1   GPA: 4.00
  Creating two more student objects:

  Enter the name of the student:B
  Enter the id of the student:2
  Enter the GPA of student:3
  Created student object d using constructor 2:
  Name: B   ID: 2   GPA: 3.00
  Enter the name of the student:C
  Enter the id of the student:3
  Enter the GPA of student:1
  Created student object e using constructor 2:
  Name: C   ID: 3   GPA: 1.00
  1. Name:    ID:    GPA: 0.00
  2. Name: A   ID: 1   GPA: 4.00
  3. Name: A   ID: 1   GPA: 4.00
  4. Name: B   ID: 2   GPA: 3.00
  5. Name: C   ID: 3   GPA: 1.00
  Which student object would you like to edit? (1 - 5): 2
  How would you like to edit the student object?
  a) Input your own student information.
  b) Use another student's information
  a
  Enter the name of the student:D
  Enter the id of the student:4
  Enter the GPA of student:/
  Sorry there was an error with your input
  Enter the name of the student:D
  Enter the id of the student:4
  Enter the GPA of student:2
  Sucessfully updated!
  Here is the updated student list.
  1. Name:    ID:    GPA: 0.00
  2. Name: D   ID: 4   GPA: 2.00
  3. Name: A   ID: 1   GPA: 4.00
  4. Name: B   ID: 2   GPA: 3.00
  5. Name: C   ID: 3   GPA: 1.00
  Continue? (y/n):n

  The student with the highest GPA:
  Name: A   ID: 1   GPA: 4.00
```
