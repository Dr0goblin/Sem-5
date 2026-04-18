<?php
require_once 'db.php';

function getResultFromMarks(int $marks): string
{
    return $marks >= 40 ? 'Pass' : 'Fail';
}

$message = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_POST['load_demo'])) {
        $countRow = $conn->query('SELECT COUNT(*) AS total FROM students')->fetch_assoc();
        $totalStudents = (int)($countRow['total'] ?? 0);

        if ($totalStudents > 0) {
            $message = 'Demo insert skipped: students table is not empty.';
        } else {
            $demoStudents = [
                ['Ram', 'WT001', 80],
                ['Shyam', 'WT002', 45],
                ['Hari', 'WT003', 67],
                ['Sita', 'WT004', 90],
                ['Gita', 'WT005', 30],
            ];

            $demoDetails = [
                ['12 Green Park, Ahmedabad', 'Mahesh Shah', '9876500001', 'mahesh.shah@example.com'],
                ['44 Lotus Colony, Surat', 'Neha Mehta', '9876500002', 'neha.mehta@example.com'],
                ['9 River View, Vadodara', 'Suresh Patel', '9876500003', 'suresh.patel@example.com'],
                ['77 Skyline, Rajkot', 'Aditi Rao', '9876500004', 'aditi.rao@example.com'],
                ['31 Sun City, Anand', 'Vikram Verma', '9876500005', 'vikram.verma@example.com'],
            ];

            $conn->begin_transaction();
            try {
                $studentStmt = $conn->prepare('INSERT INTO students (student_name, rollnumber, marks_obtained, result) VALUES (?, ?, ?, ?)');
                $detailStmt = $conn->prepare('INSERT INTO student_details (std_id, address, parent_name, mobile_phone, email) VALUES (?, ?, ?, ?, ?)');

                if (!$studentStmt || !$detailStmt) {
                    throw new Exception('Demo insert prepare failed.');
                }

                for ($i = 0; $i < count($demoStudents); $i++) {
                    [$name, $roll, $marks] = $demoStudents[$i];
                    $result = getResultFromMarks((int)$marks);
                    $studentStmt->bind_param('ssis', $name, $roll, $marks, $result);

                    if (!$studentStmt->execute()) {
                        throw new Exception('Demo student insert failed: ' . $studentStmt->error);
                    }

                    $newStudentId = (int)$conn->insert_id;
                    [$address, $parentName, $mobilePhone, $email] = $demoDetails[$i];
                    $detailStmt->bind_param('issss', $newStudentId, $address, $parentName, $mobilePhone, $email);

                    if (!$detailStmt->execute()) {
                        throw new Exception('Demo parent insert failed: ' . $detailStmt->error);
                    }
                }

                $studentStmt->close();
                $detailStmt->close();

                $conn->commit();
                $message = 'Inserted 5 demo students with parent details.';
            } catch (Exception $e) {
                $conn->rollback();
                $message = $e->getMessage();
            }
        }
    }

    if (isset($_POST['add_student'])) {
        $name = trim($_POST['student_name'] ?? '');
        $roll = trim($_POST['rollnumber'] ?? '');
        $marks = (int)($_POST['marks_obtained'] ?? 0);
        $address = trim($_POST['address'] ?? '');
        $parentName = trim($_POST['parent_name'] ?? '');
        $mobilePhone = trim($_POST['mobile_phone'] ?? '');
        $email = trim($_POST['email'] ?? '');
        $result = getResultFromMarks($marks);

        $conn->begin_transaction();
        try {
            $stmt = $conn->prepare('INSERT INTO students (student_name, rollnumber, marks_obtained, result) VALUES (?, ?, ?, ?)');
            if (!$stmt) {
                throw new Exception('Student insert prepare failed.');
            }

            $stmt->bind_param('ssis', $name, $roll, $marks, $result);
            if (!$stmt->execute()) {
                throw new Exception('Student insert failed: ' . $stmt->error);
            }
            $newStudentId = (int)$conn->insert_id;
            $stmt->close();

            $detailStmt = $conn->prepare('INSERT INTO student_details (std_id, address, parent_name, mobile_phone, email) VALUES (?, ?, ?, ?, ?)');
            if (!$detailStmt) {
                throw new Exception('Parent details insert prepare failed.');
            }

            $detailStmt->bind_param('issss', $newStudentId, $address, $parentName, $mobilePhone, $email);
            if (!$detailStmt->execute()) {
                throw new Exception('Parent details insert failed: ' . $detailStmt->error);
            }
            $detailStmt->close();

            $conn->commit();
            $message = 'Student and parent details added.';
        } catch (Exception $e) {
            $conn->rollback();
            $message = $e->getMessage();
        }
    }

    if (isset($_POST['update_marks'])) {
        $id = (int)($_POST['std_id'] ?? 0);
        $marks = (int)($_POST['marks_obtained'] ?? 0);
        $result = getResultFromMarks($marks);

        $stmt = $conn->prepare('UPDATE students SET marks_obtained = ?, result = ? WHERE std_id = ?');
        if ($stmt) {
            $stmt->bind_param('isi', $marks, $result, $id);
            $message = $stmt->execute() ? 'Marks updated.' : 'Update failed: ' . $stmt->error;
            $stmt->close();
        }
    }
}

if (isset($_GET['delete_id'])) {
    $deleteId = (int)$_GET['delete_id'];
    $stmt = $conn->prepare('DELETE FROM students WHERE std_id = ?');
    if ($stmt) {
        $stmt->bind_param('i', $deleteId);
        $message = $stmt->execute() ? 'Record deleted.' : 'Delete failed: ' . $stmt->error;
        $stmt->close();
    }
}

$editStudent = null;
if (isset($_GET['edit_id'])) {
    $editId = (int)$_GET['edit_id'];
    $stmt = $conn->prepare('SELECT * FROM students WHERE std_id = ?');
    if ($stmt) {
        $stmt->bind_param('i', $editId);
        $stmt->execute();
        $editStudent = $stmt->get_result()->fetch_assoc();
        $stmt->close();
    }
}

$students = $conn->query('SELECT * FROM students ORDER BY std_id ASC');
$highest = $conn->query('SELECT student_name, marks_obtained FROM students ORDER BY marks_obtained DESC LIMIT 1')->fetch_assoc();
$lowest = $conn->query('SELECT student_name, marks_obtained FROM students ORDER BY marks_obtained ASC LIMIT 1')->fetch_assoc();
$summary = $conn->query('SELECT COUNT(*) AS total_students, AVG(marks_obtained) AS avg_marks FROM students')->fetch_assoc();
$passFail = $conn->query("SELECT result, COUNT(*) AS total FROM students GROUP BY result ORDER BY result ASC");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Lab 7</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        table { border-collapse: collapse; width: 100%; margin-top: 10px; }
        th, td { border: 1px solid #ccc; padding: 8px; text-align: left; }
        input, button { padding: 6px; margin: 4px 0; }
        .msg { color: #0a5d0a; font-weight: 600; }
    </style>
</head>
<body>
    <h2>LAB 7 - Simple CRUD + Reports</h2>

    <p><a href="failed_parents.php">JOIN Demo</a> | <a href="oop/constructor_destructor.php">Q5</a> | <a href="oop/inheritance_polymorphism.php">Q6-Q7</a> | <a href="oop/static_members.php">Q8</a></p>

    <?php if ($message !== ''): ?>
        <p class="msg"><?= htmlspecialchars($message) ?></p>
    <?php endif; ?>

    <h3>Add Student</h3>
    <form method="post">
        <button type="submit" name="load_demo">Insert 5 Demo Students (Q1-b)</button>
    </form>

    <form method="post">
        <input type="text" name="student_name" placeholder="Name" required>
        <input type="text" name="rollnumber" placeholder="Roll Number" required>
        <input type="number" name="marks_obtained" min="0" max="100" placeholder="Marks" required>
        <input type="text" name="address" placeholder="Address" required>
        <input type="text" name="parent_name" placeholder="Parent Name" required>
        <input type="text" name="mobile_phone" placeholder="Mobile Phone" required>
        <input type="email" name="email" placeholder="Parent Email" required>
        <button type="submit" name="add_student">Add</button>
    </form>

    <?php if ($editStudent): ?>
        <h3>Edit Marks</h3>
        <form method="post">
            <input type="hidden" name="std_id" value="<?= (int)$editStudent['std_id'] ?>">
            <p>Editing <?= htmlspecialchars($editStudent['student_name']) ?> (<?= htmlspecialchars($editStudent['rollnumber']) ?>)</p>
            <input type="number" name="marks_obtained" min="0" max="100" value="<?= (int)$editStudent['marks_obtained'] ?>" required>
            <button type="submit" name="update_marks">Update</button>
        </form>
    <?php endif; ?>

    <h3>Student List (Ascending by ID)</h3>
    <table>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Roll Number</th>
            <th>Marks</th>
            <th>Result</th>
            <th>Action</th>
        </tr>
        <?php if ($students && $students->num_rows > 0): ?>
            <?php while ($row = $students->fetch_assoc()): ?>
                <tr>
                    <td><?= (int)$row['std_id'] ?></td>
                    <td><?= htmlspecialchars($row['student_name']) ?></td>
                    <td><?= htmlspecialchars($row['rollnumber']) ?></td>
                    <td><?= (int)$row['marks_obtained'] ?></td>
                    <td><?= htmlspecialchars($row['result']) ?></td>
                    <td>
                        <a href="index.php?edit_id=<?= (int)$row['std_id'] ?>">Edit</a> |
                        <a href="index.php?delete_id=<?= (int)$row['std_id'] ?>" onclick="return confirm('Delete this student?');">Delete</a>
                    </td>
                </tr>
            <?php endwhile; ?>
        <?php else: ?>
            <tr><td colspan="6">No records found.</td></tr>
        <?php endif; ?>
    </table>

    <h3>Report</h3>
    <ul>
        <li>Highest marks: <?= $highest ? htmlspecialchars($highest['student_name']) . ' (' . (int)$highest['marks_obtained'] . ')' : 'N/A' ?></li>
        <li>Lowest marks: <?= $lowest ? htmlspecialchars($lowest['student_name']) . ' (' . (int)$lowest['marks_obtained'] . ')' : 'N/A' ?></li>
        <li>Total students: <?= (int)($summary['total_students'] ?? 0) ?></li>
        <li>Average marks: <?= number_format((float)($summary['avg_marks'] ?? 0), 2) ?></li>
    </ul>

    <h3>Pass / Fail Count</h3>
    <table>
        <tr>
            <th>Result</th>
            <th>Count</th>
        </tr>
        <?php if ($passFail && $passFail->num_rows > 0): ?>
            <?php while ($row = $passFail->fetch_assoc()): ?>
                <tr>
                    <td><?= htmlspecialchars($row['result']) ?></td>
                    <td><?= (int)$row['total'] ?></td>
                </tr>
            <?php endwhile; ?>
        <?php else: ?>
            <tr><td colspan="2">No data.</td></tr>
        <?php endif; ?>
    </table>
</body>
</html>
