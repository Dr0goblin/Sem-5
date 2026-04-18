<?php
$arr1 = ["pop", "rock", "hiphop"];
$arr2 = ["country", "EDM"];
$choice = ["favourite" => "rock", "least_favourite" => "country"];

$mergedArray = array_merge($arr1, $arr2);
$sortedMergedArray = $mergedArray;
sort($sortedMergedArray);

$choiceSortedByKeys = $choice;
ksort($choiceSortedByKeys);

$choiceSortedByValues = $choice;
asort($choiceSortedByValues);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Question 5 - Array Operations</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #f0fdf4;
            color: #14532d;
            margin: 30px;
        }

        .card {
            max-width: 780px;
            background: #ffffff;
            border-radius: 16px;
            padding: 24px;
            box-shadow: 0 12px 30px rgba(20, 83, 45, 0.1);
        }

        pre {
            background: #f0fdf4;
            padding: 14px;
            border-radius: 10px;
            overflow: auto;
        }
    </style>
</head>
<body>
    <div class="card">
        <h1>Question 5: Array Operations</h1>

        <p><strong>a) Merge of <code>$arr1</code> and <code>$arr2</code>:</strong></p>
        <pre><?php print_r($mergedArray); ?></pre>

        <p><strong>b) Resulting array sorted in ascending order:</strong></p>
        <pre><?php print_r($sortedMergedArray); ?></pre>

        <p><strong>c) <code>$choice</code> sorted in ascending order of keys:</strong></p>
        <pre><?php print_r($choiceSortedByKeys); ?></pre>

        <p><strong><code>$choice</code> sorted in ascending order of values:</strong></p>
        <pre><?php print_r($choiceSortedByValues); ?></pre>
    </div>
</body>
</html>
