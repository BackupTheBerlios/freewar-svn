<?
require("../entete.php3");
echo "</head>";
require ("../config.php3");

/* Si le champ NOM ou EMAIL ou PASSWORD précédemment rempli est vide */
if (empty($nick) OR empty($email) OR empty($password) OR empty($password2) OR empty($groupe))
    {
    $texte = "Seul le champ ICQ peut etre vide !";
    include("../erreur.php3");
    exit();
    }

else
    {
    if ($password!=$password2)
         {
              $texte = "Ton password n'a pas été retaper correctement !";
              include("../erreur.php3");
              exit();
         }

    /*SI tout est ok, alors : */
    //on se connecte a la base:
    include("../connexion.php3");
    connectmysql();

    /*Selection de la base postulants_tbl*/
    $requete = mysql_query("SELECT * FROM postulants_tbl WHERE nick LIKE '$nick'");
    $reponse = @mysql_num_rows($requete);
    $requete2 = mysql_query("SELECT * FROM membres_tbl WHERE nick LIKE '$nick'");
    $reponse2 = @mysql_num_rows($requete);



               /*Vérification, si le postulant est déjà inscrit*/
               if ($reponse!=0 OR $reponse2!=0)
               {
                  $texte = "T'es déjà inscrit !";
                  include("../erreur.php3");
               }

               else
               {
                    /* Insertion des données, nom, email, password, et icq du postulants*/
                    $password = md5($password);
                    if( !mysql_query("INSERT INTO postulants_tbl VALUES('','$nick','".time()."','$email','$icq','$password','$groupe','')") )
                    {
                         $texte = "Préviens le <a href=\"mailto:doomsday@mailclub.net\">webmaster</a>, une impossibilité technique à empeché ton inscription !".mysql_error()."";
                         include("../erreur.php3");

                         exit();
                    }
                    $texte = "Ton Inscription a bien été enregistrée, tu t\'apelle maintenant \"BloodShed-$groupe $nick\".";
                    include("../succes.php3");

                    $welcome = "Salut,proutTu%20viens%20de%20t'inscrire%20comme%20postulant%20dans%20le%20clan%20Bloodshed,"
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

                    include ("../mail.php3");

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
                       include ("../mail.php3");
                    }*/

               }
    }


?>