<?
require("../config.php");
echo"<head><title>$namesite - Administration</title></head>";
require("../admin.php");
echo "<body background=\"../design/fondrouge.jpg\">";
@session_start();
include("../connexion.php");
connectmysql();

switch ($type)
{
case "sup";
       $reqverif = mysql_query("SELECT count(*) FROM news_tbl WHERE nick='$nickauth' AND id='$idnews'");
       $resverif = mysql_fetch_row($reqverif);

       if (session_is_registered("nickauth") && $levnews > 0 && ($resverif[0]==1 || $levnews==2))
       {
           if (!mysql_query("DELETE FROM news_tbl WHERE id='$idnews'"))
           {
                $texte = "Une impossiblité technique a empeché le bon fonctionnement<br>".
                "de la modification de la news. Si le problème persiste, consultez un médecin... heu,".
                "<a href=\"mailto:doomsday@mailclub.net\">Doomsday</a> ;)<br>".mysql_error();
                include("../erreur.php");
                mysql_close();
           }
           else
           {
               $texte = "News supprimé avec succès.";
               include("../succes.php");
               mysql_close();
           }

       }
       else
       {
            $texte = "Tu dois être logué pour supprimer une news.";
            include("../erreur.php");
       }

break;
default;
switch ($verification)
{
 case 1;
        if (empty($form1) OR empty($text))
        {
                $texte = "Il te manque des données.";
                include("../erreur.php");
        }
        else
        {
                $reqverif = mysql_query("SELECT count(*) FROM news_tbl WHERE nick='$nickauth' AND id='$idnews'");
                $resverif = mysql_fetch_row($reqverif);

                if (session_is_registered("nickauth") && $levnews > 0 && ($resverif[0]==1 || $levnews==2))
                {
                    $nickauth = $HTTP_SESSION_VARS["nickauth"];
                    $today = time();
                    if (!mysql_query("UPDATE news_tbl SET titre='$form1',section='$section',texte='$text',source='$form2',urlsource='$form3',modnick='$nickauth',moddate='".time()."' WHERE id='$idnews'"))
                    {
                         $texte = "Une impossiblité technique a empeché le bon fonctionnement<br>".
                         "de la modification de la news. Si le problème persiste, consultez un médecin... heu,".
                         "<a href=\"mailto:doomsday@mailclub.net\">Doomsday</a> ;)<br>".mysql_error();
                         include("../erreur.php");
                         mysql_close();
                    }
                    else
                    {
                        $texte = "News modifié avec succès.";
                        include("../succes.php");
                        mysql_close();
                    }

                }
                else
                {
                     $texte = "Tu dois être logués pour modifier une news.";
                     include("../erreur.php");
                }
        }
 break;
 default;
     if (!empty($idnews))
     {
        echo "<div style=\"text-align:center\"><span class=\"couleur2\">Modification de nouvelle</span></div><br><br>";

        echo "<div style=\"text-align:center\">".
               "<form action=\"editnews.php\" method=\"post\">".
               "<table width=\"40%\" align=\"center\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">".
               "<input type=\"hidden\" name=\"verification\" value=\"1\">".

               "<tr><td bgcolor=\"black\" colspan=\"2\">".

               // Genre de la news
               "<span class=\"couleur\">La news traite de: </span></td>".

               "<tr><td bgcolor=\"black\" width=\"50%\">".
               "<span class=\"couleur\"><p align=\"left\"><input type=\"radio\" name=\"section\" value=\"minibs\" checked>Clan</p></span></td>".
               "<td bgcolor=\"black\" width=\"50%\">".
               "<span class=\"couleur\"><p align=\"right\"><input type=\"radio\" name=\"section\" value=\"minihl\">Half-Life</p></span></td></tr>".
               "<tr><td bgcolor=\"black\" width=\"50%\">".
               "<span class=\"couleur\"><p align=\"left\"><input type=\"radio\" name=\"section\" value=\"minimonde\">Actualité</p></span></td>".
               "<td bgcolor=\"black\" width=\"50%\">".
               "<span class=\"couleur\"><p align=\"right\"><input type=\"radio\" name=\"section\" value=\"miniut\">UnrealTournament</p></span></td></tr>".
               "<tr><td bgcolor=\"black\" width=\"50%\">".
               "<span class=\"couleur\"><p align=\"left\"><input type=\"radio\" name=\"section\" value=\"miniquake\">Quake</p></span></td>".
               "<<td bgcolor=\"black\" width=\"50%\">".
               "<span class=\"couleur\"><p align=\"right\"><input type=\"radio\" name=\"section\" value=\"miniws\">Wolfenstein</p></span></td></tr>".
               "<tr><td bgcolor=\"black\" width=\"100%\" colspan=\"2\">".
               "<span class=\"couleur\"><div style=\"text-align:center\"><input type=\"radio\" name=\"section\" value=\"minicz\">CS:Condition Zero</div></span></td></tr>";

               $req = mysql_query("SELECT titre,source,urlsource,texte FROM news_tbl WHERE id='$idnews'");
               echo "<input type=\"hidden\" name=\"idnews\" value=\"$idnews\">";

               $defform1 = mysql_result($req,0,"titre");
               $defform2 = mysql_result($req,0,"source");
               $defform3 = mysql_result($req,0,"urlsource");
               $deftexte = mysql_result($req,0,"texte");
               form("Titre","Source","URL Source","","Texte");

               echo "</table></form><span class=\"couleur2\"><a href=\"#\" onclick=\"javascript:window.open('helphtml.php')\">Aide HTML</a></span></div>";
     }
     else
     {
         echo "<div style=\"text-align:center\"><span class=\"couleur2\">Modification de news</span></div>";
         echo "<table width=\"100%\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">";

         echo "<tr><td width=\"25%\" bgcolor=\"black\" align=\"center\"><span class=\"couleur2\">Date<font></td>".
                "<td width=\"25%\" bgcolor=\"black\" align=\"center\"><span class=\"couleur2\">Auteur</span></td>".
                "<td width=\"40%\" bgcolor=\"black\" align=\"center\"><span class=\"couleur2\">Titre</span></td>".
                "<td width=\"10%\" bgcolor=\"black\" align=\"center\">&nbsp;</td></tr>";


         if($levnews==1)
         {
             $req = mysql_query("SELECT * FROM news_tbl WHERE nick='$nickauth' ORDER BY id DESC LIMIT 0,20");
         }
         if($levnews==2)
         {
             $req = mysql_query("SELECT * FROM news_tbl ORDER BY id DESC LIMIT 0,20");
         }

         $res = mysql_num_rows($req);

         for($i=0;$i<$res;$i++)
         {
                $idnews = mysql_result($req,$i,"id");
                $titre = mysql_result($req,$i,"titre");
                $nick = mysql_result($req,$i,"nick");
                $date = mysql_result($req,$i,"date");

                $heure = strftime("%H",$date);
                $minute = strftime("%M",$date);
                $jour = strftime("%d",$date);
                $mois = strftime("%m",$date);
                $annee = strftime("%Y",$date);

                $date = "à $heure:$minute le $jour/$mois/$annee";

                echo "<tr><td width=\"25%\" align=\"center\"><span class=\"couleur\">$date<font></td>".
                "<td width=\"15%\" align=\"center\"><span class=\"couleur\">$nick</span></td>".
                "<td width=\"40%\" align=\"center\"><span class=\"couleur\">$titre</span></td>".

                "<td width=\"20%\" align=\"center\"><span class=\"couleur\">".
                "<a href=\"editnews.php?idnews=$idnews\">Modifier</a>".
                "/<a href=\"editnews.php?type=sup&idnews=$idnews\">Effacer</a>";
                echo "</span></td></tr>";
         }
         echo "</table>";
     }
 break;
}
break;
}
?>