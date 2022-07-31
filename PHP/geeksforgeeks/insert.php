<!DOCTYPE html>
<html>

<head>
	<title>Insert Page page</title>
</head>

<body>
	
		
		<?php 
   try { 
     $conn = new PDO("mysql:host=localhost;dbname=staff", "root", 
   ""); 
 // set the PDO error mode to exception  
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
 
		// Taking all 5 values from the form data(input)
		$first_name = $_REQUEST['first_name'];
		$last_name = $_REQUEST['last_name'];
		$gender = $_REQUEST['gender'];
		$address = $_REQUEST['address'];
		$email = $_REQUEST['email'];
		
		// Performing insert query execution
		// here our table name is college
		$sql = "INSERT INTO collage VALUES ('$first_name',
			'$last_name','$gender','$address','$email')";
         $conn->exec($sql); 
		 echo "<h3>data stored in a database successfully."
				. " Please browse your localhost php my admin"
				. " to view the updated data</h3>";
          } 
     catch(PDOException $e) 
    { 
	
    echo $sql . "<br>" . $e->getMessage(); 
   } 
  $conn = null; 
  ?> 
		
</body>

</html>
