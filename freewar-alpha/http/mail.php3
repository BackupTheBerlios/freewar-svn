<?
$textebr = str_replace ("prout", "\n", $texte);
$textediese = str_replace ("diese", "#", $textebr);
$textefinal = stripslashes($textediese);

mail($nom,$titre,$textefinal,"From: bloodshed@free.fr\nReply-to: bloodshed@free.fr");
?>