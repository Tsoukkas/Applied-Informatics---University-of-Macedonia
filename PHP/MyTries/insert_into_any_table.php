<!DOCTYPE HTML> 
<html> 
<head> 
<style> 
.error {color: #FF0000;} 
</style> 
</head> 
<body> 
<?php 

$nameErr = $emailErr = $lastnameErr = ""; 
$name = $email = $lastname  = ""; 

if ($_SERVER["REQUEST_METHOD"] == "POST") { 
 if (empty($_POST["name"])) { 
 $nameErr = "Name is required"; 
 } else { 
 $name = test_input($_POST["name"]); 
 // check if name only contains letters and whitespace 
 if (!preg_match("/^[a-zA-Z ]*$/",$name)) { 
 $nameErr = "Only letters and white space allowed"; 
 } } 
 
 if (empty($_POST["lastname"])) { 
 $lastnameErr = "LastName is required"; 
 } else { 
 $lastname = test_input($_POST["lastname"]); 
 // check if name only contains letters and whitespace 
 if (!preg_match("/^[a-zA-Z ]*$/",$lastname)) { 
 $lastnameErr = "Only letters and white space allowed"; 
 } } 
 
 if (empty($_POST["email"])) { 
 $emailErr = "Email is required"; 
 } else { 
 $email = test_input($_POST["email"]); 
 // check if e-mail address is well-formed 
 if (!filter_var($email, FILTER_VALIDATE_EMAIL)) { 
 $emailErr = "Invalid email format"; 
} } }
 
 

function test_input($data) { 
 $data = trim($data); 
 $data = stripslashes($data); 
 $data = htmlspecialchars($data); 
 return $data; 
} 
?>

<h2>PHP Form Validation Example</h2> 
<p><span class="error">* required field.</span></p> 
<form method="post" action="<?php echo 
htmlspecialchars($_SERVER["PHP_SELF"]);?>"> 

 Name: <input type="text" name="name" value="<?php echo $name;?>"> 
 <span class="error">* <?php echo $nameErr;?></span> 
 <br><br> 
 LastName: <input type="text" name="lastname" value="<?php echo $lastname;?>">
 <span class="error">* <?php echo $lastnameErr;?></span>
 <br><br>
 E-mail: <input type="text" name="email" value="<?php echo $email;?>"> 
 <span class="error">* <?php echo $emailErr;?></span> 
 <br><br>  
 <input type="submit" name="submit" value="Submit"> 
</form> 


	
<?php 

if(isset($_POST['submit'])){
	
$servername = "localhost"; 
$username = "root"; 
$password = ""; 
$dbname = "iis21139"; 

$f=$_REQUEST['name'];
$l=$_REQUEST['lastname'];
$m=$_REQUEST['email'];

try { 
 $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, 
$password); 
 
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
 
 $sql = "INSERT INTO Students (firstname, lastname, email) 
 VALUES ('$f', '$l', '$m')";

 $conn->exec($sql); 
 echo "Record created successfully"; 
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
