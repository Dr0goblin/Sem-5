<?php
$text = "Web Technology Lab Report Six";
$vowelCount = 0;
$vowels = ['a', 'e', 'i', 'o', 'u'];

for ($index = 0; $index < strlen($text); $index++) {
    if (in_array(strtolower($text[$index]), $vowels, true)) {
        $vowelCount++;
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Question 2 - Vowel Count</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #fff7ed;
            color: #431407;
            margin: 30px;
        }

        .card {
            max-width: 680px;
            padding: 24px;
            border-radius: 16px;
            background: #ffffff;
            box-shadow: 0 12px 30px rgba(67, 20, 7, 0.1);
        }

        code {
            background: #ffedd5;
            padding: 3px 6px;
            border-radius: 6px;
        }
    </style>
</head>
<body>
    <div class="card">
        <h1>Question 2: Number of Vowels in a String</h1>
        <p><strong>Input String:</strong> <code><?php echo htmlspecialchars($text, ENT_QUOTES, 'UTF-8'); ?></code></p>
        <p><strong>Total Vowels:</strong> <?php echo $vowelCount; ?></p>
    </div>
</body>
</html>
