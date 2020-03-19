<?php 
$dbhost = 'oniddb.cws.oregonstate.edu';
$dbname = 'lujui-db';
$dbuser = 'lujui-db';
$dbpass = 'vcM2bmdztHb6d793';
$link = new mysqli($dbhost, $dbuser, $dbpass, $dbname);
if ($mysqli->connect_errno) {
    echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
}
?>
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8"><meta name="viewport" content="width=device-width,initial-scale=1" />
		<title>OSU CS540</title>
		<link href="//cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet" />
		<link href="css/description.css?v=1.44" rel="stylesheet" />
	</head>
	<body>
		<nav class="navbar transparent navbar-fixed-top">
			<div class="container-fluid">
			<div class="navbar-header"><button aria-expanded="false" class="navbar-toggle collapsed" data-target="#bs-example-navbar-collapse-6" data-toggle="collapse" type="button"><span class="sr-only">Toggle navigation</span></button><a class="navbar-brand" href="./index.html">OSU CS540</a></div>

			<div class="collapse navbar-collapse" id="bs-example-navbar-collapse-6">
			<!-- <ul class="nav navbar-nav navbar-right">
				<li><a href="helper.html">Helper</a></li>
			</ul> -->
			</div>
			</div>
		</nav>

		<div class="intro-header">
			<div class="container">
				<div class="col-lg-12">
					<div class="intro-message">
					<h1>Top 100 Wine Recommandation</h1>

					<!-- <hr class="intro-divider" /> -->
						<div class="input-group">
							<?php
									$wineid = $_GET["id"];
									$query1 = "SELECT WK.wine, WK.description FROM `wine_data_1` WD,`wine_ranking` WK WHERE WD.WineID=$wineid and WD.winery= WK.winery LIMIT 0 , 30";
									$query2 = "SELECT WK.wine, WK.description FROM `wine_data_2` WD,`wine_ranking` WK WHERE WD.WineID=$wineid and WD.winery= WK.winery LIMIT 0 , 30";
									$data1 = mysqli_query($link, $query1);
									$data2 = mysqli_query($link, $query2);
									if (mysqli_num_rows($data1) == 0 &&mysqli_num_rows($data2) == 0)
									{
										echo "No Result";
										exit;
									}
							?>
							<table width="700" border="1" align="left">
							<tr>
								<td >Wine</td>
								<td >description</td>
							</tr>
							<?php
								for($i=1;$i<=mysqli_num_rows($data1);$i++){
									$rs1=mysqli_fetch_row($data1);
							?>
								<tr>
									<td><?php echo $rs1[0]?></td>
									<td><?php echo $rs1[1]?></td>
								</tr>
							<?php
								}
							?>
							

							<?php
								for($i=1;$i<=mysqli_num_rows($data2);$i++){
									$rs2=mysqli_fetch_row($data2);
							?>
								<tr>
									<td><?php echo $rs2[0]?></td>
									<td><?php echo $rs2[1]?></td>
								</tr>
							<?php
								}
							?>
						</div>
					<!-- &nbsp; -->
					<!-- <div id="msg"></div> -->
					</div>
				</div>
			</div>
		</div>
	</body>
	<!-- <script src="index.php"></script> -->
</html>