<?
if ($action == "sec")
{
 if (!checkdate($mois,$jour,$annee))
 { echo "Ta date n'est pas valide !"; exit(); }

$sec =  mktime($heure,$minute,0,$mois,$jour,$annee,-1);

echo "Temps en seconde du $jour/$mois/$annee: $sec<br><br>".
     "Autre essai :";
}

echo "<form method=\"post\" action=\"time.php3\">";

       echo "Minutes: <select name=\"minute\">";
       for ($i=0;$i<60;$i++)
       {
        echo"<option>$i</option>";
       }
       echo "</select><br>";

       echo "Heure: <select name=\"heure\">";
       for ($i=0;$i<24;$i++)
       {
        echo"<option>$i</option>";
       }
       echo "</select><br>";

       echo "Jour: <select name=\"jour\">";
       for ($i=1;$i<32;$i++)
       {
        echo"<option>$i</option>";
       }
       echo "</select><br>";

       echo "Mois: <select name=\"mois\">";
       for ($i=1;$i<13;$i++)
       {
        echo"<option>$i</option>";
       }
       echo "</select><br>";
       
       echo "Annee: <select name=\"annee\">";
       for ($i=1998;$i<2005;$i++)
       {
        echo"<option>$i</option>";
       }

echo "</select><br>".
        "<input type=\"hidden\" name=\"action\" value=\"sec\">".
        "<input type=\"submit\" value=\"OK\">";

?>