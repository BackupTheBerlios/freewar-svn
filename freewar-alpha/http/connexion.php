<?
function connectmysql()
{
 global $sqlhost, $sqluser, $sqlpass, $sqldbname;

 $lien = mysql_connect($sqlhost, $sqluser, $sqlpass);
 mysql_select_db($sqldbname,$lien);
}
?>