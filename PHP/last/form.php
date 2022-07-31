<!DOCTYPE HTML> 
<html> 
<head> 
<style> 
.error {color: #FF0000;} 
</style> 
</head> 
<body> 

<?php 

$firstnameErr = $emailErr = $lastnameErr  = ""; 
$firstname = $lastname = $email = ""; 

if ($_SERVER["REQUEST_METHOD"] == "POST") { 
 if (empty($_POST["firstname"])) { 
 $firstnameErr = "Name is required"; 
 } else { 
 $firstname = $_POST["firstname"]; 
 if (!preg_match("/^[a-zA-Z ]*$/",$firstname)) { 
 $firstnameErr = "Only letters and white space allowed"; 
 } } 
 
 if (empty($_POST["email"])) { 
 $emailErr = "Email is required"; 
 } else { 
 $email = $_POST["email"]; 
 if (!filter_var($email, FILTER_VALIDATE_EMAIL)) { 
 $emailErr = "Invalid email format"; 
 } } 
 
 if (empty($_POST["lastname"])) { 
 $lastnameErr = "lastname is required"; 
 } else { 
 $lastname = $_POST["lastname"]; 
 } 
 }

?>


<h2>PHP Form Validation Example</h2> 
<p><span class="error">* required field.</span></p> 
<form method="post" action="<?php echo 
htmlspecialchars($_SERVER["PHP_SELF"]);?>"> 
 Name: <input type="text" name="firstname" value="<?php echo $firstname;?>"> 
 <span class="error">* <?php echo $firstnameErr;?></span> 
 <br><br> 
 E-mail: <input type="text" name="email" value="<?php echo $email;?>"> 
 <span class="error">* <?php echo $emailErr;?></span> 
 <br><br> 
 lastname: <input type="text" name="lastname" value="<?php echo $lastname;?>"> 
 <span class="error"><?php echo $lastnameErr;?></span> 
 <br><br> 
 
 <input type="submit" name="submit" value="Submit"> 
</form> 

<?php 
echo "<h2>Your Input:</h2>"; 
echo $firstname; 
echo "<br>"; 
echo $lastname; 
echo "<br>"; 
echo $email; 
echo "<br>";  
?>


<?php 
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
$dbname = "last"; 

try { 
 $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, 
$password); 

  
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
 
        $first_name = $_REQUEST['firstname'];
		$last_name = $_REQUEST['lastname'];
		$email = $_REQUEST['email'];
 
 $sql = "INSERT INTO lastmoments (firstname,lastname,email)
 VALUES ('$first_name', '$last_name', '$email')"; 
  
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