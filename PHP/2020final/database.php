<!DOCTYPE html>
<html>
<head>
  <title>database</title>
  <style>
    p{
	  border:2px solid black;
	}
  </style>
</head>
<body>
<?php 
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
try { 
 $a = $_POST["name"];
 $b = $_POST["email"];
 $conn = new PDO("mysql:host=$servername;dbname=database", $username, 
$password); 
 // set the PDO error mode to exception 
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
 $sql = "CREATE DATABASE database"; 
 $sql = "CREATE TABLE Person ( 
 id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
 P_name VARCHAR(30) NOT NULL,  
 email VARCHAR(50)
 )";
 $sql = "INSERT INTO Person (P_name, email) 
 VALUES ('$a', '$b')"; 
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
   <p>
   
   
   
   
   
   
   </p>
   
   
</body>
</html>