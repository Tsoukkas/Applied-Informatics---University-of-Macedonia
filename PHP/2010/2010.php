<!DOCTYPE html>
<html>
<head>
   <title>
     2010
   </title>

</head>

<body>
   <header>
      Applet
   </header>
  
  <?php 
$surnameErr =  $genderErr = $departmentErr = $UniversityErr=$phoneErr = $emailErr=""; 
$surname  = $gender  = $department = $phone = $university= $email=""; 

if ($_SERVER["REQUEST_METHOD"] == "POST") { 
 if (empty($_POST["surname"])) { 
 $surnameErr = "Please fill in your surname"; 
 } else { 
 $surname = test_input($_POST["surname"]); 
 if (!preg_match("/^[a-zA-Z ]*$/",$surname)) { 
 $nameErr = "Only letters and white space allowed"; 
 } } 
 
 if (empty($_POST["phone"])) { 
 $phoneErr = "Please fill in your telephone"; 
 } else { 
 $phone = test_input($_POST["phone"]); 
 } 
 
 if (empty($_POST["university"])) { 
 $UniversityErr = "Please fill in your university"; 
 } else { 
 $university = test_input($_POST["university"]); 
  } 
 
 if (empty($_POST["email"])) { 
 $emailErr = "Please fill in your email"; 
 } else { 
 $email = test_input($_POST["email"]); 
 // check if e-mail address is well-formed 
 if (!filter_var($email, FILTER_VALIDATE_EMAIL)) { 
 $emailErr = "Invalid email format"; 
 } } 
 
 if (empty($_POST["department"])) { 
 $departmentErr = "Please fill in your department"; 
 } else { 
 $department = test_input($_POST["department"]);
  }
  
 
 if (empty($_POST["gender"])) { 
 $genderErr = "Please fill in your sex"; 
 } else { 
 $gender = test_input($_POST["gender"]); } 
} 
 
function test_input($data) { 
 $data = trim($data); 
 $data = stripslashes($data); 
 $data = htmlspecialchars($data); 
 return $data; 
} 

?>

<h2>2010 Exams</h2> 
<form method="post" action="<?php echo 
htmlspecialchars($_SERVER["PHP_SELF"]);?>"> 

 <input type="radio" name="gender" <?php if (isset($gender) && 
$gender=="female") echo "checked";?> value="female">Female 
 <input type="radio" name="gender" <?php if (isset($gender) && 
$gender=="man") echo "checked";?> value="man">Man 
 <br><br>
 
 Surname: <input type="text" name="surname" value="<?php echo $surname;?>"> 
 <br><br> 
 
 email: <input type="text" name="email" value="<?php echo $email;?>"> 
 <br><br>

 Phone: <input type="text" name="phone" value="<?php echo $phone;?>"> 
 <br><br>
 
  University: <input type="text" name="university" value="<?php echo $university;?>"> 
 <br><br> 
 
 Department: <input type="text" name="department" value="<?php echo $department;?>"> 
 <br><br> 
 
 <input type="submit" name="submit" value="Submit"> 
 
</form> 


<?php

check($surnameErr,$surname);
check($genderErr,$gender);
check($departmentErr,$department);
check($UniversityErr,$university);
check($phoneErr,$phone);
check($emailErr,$email);

function check($a,$b){
	if($a != " "){
    echo $a;
    }
    if($a==""){
	echo $b;
	}
}
?>

</body>
</html>
