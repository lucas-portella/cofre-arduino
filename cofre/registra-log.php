<?php
    date_default_timezone_set('America/Cuiaba');
    $date = date('d/m/y');
    $access_time = date('H:m:s');
    $user = $_GET["user"];
    $access = $_GET["access"];

    $log_str = $date.",".$access_time.",".$user.",".$access."\n";

    $handle = fopen("logs/logs.csv", "a");
    if ($handle) 
        fwrite ($handle, $log_str);

    fclose($handle);
?>  
