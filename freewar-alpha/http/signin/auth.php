<?
error_reporting(63);
function authentification()
{
    // --- Vérification de l'identifiant et du mot de passe
    header( 'WWW-Authenticate: Basic realm="Freewar"' );
    header( 'Status: 401 Unauthorized' );

    include("config.php");
    include("entete.php");
    echo "</head>";
    //  --- Code de la page affichée en cas d'annulation
    $texte = "Vous avez besoin d'une autorisation !";
    include("signin/erreurauth.php");
}

if (!isset($PHP_AUTH_USER) || isset($dejavu)
     && $PHP_AUTH_USER == $olduser && $PHP_AUTH_PW == $oldpw)
{
    authentification();
    exit();
}
else
{
    include("connexion.php");
    connectmysql();

    //  --- Vérification de l'identifiant et du mot de passe et redirection en conséquent.
    $req = mysql_query("SELECT id,password FROM membres_tbl WHERE nick LIKE '$PHP_AUTH_USER'");
    $res = mysql_num_rows($req);

    if (!empty($res))
    {
         $passmd5 = mysql_result($req,0,"password");
         $passtape = md5($PHP_AUTH_PW);
         if ($passtape == $passmd5)
         {
                     $nickauth = $PHP_AUTH_USER;
                     $auth = "non";
                     $idnick = mysql_result($req,0,"id");

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

                     header ('Location: index.php');

                     $req = mysql_query("SELECT password FROM membres_tbl WHERE nick='$nickauth'");
                     $md5 = mysql_result($req,0,"password");
                     setcookie("PASSAUTH",$md5,time()+24*3600*365);
                     setcookie("NICKAUTH",$nickauth,time()+24*3600*365);
         }
         else
         {
                     include("entete.php");
                     echo "</head>";
                     //  --- Erreur dans le mot de passe
                     $texte= "Ce mot de passe n'est pas correct !";
                     include("signin/erreurauth.php");
         }
    }
    else
    {
            include("entete.php");
            echo "</head>";
            //  --- Erreur dans l'identifiant
            $texte= "Ce pseudo n'est pas correct !";
            include("signin/erreurauth.php");
    }
    mysql_close();
}
?>