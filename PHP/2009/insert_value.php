<!DOCTYPE html>
<html>
<head>
  <title>2009</title>
</head>
<body>

   <?php 
$pass = ""; 
if ($_SERVER["REQUEST_METHOD"] == "POST") { 
 if (empty($_POST["pass"])) { 
 $pass = ""; 
 } else { 
 $pass = test_input($_POST["pass"]);  
 } 
 
function test_input($data) { 
 $data = trim($data); 
 $data = stripslashes($data); 
 $data = htmlspecialchars($data); 
 return $data; 
} 
}
?>

<h2>PHP Form Validation Example</h2> 
<form method="post" action="<?php echo 
htmlspecialchars($_SERVER["PHP_SELF"]);?>"> 
 Password: <input type="text" name="pass" value="<?php echo $pass;?>"> 
 <br><br> 
 <input type="submit" name="submit" value="Submit"> 
</form> 

<?php 
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
$dbname = "2009"; 
try { 
 $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, 
$password); 
$number = "2";
$name = "andonis";
$id = "1";

 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
 $sql = "INSERT INTO student VALUES ('$number','$name',
			'$id')";
 
 $conn->exec($sql); 
 echo "New record created successfully"; 
 } 
catch(PDOException $e) 
 { 
 echo $sql . "<br>" . $e->getMessage(); 
 } 
$conn = null; 
?> 

</body>
</html>