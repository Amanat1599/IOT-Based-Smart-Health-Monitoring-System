<html>
<head>
    
    <link rel="stylesheet" type="text/css" href="style.css" media="screen"/>

</head>




<body>
<h1>IOT Based Smart Health Monitering System</h1>
<table>
<tr>
<th> id </th>
<th> x_axis </th>
<th> y_axis </th>
<th> z_axis</th>
<th> Heart Rate</th>
<th> Temperature</th>
<th> Humidity</th>
<th> Date Time</th>

</tr>
<?php

$hostname = "localhost"; 
$username = "root"; 
$password = ""; 
$database = "final_db";  //Database name 

$conn = mysqli_connect($hostname, $username, $password, $database);
$sql="select * from sensor_value";
$result = $conn -> query($sql);

if (($result -> num_rows) >0){
	while ($row = $result->fetch_assoc()){
		echo "<tr><td>" .$row["ID"]. "</td><td>" .$row["x_axis"]."</td><td>" .$row["y_axis"]."</td><td>" .$row["z_axis"]."</td><td>" .$row["Heart_Rate"]."</td><td>" .$row["Temperature"]."</td><td>" .$row["Humidity"]."</td><td>" .$row["DateTime"]."</td></tr>";
	}
}
else{
	echo "No result";
}
$conn->close()

?>
</table>

</body>





</html>