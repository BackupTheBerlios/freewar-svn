<?
$snipeur = mysql_result($req,$o,"snipeur");
$rusheur = mysql_result($req,$o,"rusheur");
$teamplay = mysql_result($req,$o,"teamplay");

switch ($snipeur)
{
        case 0;
        $medsnipeur = "";
        break;
        case 1;
        $medsnipeur = "C++: <img alt=\"Bronze\" src=\"image/cup_bronze.gif\">";
        break;
        case 2;
        $medsnipeur = "C++: <img alt=\"Argent\" src=\"image/cup_silver.gif\">";
        break;
        case 3;
        $medsnipeur = "C++: <img alt=\"Or\" src=\"image/cup_gold.gif\">";
        break;
}
switch ($rusheur)
{
        case 0;
        $medrusheur = "";
        break;
        case 1;
        $medrusheur = "Rush: <img alt=\"Bronze\" src=\"image/cup_bronze.gif\">";
        break;
        case 2;
        $medrusheur = "Rush: <img alt=\"Argent\" src=\"image/cup_silver.gif\">";
        break;
        case 3;
        $medrusheur = "Rush: <img alt=\"Or\" src=\"image/cup_gold.gif\">";
        break;
}
switch ($teamplay)
{
        case 0;
        $medteamplay = "";
        break;
        case 1;
        $medteamplay = "GFX: <img alt=\"Bronze\" src=\"image/cup_bronze.gif\">";
        break;
        case 2;
        $medteamplay = "GFX: <img alt=\"Argent\" src=\"image/cup_silver.gif\">";
        break;
        case 3;
        $medteamplay = "GFX: <img alt=\"Or\" src=\"image/cup_gold.gif\">";
        break;
}

echo "<span class=\"couleur\">$medsnipeur"."$medrusheur"."$medteamplay</span>";

?>