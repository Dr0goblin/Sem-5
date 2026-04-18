<?php
function sumNumbers()
{
    $arguments = func_get_args();
    $sum = 0;

    foreach ($arguments as $value) {
        $sum += $value;
    }

    return $sum;
}

function collectArguments()
{
    return func_get_args();
}

$sumOfTwo = sumNumbers(10, 20);
$sumOfThree = sumNumbers(10, 20, 30);
$argumentsForTwo = collectArguments(10, 20);
$argumentsForThree = collectArguments(10, 20, 30);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Question 4 - Function Overloading</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background: #f5f3ff;
            color: #312e81;
            margin: 30px;
        }

        .panel {
            max-width: 760px;
            background: #ffffff;
            border-radius: 16px;
            padding: 24px;
            box-shadow: 0 12px 30px rgba(49, 46, 129, 0.12);
        }

        code, pre {
            background: #ede9fe;
            border-radius: 8px;
        }

        code {
            padding: 2px 6px;
        }

        pre {
            padding: 14px;
            overflow: auto;
        }
    </style>
</head>
<body>
    <div class="panel">
        <h1>Question 4: Function Overloading and <code>func_get_args()</code></h1>
        <p>PHP does not support traditional function overloading by changing the number of parameters in the same way as languages like Java or C++.</p>
        <p>However, we can simulate similar behavior using a single function with <code>func_get_args()</code>, which collects all passed arguments into an array.</p>

        <p><strong>Example Results:</strong></p>
        <pre>
sumNumbers(10, 20) = <?php echo $sumOfTwo; ?>
sumNumbers(10, 20, 30) = <?php echo $sumOfThree; ?>
        </pre>

        <p><strong>Arguments captured with <code>func_get_args()</code> for two numbers:</strong></p>
        <pre><?php print_r($argumentsForTwo); ?></pre>

        <p><strong>Arguments captured with <code>func_get_args()</code> for three numbers:</strong></p>
        <pre><?php print_r($argumentsForThree); ?></pre>
    </div>
</body>
</html>
