<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "myDB";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "UPDATE MyGuests SET lastname='Dickens' WHERE id=3";

if ($conn->query($sql) === TRUE) {
    $affRows = $conn->affected_rows;
	echo $affRows . " record(s) updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}

$conn->close();
?> 
