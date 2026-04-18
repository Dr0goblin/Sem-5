<?php
$size = 10;
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Question 1 - Multiplication Table</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #f6f8fb;
            color: #1f2937;
            margin: 30px;
        }

        table {
            border-collapse: collapse;
            margin-top: 20px;
            background: #ffffff;
        }

        th, td {
            border: 1px solid #cbd5e1;
            padding: 10px 14px;
            text-align: center;
        }

        th {
            background: #1d4ed8;
            color: #ffffff;
        }

        .corner {
            background: #0f172a;
        }
    </style>
</head>
<body>
    <h1>Question 1: Multiplication Table</h1>
    <p>This script generates a multiplication table from 1 to <?php echo $size; ?>.</p>

    <table>
        <tr>
            <th class="corner">x</th>
            <?php for ($column = 1; $column <= $size; $column++): ?>
                <th><?php echo $column; ?></th>
            <?php endfor; ?>
        </tr>

        <?php for ($row = 1; $row <= $size; $row++): ?>
            <tr>
                <th><?php echo $row; ?></th>
                <?php for ($column = 1; $column <= $size; $column++): ?>
                    <td><?php echo $row * $column; ?></td>
                <?php endfor; ?>
            </tr>
        <?php endfor; ?>
    </table>
</body>
</html>
