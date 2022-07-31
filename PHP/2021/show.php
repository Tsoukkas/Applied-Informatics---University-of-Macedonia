<!DOCTYPE html>
<html>
    <head>
        <title>
            Εξέταση 2021 Σεπτεμβρίου
        </title>
        <meta charset="utf-8">
        <link rel="stylesheet" href="2021_1.css">
        <script src="2021_1.js"></script>
    </head>
    <body>
        <h1>Αντώνης Τσούκκας iis21139@uom.edu.gr </h1>
       
	   <?php 
echo "<table style='border: solid 1px black;'>"; 
echo "<tr><th>Id</th><th>Name</th><th>Website</th></tr>";
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
 $stmt = $conn->prepare("SELECT id, Name, Website FROM dedomena"); 
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