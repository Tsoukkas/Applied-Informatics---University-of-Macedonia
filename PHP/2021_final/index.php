<!DOCTYPE html>
<html>
<head>
<title>
TELEFTEA FORA
</title>
</head>
<body>
    <h1>Aντώνης Τσούκκας iis21139@uom.edu.gr </h1>
	
	<?php 
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
try { 
 $conn = new PDO("mysql:host=$servername;dbname=iis21139", $username, 
$password); 
 // set the PDO error mode to exception 
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
 $sql = "CREATE DATABASE iis21139"; 
 // use exec() because no results are returned 
 $sql = "CREATE TABLE iis21139 ( 
 id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
 name VARCHAR(30) NOT NULL, 
 website VARCHAR(50) NOT NULL
 )";
 $conn->exec($sql); 
 
 echo "Database created successfully<br>"; 
 echo "Table created successfully<br>"; 
 } 
catch(PDOException $e) 
 { 
 echo $sql . "<br>" . $e->getMessage(); 
 } 
$conn = null; 
?>

<a href="show.php">Εμφάνιση</a>
 <a href="set.php">Καταχώριση</a>
 <a href="pick.php">Διαλογή</a>
	
</body>
</html>