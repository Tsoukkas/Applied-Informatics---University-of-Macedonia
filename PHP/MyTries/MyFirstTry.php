<!DOCTYPE HTML> 
<html>
<head>
<style>
.error {color: #FF0000;}
</style>
</head>
<body> 
<?php
$nameR = $emailR = $ageR = $genderR = "";
$name = $email = $age = $university = $gender = "";


if ($_SERVER["REQUEST_METHOD"] == "POST") {
   if (empty($_POST["name"])) {
     $nameR = "Name is required";
   } else {
     $name = test_input($_POST["name"]);
     // check if name only contains letters and whitespace
     if (!preg_match("/^[a-zA-Z ]*$/",$name)) {
       $nameR = "Only letters and white space allowed"; 
     }
   }
   
   if (empty($_POST["email"])) {
     $emailR = "Email is required";
   } else {
     $email = test_input($_POST["email"]);
     // check if e-mail address is well-formed
     if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
       $emailR = "Invalid email format"; 
     }
   }
     
   if (empty($_POST["age"])) {
     $ageR = "Your age is required";
   } else {
     $age = test_input($_POST["age"]);
     // check if URL address syntax is valid (this regular expression also allows dashes in the URL)
  
   }

   if (empty($_POST["university"])) {
     $university = "";
   } else {
     $university = test_input($_POST["university"]);
   }

   if (empty($_POST["gender"])) {
     $genderR = "Gender is required";
   } else {
     $gender = test_input($_POST["gender"]);
   }
}

function test_input($data) {
   $data = trim($data);
   $data = stripslashes($data);
   $data = htmlspecialchars($data);
   return $data;
}
?>

<h2>PHP Practice</h2>
<p><span class="error">* the field is required</span></p>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>"> 
   Name: <input type="text" name="name">
   <span class="error">* <?php echo $nameR;?></span>
   <br><br>
   E-mail: <input type="text" name="email">
   <span class="error">* <?php echo $emailR;?></span>
   <br><br>
   Age: <input type="text" name="age">
   <span class="error"><?php echo $ageR;?></span>
   <br><br>
   University: <input type="text" name="niversity">
   <br><br>
   Gender:
   <input type="radio" name="gender" value="female">Female
   <input type="radio" name="gender" value="male">Male
   <span class="error">* <?php echo $genderR;?></span>
   <br><br>
   <input type="submit" name="submit" value="Submit"> 
</form>


<?php
echo "<h2>Your Input:</h2>";
echo $name;
echo "<br>";
echo $email;
echo "<br>";
echo $age;
echo "<br>";
echo $university;
echo "<br>";
echo $gender;
?>

</body>
</html>