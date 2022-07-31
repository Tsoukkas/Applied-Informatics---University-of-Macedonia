<head> 
<style> 
.error {color: #FF0000;} 
</style> 
</head> 
<body> 

<?php 
// define variables and set to empty values 
$nameErr = $websiteErr = ""; 
$name = $website =  ""; 

if ($_SERVER["REQUEST_METHOD"] == "POST") { 
 if (empty($_POST["name"])) { 
 $nameErr = "Name is required"; 
 } else { 
 $name = test_input($_POST["name"]); 
 // check if name only contains letters and whitespace 
 if (!preg_match("/^[a-zA-Z ]*$/",$name)) { 
 $nameErr = "Only letters and white space allowed"; 
 } } 
 
 if (empty($_POST["website"])) { 
 $website = "Website is Required"; 
 } else { 
 $website = test_input($_POST["website"]); 
 if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-
9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i",$website)) { 
 $websiteErr = "Invalid URL"; 
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
htmlspecialchars($_SERVER["index.php"]);?>">

 Name: <input type="text" name="name" value="<?php echo $name;?>"> 
 <span class="error">* <?php echo $nameErr;?></span> 
 <br><br> 

 Website: <input type="text" name="website" value="<?php echo $website;?>"> 
 <span class="error">*<?php echo $websiteErr;?></span> 
 <br><br> 
 
 <input type="submit" name="submit1" value="Submit" on click="function1()"> 

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
 
 echo "connection successfull" ;
 function function1(){
if(isset($_POST['submit1'])){
$first=$_POST["name"];
$site = $_POST["website"];
 $conn->beginTransaction(); 
 $conn->exec("INSERT INTO dedomena (name, website) 
 VALUES ('$first','$site')"); 
  $conn->commit();
 echo "New record created successfully"; 
}

}
} 
catch(PDOException $e) 
 { 
 $conn->rollback();
 echo $sql . "<br>" . $e->getMessage(); 
 } 
$conn = null; 
?>	

</form>
</body> 
</html>