<?
// modified by cam (une deuxième fois)
echo "<div style=\"text-align:left\"><table width=\"80%\">".
       "<tr>";

// Titre
echo "<td style=\"width:45%\"><span class=\"couleur2\">Partenaire ZorkShooter:</span></td>".
     "<td style=\"width:45%\"><span class=\"couleur2\">Tribune : (<a href=\"#\" ".
     "onclick=\"javascript:window.open('tribune.php3','Tribune','width=300,".
     "height=150')\">ajouter message</a>)</span></td>".
     "</tr>".
     "<tr>";
// News Zork Shooter
echo  "<td style=\"text-align:left; width:45%\">".
        "<span class=\"couleur2\">";
        // "<script src=\"http://zorkshooter.quakexpert.com/historynews.php3?target=1\" type=\"\" language=\"JavaScript\"></script>".
        //"<script src=\"http://www.zorkshooter.com/main/news/news_distantes.php?nombrenews=5&lenghttitre=35\" type=\"\" language=\"JavaScript\"></script>".

        /* added by cam un soir qu'il attendait qu'un download se finisse .. */
echo "<script src=\"http://www.cameuh.net/bloodshed/getzork.php?amp;nombrenews=5&amp;lenghttitre=35&amp;target=1\" type=\"\" language=\"JavaScript\"></script>";
        /* fin de l'added */

echo    "</span>".
      "</td>";

// Tribune !
echo "<td style=\"text-align:left; width:45%\">";

$req = mysql_query("SELECT * FROM tribune_tbl ORDER BY date DESC LIMIT 0,5");
$res = mysql_num_rows($req);

for($i=0;$i<$res;$i++)
{
     $texte = mysql_result($req,$i,"texte");

     $date = mysql_result($req,$i,"date");
     $jrs = strftime("%d",$date);
     $ms = strftime("%m",$date);
     $date = $jrs."/".$ms;

        $texte = str_replace (":)", "<img alt=\":)\" height=\"12\" src=\"image/smiley.gif\">", nl2br($texte));
        $texte = str_replace (";)", "<img alt=\";)\" height=\"12\" src=\"image/clindoeil.gif\">", $texte);
        $texte = str_replace (":smokin","<img alt=\":)\" height=\"12\" src=\"image/smokin.gif\">", $texte);
        $texte = str_replace (":p", "<img alt=\":p\" height=\"12\" src=\"image/langue.gif\">", $texte);

     echo "<span class=\"couleur2\">$date:</span> <span class=\"couleur\">$texte</span><br>";
}

echo "</td></tr></table></div>";

?>