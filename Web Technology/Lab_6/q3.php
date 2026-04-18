<?php
$numbers = [2, 4, 6, 8, 10];
$squares = [];

foreach ($numbers as $number) {
    $squares[] = $number * $number;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Question 3 - Square Using foreach</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #effcf6;
            color: #064e3b;
            margin: 30px;
        }

        .box {
            max-width: 700px;
            background: #ffffff;
            border-radius: 16px;
            padding: 24px;
            box-shadow: 0 12px 30px rgba(6, 78, 59, 0.1);
        }

        pre {
            background: #ecfdf5;
            padding: 14px;
            border-radius: 10px;
            overflow: auto;
        }
    </style>
</head>
<body>
    <div class="box">
        <h1>Question 3: Square of Numbers Using foreach</h1>
        <p><strong>Original Array:</strong></p>
        <pre><?php print_r($numbers); ?></pre>

        <p><strong>Squares of the Numbers:</strong></p>
        <pre><?php print_r($squares); ?></pre>
    </div>
</body>
</html>
