<?
require("../config.php");
echo"<head><title>$namesite - Administration</title></head>";
require("../admin.php");
echo "<body background=\"../design/fondrouge.jpg\">";
switch ($verification)
{
 case "1";
        if (empty($form1) OR empty($text))
        {
                $texte = "Il te manque des données.";
                include("../erreur.php");
        }
        else
        {
                @session_start();
                if (session_is_registered("nickauth") && $levscreenshots > 0)
                {
                    $nickauth = $HTTP_SESSION_VARS["nickauth"];
                    include("../connexion.php");
                    connectmysql();
                    $today = time();
                    // taille en octet des fichiers maximum
                    $taille = 1000000;


                    $idfuturscreen = mysql_query("SELECT id FROM screenshots_tbl ORDER BY id DESC");
                    $id = mysql_result($idfuturscreen,0,"id");
                    $id = $id+1;

                    if ($formurl_size!=0) {$taille_ko=$formurl_size/1024;} else {$taille_ko=0;}
                    if ($formurl=="none") {$texte="Vous n'avez pas sélectionné de fichier.";include("../erreur.php");}
                    if ($formurl_size>$taille)
                    {
                         if($taille!=0)
                         {
                                 $taille_max_ko=$taille/1024;
                         }
                         $texte="Votre fichier est trop gros ($taille_max_ko ko max)";
                         include("../erreur.php");
                    }
                    if ($formurl!="none" && $formurl_size<$taille && $formurl_size!=0)
                    {
                         $formurl=stripslashes($formurl);                 // pour windows

                         if (!copy($formurl, "../1d/screen/$id.jpg"))
                         {
                              $texte="Probleme de transfert !";
                              include("erreur2.php");
                         }
                         else
                         {
                             $text = nl2br($text);
                             if (!mysql_query("INSERT INTO screenshots_tbl VALUES('$id','$nickauth','$today','$form1','$text','0','')"))
                             {
                                  $texte = "Une impossiblité technique a empeché le bon fonctionnement<br>".
                                  "de l\'insertion du screenshot. Si le problème persiste, consultez un médecin... heu,".
                                  "<a href=\"mailto:doomsday@mailclub.net\">Doomsday</a> ;)<br>".mysql_error();
                                  include("../erreur.php");
                             }
                             else
                             {
                                 $texte = "Screen-shot ajouté avec succès.";
                                 include("../succes.php");
                             }

                         }
                    mysql_close();
                    }

                }
                else
                {
                     $texte = "Vous devez être logués pour poster un screen-shot.";
                     include("../erreur.php");
                }
        }
 break;
 default;
        echo "<div style=\"text-align:center\"><span class=\"couleur2\">Ajout de Screen-Shot</span></div><br><br>";

        echo "<div style=\"text-align:center\">".
               "<form ENCTYPE=\"multipart/form-data\" action=\"addscreen.php\" method=\"post\">".
               "<input type=\"hidden\" name=\"verification\" value=\"1\">".
               "<table width=\"40%\" align=\"center\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">";

        form("Titre","","","Fichier","Commentaire");

        echo "</table></form></div>";
 break;
}


?>