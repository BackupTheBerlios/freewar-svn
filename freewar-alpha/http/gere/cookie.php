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

        $texte = "Cookie supprimé avec succès.";
        include("../succes.php");
break;
default:
if (session_is_registered("nickauth"))
{
        setcookie("PASSAUTH",$md5,time()+$expire,"../");
        require("../entete.php");
        echo "</head>";
        require("../admin.php");

        $texte = "Cookie envoyé avec succès, ils sont opérationnels pendant 1 an.";
        include("../succes.php");

}
else
{
    require("../entete.php");
    echo "</head>";
    require("../admin.php");

    $texte = "Tu dois être logué pour envoyer les cookies.";
    include("../erreur.php");
}
break;
}


?>