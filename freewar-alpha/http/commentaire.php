<?
if (!isset($type)) { $type = "pwet"; }
switch ($type)
{
 case "sup":
    if (session_is_registered("nickauth") && session_is_registered("levcomment"))
    {
        // Effacement du commentaire
        if ($levcomment==1 && $nickauth==$nick || $levcomment==2)
        {
             if(mysql_query("DELETE FROM commentaire_tbl WHERE id='$id'"))
             {
                $texte = "Commentaire supprimé.";
                include("succes.php");
             }
             else
             {
                 $texte = "Erreur du TSX17";
                include("erreur.php");
             }
        }
        else
        {
            $texte = "Quel tricheur celui la :o)";
            include("erreur.php");
        }
    }
    else
    {
        $texte = "Quel tricheur celui la :p";
        include("erreur.php");
    }
 break;
 case "add":
    if (empty($nick) || empty($texte))
    {
        $texte = "Tu as laissé des champs vides !";
        include("erreur.php");
    }
    else
    {
        $req = mysql_query("SELECT count(*) FROM membres_tbl WHERE nick='$nick'");
        if(mysql_result($req,0,"count(*)")==1)
        {
          if(session_is_registered("nickauth"))
          {
              $bonpourposter = 1;
          }
          else
          {
              $texte = "Tu dois te loguer !";
              include("erreur.php");
              $bonpourposter = 0;
          }
        }
        else $bonpourposter = 1;
        if ($bonpourposter == 1)
        {
             if (mysql_query("INSERT INTO commentaire_tbl VALUES('','$idnews','$nick','".time()."','$texte')"))
             {
                 $texte = "Commentaire ajouté.";
                 include("succes.php");
             }
             else
             {
                 $texte = "Prévenir Doomsday, une erreur interne est survenu :(";
                 include("erreur.php");
             }
        }
    }
 break;
 default:
    $query = "SELECT * FROM news_tbl WHERE id='$id'";
    $idnews = $id;

    $moistableau = array(1=>"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre","Octobre", "Novembre", "Décembre");

    /*je me connecte a la base mysql pour les news*/
    $requete = mysql_query($query);
    $result = mysql_num_rows($requete);

    if ($result==1)
    {
        // Trie la news
        $i=0;
           // Divers
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
            { $email = $emailwebmaster; }

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
                    $source = "Source: $source.";
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
              { $commentaire = "Aucun commentaire"; }
           else if($res_comment == 1)
                { $commentaire = "1 commentaire"; }
           else { $commentaire = "$res_comment commentaires"; }


           // Choix aléatoire de background du titre
           $image = "mininews.jpg";

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
                "\t$modif $commentaire\n".
                "</div>\n".
                "<br><br>\n";

           // Boucle pour les commentaires
           for($o=0;$o<$res_comment;$o++)
           {
               // Divers
               $nick = mysql_result($req_comment,$o,"nick");
               $id = mysql_result($req_comment,$o,"id");

               // Date
               $date = mysql_result($req_comment,$o,"date");
               $jour = strftime("%d",$date);
               $idmois = date("n",$date);
               $tempmois = $moistableau[$idmois];
               $annee= strftime("%Y",$date);
               $heure= strftime("%H",$date);
               $minute=strftime("%M",$date);
               $date = " - à $heure:$minute le $jour $tempmois $annee";

               // EMail
               $emailtemp = mysql_query("SELECT email FROM membres_tbl WHERE nick LIKE '$nick'");
               if (@mysql_result ($emailtemp,0,"email"))
                {
                  $email = "<a href=\"mailto:".mysql_result ($emailtemp,0,"email")."\">";
                  $email2 = "</a>";
                }
               else
                {
                  $email = "";
                  $email2= "";
                }

               // texte
               $texte = mysql_result($req_comment,$o,"texte");

               // Smiley et autres
               $texte = stripslashes($texte);
               $texte = str_replace (":)", "<img alt=\":)\" height=\"12\" src=\"image/smiley.gif\">", nl2br($texte));
               $texte = str_replace (";)", "<img alt=\";)\" height=\"12\" src=\"image/clindoeil.gif\">", $texte);
               $texte = str_replace (":smokin","<img alt=\":)\" height=\"12\" src=\"image/smokin.gif\">", $texte);
               $texte = str_replace (":p", "<img alt=\":p\" height=\"12\" src=\"image/langue.gif\">", $texte);

               // Effacement du commentaire
               if (!isset($levcomment)) { $levcomment = 0; }
               if ($levcomment==1 && $nickauth==$nick || $levcomment==2)
               {
                    $effacer = " - <a href=\"?page=commentaire&amp;type=sup&amp;id=$id&amp;nick=$nick\">Supprimer</a>";
               }
               else $effacer = "&nbsp;";

               echo "<div id=\"comments\">\n".
                    "\t<div id=\"comments_title\">\n".
                    "\t\t<b>$email"."$nick"."$email2"."</b>$date$effacer\n".
                    "\t</div>\n".
                    "\t<div id=\"comments_content\">\n".
                    "\t\t$texte\n".
                    "\t</div>\n".
                    "</div>\n".
                    "<br>\n";
           }

           if (!isset($nickauth)) { $nickauth = ""; }
           $emailtemp = mysql_query("SELECT email FROM membres_tbl WHERE nick='$nickauth'");
           $emailauth = @mysql_result ($emailtemp,0,"email");

           echo "<form action=\"?page=commentaire&amp;type=add\" method=\"post\">".

                 // Id de la news
                 "<div style=\"text-align:center\"><input type=\"hidden\" name=\"idnews\" value=\"$idnews\">".

                 "<table width=\"60%\" border=\"0\" style=\"background-color:black\">".
                 "<tr><td colspan=\"3\" style=\"width:100%\"><span class=\"htext\">Ajouter un commentaire:</span></td></tr>".


                 // Nick
                 "<tr><td style=\"width:20%\"><span class=\"text\">Nick:</span></td><td style=\"width:80%\" colspan=\"2\"><input type=\"text\" value=\"$nickauth\" name=\"nick\"></td></tr>".

                 // Email
                 "<tr><td style=\"width:20%\"><span class=\"text\">Email:</span></td><td style=\"width:80%\" colspan=\"2\"><input type=\"text\" value=\"$emailauth\" name=\"email\"></td></tr>".

                 // Texte
                 "<tr><td style=\"width:20%\">&nbsp;</td><td style=\"width:60%\"><textarea rows=\"7\" cols=\"30\" name=\"texte\"></textarea></td><td style=\"width:20%\">&nbsp;</td></tr>".

                 // Bouton envoyer
                 "<tr><td style=\"width:100%\" colspan=\"3\"><input type=\"submit\" value=\"Ajouter\"></td></tr>".

                 "</table></div></form>";
    }
    else
    {
         $texte = "?";
         include("erreur.php");
    }
 break;
}
?>