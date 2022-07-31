<!DOCTYPE html>
<html>
    <head>
        <title>
            Ερώτημα C
        </title>
        <meta charset="UTF-8">
        <link rel="stylesheet" href="2020_1">
    </head>
    <body>
	


     <?php 
	 echo "<table style='border: solid 1px black;'>";
 echo "<tr><th>Id</th><th>Firstname</th><th>Lastname</th></tr>";

class TableRows extends RecursiveIteratorIterator {
    function __construct($it) {
        parent::__construct($it, self::LEAVES_ONLY);
    }

    function current() {
        return "<td style='width: 150px; border: 1px solid black;'>" . parent::current(). "</td>";
    }

    function beginChildren() {
        echo "<tr>";
    }

    function endChildren() {
        echo "</tr>" . "\n";
    }
}
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
try { 
 $conn = new PDO("mysql:host=$servername;dbname=database", $username, 
$password); 
 // set the PDO error mode to exception 
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
 $sql = "CREATE DATABASE database"; 
 $sql = "CREATE TABLE Persons ( 
 id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
 P_name VARCHAR(30) NOT NULL,  
 email VARCHAR(50), 
 )";
 $a=$_POST['name'];
 $b=$_POST['email'];
 $sql = "INSERT INTO Persons (id, P_name, email) 
 VALUES ('John', '$a', '$b')";
 // use exec() because no results are returned 
 $conn->exec($sql); 
 echo "Δώσατε:";
 <br>
 echo " $a";
 echo "$b";
 echo "Database created successfully.<br>"; 
 echo "Table Persons created successfully.<br>"; 
 $stmt = $conn->prepare("SELECT id, firstname, lastname FROM MyGuests");
    $stmt->execute();

    // set the resulting array to associative
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);

    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) {
        echo $v;
    }
}
  
 } 
catch(PDOException $e) 
 { 
 echo $sql . "<br>" . $e->getMessage(); 
 } 
$conn = null; 
?>
    </body>
</html>