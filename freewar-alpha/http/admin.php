<?
function paragraphe($titre,$fichier)
{
       global $membres;
       if ($fichier=="membres")
       {
              echo "".
              "<tr>".
                  "<td bgcolor=\"black\" width=\"100%\" colspan=\"100\"><font class=\"text\"><div align=center>$titre</div></font>".
                  "</td>".
              "</tr>".
              "<tr>";

                  if($membres==2)
                  {
                      echo "<td colspan=\"33\" width=\"33%\"><div style=\"text-align:center\"><span class=\"text\">".
                           "<a href=\"#\" onclick=\"javascript:window.open('gere/addmembre.php','Administration','width=550,height=450,scrollbars=yes')\">Ajouter</a></span></div>".
                            "</td>".
                              "<td colspan=\"34\" width=\"34%\"><div style=\"text-align:center\"><span class=\"text\"><a href=\"#\" onclick=\"javascript:window.open('gere/edit"."$fichier".".php','Administration','width=550,height=450,scrollbars=yes')\">Infos Personnelles.</a></span></div>".
                              "</td>".
                              "<td colspan=\"33\" width=\"33%\"><div style=\"text-align:center\"><span class=\"text\">".
                              "<a href=\"#\" onclick=\"javascript:window.open('gere/edit"."$fichier".".php?type=mod','Administration','width=550,height=450,scrollbars=yes')\">Modifier/Ejecter</a></span></div>".
                            "</td>";
                  }
                  else
                  {
                      echo "<td colspan=\"100\" width=\"33%\"><div style=\"text-align:center\"><span class=\"text\"><a href=\"#\" onclick=\"javascript:window.open('gere/edit"."$fichier".".php','Administration','width=550,height=450,scrollbars=yes')\">Infos Personnelles.</a></span></div>".
                            "</td>";
                  }

              echo "</tr>".
              "<tr>".
                  "<td width=\"100%\" colspan=\"100\">&nbsp;".
                  "</td>".
              "</tr>";
       }
       else
       {
              echo "
              <tr>
                  <td bgcolor=\"black\" width=\"100%\" colspan=\"100\"><div style=\"text-align:center\"><span class=\"text\">$titre</span></div>
                  </td>
              </tr>
              <tr>
                  <td colspan=\"50\" width=\"50%\"><div style=\"text-align:center\"><span class=\"text\"><a href=\"#\" onclick=\"javascript:window.open('gere/add"."$fichier".".php','Administration','width=550,height=450,scrollbars=yes')\">Ajouter</a></span></div>
                  </td>
                  <td colspan=\"50\" width=\"50%\"><div style=\"text-align:center\"><span class=\"text\"><a href=\"#\" onclick=\"javascript:window.open('gere/edit"."$fichier".".php','Administration','width=550,height=450,scrollbars=yes')\">Modifier/Effacer</a></span></div>
                  </td>
              </tr>
              <tr>
                  <td width=\"100%\" colspan=\"100\">&nbsp;
                  </td>
              </tr>";
       }
}

function form($form1,$form2,$form3,$formurl,$formtexte)
{
       global $defform1,$defform2,$defform3,$deftexte;
       if ($form1!="")
       {
              echo"<tr>
                  <td bgcolor=\"black\" width=\"50%\"><div style=\"text-align:center\"><span class=\"text\">$form1</span></div>
                  </td>
                  <td bgcolor=\"black\" width=\"50%\"><div style=\"text-align:center\"><input value=\"$defform1\" size=\"25\" name=\"form1\" maxlength=\"40\" type=\"text\"></div>
                  </td>
              </tr>";
       }
       if ($form2!="")
       {
              echo"<tr>
                  <td bgcolor=\"black\" width=\"50%\"><div style=\"text-align:center\"><span class=\"text\">$form2</span></div>
                  </td>
                  <td bgcolor=\"black\" width=\"50%\"><div style=\"text-align:center\"><input value=\"$defform2\" size=\"25\" name=\"form2\" maxlength=\"40\" type=\"text\"></div>
                  </td>
              </tr>";
       }
       if ($form3!="")
       {
              echo"<tr>
                  <td bgcolor=\"black\" width=\"50%\"><div style=\"text-align:center\"><span class=\"text\">$form3</span></div>
                  <td bgcolor=\"black\" width=\"50%\"><div style=\"text-align:center\"><input value=\"$defform3\" size=\"25\" name=\"form3\" maxlength=\"40\" type=\"text\"></div>
                  </td>
              </tr>";
       }
       if ($formurl!="")
       {
              echo "<tr>
                  <td bgcolor=\"black\" width=\"50%\"><span style=\"text-align:center\"><font class=\"text\">$formurl</span></div>
                  </td>
                  <INPUT TYPE=\"hidden\" name=\"MAX_FILE_SIZE\" value=\"1000000\">
                  <td bgcolor=\"black\" width=\"50%\"><div style=\"text-align:center\"><input size=\"25\" name=\"formurl\" maxlength=\"400\" type=\"file\"></div>
              </tr>";
       }
       if ($formtexte!="")
       {
              echo"<tr>
                  <td bgcolor=\"black\" width=\"50%\"><div style=\"text-align:center\"><span class=\"text\">$formtexte</span></div>
                  </td>
                  <td bgcolor=\"black\" width=\"50%\"><div style=\"text-align:center\"><textarea name=\"text\" rows=\"8\" cols=\"38\">$deftexte</textarea></div>
              </tr>";
       }
       echo "<tr>
              <td bgcolor=\"black\" width=\"100%\" colspan=\"2\"><div style=\"text-align:center\">
                  <input type=\"submit\" value=\"Valider\"></div>
              </td>
            </tr>";

}
?>