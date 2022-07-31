<!DOCTYPE HTML> 
<html> 
<head> 
<style> 
.error {color: #FF0000;} 
</style> 
</head> 
<body> 
  <h1>Aντώνης Τσούκκας iis21139@uom.edu.gr </h1>
<?php 

$nameErr  = $websiteErr = ""; 
$name = $id = $website = ""; 

if ($_SERVER["REQUEST_METHOD"] == "POST") { 
 if (empty($_POST["name"])) { 
 $nameErr = "Name is required"; 
 } 

 
 if (empty($_POST["website"])) { 
 $website = ""; 
 } 
 
 else if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-
9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i",$website)) { 
 $websiteErr = "Invalid URL"; 
 } } 

?>

<h2>PHP Form Validation Example</h2> 
<p><span class="error">* required field.</span></p> 
<form method="post" action="<?php echo 
htmlspecialchars($_SERVER["PHP_SELF"]);?>"> 

 Id: <input type="text" name="id" value="<?php echo $id;?>"> 
 <br><br>
 
 Name: <input type="text" name="name" value="<?php echo $name;?>"> 
 <span class="error">* <?php echo $nameErr;?></span> 
 <br><br> 
 
 Website: <input type="text" name="website" value="<?php echo $website;?>"> 
 <span class="error"><?php echo $websiteErr;?></span> 
 <br><br> 

 <input type="submit" name="submit" value="Submit"> 
 
</form> 

<?php

if(!isset($_POST['submit'])){
  echo "Fail insert.";
}
else{
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
$dbname = "iis21139"; 
try { 

$f1=$_POST["id"];
$f2=$_POST["name"];
$f3=$_POST["website"];
 $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, 
$password); 
 // set the PDO error mode to exception 
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
 $sql = "INSERT INTO iis21139 (id, name, website) 
 VALUES ('$f1', '$f2', '$f3')"; 
 // use exec() because no results are returned 
 $conn->exec($sql); 
 echo "New record created successfully"; 
 } 
catch(PDOException $e) 
 { 
 echo $sql . "<br>" . $e->getMessage(); 
 } 
$conn = null; 

} 

?>
</body> 
</html> 
