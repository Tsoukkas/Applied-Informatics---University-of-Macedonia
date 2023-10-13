<?php

// Σύνδεση με τη βάση δεδομένων
$host = 'localhost';
$db   = 'polis';
$user = 'root';
$pass = '';

$connection = mysqli_connect($host,$user,$pass,$db) or die("Error " . mysqli_error($connection));


$sql = "select * FROM cities";
$result = mysqli_query($connection, $sql) or die("Error in Selecting " . mysqli_error($connection));

$items = array();

while ($row = mysqli_fetch_array($result)) {
$nested_data = array();
//$nested_data['fname']= $row['fname'];
$nested_data['name']= $row['name'];
$nested_data['monument']= $row['monument'];
$nested_data['country']= $row['country'];
$nested_data['image']= $row['image'];
$items[$row['id']] = $nested_data;
}
echo json_encode($items);

mysqli_close($connection);

?>
