<?php 
$dbhost = 'oniddb.cws.oregonstate.edu';
$dbname = 'lujui-db';
$dbuser = 'lujui-db';
$dbpass = 'vcM2bmdztHb6d793';
$link = new mysqli($dbhost, $dbuser, $dbpass, $dbname);
if ($mysqli->connect_errno) {
    echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
}

    if($_GET){
        $WineInformation1 = $_GET["WineInformation1"];
        $attribute1=$_GET["select1"];
        $order1=$_GET["order1"];
        // $WineInformation2 = $_GET["WineInformation2"];
        // $attribute2=$_GET["select2"];
        // SELECT WK.wine, WK.description FROM `wine_data_1` WD,`wine_ranking` WK WHERE WD.WineID=$wineid and WD.winery= WK.winery LIMIT 0 , 30
        // $query1 = "SELECT WD.WineID, WD.points,WD.price,WD.winery,WD.region1,WD.province,WD.country FROM `wine_data_1` WD,`wine_ranking` WK WHERE WD.$attribute1= '$WineInformation1' and WD.winery= WK.winery LIMIT 0 , 30";
        $query1 = "SELECT WD.WineID, WD.points,WD.price,WD.winery,WD.region1,WD.province,WD.country FROM `wine_data_1` WD,`wine_ranking` WK WHERE WD.$attribute1= '$WineInformation1' and WD.winery= WK.winery ORDER BY WD.$order1 DESC LIMIT 0 , 30";
        $query2 = "SELECT WD.WineID, WD.points,WD.price,WD.winery,WD.region1,WD.province,WD.country FROM `wine_data_2` WD,`wine_ranking` WK WHERE WD.$attribute1 = '$WineInformation1' and WD.winery= WK.winery ORDER BY WD.$order1 DESC LIMIT 0 , 30";
        $query3 = "SELECT WD.WineID, WD.points,WD.price,WD.winery,WD.region1,WD.province,WD.country FROM `wine_data_1` WD WHERE WD.$attribute1 = '$WineInformation1' and WD.WineID not in (SELECT WD1.WineID FROM `wine_data_1` WD1,`wine_ranking` WK WHERE WD.$attribute1= '$WineInformation1' and WD1.winery= WK.winery) LIMIT 0 , 30";
        $query4 = "SELECT WD.WineID, WD.points,WD.price,WD.winery,WD.region1,WD.province,WD.country FROM `wine_data_2` WD WHERE WD.$attribute1 = '$WineInformation1' and WD.WineID not in (SELECT WD1.WineID FROM `wine_data_2` WD1,`wine_ranking` WK WHERE WD.$attribute1= '$WineInformation1' and WD1.winery= WK.winery) LIMIT 0 , 30";

        $data1 = mysqli_query($link, $query1); 
        $data2 = mysqli_query($link, $query2); 
        $data3 = mysqli_query($link, $query3); 
        $data4 = mysqli_query($link, $query4);
        //$data5 = mysqli_query($link, $query5);


    }
    //}
?>
<table width="700" border="1" align="center" style="color:white;">
   <tr>
    <!-- <td >WineID</td> -->
    <td >points</td>
    <td >price</td>
    <td >winery</td>
    <td >region1</td>
    <td >province</td>
    <td >country</td>
    <td >Winery In 2018 top 100</td>
  </tr>
<?php
  for($i=1;$i<=mysqli_num_rows($data1);$i++){
$rs1=mysqli_fetch_row($data1);
?>
  <tr>
    <td><?php echo $rs1[1]?></td>
    <td><?php echo $rs1[2]?></td>
    <td><?php echo $rs1[3]?></td>
    <td><?php echo $rs1[4]?></td>
    <td><?php echo $rs1[5]?></td>
    <td><?php echo $rs1[6]?></td>
    <td><?php echo "<a href='description.php?id=".$rs1[0]."' target='_blank' >Yes</a>"?></td>
  </tr>
  
<?php
}
?>
<?php
  for($i=1;$i<=mysqli_num_rows($data2);$i++){
$rs2=mysqli_fetch_row($data2);
?>
  <tr>
    <td><?php echo $rs2[1]?></td>
    <td><?php echo $rs2[2]?></td>
    <td><?php echo $rs2[3]?></td>
    <td><?php echo $rs2[4]?></td>
    <td><?php echo $rs2[5]?></td>
    <td><?php echo $rs2[6]?></td>
    <td><?php echo "<a href='description.php?id=".$rs2[0]."' target='_blank'>Yes</a>"?></td>
  </tr>
  
<?php
}
?>
<?php
  for($i=1;$i<=mysqli_num_rows($data3);$i++){
$rs3=mysqli_fetch_row($data3);
?>
  <tr>
    <td><?php echo $rs3[1]?></td>
    <td><?php echo $rs3[2]?></td>
    <td><?php echo $rs3[3]?></td>
    <td><?php echo $rs3[4]?></td>
    <td><?php echo $rs3[5]?></td>
    <td><?php echo $rs3[6]?></td>
    <td><?php echo "No"?></td>
  </tr>
  
<?php
}
?>
<?php
  for($i=1;$i<=mysqli_num_rows($data4);$i++){
$rs4=mysqli_fetch_row($data4);
?>
  <tr>
    <td><?php echo $rs4[1]?></td>
    <td><?php echo $rs4[2]?></td>
    <td><?php echo $rs4[3]?></td>
    <td><?php echo $rs4[4]?></td>
    <td><?php echo $rs4[5]?></td>
    <td><?php echo $rs4[6]?></td>
    <td><?php echo "No"?></td>
  </tr>
  
<?php
}
?>