CREATE DATABASE IF NOT EXISTS lab7_db;
USE lab7_db;

DROP TABLE IF EXISTS student_details;
DROP TABLE IF EXISTS students;

CREATE TABLE students (
    std_id INT AUTO_INCREMENT PRIMARY KEY,
    student_name VARCHAR(100) NOT NULL,
    rollnumber VARCHAR(20) NOT NULL UNIQUE,
    marks_obtained INT NOT NULL,
    result ENUM('Pass', 'Fail') NOT NULL
);

CREATE TABLE student_details (
    detail_id INT AUTO_INCREMENT PRIMARY KEY,
    std_id INT NOT NULL UNIQUE,
    address VARCHAR(255) NOT NULL,
    parent_name VARCHAR(100) NOT NULL,
    mobile_phone VARCHAR(20) NOT NULL,
    email VARCHAR(120) NOT NULL,
    FOREIGN KEY (std_id) REFERENCES students(std_id) ON DELETE CASCADE
);

INSERT INTO students (student_name, rollnumber, marks_obtained, result) VALUES
('Ram', 1, 80, 'Pass'),
('Shyam', 2, 45, 'Fail'),
('Hari', 3, 67, 'Pass'),
('Sita', 4, 90, 'Pass'),
('Gita', 5, 30, 'Fail');

