<?
require("../entete.php3");
echo "</head>";
require("../config.php3");

/* Inscription en tant que Membre Postulant */
   /* Morale..... */
   echo "<span class=\"couleur\"><div style=\"text-align:center\">Si tu veux rejoindre notre Clan, il faut d'abord que tu sois apprécié comme tel parmis".
   " les membres, et que tu respecte les règles de conduites(dispo. sur le site).".
   " Tu restera postulant environ une semaine, et au bout de cette semaine, chaque membre".
   " actuels voteront un avis positif ou négatif sur le postulant (toi). Si 2 votes négatifs sont votés, tu es".
   " refusé de notre clan. Tu pourras retenter une candidature quand tu voudras.</div></span>";

   /* Formulaire a remplir qui ammennera a "addmembre.php3" */
   echo "<div style=\"text-align:center\"><form method=\"post\" action=\"addmembre.php3\">

          <table width=\"100%\">

          <!-- Champ Nom -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton surnom : </div></span></td><td width=\"50%\">
          <input type=\"text\" name=\"nick\" maxlength=\"20\" size=\"20\"></td></tr>

          <!-- Champ password -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton Password : </div></span></td><td width\"50%\">
          <input type=\"password\" name=\"password\" maxlength=\"20\"></td></tr>

          <!-- Champ confirmation password -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Confirme ton password : </div></span></td><td width=\"50%\">
          <input type=\"password\" name=\"password2\" maxlength=\"20\"></td></tr>

          <!-- Champ EMail -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton E-Mail : </div></td><td width=\"50%\">
          <input type=\"text\" name=\"email\" maxlength=\"50\" size=\"20\"></td></tr>

          <!-- Champ ICQ -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton ICQ : </div></td><td width=\"50%\">
          <input type=\"text\" name=\"icq\" maxlength=\"50\" size=\"20\"></td></tr>

          <!-- Champ groupe -->
          <tr><td width=\"50%\">
          <span class=\"couleur2\"><div align=\"right\">Ton département (ou pays): </div></td><td width=\"50%\">
          <select name=\"groupe\">";
          for($g=1;$g<100;$g++)
          {
              echo "<option>$g</option>";
          }
          // Option pour les étrangers :)
          echo "<option>Québec</option>".
               "<option>Belgique</option>".
               "<option>Luxembourg</option>".
               "<option>Suisse</option>";

          echo"</select></table><br><br><br>".
          "<!-- Bouton de confirmation -->
          <input type=\"submit\" name=\"inscription\" value=\"S'inscrire\">";

echo "<span class=\"couleur\"><br><br>PS: Le password sert à l'administration du postulant quand il sera membre.
       </span></form></div></body>";
?>