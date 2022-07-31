<!DOCTYPE html>
<html>
    <head>
        <title>
            Εξέταση 2021 Σεπτεμβρίου PHP
        </title>
        <meta charset="utf-8">
    </head>
<body>
	
<h1>Αντώνης Τσούκκας iis21139@uom.edu.gr </h1>
	
<?php 
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
$dbname = "iis21139"; 
try { 
 $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, 
$password); 
 // set the PDO error mode to exception 
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 

 $sql = "CREATE TABLE dedomena ( 
 id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
 name VARCHAR(30) NOT NULL, 
 website VARCHAR(30) NOT NULL 
 )"; 
 $conn->exec($sql); 
 echo "Table dedomena created successfully"; 
 } 
catch(PDOException $e) 
 { 
 echo $sql . "<br>" . $e->getMessage(); 
 }
$conn = null; 

 ?> 

<a href="show.php">Εμφάνιση </a>
<a href="set.php">Καταχώρηση </a>
<a href="pick.php">Διαλογή </a>

</body>
</html>