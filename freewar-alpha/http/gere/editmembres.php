<?
require("../config.php");
require("../entete.php");
echo "</head>";
require("../admin.php");

@session_start();
include("../connexion.php");
connectmysql();

switch ($type)
{
case "info":
       if (session_is_registered("nickauth"))
       {
             if(mysql_query("UPDATE membres_tbl SET email='$email',icq='$icq',arme='$arme',map='$map',connexion='$connexion',pays='$pays',ville='$ville',urlphoto='$urlphoto',age='$age',commentaire='$commentaire' WHERE nick='$nickauth'"))
             {
                   $texte = "Modifications réussies";
                   include("../succes.php");
             }
             else
             {
                 $texte = "Il n'y a plus d'encre, changez de cartouche.".mysql_errno();
                 include("../erreur.php");
             }
       }
       else
       {
           $texte = "Tu dois être logué pour modifier tes informations.";
           include("../erreur.php");
       }
break;
case "sup":

       if (session_is_registered("nickauth") && session_is_registered("levmembres") && $levmembres == 2)
       {
           // Definition des variables necessaire pour le mettre dans la table retraite_bl
           $retraite = mysql_query("SELECT nick,email,icq,date,commentaire FROM membres_tbl WHERE id='$id'");
           $nick = mysql_result($retraite,0,"nick");
           $email = mysql_result($retraite,0,"email");
           $icq = mysql_result($retraite,0,"icq");
           $date = mysql_result($retraite,0,"date");
           $commentaire = mysql_result($retraite,0,"commentaire");
           $commentaire = addslashes($commentaire);

           if (!mysql_query("INSERT INTO retraite_tbl VALUES('','$nick','$email','$icq','$date','".time()."','$commentaire')"))
           {
                $texte = "Une impossiblité technique a empeché le bon fonctionnement<br>".
                "de la suppresion du membre. Si le problème persiste, consultez un médecin... heu,".
                "<a href=\"mailto:doomsday@mailclub.net\">Doomsday</a> ;)<br>".mysql_error();
                include("../erreur.php");
                mysql_close();
           }
           else
           {
               mysql_query("DELETE FROM membres_tbl WHERE id='$id'");
               mysql_query("DELETE FROM admin_tbl WHERE id='$id'");
               $texte = "Membre supprimé avec succès.<br>".mysql_error();
               include("../succes.php");
               mysql_close();
           }

       }
       else
       {
            $texte = "Tu dois être logués pour supprimer un membre.";
            include("../erreur.php");
       }

break;
case "mod":
       switch ($action)
       {
       case "mod":

         $req = mysql_query("SELECT * FROM membres_tbl WHERE id='$id'");
         $reqadmin = mysql_query("SELECT * FROM admin_tbl WHERE idnick='$id'");

         $titre = mysql_result($req,0,"titre");
         $groupe = mysql_result($req,0,"groupe");
         $tp = mysql_result($req,0,"teamplay");
         $rush = mysql_result($req,0,"rusheur");
         $snip = mysql_result($req,0,"snipeur");

         $news = mysql_result($reqadmin,0,"news");
         $membres = mysql_result($reqadmin,0,"membres");
         $matchs = mysql_result($reqadmin,0,"matchs");
         $lan = mysql_result($reqadmin,0,"lan");
         $screen = mysql_result($reqadmin,0,"screenshots");
         $strat = mysql_result($reqadmin,0,"strat");
         $commentaire = mysql_result($reqadmin,0,"commentaire");

         echo "<form action=\"editmembres.php\" method=\"post\">".
               "<input type=\"hidden\" name=\"id\" value=\"$id\">".
               "<input type=\"hidden\" name=\"type\" value=\"mod\">".
               "<input type=\"hidden\" name=\"action\" value=\"verifmod\">";


         $titre = "<input type=\"text\" value=\"$titre\" name=\"titre\">";
         // Medailles !
         $tptemp = "<select name=\"tp\">";
                  if ($tp==0) $tptemp.= "<option selected value=\"0\">Aucune</option>";
                  else $tptemp.= "<option value=\"0\">Aucune</option>";
                  if ($tp==1) $tptemp.= "<option selected value=\"1\">Bronze</option>";
                  else $tptemp.= "<option value=\"1\">Bronze</option>";
                  if ($tp==2) $tptemp.= "<option selected value=\"2\">Argent</option>";
                  else $tptemp.= "<option value=\"2\">Argent</option>";
                  if ($tp==3) $tptemp.= "<option selected value=\"3\">Or</option>";
                  else $tptemp.= "<option value=\"3\">Or</option>";
         $tp = $tptemp."</select>";

         $rushtemp = "<select name=\"rush\">";
                  if ($rush==0) $rushtemp.= "<option selected value=\"0\">Aucune</option>";
                  else $rushtemp.= "<option value=\"0\">Aucune</option>";
                  if ($rush==1) $rushtemp.= "<option selected value=\"1\">Bronze</option>";
                  else $rushtemp.= "<option value=\"1\">Bronze</option>";
                  if ($rush==2) $rushtemp.= "<option selected value=\"2\">Argent</option>";
                  else $rushtemp.= "<option value=\"2\">Argent</option>";
                  if ($rush==3) $rushtemp.= "<option selected value=\"3\">Or</option>";
                  else $rushtemp.= "<option value=\"3\">Or</option>";
         $rush = $rushtemp."</select>";

         $sniptemp = "<select name=\"snip\">";
                  if ($snip==0) $sniptemp.= "<option selected value=\"0\">Aucune</option>";
                  else $sniptemp.= "<option value=\"0\">Aucune</option>";
                  if ($snip==1) $sniptemp.= "<option selected value=\"1\">Bronze</option>";
                  else $sniptemp.= "<option value=\"1\">Bronze</option>";
                  if ($snip==2) $sniptemp.= "<option selected value=\"2\">Argent</option>";
                  else $sniptemp.= "<option value=\"2\">Argent</option>";
                  if ($snip==3) $sniptemp.= "<option selected value=\"3\">Or</option>";
                  else $sniptemp.= "<option value=\"3\">Or</option>";
         $snip = $sniptemp."</select>";

         $newstemp = "<select name=\"news\">";
                  if ($news==0) $newstemp.= "<option selected value=\"0\">Aucun</option>";
                  else $newstemp.= "<option value=\"0\">Aucun</option>";
                  if ($news==1) $newstemp.= "<option selected value=\"1\">Ajouter</option>";
                  else $newstemp.= "<option value=\"1\">Ajouter</option>";
                  if ($news==2) $newstemp.= "<option selected value=\"2\">Modifier/Effacer</option>";
                  else $newstemp.= "<option value=\"2\">Modifier/Effacer</option>";
         $news = $newstemp."</select>";

         $membrestemp = "<select name=\"membres\">";
                  if ($membres==0) $membrestemp.= "<option selected value=\"0\">Aucun</option>";
                  else $membrestemp.= "<option value=\"0\">Aucun</option>";
                  if ($membres==1) $membrestemp.= "<option selected value=\"1\">Ajouter</option>";
                  else $membrestemp.= "<option value=\"1\">Ajouter</option>";
                  if ($membres==2) $membrestemp.= "<option selected value=\"2\">Modifier/Effacer</option>";
                  else $membrestemp.= "<option value=\"2\">Modifier/Effacer</option>";
         $membres = $membrestemp."</select>";

         $matchstemp = "<select name=\"matchs\">";
                  if ($matchs==0) $matchstemp.= "<option selected value=\"0\">Aucun</option>";
                  else $matchstemp.= "<option value=\"0\">Aucun</option>";
                  if ($matchs==1) $matchstemp.= "<option selected value=\"1\">Ajouter</option>";
                  else $matchstemp.= "<option value=\"1\">Ajouter</option>";
                  if ($matchs==2) $matchstemp.= "<option selected value=\"2\">Modifier/Effacer</option>";
                  else $matchstemp.= "<option value=\"2\">Modifier/Effacer</option>";
         $matchs = $matchstemp."</select>";

         $lantemp = "<select name=\"lan\">";
                  if ($lan==0) $lantemp.= "<option selected value=\"0\">Aucun</option>";
                  else $lantemp.= "<option value=\"0\">Aucun</option>";
                  if ($lan==1) $lantemp.= "<option selected value=\"1\">Ajouter</option>";
                  else $lantemp.= "<option value=\"1\">Ajouter</option>";
                  if ($lan==2) $lantemp.= "<option selected value=\"2\">Modifier/Effacer</option>";
                  else $lantemp.= "<option value=\"2\">Modifier/Effacer</option>";
         $lan = $lantemp."</select>";

         $screentemp = "<select name=\"screen\">";
                  if ($screen==0) $screentemp.= "<option selected value=\"0\">Aucun</option>";
                  else $screentemp.= "<option value=\"0\">Aucun</option>";
                  if ($screen==1) $screentemp.= "<option selected value=\"1\">Ajouter</option>";
                  else $screentemp.= "<option value=\"1\">Ajouter</option>";
                  if ($screen==2) $screentemp.= "<option selected value=\"2\">Modifier/Effacer</option>";
                  else $screentemp.= "<option value=\"2\">Modifier/Effacer</option>";
         $screen = $screentemp."</select>";

         $strattemp = "<select name=\"strat\">";
                  if ($strat==0) $strattemp.= "<option selected value=\"0\">Aucun</option>";
                  else $strattemp.= "<option value=\"0\">Aucun</option>";
                  if ($strat==1) $strattemp.= "<option selected value=\"1\">Ajouter</option>";
                  else $strattemp.= "<option value=\"1\">Ajouter</option>";
                  if ($strat==2) $strattemp.= "<option selected value=\"2\">Modifier/Effacer</option>";
                  else $strattemp.= "<option value=\"2\">Modifier/Effacer</option>";
         $strat = $strattemp."</select>";

         $commentairetemp = "<select name=\"strat\">";
                  if ($commentaire==0) $commentairetemp.= "<option selected value=\"0\">Aucun</option>";
                  else $commentairetemp.= "<option value=\"0\">Aucun</option>";
                  if ($commentaire==1) $commentairetemp.= "<option selected value=\"1\">Ajouter</option>";
                  else $commentairetemp.= "<option value=\"1\">Ajouter</option>";
                  if ($commentaire==2) $commentairetemp.= "<option selected value=\"2\">Modifier/Effacer</option>";
                  else $commentairetemp.= "<option value=\"2\">Modifier/Effacer</option>";
         $commentaire = $commentairetemp."</select>";

         $groupe = "<input type=\"text\" value=\"$groupe\" name=\"groupe\">";

         echo "<div style=\"text-align:center\"><span class=\"couleur2\">Modification de membres</span></div>".
                "<table width=\"100%\" style=\"border:0\" cellpadding=\"0\" cellspacing=\"0\">".

                "<tr>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Titre</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Teamplay</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Rusheur</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Snipeur</span></td>".
                "</tr>".

                "<tr>".
                "<td style=\"widht:100%\" colspan=\"100\">&nbsp;</td>".
                "</tr>".

                "<tr>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$titre</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$tp</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$rush</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$snip</span></td>".
                "</tr>".

                "<tr>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Droit modif.: News</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Membres</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Match</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">LAN</span></td>".
                "</tr>".

                "<tr>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$news</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$membres</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$matchs</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$lan</span></td>".
                "</tr>".

                "<tr>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Screen-shots</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Strats.</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Commentaire</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">Groupe</span></td>".
                "</tr>".

                "<tr>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$screen</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$strat</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$commentaire</span></td>".
                "<td colspan=\"25\" style=\"width:25%,background-color:black,text-align:center\"><span class=\"couleur2\">$groupe</span></td>".
                "</tr>".

                "<tr><td style=\"widht:100%\" colspan=\"100\"><input type=\"submit\" value=\"Modifier\"></td></tr>".


                "</table>";

       break;
       case "verifmod":

       if(session_is_registered("nickauth") && $levmembres==2)
       {
             if(mysql_query("UPDATE membres_tbl SET groupe='$groupe',titre='$titre',rusheur='$rush',teamplay='$tp',snipeur='$snip' WHERE id='$id'"))
             {
                if(mysql_query("UPDATE admin_tbl SET news='$news',membres='$membres',lan='$lan',matchs='$matchs',screenshots='$screen',strat='$strat' WHERE idnick='$id'"))
                {
                   $texte = "Modifications réussies";
                   include("../succes.php");
                }
                else
                {
                    $texte = "Le 386 a laché !";
                    include("../erreur.php");
                }
             }
             else
             {
                 $texte = "Il n'y a plus d'encre, changez de cartouche.";
                 include("../erreur.php");
             }
       }
       else
       {
           $texte = "Tu dois être logué mon gars";
           include("../erreur.php");
       }

       break;
       default:
         echo "<div style=\"text-align:center\"><span class=\"couleur2\">Supression de membres</span></div>";
         echo "<table width=\"100%\" style=\"border:0\" cellpadding=\"0\" cellspacing=\"0\">";

         echo "<tr><td style=\"width:40%,background-color:black,text-align:center\"><span class=\"couleur2\">Recrutement</span></td>".
                "<td style=\"width:40%,background-color:black,text-align:center\"><span class=\"couleur2\">Membre</span></td>".
                "<td style=\"width:40%,background-color:black,text-align:center\">&nbsp;</td></tr>";

         $req = mysql_query("SELECT id,nick,date FROM membres_tbl");
         $res = mysql_num_rows($req);

         for($i=0;$i<$res;$i++)
         {
                $idmembres = mysql_result($req,$i,"id");
                $nick = mysql_result($req,$i,"nick");
                $date = mysql_result($req,$i,"date");

                $heure = strftime("%H",$date);
                $minute = strftime("%M",$date);
                $jour = strftime("%d",$date);
                $mois = strftime("%m",$date);
                $annee = strftime("%Y",$date);

                $date = "à $heure:$minute le $jour/$mois/$annee";

                echo "<tr><td width=\"40%\" align=\"center\"><span class=\"couleur\">$date<font></td>".
                "<td width=\"40%\" align=\"center\"><span class=\"couleur\">$nick</span></td>".
                "<td width=\"20%\" align=\"center\"><span class=\"couleur\">".
                "<a href=\"editmembres.php?type=mod&amp;action=mod&amp;id=$idmembres\">Modifier</a>".
                "<a href=\"editmembres.php?type=sup&amp;id=$idmembres\">Effacer</a>".
                "</span></td></tr>";
         }
         echo "</table>";
       break;
       }
 break;
 default:
         $req = mysql_query("SELECT email,icq,commentaire,arme,map,age,connexion,pays,urlphoto,ville FROM membres_tbl WHERE nick='$nickauth'");
         $email = mysql_result($req,0,"email");
        $icq = mysql_result($req,0,"icq");
         $commentaire = mysql_result($req,0,"commentaire");
         $arme = mysql_result($req,0,"arme");
         $map = mysql_result($req,0,"map");
         $age = mysql_result($req,0,"age");
         $connexion = mysql_result($req,0,"connexion");
         $pays = mysql_result($req,0,"pays");
         $urlphoto = mysql_result($req,0,"urlphoto");
         $ville = mysql_result($req,0,"ville");

         echo "<form action=\"editmembres.php?type=info\" method=\"post\">".

             "<div style=\"text-align:center\"><span class=\"couleur2\">Modifications des données personnelles:</span></div><br>".
              "<table style=\"width:100%\">".

              "<tr>".
                       "<td colspan=\"100\" style=\"width:100%\">Activer/Désactiver les cookies pour le login: ";

         if (empty($PASSAUTH))
         {
             echo        "<input type=\"button\" value=\"Envoyer cookies\" onclick=\"javascript:window.open('cookie.php')\">".
                         " (<a href=\"#\" onclick=\"javascript:alert('Vérifiez bien que les cookies sont".
                         " activés sur votre Navigateur.')\">?</a>)";
         }
         else
         {
             echo        "<input type=\"button\" value=\"Effacer cookies\" ".
                         "onclick=\"javascript:window.open('cookie.php?type=sup')\">";
         }



         echo          "</td>".
              "</tr>".

              "<tr>".
                       "<td style=\"width:70%\" colspan=\"70\"><span class=\"couleur\">Ton Email: ".
                           "<input type=\"text\" style=\"width:250px\" value=\"$email\" name=\"email\"></span>".
                       "</td>".
                       "<td style=\"width:30%\" colspan=\"30\" align=\"center\"><span class=\"couleur\">Ton ICQ: ".
                            "<input type=\"text\" style=\"width:80px\" value=\"$icq\" name=\"icq\"></span>".
                       "</td>".
              "</tr>".
              "<tr><td width=\"33%\" colspan=\"33\" align=\"center\"><span class=\"couleur\">Arme préférée: ".
                            "<input type=\"text\" value=\"$arme\" name=\"arme\">".
                       "</td>".
                       "<td style=\"width:34%\" colspan=\"34\" align=\"center\"><span class=\"couleur\">Map préférée: ".
                            "<input type=\"text\" value=\"$map\" name=\"map\"></span>".
                       "</td>".
                       "<td style=\"width:33%\" colspan=\"33\" align=\"center\"><span class=\"couleur\">Connexion: ".
                            "<input type=\"text\" value=\"$connexion\" name=\"connexion\"></span>".
                       "</td>".
              "</tr>".
              "<tr><td style=\"width:50%\" colspan=\"50\" align=\"center\"><span class=\"couleur\">Pays: ".
                            "<input type=\"text\" value=\"$pays\" name=\"pays\"></span>".
                       "</td>".

                   "<td style=\"width:50%\" colspan=\"50\" align=\"center\"><span class=\"couleur\">Ville: ".
                            "<input type=\"text\" value=\"$ville\" name=\"ville\"></span>".
                       "</td>".
              "</tr>".
              "<tr><td style=\"width:70%\" colspan=\"70\" align=\"center\"><span class=\"couleur\">URL d'une photo a toi: ".
                            "<input type=\"text\" value=\"$urlphoto\" name=\"urlphoto\"></span>".
                       "</td>".
                       "<td style=\"width:30%\" colspan=\"30\" align=\"center\"><span class=\"couleur\">Ton age: ".
                            "<input type=\"text\" style=\"width:20px\" name=\"age\" value=\"$age\"></span>".
                       "</td>".
              "</tr></table><br><br>".



              "<div style=\"text-align:center\"><span class=\"couleur\">Commentaire, description:<br>".
                            "<textarea rows=\"10\" cols=\"50\" name=\"commentaire\">$commentaire</textarea></span>".
              "</div>".

              "<div style=\"text-align:center\"><input type=\"submit\" value=\"Modifier\"></div>".

              "</form>";
 break;
}
?>