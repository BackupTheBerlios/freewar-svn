<?
require("../config.php3");
echo "<body bgcolor=\"black\">";

include("../connexion.php3");
connectmysql();

$requete = mysql_query("SELECT * FROM screenshots_tbl WHERE id LIKE '$id'");

$titre = mysql_result($requete,0,"titre");
$commentaire = mysql_result($requete,0,"commentaire");
$nick = mysql_result($requete,0,"nick");

$requetemail = mysql_query("SELECT email FROM membres_tbl WHERE nick='$nick'");
$requetemail2 = mysql_query("SELECT email FROM retraite_tbl WHERE nick='$nick'");

if (mysql_result($requetemail,0,"email"))
{ $mail = mysql_result($requetemail,0,"email"); }
elseif (mysql_result($requetemail2,0,"email"))
{ $mail = mysql_result($requetemail2,0,"email"); }
else
{ $mail = "bloodshed@free.fr"; }

echo "<div style=\"text-align:center\"><img width=\"640\" height=\"480\" title=\"$titre\" src=\"screen/$id.jpg\">".
     "<br><br><span class=\"couleur\"><i>$commentaire</i></span><br><br>".
     "<span class=\"couleur2\">Screen-shot soumis par <b><a href=\"mailto:$mail\">$nick</a></b></span></div>";


?>