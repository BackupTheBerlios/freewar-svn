<?
include("../config.php");
include("../entete.php");
echo "</head>";

echo "<div style=\"text-align:center\"><span class=\"couleur2\">Aide en HTML<br><br>";

echo "N'utilisez pas les connaissances que vous avez pour créer quoi que ce soit, le site".
       " est en HTML 4.01 strict, et requiert des spécifications pour chaque balise html; ce qu'un editeur d'HTML comme".
       " Dreamweaver ou FrontPage Express est périmé, donc il vaut mieux s'abstenir que mettre une balise HTML au hasard.".
       "<br>Si vous n'etes pas sur, demandez a Doomsday.</span></div>".

       "<br><br><br><span class=\"couleur\">Exemple courant des principales balises dont vous pouvez vous servir: <br>"; ?>Pour faire un lien vers une page web: &lt;a href=&quot;#&quot; onclick=&quot;javascript:window.open('url')&quot;&gt;Titre&lt;/a&gt; <br><?
       echo "Pour faire un lien vers un email: &lt;a href=&quot;mailto:email@france.net&quot;&gt;Nick de la personne&lt;/a&gt; <br>".

         "Pour mettre cette </span><span class=\"couleur2\">couleur</span><span class=\"couleur\">: &lt;span class=&quot;couleur2&quot;&gt;Le texte blabla&lt;/span&gt; <br>".

         "C'est tout pour l'instant, si vous désirez autre chose, dite le moi sur irc, ou par <a href=\"mailto:doomsday@mailclub.net\">mail</a></span>";
?>