<?php

$opt_email = "tbyron@ncsu.edu";
$opt_a_email = "<a href=\"mailto:tbyron@ncsu.edu\">tbyron@ncsu.edu</a>";

$opt_title = 'Terry Byron';
if (isset($subtitle))
  $opt_title .= " - $subtitle";

define("SHOW_INTRO", 1);
define("SHOW_JOB_TITLE", 2);
define("SHOW_SIDEBAR", 4);


function start_page($opts = 7)
{
  global $opt_title, $opt_a_email;

  $show_intro = ($opts & SHOW_INTRO);
  $show_job_title = ($opts & SHOW_JOB_TITLE);
  $show_sidebar = ($opts & SHOW_SIDEBAR);
  $content = "content";
  if (!$show_sidebar)
    $content = "wide-content";
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html;CHARSET=iso-8859-1">
<title><?php print "$opt_title";?></title>
<link rel="stylesheet" type="text/css" media="screen" href="styles.css">
<link rel="stylesheet" type="text/css" media="print" href="styles.css">
</head>
<body>
<div id="all-wrapper">

  <div id="header">
    <div id="banner">
      <a href="http://www.ncsu.edu"><img src="ncsu-logo.gif" border="0"></a>
    </div>
    <div id="nav">
      <span><a href="index.php">Home</a></span>
      <span><a href="ocr.php">OCR</a></span>
    </div>
  </div>

  <div id="content-wrapper">

<?php if ($show_sidebar): ?>
    <div id="sidebar">
      <img src="tbyron-small.jpg" border="0">
      <br>
      <?php print"$opt_a_email"; ?><br>
      Tel: (919) 515-3630<br>
      Office: 5138 SAS Hall<br>
      <a href="https://maps.ncsu.edu/#/buildings/032A">Campus Map</a>

      <p>
        <b>Mailing Address:</b><br>
        Department of Statistics <br> 
        Campus Box 8203, NCSU<br>
        Raleigh, NC 27695-8203
      </p>
      <p>
        <b>Courier Address:</b><br>
        Department of Statistics <br> 
	2311 Katharine Stinson Drive<br>
        5109 SAS Hall, NCSU<br>
        Raleigh, NC 27607
      </p>
      <p><a href="https://statistics.sciences.ncsu.edu/">Department of Statistics</a></p>
      <p><a href="https://www.ncsu.edu">NC State University</a></p>
    </div>
<?php endif; ?>

<?php if ($show_intro): ?>
    <div id="intro">
      <div id="name">Terry Byron</div>
<?php if ($show_job_title): ?>

     <div id="brc">IT Systems Programmer Sr., 
      <a href="https://statistics.sciences.ncsu.edu/">Department of Statistics</a>, <a href="https://www.ncsu.edu">North Carolina State University, Raleigh NC </a> (May 2001)</div>

<?php endif; ?>
    </div>
<?php endif; ?>

    <div id="<?=$content?>">
<?php
}
?>

<?php
function get_script_filename()
{
  if (isset($_SERVER['PATH_TRANSLATED']))
    return $_SERVER['PATH_TRANSLATED'];

  if (isset($_SERVER['SCRIPT_FILENAME']))
    return $_SERVER['SCRIPT_FILENAME'];

  return null;
}

function end_page()
{
  $last_updated = null;
  $script = get_script_filename();
  if ($script)
    $last_updated = "Last updated: " . date("F j, Y", filemtime($script));
?>
      <div class="clear"></div>

    </div>
  </div>
  <div id="footer">
    <p id="last-update"><?=$last_updated?></p>
    <div id="footer-bar">&nbsp;</div>
  </div>
</div>

</body>
</html>

<?php
}
?>
