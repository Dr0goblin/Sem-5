# LAB 7 - Question-Wise Demo Guide

## Project Files
- `setup.sql` - database schema for `students` and `student_details`
- `db.php` - MySQL connection and table creation
- `index.php` - CRUD + reports + pass/fail count + demo insert button
- `failed_parents.php` - JOIN query for failed students and parent contact
- `oop/constructor_destructor.php` - constructor and destructor demo
- `oop/inheritance_polymorphism.php` - inheritance, polymorphism, access modifiers, getter/setter
- `oop/static_members.php` - static members demo

## How to Run
1. Start Apache and MySQL in XAMPP.
2. Import `setup.sql` once in MySQL (phpMyAdmin or mysql CLI).
3. Open `index.php` in browser.

## Exact Mapping to Your Questions

### 1) CRUD Operation using PHP
1. (a) Table `students` with required columns:
	- `std_id`, `student_name`, `rollnumber`, `marks_obtained`, `result`
	- See `setup.sql` and `db.php`
2. (b) Insert details of 5 students:
	- In `index.php`, click button: **Insert 5 Demo Students (Q1-b)**
3. (c) Display result with edit/delete buttons:
	- In `index.php`, see **Student List** table and **Edit/Delete** links
4. (d) Edit marks of one student:
	- Click **Edit**, update marks, submit **Update**
5. (e) Delete one student:
	- Click **Delete** on any row

### 2) Reports from the Students Table
In `index.php` under **Report**:
1. Highest marks student name
2. Lowest marks student name
3. Total students
4. Average marks of class

### 3) Ascending Order + Pass/Fail Count
In `index.php`:
1. Student records displayed in ascending order by `std_id`
2. Pass/Fail student count shown in **Pass / Fail Count** table

### 4) JOIN Demonstration in MySQL
1. Additional table `student_details` has:
	- address, parent_name, mobile_phone, email
2. Open `failed_parents.php`:
	- Shows parent name and email for students with result = Fail
	- Uses INNER JOIN between `students` and `student_details`

### 5) Constructor and Destructor in PHP
Open `oop/constructor_destructor.php`:
1. Constructor message appears when object is created
2. Destructor message appears at script end

### 6) Inheritance and Polymorphism (Lecturer -> Parttime/Fulltime)
Open `oop/inheritance_polymorphism.php`:
1. Parent class: `Lecturer`
2. Child classes: `Parttime`, `Fulltime`
3. Polymorphism shown by overriding `calculateSalary()` and `getRoleDescription()`

### 7) Access Modifiers + Getter/Setter
In `oop/inheritance_polymorphism.php`:
1. `public` property: `name`
2. `protected` property: `department`
3. `private` property: `employeeId`
4. Getter/Setter used for `name`, `department`, and `employeeId`

### 8) Static Members in OOP
Open `oop/static_members.php`:
1. Static property: `CounterDemo::$objectCount`
2. Static method: `CounterDemo::getObjectCount()`
3. Demonstrates class-level member shared by all objects
