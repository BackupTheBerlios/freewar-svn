<?
if (session_is_registered("nickauth"))
{
      echo "<div style=\"text-align:center\"><span class=\"htext\">Administration</span></div><br><br>";

      echo "<div style=\"text-align:center\"><table width=\"25%\" align=\"center\">";

  include("admin.php");

  $idnick = mysql_result(mysql_query("SELECT id FROM membres_tbl WHERE nick='$nickauth'"),0,"id");
  $req = mysql_query("SELECT * FROM admin_tbl WHERE idnick LIKE '$idnick'");
  $news = mysql_result($req,0,"news");
  $membres = mysql_result($req,0,"membres");
  $lan = mysql_result($req,0,"lan");
  $matchs = mysql_result($req,0,"matchs");
  $screenshots = mysql_result($req,0,"screenshots");
  $strat = mysql_result($req,0,"strat");

  if($news>0) { paragraphe("News","news"); }
  paragraphe("Membres","membres");
  if($matchs>0) { paragraphe("Match","match"); }
  if($lan>0) { paragraphe("LAN","lan"); }
  if($screenshots>0) { paragraphe("Screen-Shot","screen"); }
  if($strat>0) { paragraphe("Stratégie Privé","strat"); }

  echo "</table></div>";
}
else
{
       $texte = "Tu n'es pas logué";
       include("erreur.php");
}
?>