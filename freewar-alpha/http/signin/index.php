<?
if (!session_is_registered("nickauth"))
{
    echo  "<p>\n".
          "\tMembers only\n".
          "</p>".
          "<a href=\"?page=$page&amp;auth=yes\" title=\"Sign in!\">Sign in</a>";
}
else
{
    echo  "<p>\n".
          "\t$nickauth\n".
          "</p>".
          "<a href=\"?page=gere\" title=\"Admin the web site\">Menu Admin</a>\n".
          "<a href=\"?page=$page&amp;logout=1\" title=\"Sign out!\">Sign out</a>\n";
}
?>