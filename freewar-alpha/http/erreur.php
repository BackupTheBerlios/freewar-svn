<?
$texte = stripslashes($texte);
echo"
<body style=\"background-color:white\">\n".

"<div style=\"text-align:center\"><span class=\"couleur2\">Administration</span>\n".
"<table border=\"0\" cellspacing=\"0\" cellpadding=\"0\" style=\"width: 300px\">\n".

    "<tr>\n".
        "<td style=\"background-color: white; text-align: center;width: 100%\">\n".
         "<span class=\"couleur\">Erreur</span>\n".
        "</td>\n".
    "</tr>\n".

    "<tr>\n".
        "<td style=\"width: 100%; text-align:center\">\n".
         "<span class=\"couleur\">&nbsp;</span>\n".
        "</td>\n".
    "</tr>\n".

    "<tr>\n".
        "<td style=\"width: 100%; text-align:center\">\n".
              "<span class=\"couleur\">$texte</span>\n".
        "</td>\n".
    "</tr>\n".

    "<tr>\n".
        "<td style=\"width: 100%; text-align:center\">\n".
         "<span class=\"couleur\">&nbsp;</span>\n".
        "</td>\n".
    "</tr>\n".

    "<tr>\n".
        "<td style=\"background-color: white; text-align: center; width: 100%\">\n".
              "<a href=\"#\" onclick=\"javascript:window.history.go(-1)\">Retour</a>\n".
        "</td>\n".
    "</tr>\n".


"</table>\n".
"</div>\n";
?>