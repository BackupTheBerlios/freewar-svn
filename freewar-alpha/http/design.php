<body>
<div id="menu">
     <p>
        General
     </p>
     <? include ("general/index.php"); ?>
     <p>
        The Game
     </p>
     <? include ("game/index.php"); ?>
     <? include ("signin/index.php"); ?>
</div>
<div id="main">
     <div id="title">
          <img alt="Freewar" border="0" src="design/logo.png">
     </div>
     <br>
     <div id="maincenter">
          <? include ($main); ?>
     </div>
     <div id="copyright">
          <p>
          <? include ("copyright/index.php"); ?>
          </p>
     </div>
</div>