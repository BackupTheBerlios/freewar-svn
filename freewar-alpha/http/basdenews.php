<?
/* Suite de news.php3 */

/* ptits liens des archives de news*/
echo "<br><b>Archives des news :</b>";


/* Selection de la base, et choix des colonnes d�sir�s : moisPN anneePN */
$requete = mysql_query( "SELECT date FROM news_tbl ORDER BY date ASC" );
$reponse = mysql_num_rows( $requete );

/* Je mets en variable les mois/ann�e d'aujourd'hui */
$moistoday = date("n",$dateuh);
$anneetoday = strftime("%Y",time());

/* J'affiche les diff�rents mois / ann�e */
for( $i=0 ;$i<$reponse ; $i++ )
{
      $dateuh = mysql_result($requete,$i,"date");
      $moistemp2 = strftime("%m",$dateuh);
      /* Si c'est la 1ere "boucle" */
      if (empty($moistemp))
      {
          $moistemp = date("n",$dateuh);
          $anneetemp = strftime("%Y",$dateuh);
          $moistableau = array(1=>"Janvier", "F�vrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Ao�t", "Septembre","Octobre", "Novembre", "D�cembre");

          echo " <a href=\"?page=archives&amp;date=$dateuh\">".$moistableau[$moistemp]." $anneetemp</a>";

      }
      else
      {
          /* Si j'ai d�j� mis un mois identique a celui que je vais mettre, alors je reviens en haut */
          if ( $moistemp != $moistemp2 )
          {
               $anneetemp = strftime("%Y",$dateuh);
               $moischiffre = date("n",$dateuh);
               if ($moischiffre != $moistoday )
               {
                  $moistemp = date("n",$dateuh);
                  $moistableau = array(1=>"Janvier", "F�vrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Ao�t", "Septembre","Octobre", "Novembre", "D�cembre");
                  $moiseuh = $moistableau[$moistemp];

                  //$moiseuh = $moistab[$moistemp];
                  echo " - <a href=\"?page=archives&amp;type=news&amp;date=$dateuh\">$moiseuh $anneetemp</a>";
               }
          }
      }
}
?>
