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
echo "<table style='border: solid 1px black;'>"; 
echo "<tr><th>Id</th><th>Name</th><th>website</th></tr>";
class TableRows extends RecursiveIteratorIterator { 
 function __construct($it) { 
 parent::__construct($it, self::LEAVES_ONLY); 

 } 
 function current() { 
 return "<td style='width:150px;border:1px solid black;'>" . parent::current(). 
"</td>"; 
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
$dbname = "iis21139"; 
try { 
 $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, 
$password); 
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
 $stmt = $conn->prepare("SELECT id, name, website FROM iis21139"); 
 $stmt->execute(); 
 // set the resulting array to associative 
 $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
 foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
 echo $v; 
 } 
} 
catch(PDOException $e) { 
 echo "Error: " . $e->getMessage(); 
} 
$conn = null; 
echo "</table>"; 
?> 

</body>
</html>