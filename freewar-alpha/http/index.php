<?php
$mtime = microtime();
$mtime = explode(" ",$mtime);
$mtime = $mtime[1] + $mtime[0];
$starttime = $mtime;

require("config.php");

// error_reporting(0);
error_reporting(2047);
// Authentification
if (empty($auth)) { $auth = "no"; }
if ($auth=="yes")
{
     $auth = "no";
     include("3d/auth.php");
}

/* on se connecte a la base de données */
if( $lien = mysql_connect($sqlhost, $sqluser, $sqlpass) )
   {
        mysql_select_db($sqldbname, $lien);

// Je détermine tout le tralala pour les sessions/cookies.
session_save_path("/data/tmp/php-session");
session_start();
if (!empty($HTTP_COOKIE_VARS["PASSAUTH"]) && !session_is_registered("nickauth"))
{
    $req = mysql_query("SELECT id,nick,password FROM membres_tbl WHERE password='".$HTTP_COOKIE_VARS['PASSAUTH']."'");
    $res = mysql_num_rows($req);
    if (!empty($res))
    {
            $idnick = mysql_result($req,0,"id");
            $nickauth = mysql_result($req,0,"nick");

            $requu = mysql_query("SELECT * FROM admin_tbl WHERE idnick LIKE '$idnick'");
            $levnews = mysql_result($requu,0,"news");
            $levmembres = mysql_result($requu,0,"membres");
            $levmatchs = mysql_result($requu,0,"matchs");
            $levscreenshots = mysql_result($requu,0,"screenshots");
            $levstrat = mysql_result($requu,0,"strat");
            $levlan = mysql_result($requu,0,"lan");
            $levcomment = mysql_result($requu,0,"commentaire");

            session_register("nickauth");
            session_register("idnick");
            session_register("levlan");
            session_register("levnews");
            session_register("levmembres");
            session_register("levmatchs");
            session_register("levscreenshots");
            session_register("levstrat");
            session_register("levcomment");
    }
    else
    {
        setcookie("PASSAUTH");
    }
}
if (isset($logout) && $logout == 1 || !session_is_registered("nickauth"))
{
    session_unset(); // on efface toutes les variables de session
    session_destroy(); // on detruit la session en cours
    unset($PHP_AUTH_PW);
    unset($PHP_AUTH_USER);
    setcookie("PASSAUTH");
}

// Cookie pour avoir lu les commentaires ou pas !
if ($page=="commentaire")
{
     setcookie("COMMENTAIRE$id",$nb,time()+24*3600*365);
}

include("entete.php");
echo "</head>";

if ($msgerreur==1)
{
     include("erreur.php");
     exit();
}

$nom["news"]             = "news.php";
$nom["archives"]         = "archives.php";
$nom["staff"]            = "general/membres.php";
$nom["download"]         = "general/download.php";
$nom["presentation"]     = "general/presentation.php";
$nom["gere"]             = "gere/index.php";
$nom["retraite"]         = "general/retraite.php";
$nom["commentaire"]      = "commentaire.php";
$nom["building"] 	 = "game/building.php";
$nom["env"]      	 = "game/environ.php";
$nom["os"]      	 = "game/compatibility.php";
$nom["units"]   	 = "game/units.php";
$nom["features"]	 = "game/features.php";
$nom["contact"]          = "general/contact.php";

if(!isset($page))
{
     $page="news";
}
$main=( $nom[$page] );


        include ("design.php");

        mysql_close();
   }
   else
   {
        $texte = "Une erreur est survenu. Contactez le <a href=\"mailto:$emailwebmaster>webmaster</a> si le problème persiste.";
        include("erreur.php");
   }

$mtime = microtime();
$mtime = explode(" ",$mtime);
$mtime = $mtime[1] + $mtime[0];
$endtime = $mtime;
$totaltime = ($endtime - $starttime);

printf("<div style=\"text-align:center\"><span class=\"couleur\">$namesite a généré cette page en %f secondes.</span></div>", $totaltime);
echo "</body></html>";
?>


