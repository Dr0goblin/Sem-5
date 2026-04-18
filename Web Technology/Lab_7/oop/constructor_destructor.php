<?php
class StudentSession
{
    private string $studentName;

    public function __construct(string $studentName)
    {
        $this->studentName = $studentName;
        echo "<p>Constructor called: Session started for {$this->studentName}</p>";
    }

    public function study(): void
    {
        echo "<p>{$this->studentName} is attending the Web Technology class.</p>";
    }

    public function __destruct()
    {
        echo "<p>Destructor called: Session ended for {$this->studentName}</p>";
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Constructor and Destructor Demo</title>
</head>
<body>
    <h2>OOP Demo: Constructor and Destructor in PHP</h2>
    <?php
        $session = new StudentSession('Aarav');
        $session->study();
    ?>
    <p><a href="../index.php">Back to Main Page</a></p>
</body>
</html>
