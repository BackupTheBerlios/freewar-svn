<?
require("../config.php");
echo"<head><title>$namesite - Administration</title></head>";
require("../admin.php");
echo "<body background=\"../design/fondrouge.jpg\">";
@session_start();
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
                echo "auth:".$HTTP_SESSION_VARS["nickauth"]." lev:$levnews<br>";
                if (session_is_registered("nickauth") && $levnews>0)
                {
                    $nickauth = $HTTP_SESSION_VARS["nickauth"];
                    include("../connexion.php");
                    connectmysql();
                    $text = str_replace("&","&amp;",$text);

                    if (!mysql_query("INSERT INTO news_tbl VALUES('','$nickauth','".time()."','$form1','$section','$text','$form2','$form3','','')"))
                    {
                         $texte = "Une impossiblité technique a empeché le bon fonctionnement<br>".
                         "de l\'insertion de la news. Si le problème persiste, consultez un médecin... heu,".
                         "<a href=\"mailto:doomsday@mailclub.net\">Doomsday</a> ;)<br>".mysql_error();
                         include("../erreur.php");
                         mysql_close();
                    }
                    else
                    {
                        $texte = "News ajouté avec succès.";
                        include("../succes.php");
                        mysql_close();
                    }

                }
                else
                {
                     $texte = "Tu dois être logués pour poster une news.";
                     include("../erreur.php");
                }
        }
 break;
 default;
        echo "<div style=\"text-align:center\"><span class=\"couleur2\">Ajout de nouvelle</span></div><br><br>";

        echo "<div style=\"text-align:center\">".
               "<form action=\"addnews.php\" method=\"post\">".
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

        form("Titre","Source","URL Source","","Texte");

        echo "</table></form><br><span class=\"couleur2\"><a href=\"#\" onclick=\"javascript:window.open('helphtml.php')\">Aide HTML</a></span></div>";
 break;
}


?>