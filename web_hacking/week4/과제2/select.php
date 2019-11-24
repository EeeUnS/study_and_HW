<?php
$conn = mysqli_connect(
  'localhost',
  'root',
  '0000',
  'certis'
);
echo "hel";
$sql = "SELECT * FROM userdata";
$result = mysqli_query($conn, $sql);

while($row = mysqli_fetch_array($result)) 
{
  echo $row['id'] ;
  echo "       " ;
  echo $row['pw'] ;
  echo "<BR>";
}
?>