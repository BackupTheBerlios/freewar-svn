<?
if (!isset($PHP_AUTH_PW) || !isset($PHP_AUTH_USER))
{ $PHP_AUTH_PW = ""; $PHP_AUTH_USER = ""; }

echo"<body bgcolor=\"black\" background=\"image/fondrouge.jpg\">\n".

"<div style=\"text-align:center\"><span class=\"couleur2\">Administration</span>\n".
"<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"300\">\n".

    "<tr>\n".
        "<td bgcolor=\"black\" align=\"center\" width=\"100%\">\n".
         "<span class=\"couleur\">Erreur</span>\n".
        "</td>\n".
    "</tr>\n".
    "<tr>\n".
        "<td background=\"design/bois.jpg\" align=\"center\" width=\"100%\">\n".
          "&nbsp;\n".
        "</td>\n".
    "</tr>\n".
    "<tr>\n".
        "<td background=\"design/bois.jpg\" align=\"center\" width=\"100%\">\n".
         "<span class=\"couleur\">$texte</span>\n".
         "</td>\n".
    "</tr>\n".
    "<tr>\n".
        "<td background=\"design/bois.jpg\" align=\"center\" width=\"100%\">\n".
         "&nbsp;\n".
        "</td>\n".
    "</tr>\n".
    "<tr>\n".
        "<td background=\"design/bois.jpg\" align=\"center\" width=\"100%\">\n".
              "<form action=\"?auth=yes\" method=\"post\">\n".
              "<input type=\"hidden\" name=\"dejavu\"  value=\"1\">\n".
              "<input type=\"hidden\" name=\"oldpw\" value=\"$PHP_AUTH_PW\">\n".
              "<input type=\"hidden\" name=\"olduser\" value=\"$PHP_AUTH_USER\">\n".
              "<input type=\"Submit\" value=\"Se ré-authentifier\">\n".
              "</form>\n".
        "</td>\n".
    "</tr>\n".
"</table>\n".
"</div>\n";
?>