<?
error_reporting(63);
// Affiche une boucle de tous les groupes
// on demande la liste des membres de la team $groupe
$requete = mysql_query("SELECT DISTINCT groupe FROM membres_tbl ORDER BY groupe ASC");
$total = mysql_num_rows($requete);

$reponse = mysql_num_rows(mysql_query("SELECT id FROM membres_tbl"));

      // On affiche la liste des membres
      echo "<div style=\"text-align:center\"><table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" style=\"width:80%\">\n".
        "<tr><td style=\"text-align:center; background-color:white; width:15%\">\n".
        "<span class=\"couleur2\">Titre Spécial</span></td>\n".
        "<td style=\"text-align:center; background-color:white; width:20%\">\n".
        "<span class=\"couleur2\">Nickname</span></td>\n".
        "<td style=\"text-align:center; background-color:white; width:30%\">\n".
        "<span class=\"couleur2\">Divers</span></td>\n".
        "<td style=\"text-align:center; background-color:white; width:25%\">\n".
        "</td>\n".
        "</tr>\n";

for($i=0;$i<$total;$i++)
{
      if ($i!=0)
      {
            // On affiche la liste des membres
            echo "<div style=\"text-align:center\"><table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" style=\"width:80%\">\n";
      }

      $groupe = mysql_result($requete,$i,"groupe");
      if(is_numeric($groupe))
      {
          if ($groupe==1)
          {
               echo "<tr><td style=\"background-color:#66CCFF; width:100%\" colspan=\"4\"><div style=\"text-align:center\"><span class=\"couleur\">Administration:</span></div></td></tr>";
          }
          else
          {
               echo "<tr><td style=\"background-color:#66CCFF; width:100%\" colspan=\"4\"><div style=\"text-align:center\"><span class=\"couleur\">Divers ($groupe):</span></div></td></tr>";
          }
      }
      else
      {
          echo "<tr><td style=\"background-color:#66CCFF; width:100%\" colspan=\"4\"><div style=\"text-align:center\"><span class=\"couleur\">Equipe $groupe:</span></div></td></tr>";
      }


      $req = mysql_query("SELECT nick,email,icq,titre,snipeur,rusheur,teamplay FROM membres_tbl WHERE groupe LIKE '$groupe'");
      $res = mysql_num_rows($req);

      for($o=0;$o<$res;$o++)
      {
            $nick = mysql_result($req,$o,"nick" );
            $email = mysql_result($req,$o,"email" );
            $icq = mysql_result($req,$o,"icq" );
            if(empty($icq))
            {
               $icq = "&nbsp;";
            }
            else
            {
               $icq = "<a href=\"http://wwp.icq.com/scripts/search.dll?to=$icq\"><img alt=\"AddICQ\" src=\"../image/addicq.gif\" style=\"border:0\"></a>";
            }

            $titre = mysql_result($req,$o,"titre");

            echo "<tr><td style=\"text-align:center; width:15%\">\n".
            "<span class=\"couleur\">$titre</span></td>\n".
            "<td style=\"text-align:center; width:20%\">\n".
            "<span class=\"couleur\">$nick</span></td>\n".
            "<td style=\"text-align:center; width:30%\">$icq<a href=\"mailto:$email\">".
            " <img alt=\"eMail\" src=\"../image/email.png\" style=\"border:0\"></a>".
            " <a href=\"#\" onclick=\"javascript:window.open('hg/pagemembre.php3?membre=$nick','Membre','width=550,height=450,scrollbars=yes')\">Description</a>".
            "</td>\n".
            "<td style=\"text-align:center; width:25%\">";

            echo "</td>\n".
            "</tr>\n";
      }
           echo "</table></div><br>\n";
}

$reqpostulant = mysql_query("SELECT nick,email,icq,groupe FROM postulants_tbl");
$respostulant = mysql_num_rows($reqpostulant);
if ($respostulant!=0)
{

echo "<div style=\"text-align:center\"><table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" style=\"width:80%\">\n".
      "<tr><td style=\"text-align:center; background-color:black; width:15%\">\n".
      "<span class=\"couleur2\">Région/Pays</span></td>\n".
      "<td style=\"text-align:center; background-color:black; width:20%\">\n".
      "<span class=\"couleur2\">Nickname</span></td>\n".
      "<td style=\"text-align:center; background-color:black; width:30%\">\n".
      "<span class=\"couleur2\">Divers</span></td>\n".
      "<td style=\"text-align:center; background-color:black; width:25%\">\n".
      "<span class=\"couleur2\">&nbsp;</span></td>\n".
      "</tr>\n";

for($j=0;$j<$respostulant;$j++)
{
     $groupe = mysql_result( $reqpostulant , $j , "groupe" );
     $nick = mysql_result( $reqpostulant, $j, "nick" );
     $email = mysql_result( $reqpostulant, $j, "email" );
     $icq = mysql_result( $reqpostulant, $j, "icq" );
      if(empty($icq))
      {
         $icq = "&nbsp;";
      }
      else
      {
         $icq = "<a href=\"http://wwp.icq.com/scripts/search.dll?to=$icq\"><img alt=\"AddICQ\" src=\"../image/addicq.gif\" style=\"border:0\"></a>";
      }

     echo "<tr><td style=\"text-align:center;width:15%\">\n".
     "<span class=\"couleur\">$groupe</span></td>\n".
     "<td style=\"text-align:center; width:20%\">\n".
     "<span class=\"couleur\">$nick</span></td>\n".
     "<td style=\"text-align:center; width:30%\">$icq".
     "<a href=\"mailto:$email\">".
     " <img alt=\"eMail\" src=\"../image/email.gif\" style=\"border:0\"></a>".
     "</td>\n".
     "<td style=\"width:25%\">&nbsp;</td>\n".
     "</tr>\n";
}
echo "</table></div>";
}
echo "<br><br><div style=\"text-align:center\" style=\"width:80%\"><span class=\"couleur2\">Voir les <a href=\"index2.php3?page=retraite\">personnes</a> qui ont également participés à l'aventure.</span></div>";
?>