<?
error_reporting(2047);
require ("../config.php");
require("../entete.php");
echo "</head>";
include("../connexion.php");
connectmysql();
@session_start();

switch ($type)
{
 case "add":

/* Si le champ NOM ou EMAIL ou PASSWORD précédemment rempli est vide */
if (empty($nick) OR empty($email) OR empty($password) OR empty($password2) OR empty($groupe))
    {
    $texte = "Seul le champ ICQ peut etre vide !";
    include("../erreur.php");
    exit();
    }

else
    {
    if ($password!=$password2)
         {
              $texte = "Ton password n'a pas été retaper correctement !";
              include("../erreur.php");
              exit();
         }

    //SI tout est ok, alors :

    /*Selection de la base postulants_tbl*/
    $requete = mysql_query("SELECT * FROM postulants_tbl WHERE nick LIKE '$nick'");
    $reponse = @mysql_num_rows($requete);
    $requete2 = mysql_query("SELECT * FROM membres_tbl WHERE nick LIKE '$nick'");
    $reponse2 = @mysql_num_rows($requete);

               /*Vérification, si le postulant est déjà inscrit*/
               if ($reponse!=0 OR $reponse2!=0)
               {
                  $texte = "T'es déjà inscrit !";
                  include("../erreur.php");
               }

               else
               {
                    /* Insertion des données, nom, email, password, et icq du postulants*/
                    $password = md5($password);
                    if( !mysql_query("INSERT INTO membres_tbl VALUES('','$groupe','$nick','$password','".time()."','$email','','$icq','','','','','','','','','','','')") )
                    {
                         $texte = "Préviens le <a href=\"mailto:doomsday@mailclub.net\">webmaster</a>, une impossibilité technique à empeché ton inscription !".mysql_error()."";
                         include("../erreur.php");

                         exit();
                    }

                    $idnick = mysql_result(mysql_query("SELECT id FROM membres_tbl WHERE nick='$nick'"),0,"id");
                    mysql_query("INSERT INTO admin_tbl VALUES('','$idnick','0','1','0','0','1','0','1')");
                    $texte = "Ton Inscription a bien été enregistrée, tu t\'apelle maintenant \"$nick@Bloodshed.cs\".";
                    include("../succes.php");

                    $welcome = "Salut,proutTu%20viens%20d'être%20inscris%20comme%20membre%20dans%20le%20clan%20Bloodshed,"
                    ."et%20nous%20te%20souhaitons%20la%20bienvenue%20!proutNous%20t'invitons%20a%20nous%20rejoindre%20sur%20ICQ"
                    ."%20(nos%20numéros%20sont%20sur%20le%20site%20web%20section%20Membres)%20ou%20bien%20sur%20IRC%20(serveur:"
                    ."%20irc.quakenet.org%20channel:diesebloodshed).proutSi%20tu%20n'a%20pas%20ces%20logiciels,%20tu%20peux%20"
                    ."les%20telecharger%20maintenant%20sur%20www.icq.com%20et%20www.mirc.com%20.%20Ces%20logiciels%20permettent"
                    ."%20de%20se%20donner%20rendez%20vous%20facilement%20pour%20les%20parties%20de%20Counter-Strike."
                    ."proutproutPS:%20Si%20tu%20n'arrive%20pas%20a%20faire%20marcher%20ces%20logiciels,%20je%20t'invite%20a%20laisser%20un%20"
                    ."message%20d'aide%20sur%20notre%20forum%20(disponible%20via%20le%20site%20web).proutproutprout"
                    ."L'equipe%20Bloodshedprouthttp://bloodshed.free.fr";

                       $nom = $email;
                       $titre = "Bienvenue";
                       $texte = $welcome;
                       $texte = str_replace("%20"," ",$texte);

                    include ("../mail.php");

                    /*$avertissement = "Salut%20a%20tous,%20je%20voulais%20vous%20tenir%20informés%20de%20l'inscription%20d'un%20nouveau"
                    ."%20postulant%20$nick%20parmis%20nous%20!.proutIl%20se%20situe%20dans%20le%20département%20$groupe.proutJe%20vous%20invite%20à%20regarder%20son%20attitude%20pour%20pouvoir%20lui%20donner"
                    ."%20un%20vote%20positif%20ou%20négatif%20Lundi%20prochain%20;)proutSes%20coordonnées%20sont%20sur%20le%20site.prout"
                    ."Team%20BloodShedprouthttp://bloodshed.free.fr";

                    $requete1 = mysql_query("SELECT email FROM membres_tbl");
                    $result1 = mysql_num_rows($requete1);

                    $nametemp = str_replace (" ","%20",$name);

                    for ($i=0 ; $i < $result1 ; $i++)
                    {
                       $mailmembre = mysql_result($requete1 , $i , "email");
                       $nom = $mailmembre;
                       $titre = "Postulant%20BloodShed";
                       $texte = "$avertissement";
                       include ("../mail.php");
                    }*/

               }
    }
 break;
 default:

/* Inscription en tant que Membre Postulant */
   /* Morale..... */
   echo "<span class=\"couleur\"><div style=\"text-align:center\">Si tu veux rejoindre notre Clan, il faut d'abord que tu sois apprécié comme tel parmis".
   " les membres, et que tu respecte les règles de conduites(dispo. sur le site).".
   " Tu restera postulant environ une semaine, et au bout de cette semaine, chaque membre".
   " actuels voteront un avis positif ou négatif sur le postulant (toi). Si 2 votes négatifs sont votés, tu es".
   " refusé de notre clan. Tu pourras retenter une candidature quand tu voudras.</div></span>";

   /* Formulaire a remplir qui ammennera a "addmembre.php" */
   echo "<div style=\"text-align:center\"><form method=\"post\" action=\"addmembre.php?type=add\">

          <table width=\"100%\">

          <!-- Champ Nom -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton surnom : </div></span></td><td width=\"50%\">
          <input type=\"text\" name=\"nick\" maxlength=\"20\" size=\"20\"></td></tr>

          <!-- Champ password -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton Password : </div></span></td><td width\"50%\">
          <input type=\"password\" name=\"password\" maxlength=\"20\"></td></tr>

          <!-- Champ confirmation password -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Confirme ton password : </div></span></td><td width=\"50%\">
          <input type=\"password\" name=\"password2\" maxlength=\"20\"></td></tr>

          <!-- Champ EMail -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton E-Mail : </div></td><td width=\"50%\">
          <input type=\"text\" name=\"email\" maxlength=\"50\" size=\"20\"></td></tr>

          <!-- Champ ICQ -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton ICQ : </div></td><td width=\"50%\">
          <input type=\"text\" name=\"icq\" maxlength=\"50\" size=\"20\"></td></tr>

          <!-- Champ groupe -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton département (ou pays): </div></td><td width=\"50%\">
          <select name=\"groupe\">";
          for($g=1;$g<100;$g++)
          {
              echo "<option>$g</option>";
          }
          // Option pour les étrangers :)
          echo "<option>Québec</option>".
               "<option>Belgique</option>".
               "<option>Luxembourg</option>".
               "<option>Suisse</option>";

          echo"</select></table><br><br><br>".
          "<!-- Bouton de confirmation -->
          <input type=\"submit\" name=\"inscription\" value=\"S'inscrire\">";

echo "<span class=\"couleur\"><br><br>PS: Le password sert à l'administration du postulant quand il sera membre.
       </span></form></div></body>";
break;
}
?>