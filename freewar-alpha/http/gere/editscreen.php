<?
require("../config.php");
echo"<head><title>$namesite - Administration</title></head>";
require("../admin.php");
echo "<body background=\"../design/fondrouge.jpg\">";
@session_start();
switch ($type)
{
case "sup";


       if (session_is_registered("nickauth") && $levscreenshots > 0)
       {
           include("../connexion.php");
           connectmysql();
           if (!mysql_query("DELETE FROM screenshots_tbl WHERE id='$idscreen'"))
           {
                $texte = "Une impossiblité technique a empeché le bon fonctionnement<br>".
                "de la suppression du screen-shot. Si le problème persiste, consultez un médecin... heu,".
                "<a href=\"mailto:doomsday@mailclub.net\">Doomsday</a> ;)<br>".mysql_error();
                include("../erreur.php");
                mysql_close();
           }
           else
           {
               // suppression du fichier concerné
               unlink("../1d/screen/$idscreen.jpg");

               $texte = "Screen-Shot supprimé avec succès.";
               include("../succes.php");
               mysql_close();
           }

       }
       else
       {
            $texte = "Vous devez être logués pour supprimer un screenshot.";
            include("../erreur.php");
       }

break;
default;

    include("../connexion.php");
    connectmysql();

        echo "<div style=\"text-align:center\"><span class=\"couleur2\">Suppression de Screen-Shot</span></div><br><br>";

         if($levscreenshots==1)
         {
             $req = mysql_query("SELECT * FROM screenshots_tbl WHERE nick='$nickauth' ORDER BY id DESC LIMIT 0,20");
         }
         elseif($levscreenshots==2)
         {
             $req = mysql_query("SELECT * FROM screenshots_tbl ORDER BY id DESC LIMIT 0,20");
         }
         elseif(!session_is_registered("nickauth"))
         {
             $texte = "Tu dois être logué pour faire une action !";
             include("../erreur.php");
         }
         else
         {
             $texte = "Tu n'a aucun droit sur les screen-shots";
             include("../erreur.php");
         }
         if ($res = @mysql_num_rows($req))
         {

                 echo "<div style=\"text-align:center\">".
               "<form action=\"editscreen.php\" method=\"post\">".
               "<input type=\"hidden\" name=\"verification\" value=\"1\">";

               echo "<table width=\"100%\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">";

               echo "<tr><td width=\"25%\" bgcolor=\"black\" align=\"center\"><span class=\"couleur2\">Commentaire<font></td>".
                "<td width=\"25%\" bgcolor=\"black\" align=\"center\"><span class=\"couleur2\">Auteur</span></td>".
                "<td width=\"40%\" bgcolor=\"black\" align=\"center\"><span class=\"couleur2\">Titre</span></td>".
                "<td width=\"10%\" bgcolor=\"black\" align=\"center\">&nbsp;</td></tr>";


                    for($i=0;$i<$res;$i++)
                    {
                          $idscreen = mysql_result($req,$i,"id");
                          $titre = mysql_result($req,$i,"titre");
                          $nick = mysql_result($req,$i,"nick");
                          $commentaire = mysql_result($req,$i,"commentaire");

                          $date = "à $heure:$minute le $jour/$mois/$annee";

                          echo "<tr><td width=\"25%\" align=\"center\"><span class=\"couleur\">$commentaire<font></td>".
                          "<td width=\"15%\" align=\"center\"><span class=\"couleur\">$nick</span></td>".
                          "<td width=\"40%\" align=\"center\"><span class=\"couleur\">$titre</span></td>".

                          "<td width=\"20%\" align=\"center\"><span class=\"couleur\">".
                          "<a href=\"editscreen.php?type=sup&idscreen=$idscreen\">Effacer</a>";
                          echo "</span></td></tr>";
                    }
                echo "</table>";
         }
         else
         {
              echo "<div style=\"text-align:center\"><span class=\"couleur\">Tu n'a aucun screen-shot a ton actif.</span></div>";
         }
break;
}
?>