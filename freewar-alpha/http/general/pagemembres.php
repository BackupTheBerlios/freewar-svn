<?
include("../entete.php3");
include("../config.php3");
include("../connexion.php3");
echo "</head><body>";

connectmysql();

$req = mysql_query("SELECT * FROM membres_tbl WHERE nick='$membre'");
$res = mysql_num_rows($req);
if($res==1)
{
    $groupe = mysql_result($req,0,"groupe");
    $date = mysql_result($req,0,"date");
    $email = mysql_result($req,0,"email");
    $titre = mysql_result($req,0,"titre");
    $icq = mysql_result($req,0,"icq");
    $commentaire = mysql_result($req,0,"commentaire");
    $arme = mysql_result($req,0,"arme");
    $map = mysql_result($req,0,"map");
    $age = mysql_result($req,0,"age");
    $connexion = mysql_result($req,0,"connexion");
    $pays = mysql_result($req,0,"pays");
    $urlphoto = mysql_result($req,0,"urlphoto");
    $ville = mysql_result($req,0,"ville");

    if (empty($date)) $date = "Le début!";
    else
    {
          $jrs = strftime("%d",$date);
          $mois = strftime("%m",$date);
          $annee = strftime("%Y",$date);
          $date = "$jrs/$mois/$annee";
    }

    echo "<div style=\"text-align:center\"><span class=\"couleur2\">Page du membre $membre<br><br></span></div>";

    echo "<table style=\"width:95%\">".

           "<tr><td style=\"width:50%\" colspan=\"50\"><div style=\"text-align:left\"><span class=\"couleur2\">Membre depuis: </span><span class=\"couleur\">$date</span></div></td>".
                "<td style=\"width:50%\" colspan=\"50\"><div style=\"text-align:left\"><span class=\"couleur2\">Infos diverses: </span><span class=\"couleur\">";

           if (!empty($icq))
           {
                echo "ICQ: $icq, ";
           }
           echo "eMail: $email</span></div></td>".
           "</tr><tr><td colspan=\"50\" style=\"width:50%\"><div style=\"text-align:left\"><span class=\"couleur2\">Arme préféré: </span><span class=\"couleur\">$arme</span></div></td>".
                "<td colspan=\"50\" style=\"width:50%\"><div style=\"text-align:left\"><span class=\"couleur2\">Map préféré: </span><span class=\"couleur\">$map</span></div></td>".
           "</tr><tr><td colspan=\"50\" style=\"width:50%\"><div style=\"text-align:left\"><span class=\"couleur2\">Connexion: </span><span class=\"couleur\">$connexion</span></div></td>".
                "<td colspan=\"50\" style=\"width:50%\"><div style=\"text-align:left\"><span class=\"couleur2\">Infos diverses: </span><span class=\"couleur\">Ville: $ville, Pays: $pays</span></div></td>".
           "</tr><tr><td colspan=\"100\" style=\"width:100%\">&nbsp;</td></tr>".
           "<tr><td colspan=\"70\" style=\"width:70%\"><div style=\"text-align:left\"><span class=\"couleur2\">Texte de l'intéréssé:</span><br><span class=\"couleur\">$commentaire</span></div></td>".
           "<td colspan=\"30\" style=\"width:30%\">";

           if (!empty($urlphoto))
           {
                echo "<img alt=\"PhotO!\" src=\"$urlphoto\"></td></tr>";
           }

           echo "</table>";

}
else
{
    $texte = "Effectuez brièvement une perfusion sur le bras shradder.";
    include("../erreur.php3");
}
?>
</body>
</html>