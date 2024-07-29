<?php
echo"Hellow world! Test is okay";

$hostname = "localhost"; 
$username = "root"; 
$password = ""; 
$database = "final_db";  //Database name 

$conn = mysqli_connect($hostname, $username, $password, $database);

if (!$conn) { 
	die("Connection failed: " . mysqli_connect_error()); 
} 

echo "Database connection is OK<br>"; 
/*
//if(isset($_POST["temperature"]) && isset($_POST["humidity"])) {

	$t = $_POST["Temperature"];
	$h = $_POST["Humidity"];
*/
    $x= $_POST["x_axis"];
    $y= $_POST["y_axis"];
    $z= $_POST["z_axis"];
	$hr= $_POST["Heart_Rate"];
    $t = $_POST["Temperature"];
	$h = $_POST["Humidity"];
	
	$sql = "insert into sensor_value (x_axis,y_axis,z_axis,Heart_Rate,Temperature,Humidity) VALUES(".$x.", ".$y.",".$z.", ".$hr.",".$t.", ".$h.")"; 

	if (mysqli_query($conn, $sql)) { 
		echo "\nNew record created successfully"; 
	} else { 
		echo "Error: " . $sql . "<br>" . mysqli_error($conn); 
	}



?>