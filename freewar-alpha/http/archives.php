<?
if (isset($type))
{
 switch ($type)
 {
  case "news":

  $type = "archives";
  include("news.php3");

  break;
  default:
  break;
 }
}
?>