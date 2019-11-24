<?php
if(!isset($_POST['user_id']) || !isset($_POST['user_pw'])) exit;

$user_id = $_POST['user_id'];
$user_pw = $_POST['user_pw'];
$conn = mysqli_connect('localhost', 'root' , '0000', 'certis');

mysqli_query($conn, "
    INSERT INTO userdata (
        id,
        pw
    ) VALUES (
	'{$user_id}',
	'{$user_pw}'
    )");

echo "insert";
?>

