<?
@session_start();
require("../config.php");
include("../connexion.php");
connectmysql();
$req = mysql_query("SELECT password FROM membres_tbl WHERE nick='$nickauth'");
$md5 = mysql_result($req,0,"password");
$expire = 365*24*3600;

switch($type)
{
case "sup":
        setcookie("PASSAUTH");
        require("../entete.php");
        echo "</head>";
        require("../admin.php");

        $texte = "Cookie supprim� avec succ�s.";
        include("../succes.php");
break;
default:
if (session_is_registered("nickauth"))
{
        setcookie("PASSAUTH",$md5,time()+$expire,"../");
        require("../entete.php");
        echo "</head>";
        require("../admin.php");

        $texte = "Cookie envoy� avec succ�s, ils sont op�rationnels pendant 1 an.";
        include("../succes.php");

}
else
{
    require("../entete.php");
    echo "</head>";
    require("../admin.php");

    $texte = "Tu dois �tre logu� pour envoyer les cookies.";
    include("../erreur.php");
}
break;
}


?>