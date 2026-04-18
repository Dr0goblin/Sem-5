<?php
require_once 'db.php';

$sql = "
    SELECT s.student_name, s.rollnumber, s.marks_obtained, s.result, d.parent_name, d.email
    FROM students s
    INNER JOIN student_details d ON s.std_id = d.std_id
    WHERE s.result = 'Fail'
    ORDER BY s.std_id ASC
";

$result = $conn->query($sql);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Failed Students Parent Contact</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 24px; }
        table { border-collapse: collapse; width: 100%; }
        th, td { border: 1px solid #ccc; padding: 8px; text-align: left; }
        th { background: #f2f2f2; }
        a { text-decoration: none; color: #0b57d0; }
    </style>
</head>
<body>
    <h2>JOIN Demo: Parent Name and Email of Failed Students</h2>

    <table>
        <tr>
            <th>Student Name</th>
            <th>Roll Number</th>
            <th>Marks</th>
            <th>Result</th>
            <th>Parent Name</th>
            <th>Email</th>
        </tr>
        <?php if ($result && $result->num_rows > 0): ?>
            <?php while ($row = $result->fetch_assoc()): ?>
                <tr>
                    <td><?= htmlspecialchars($row['student_name']) ?></td>
                    <td><?= htmlspecialchars($row['rollnumber']) ?></td>
                    <td><?= (int)$row['marks_obtained'] ?></td>
                    <td><?= htmlspecialchars($row['result']) ?></td>
                    <td><?= htmlspecialchars($row['parent_name']) ?></td>
                    <td><?= htmlspecialchars($row['email']) ?></td>
                </tr>
            <?php endwhile; ?>
        <?php else: ?>
            <tr><td colspan="6">No failed students found.</td></tr>
        <?php endif; ?>
    </table>

    <p><a href="index.php">Back to CRUD and Reports</a></p>
</body>
</html>
