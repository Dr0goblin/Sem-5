<?php
$hosts = ['127.0.0.1', 'localhost'];
$user = 'root';
$password = '';
$database = 'lab7_db';
$port = 3306;

$conn = null;
$lastError = 'Unknown connection error.';

foreach ($hosts as $host) {
    try {
        $conn = new mysqli($host, $user, $password, null, $port);
        break;
    } catch (mysqli_sql_exception $e) {
        $lastError = $e->getMessage();
    }
}

if (!$conn || $conn->connect_error) {
    die('Database connection failed: ' . $lastError . ' Please start MySQL in XAMPP Control Panel and verify port 3306.');
}

$conn->set_charset('utf8mb4');

$conn->query("CREATE DATABASE IF NOT EXISTS `$database`");
$conn->select_db($database);

$conn->query(
    "CREATE TABLE IF NOT EXISTS students (
        std_id INT AUTO_INCREMENT PRIMARY KEY,
        student_name VARCHAR(100) NOT NULL,
        rollnumber VARCHAR(20) NOT NULL UNIQUE,
        marks_obtained INT NOT NULL,
        result ENUM('Pass', 'Fail') NOT NULL
    )"
);

$conn->query(
    "CREATE TABLE IF NOT EXISTS student_details (
        detail_id INT AUTO_INCREMENT PRIMARY KEY,
        std_id INT NOT NULL UNIQUE,
        address VARCHAR(255) NOT NULL,
        parent_name VARCHAR(100) NOT NULL,
        mobile_phone VARCHAR(20) NOT NULL,
        email VARCHAR(120) NOT NULL,
        FOREIGN KEY (std_id) REFERENCES students(std_id) ON DELETE CASCADE
    )"
);

$studentCountRow = $conn->query("SELECT COUNT(*) AS total FROM students")->fetch_assoc();
$studentCount = (int)($studentCountRow['total'] ?? 0);

if ($studentCount === 0) {
    // Ensure IDs restart from 1 when table is empty.
    $conn->query("ALTER TABLE students AUTO_INCREMENT = 1");
}

$detailsCountRow = $conn->query("SELECT COUNT(*) AS total FROM student_details")->fetch_assoc();
$detailsCount = (int)($detailsCountRow['total'] ?? 0);

if ($detailsCount === 0) {
    $conn->query("ALTER TABLE student_details AUTO_INCREMENT = 1");
}
?>
