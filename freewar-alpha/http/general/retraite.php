<?
error_reporting(63);

$req = mysql_query("SELECT * FROM retraite_tbl ORDER BY date ASC");
$res = mysql_num_rows($req);

      // On affiche la liste des membres
      echo "<div style=\"text-align:center\"><table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" style=\"width:80%\">\n".
        "<tr><td style=\"text-align:center; background-color:black; width:10%\">\n".
        "<span class=\"couleur2\">Date d'entrée:</span></td>\n".
        "<td style=\"text-align:center; background-color:black; width:20%\">\n".
        "<span class=\"couleur2\">Nickname</span></td>\n".
        "<td style=\"text-align:center; background-color:black; width:35%\">\n".
        "<span class=\"couleur2\">Divers</span></td>\n".
        "<td style=\"text-align:center; background-color:black; width:25%\">\n".
        "<span class=\"couleur2\">Date de 'démission'</span></td>\n".
        "</tr>\n";

for($i=0;$i<$res;$i++)
{
            // On affiche la liste des membres

            $nick = mysql_result($req,$i,"nick" );
            $email = mysql_result($req,$i,"email" );
            $icq = mysql_result($req,$i,"icq" );
            $datee = mysql_result($req,$i,"date" );
            $dates = mysql_result($req,$i,"dateretraite" );
            $commentaire = mysql_result($req,$i,"commentaire" );
            $commentaire = stripslashes($commentaire);

            $jrs = strftime("%d",$datee);
            $mois = strftime("%m",$datee);
            $annee = strftime("%Y",$datee);
            $datee = "$jrs/$mois/$annee";

            $jrs = strftime("%d",$dates);
            $mois = strftime("%m",$dates);
            $annee = strftime("%Y",$dates);
            $dates = "$jrs/$mois/$annee";


            if(empty($icq))
            {
               $icq = "&nbsp;";
            }
            else
            {
               $icq = "<a href=\"http://wwp.icq.com/scripts/search.dll?to=$icq\"><img alt=\"AddICQ\" src=\"../image/addicq.gif\" style=\"border:0\"></a>";
            }

            echo "<tr><td style=\"text-align:center; width:10%\">\n".
            "<span class=\"couleur\">$datee</span></td>\n".
            "<td style=\"text-align:center; width:20%\">\n".
            "<span class=\"couleur\">$nick</span></td>\n".
            "<td style=\"text-align:center; width:35%\">$icq<a href=\"mailto:$email\">".
            " <img alt=\"eMail\" src=\"../image/email.gif\" style=\"border:0\"></a>".
            " <a href=\"#\" onclick=\"javascript:alert('$commentaire')\">Commentaire</a>".
            "</td>\n".
            "<td style=\"text-align:center; width:25%\">$dates</td>\n".
            "</tr>\n";
}
echo "</table></div><br>\n";
?>