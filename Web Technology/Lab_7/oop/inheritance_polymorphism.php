<?php
class Lecturer
{
    public string $name;          // public property
    protected string $department; // protected property
    private string $employeeId;   // private property

    public function __construct(string $name, string $department, string $employeeId)
    {
        $this->name = $name;
        $this->department = $department;
        $this->employeeId = $employeeId;
    }

    public function getEmployeeId(): string
    {
        return $this->employeeId;
    }

    public function getName(): string
    {
        return $this->name;
    }

    public function setName(string $name): void
    {
        $this->name = $name;
    }

    public function setEmployeeId(string $employeeId): void
    {
        $this->employeeId = $employeeId;
    }

    public function getDepartment(): string
    {
        return $this->department;
    }

    public function setDepartment(string $department): void
    {
        $this->department = $department;
    }

    public function getRoleDescription(): string
    {
        return "Lecturer {$this->name} works in {$this->department} department.";
    }

    public function calculateSalary(): float
    {
        return 30000;
    }
}

class Parttime extends Lecturer
{
    private float $hourlyRate;
    private int $hoursWorked;

    public function __construct(string $name, string $department, string $employeeId, float $hourlyRate, int $hoursWorked)
    {
        parent::__construct($name, $department, $employeeId);
        $this->hourlyRate = $hourlyRate;
        $this->hoursWorked = $hoursWorked;
    }

    public function calculateSalary(): float
    {
        return $this->hourlyRate * $this->hoursWorked;
    }

    public function getRoleDescription(): string
    {
        return "Part-time Lecturer {$this->name} ({$this->getDepartment()})";
    }
}

class Fulltime extends Lecturer
{
    private float $monthlySalary;
    private float $allowance;

    public function __construct(string $name, string $department, string $employeeId, float $monthlySalary, float $allowance)
    {
        parent::__construct($name, $department, $employeeId);
        $this->monthlySalary = $monthlySalary;
        $this->allowance = $allowance;
    }

    public function calculateSalary(): float
    {
        return $this->monthlySalary + $this->allowance;
    }

    public function getRoleDescription(): string
    {
        return "Full-time Lecturer {$this->name} ({$this->getDepartment()})";
    }
}

$teachers = [
    new Parttime('Rita Joshi', 'Computer Science', 'PT101', 500, 40),
    new Fulltime('Nitin Rao', 'Information Technology', 'FT201', 55000, 7000)
];

// Demonstrate setter/getter use for public and private properties.
$teachers[0]->setName('Rita J.');
$teachers[1]->setEmployeeId('FT202');
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Inheritance and Polymorphism Demo</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 24px; }
        table { border-collapse: collapse; width: 100%; }
        th, td { border: 1px solid #ccc; padding: 8px; }
        th { background: #f2f2f2; }
    </style>
</head>
<body>
    <h2>OOP Demo: Inheritance, Polymorphism, Access Modifiers</h2>
    <p>This example shows:</p>
    <ul>
        <li>Inheritance: <strong>Parttime</strong> and <strong>Fulltime</strong> extend <strong>Lecturer</strong>.</li>
        <li>Polymorphism: both classes override <strong>calculateSalary()</strong> and <strong>getRoleDescription()</strong>.</li>
        <li>Access Modifiers: public, protected, private properties in parent class.</li>
        <li>Getter/Setter: public <strong>name</strong> and private <strong>employeeId</strong> are accessed via methods.</li>
    </ul>

    <table>
        <tr>
            <th>Name (Getter)</th>
            <th>Role Description</th>
            <th>Employee ID (via getter)</th>
            <th>Salary (Polymorphic)</th>
        </tr>
        <?php foreach ($teachers as $teacher): ?>
            <tr>
                <td><?= htmlspecialchars($teacher->getName()) ?></td>
                <td><?= htmlspecialchars($teacher->getRoleDescription()) ?></td>
                <td><?= htmlspecialchars($teacher->getEmployeeId()) ?></td>
                <td><?= number_format($teacher->calculateSalary(), 2) ?></td>
            </tr>
        <?php endforeach; ?>
    </table>

    <p><a href="../index.php">Back to Main Page</a></p>
</body>
</html>
