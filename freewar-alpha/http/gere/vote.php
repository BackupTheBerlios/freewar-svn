<?
require("../config.php");
echo"<head><title>$namesite - Administration</title></head>";
include("../connexion.php");
echo "<body background=\"../design/fondrouge.jpg\">";

// Suspention des votes !
$na = 2;
if ($na==1)
{
@session_start();
connectmysql();

switch ($type)
{
 case "vote";

   /* On demande la liste des membres */
   if (session_is_registered("nickauth"))
   {
        $requete2 = mysql_query("SELECT * FROM votepos_tbl WHERE nick LIKE '$nickauth' AND postulant LIKE '$postulant'");
        $reponse2 = @mysql_num_rows($requete2);

        /*Si le voteur n'a pas deja vot� pour le postulant*/
        if ($reponse2 == 0 )
        {
                         $requete35 = mysql_query("SELECT * FROM postulants_tbl WHERE nick='$postulant'");

                         if ($vote=="Positif") $vote = 0;
                         elseif ($vote=="Negatif")
                         {
                             $vote = mysql_result($requete35,0,"vote")+1;
                             mysql_query("UPDATE postulants_tbl SET vote='$vote' WHERE nick LIKE '$postulant'");
                         }

                         /* Insertion du vote */
                         mysql_query ("INSERT INTO votepos_tbl VALUES ('','$nickauth','$postulant')");
                         $texte =  "Ton vote a bien �t� pris en compte";
                         include("../succes.php");

                        $requete5 = mysql_query("SELECT * FROM votepos_tbl WHERE postulant LIKE '$postulant'");
                        $reponse5 = mysql_num_rows($requete5);
                        $requete6 = mysql_query("SELECT count(*) FROM membres_tbl");
                        $reponse6 = mysql_result($requete6,0,"count(*)");

                        $time = mysql_result($requete35,0,"date")+1814400;
                        if($time < time())
                        { $time = "ok"; }
                        else { $time = "no"; }
                        if ($reponse5 == $reponse6) { $time = "ok"; }
                        $emailposmembre = mysql_result($requete35,0,"email");
                        if ($time == "ok")
                        {
                           if ($vote<2)
                           {
                               $icq = mysql_result($requete35,0,"icq");
                               $password = mysql_result($requete35,0,"password");
                               $groupe = mysql_result($requete35,0,"groupe");

                               /*Insertion du postulant dans les membres*/
                               mysql_query("INSERT INTO membres_tbl VALUES('','$groupe','$postulant','$password','".time()."','$email','','$icq','','','','','','','','','','','')");
                               $idnick = mysql_result(mysql_query("SELECT id FROM membres_tbl WHERE nick='$postulant'"),0,"id");
                               mysql_query("INSERT INTO admin_tbl VALUES('','$idnick','0','1','0','0','1','0')");

                               /*Mise des variables pour l'insertion de la news */
                               $titrepos = "Un nouveau membre est parmis nous !";
                               $textpos = "Le nombre suffisant de vote � �t� atteint pour que $postulant ".
                                "ne soit plus postulant, mais un vrai membre BloodShed maintenant ! Je compte sur vous pour ".
                                "que vous l\'acceptez comme tel, et que vous l\'acceuillez comme il se doit :p.<br>";

                               $textpos2 = "Souhaitez la bienvenue a $postulant ! Il est pass� de postulant ".
                                "� membre BloodShed ! Je compte sur vous pour que vous le guidez dans cette antre qui ".
                                "s\'ouvre � lui ;) Encore bravo $postulant :smokin<br>";

                                $nb = rand(1,11);
                                if ($nb%2) { $textposfinal = $textpos; }
                                else { $textposfinal = $textpos2; }

                                /* Insertion de la news*/
                                mysql_query("INSERT INTO news_tbl VALUES('','Team Bloodshed','".time()."','$titrepos','minibs','$textposfinal','','','','')");

                                $texte = "$postulant a atteint le nombre maximum de voix, et il est d�sormais accept� :)";
                                include("../succes.php");

                                /*Suppression du postulant et de ses votes*/
                                mysql_query("DELETE FROM postulants_tbl WHERE nick='$postulant'");
                                mysql_query("DELETE FROM votepos_tbl WHERE postulant='$postulant'");
                           }
                        }
                        if ($vote>=2)
                        {
                             $texterefus = "Bonjour,%20je%20suis%20d�sol�,%20mais%20le%20vote%20a%20�t�%20majoritairement%20n�gatif%20en%20ta%20d�faveur%20:(.prout".
                             "Peut-etre%20que%20tu%20n'as%20pas%20su%20etre%20actif%20a%20la%20demande%20des%20membres,%20pas%20assez%20participer%20au%20forum,irc%20ou%20tout%20simplementprout".
                             "en%20game%20!%20Mais%20ne%20d�sesp�re%20pas,%20tu%20peux%20toujours%20te%20rattraper%20en%20te%20r�inscrivant%20!%20On%20t'obserervera%20de%20nouveau%20sans%20pr�jug�s%20;)prout".
                             "A%20bientot%20peut-etre,prout".
                             "L'equipe%20Bloodshedprout".
                             "$urlsite";

                             $nom = $emailposmembre;
                             $texte = $texterefus;
                             $texte = str_replace("%20"," ",$texte);
                             $titre = "D�sol�";
                             include ("../mail.php");

                             mysql_query("DELETE FROM postulants_tbl WHERE nick LIKE '$postulant'");
                             mysql_query("DELETE FROM votepos_tbl WHERE postulant LIKE '$postulant'");

                             $texte = "$postulant n'a pas �t� suffisament acclam� ! Il n'est pas accept�...";
                             include("../succes.php");
                        }
        }
        else
        {
            $texte = "Tu as d�j� vot� pour ce postulant.";
            include("../erreur.php");
        }
   }
   else
   {
          $texte = "Tu dois �tre logu�s.";
          include("../erreur.php");
   }
 break;
 default;

 /* Titre */
 echo "<span class=\"couleur2\"><div style=\"text-align:center\">Votez !</div></span>";
 echo "<br><p>&nbsp;</p>";

 echo "<div style=\"text-align:center\"><form type=\"post\" action=\"vote.php?type=vote\">";

 /* Choix du postulant */
     echo "<select name=\"postulant\">";

     $req = mysql_query("SELECT nick FROM postulants_tbl");
     $result = mysql_num_rows($req);

     for($i=0;$i<$result;$i++)
     {
          $postulant = mysql_result($req,$i,"nick");
          echo "<option>$postulant</option>";

     }
     echo "</select>";
     echo "<input type=\"hidden\" name=\"type\" value=\"vote\">";
     echo "<br><br>";

 /* Vote + ou - ? */
 echo "<span class=\"couleur\">Vote </span><select name=\"vote\">";
 echo "<option>Positif</option><option>Neutre</option><option>Negatif</option>";
 echo "</select>";

 echo "<br><br><input type=\"submit\" value=\"Voter\"></form></div>";

 break;
}
}
?>