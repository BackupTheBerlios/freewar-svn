<?
$requetesc = mysql_query("SELECT * FROM screenshots_tbl");
$resultsc = mysql_num_rows($requetesc);
$today = time();

$screenactuel = mysql_query("SELECT * FROM screenshots_tbl WHERE archive='1'");

if (mysql_num_rows($screenactuel))
{
      $insertion = mysql_result($screenactuel,0,"insertion");
      $diff = ($today - $insertion);

      // 259200 est egal a 3jours
      if ($diff > 259200)
      {
           $ok = 1;
           $screentemp = mysql_result($screenactuel,0,"id");
           mysql_query("UPDATE screenshots_tbl SET archive='2' WHERE id='$screentemp'");

      }
      else
      {
          $screen = mysql_result($screenactuel,0,"id");
          $titre = mysql_result($screenactuel,0,"titre");
          $ok = 0;
      }

}
else { $ok = 1; }
if ($ok == 1)
{
      $screenfutur = mysql_query("SELECT * FROM screenshots_tbl WHERE archive='0' ORDER BY id ASC");

      if (mysql_num_rows($screenfutur))
      {
                $screen = mysql_result($screenfutur,0,"id");
                $titre = mysql_result($screenfutur,0,"titre");

                mysql_query("UPDATE screenshots_tbl SET archive='1' WHERE id='$screen'");
                mysql_query("UPDATE screenshots_tbl SET insertion='$today' WHERE id='$screen'");
      }
      else
      {
                $chiffre = @rand(1,$resultsc);
                $screenhasard = mysql_query("SELECT * FROM screenshots_tbl WHERE id='$chiffre'");
                if (mysql_num_rows($screenhasard))
                {
                   $screen = mysql_result($screenhasard,0,"id");
                   $titre = mysql_result($screenhasard,0,"titre");
                }
                else
                {
                    $vide = 1;
                ]
      }
}
if ($vide != 1)
{
 echo "<a href=\"#\" onclick=\"javascript:window.open".
       "('$urlsite/1d/screen.php3?id=$screen','Screenshot','width=800,height=600,scrollbars=yes,left=0,top=0')\">".
       "<img alt=\"$titre\" src=\"$urlsite/1d/screen/$screen.jpg\" width=\"80\" height=\"58\" style=\"border:0\"></a>";
}
?>