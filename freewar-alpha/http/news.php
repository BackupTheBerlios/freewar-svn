<?
//include("partenaire.php");
error_reporting(0);
if(@isset($type) && $type=="archives")
{
    $actuel_timestamp = $date;

    $moissup = mktime(0,0,0,date("n",$date)+1,1,strftime("%Y",$date));
    $moispreced = mktime(0,0,0,date("n",$date),1,strftime("%Y",$date));
    echo $moispreced." et ".$moisup;
    $query = "SELECT * FROM news_tbl WHERE date<'$moissup' AND date>'$moispreced' ORDER BY date DESC";
}
else
{
    $actuel_timestamp = time();
    $query = "SELECT * FROM news_tbl ORDER BY date DESC LIMIT 0, 10";
}
    $mois_actuel = date("n",$actuel_timestamp);
    $annee_actuelle = strftime("%Y",$actuel_timestamp);

    $moistableau = array(1=>"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre","Octobre", "Novembre", "Décembre");
    $mois_actuel = $moistableau[$mois_actuel];


echo "<span class=\"htext\">Mois en cours : $mois_actuel $annee_actuelle ...</span>";

    /*je me connecte a la base mysql pour les news*/
    $requete = mysql_query($query);
    $result = mysql_num_rows($requete);

        // Trie les news par ordre décroissant
        for ($i=0;$i<$result;$i++)
        {
           // Divers
           $id = mysql_result($requete,$i,"id");
           $nick = mysql_result($requete,$i,"nick");

           // Date
           $date = mysql_result($requete,$i,"date");
           $jour = strftime("%d",$date);
           $idmois = date("n",$date);
           $tempmois = $moistableau[$idmois];
           $annee= strftime("%Y",$date);
           $heure= strftime("%H",$date);
           $minute=strftime("%M",$date);
           $date = "à $heure:$minute le $jour $tempmois $annee";

           // EMail
           $emailtemp = mysql_query("SELECT email FROM membres_tbl WHERE nick LIKE '$nick'");
           if (@mysql_result ($emailtemp,0,"email"))
            { $email = mysql_result ($emailtemp,0,"email"); }
           else
            { $email = "doomsday@mailclub.net"; }

           // Titre
           $titre = mysql_result($requete,$i,"titre");

           // Smiley et autres
           $texte = stripslashes( mysql_result($requete,$i,"texte") );
           $texte = str_replace (":)", "<img alt=\":)\" height=\"12\" src=\"image/smiley.gif\">", nl2br($texte));
           $texte = str_replace (";)", "<img alt=\";)\" height=\"12\" src=\"image/clindoeil.gif\">", $texte);
           $texte = str_replace (":smokin","<img alt=\":)\" height=\"12\" src=\"image/smokin.gif\">", $texte);
           $texte = str_replace (":p", "<img alt=\":p\" height=\"12\" src=\"image/langue.gif\">", $texte);

           // Source de la news
           $source = mysql_result($requete,$i,"source");
           if (!empty($source))
           {
               $urlsource = mysql_result($requete,$i,"urlsource");
               if (!empty($urlsource))
               {
                    $source = "Source: <a href=\"#\" onclick=\"javascript:window.open('$urlsource')\">$source</a>.";
               }
               else
               {
                    $source = " - Source: $source.";
               }
           }
           else $source = "";

           // Modification apporté a la news ?
           $modnick = mysql_result($requete,$i,"modnick");
           if (empty($modnick)) $modif="";
           else
           {
                $moddate = mysql_result($requete,$i,"moddate");
                $jour = strftime("%d",$moddate);
                $tempmois = strftime("%m",$moddate);
                include("def.php");
                $annee= strftime("%Y",$moddate);
                $heure= strftime("%H",$moddate);
                $minute=strftime("%M",$moddate);
                $moddate = "à $heure:$minute le $jour $tempmois2 $annee";

                $modemailtemp = mysql_query("SELECT email FROM membres_tbl WHERE nick LIKE '$modnick'");
                $modemail = mysql_result ($modemailtemp,0,"email");
                $modif="Modifié par <a href=\"mailto:$modemail\">$modnick</a> le $moddate.";
           }

           // Quelle section est la news ?
           $section = mysql_result($requete,$i,"section");

           // Commentaire
           $req_comment = mysql_query("SELECT * FROM commentaire_tbl WHERE idnews='$id'");
           $res_comment = mysql_numrows($req_comment);

           if($res_comment == 0)
              { $commentaire = "<a href=\"?page=comments&amp;id=$id\">Ajouter un commentaire</a>"; }
           else if($res_comment == 1)
                { $commentaire = "<a href=\"?page=comments&amp;id=$id&amp;nb=1\">1 commentaire</a>"; }
           else { $commentaire = "<a href=\"?page=comments&amp;id=$id&amp;nb=$res_comment\">$res_comment commentaires</a>"; }

           // Commentaire non lus !
           $tmp = error_reporting(7);
           $cookie = $HTTP_COOKIE_VARS["COMMENTAIRE$id"];
           error_reporting($tmp);
           if(isset($cookie))
           {
              $commentaire_restant = $res_comment-$cookie;
              if ($commentaire_restant==0) { $commentaire_restant = "( Aucun nouveau. )"; }
              else if ($commentaire_restant>0) { $commentaire_restant = "( $commentaire_restant non lus. )"; }
              else { $commentaire_restant = ""; }
           }
           else { $commentaire_restant = ""; }

           // Choix aléatoire de background du titre
           if( $i%2 ) $image = "mininews.jpg";
           else  $image = "mininews2.jpg";

           // Affichage de toutes les données
           echo "<div id=\"news_author\">\n".
                "\t<b><a href=\"mailto:$email\">$nick</a></b> - $date\n".
                "</div>\n".
                "<div id=\"news_title\">\n".
                "\t<img alt=\"$section\" src=\"image/$section.gif\"> <b>$titre</b>$source\n".
                "</div>\n".
                "<div id=\"news_content\">\n".
                "\t$texte\n".
                "</div>\n".
                "<div id=\"news_comments\">\n".
                "\t$modif $commentaire $commentaire_restant\n".
                "</div>\n".
                "<br><br>\n";
           unset($commentaire_restant);
        }

include ("basdenews.php");
?>