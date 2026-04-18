<?php
class CounterDemo
{
    public static int $objectCount = 0;
    private string $name;

    public function __construct(string $name)
    {
        $this->name = $name;
        self::$objectCount++;
    }

    public static function getObjectCount(): int
    {
        return self::$objectCount;
    }

    public function getName(): string
    {
        return $this->name;
    }
}

$a = new CounterDemo('Object A');
$b = new CounterDemo('Object B');
$c = new CounterDemo('Object C');
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Static Members Demo</title>
</head>
<body>
    <h2>OOP Demo: Static Members in PHP</h2>
    <p>Static members belong to the class, not to individual objects.</p>
    <p>Total objects created: <strong><?= CounterDemo::getObjectCount() ?></strong></p>
    <p>Accessing static property directly: <strong><?= CounterDemo::$objectCount ?></strong></p>
    <p><a href="../index.php">Back to Main Page</a></p>
</body>
</html>
