<?
include("entete.php3");
include("config.php3");
include("connexion.php3");
connectmysql();

switch($action)
{
case 1:
 if(empty($texte))
 {
  $texte = "Tu as oublier de mettre un message.";
  include("erreur.php3");
 }
 else
 {
  $texte = str_replace ("<", "" , $texte);
  $texte = str_replace (">", "" , $texte);
  $texte = str_replace ("\"", "" , $texte);
  $texte = str_replace ("script", "" , $texte);

  if(mysql_query("INSERT INTO tribune_tbl VALUES('','".time()."','$texte','".getenv("REMOTE_ADDR")."')"))
  {
   $texte = "Message ajouté avec succès.";
   include("succes.php3");
  }
  else
  {
   $texte = "Erreur interne ";
   include("erreur.php3");
  }
 }
break;
default;
 echo "<div style=\"text-align:center\"><span class=\"couleur2\">".
        "Tribune, ajout de message:</span><br>".

        "<form action=\"tribune.php3?action=1\" method=\"post\">".
        "<input type=\"hidden\" value=\"1\" name=\"action\">".

        "<textarea maxlenght=\"40\" name=\"texte\">Ton message...</textarea><br>".
        "<input type=\"submit\" value=\"Envoyer\">";
break;
}
?>